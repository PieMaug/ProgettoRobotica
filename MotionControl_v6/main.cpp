/*
 * main.cpp
 */

#include "mTimer.h"
#include "geometry.h"
#include "kinematics.h"
#include "speed_control.h"
#include "relative_rotation.h"
#include "absolute_rotation.h"
#include "circ_rotation.h"
#include "path_control.h"
#include "follow_line.h"
#include "goto_point.h"

#include <stdio.h>
#include <fstream>
#include <signal.h>

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>


Pose current_robot_pose;
Kinematics kinematics(current_robot_pose, 0.5, 0.5, 3.33, 4000); // initial values, wheels diameter, interasse, tick
SpeedControlTask speed_control(kinematics);
RelativeRotation relative_rotation(kinematics, speed_control, 1, 2, 1, 0.5, 1);   //acc, vel_max, dec, vel_min ,tolleranza, 
AbsoluteRotation absolute_rotation(kinematics, speed_control, 1, 2, 1, 0.5, 1);
CircularRotation circular_rotation(kinematics, speed_control, 1, 2, 1, 0.5, 0.5);
FollowLine follow_line(kinematics, speed_control, 1, 2, 1, 0.1);
GoTo_Point goto_point(kinematics, speed_control, 1, 2, 1, 0.1);
PathControl path_control(kinematics, speed_control);

//termination signal handler
bool cycle = true;
void terminate(int a){
	cycle = false;
}

//arguments handler
bool absolute = false,
	circular = false,
	follow = false,
	gotop = false,
	relative = false;
int type = 0;
int angle = 0;
float xT = 0, yT = 0,
	xS =  0, yS = 0;
float radius = 0;
void arg_handler(int,char**);

int main(int argc, char** argv){
	arg_handler(argc,argv);
/*
	std::cout << "A: " << absolute << std::endl
			<< "C: " << circular << std::endl
			<< "R: " << relative << std::endl
			<< "1: " << radius << std::endl
			<< "x: " << xT << " y: " << yT << std::endl
			<< "Angle: " << angle << std::endl;
*/
	signal(SIGINT,terminate);
	std::ofstream fout("out.txt");

	//init timer and kinematics
	mTimer timer(TIME_UNIT);
	TelemInterface telem;
	kinematics.set_telem(&telem);
	//set PID parameters
	speed_control.set_params(9, 0.4, 2); //kp, ki, kd
	
	//starts modules
	if(absolute){
		path_control.addAbsRotation(angle);
	//	absolute_rotation.evaluate_absolute_rotation(angle);
	//	absolute_rotation.on();
	}
	if(circular){
		path_control.addCircularRotation(angle,radius);
	//	circular_rotation.set_rotation_target(angle,radius);
	//	circular_rotation.on();
	}
	if(follow){
		path_control.addFollowLine(xT,yT);
	//	follow_line.set_target(xT,yT,xS,yS);
	//	follow_line.on();
	}
	if(gotop){
		path_control.addGoTo_Point(xT,yT);
	//	goto_point.set_target(xT,yT);
	//	goto_point.on();
	}
	if(relative){
		path_control.addRelRotation(angle);
	//	relative_rotation.set_rotation_target(angle);
	//	relative_rotation.on();
	}
	speed_control.set_targets(1,1);
	
	kinematics.on();
	speed_control.on();
	path_control.on();

	//main loop;
	int t_ms = 0, t_sec = 0;
	timer.start();
	while(cycle){
		if(timer.getInterrupt()){
			run_all_tasks();
			t_ms++;
			fout << (t_ms + ONE_SEC*t_sec) << " "  << kinematics.speed_left() 
					<< " " << kinematics.speed_right() 
					<< " " << kinematics.pose().x() 
					<< " " << kinematics.pose().y()
					<< " " << kinematics.pose().theta() * 180/PI
					<< std::endl;
			if(t_ms == ONE_SEC){
				std::cout << "Timestamp: " << telem.get_timestamp() << std::endl
						<< "Left speed: " << kinematics.speed_left() 
						<< ", Right speed: " << kinematics.speed_right()
						<< std:: endl << "Targets:  " 
						<< speed_control.get_target_left() << " " 
						<< speed_control.get_target_right()
						<< std::endl << "Pose: "
						<< kinematics.pose().x() << " "
						<< kinematics.pose().y() << std::endl
						<< "Angle: " << kinematics.pose().theta() * 180/PI
						<< std::endl << std::endl;
				t_ms = 0;
				t_sec++;
			}
			timer.reset();
		}
	}

	//stop modules
	path_control.off();
	absolute_rotation.off();
	circular_rotation.off();
	relative_rotation.off();
	follow_line.off();
	goto_point.off();
	speed_control.off();
	kinematics.off();
	
	//stop timer
	timer.stop();

	return 0;
}

void arg_handler(int argc, char** argv){
	char c;
	while((c = getopt(argc,argv,"a:c:f:g:r:1:2:3:")) != -1 ){
		switch(c){
			case 'a':
				type = ABSOLUTE_ROTATION;
				absolute = true;
				angle = atoi(optarg);
				break;
			case 'c':
				type = CIRCULAR_ROTATION;
				circular = true;
				angle = atoi(optarg);
				break;
			case 'f':
				type = FOLLOW_LINE;
				follow = true;
				xT = atof(optarg);
				break;
			case 'g':
				type = GOTO_POINT;
				gotop = true;
				xT = atof(optarg);
				break;
			case 'r':
				type = RELATIVE_ROTATION;
				relative = true;
				angle = atoi(optarg);
				break;
			case '1':
				if(circular)
					radius = atof(optarg);
				if(follow | gotop)
					yT = atof(optarg);
				break;
			case '2':
				if(follow)
					xS = atof(optarg);
				break;
			case '3':
				if(follow)
					yS = atof(optarg);
				break;
		}
	}
}
