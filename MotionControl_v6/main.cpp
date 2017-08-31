/*
 * main.cpp
 */

#if 0

//#include <p33FJ128MC802.h>
#include "mTimer.h"
#include "telem_interface.h"
#include "geometry.h"
#include "kinematics.h"
#include "speed_control.h"
//#include "can_interface.h"
//#include "clocking.h"
//#include "qei.h"
//#include "pwm.h"
//#include "timers.h"
//#include "gpio.h"
#include "relative_rotation.h"
#include "absolute_rotation.h"
#include "circ_rotation.h"
#include "path_control.h"
#include "follow_line.h"
#include "goto_point.h"

#include <stdio.h>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>

#if 0
void initialize_peripherals()
{
    init_clock();

    IEC0 = 0;				// DISABLE ALL USER INTERRUPT
    IEC1 = 0;				
    IEC2 = 0;
    IEC3 = 0;	
    IEC4 = 0;	

    RCONbits.SWDTEN   = 0;	// disable Watchdog Timer

    init_gpio();
    init_can_interface();
    init_pwm();
    init_timer2();
    init_qei();


}

void flash_at_boot()
{
    /* led flashing to signal a reboot */
    for (int i = 0;i < 5;i++) {
        __delay_ms(100);
        led_on();
        __delay_ms(100);
        led_off();
    }
}
#endif


Pose current_robot_pose;
Kinematics kinematics(current_robot_pose, 27, 27, 303, 4000); // initial values, wheels diameter, interasse, tick
SpeedControlTask speed_control(kinematics);
//CanCommandReceiver  can_receiver(kinematics, speed_control);
//CanPoseSender  can_pose_sender(current_robot_pose);
//CanSpeedSender  can_speed_sender(speed_control);

RelativeRotation relative_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);   //acc, vel, dec, bho ,tolleranza, 
AbsoluteRotation absolute_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);
CircularRotation circular_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);
FollowLine follow_line(kinematics, speed_control, 600, 600, 600, 20);
GoTo_Point goto_point(kinematics, speed_control, 600, 600, 600, 20);

int main(int argc, char ** argv)
{
	gazebo::client::setup(argc,argv);
	//TelemInterface* telem = new TelemInterface;
	TelemInterface telem;
	ControlInterface* ctl = new ControlInterface;
	//kinematics.set_telem(telem);
	//speed_control.set_ctl(ctl);
    //initialize_peripherals();
    //flash_at_boot();
	mTimer tmr(500); 
    //kinematics.on();
	//speed_control.set_params(1,0,0);
	//speed_control.set_targets(0.5,0.5);
    //speed_control.on();
	//can_pose_sender.on();
    //path_control.on();
	printf("Faccio da prova\n");
    tmr.start();
    for (;;) {

        //can_receiver.run();

        // wait next timer tick
        if (tmr.getInterrupt()) {
			tmr.reset();
			telem.print();
			//run_all_tasks();
			//kinematics.run();
			//speed_control.run();
        }

    }
    return 0;
}

#else

#include "Motor.h"
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

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>

Pose current_robot_pose;
Kinematics kinematics(current_robot_pose, 27, 27, 303, 4000); // initial values, wheels diameter, interasse, tick
SpeedControlTask speed_control(kinematics);
RelativeRotation relative_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);   //acc, vel, dec, bho ,tolleranza, 
AbsoluteRotation absolute_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);
CircularRotation circular_rotation(kinematics, speed_control, 600, 600, 600, 20, 0.5);
FollowLine follow_line(kinematics, speed_control, 600, 600, 600, 20);
GoTo_Point goto_point(kinematics, speed_control, 600, 600, 600, 20);

std::string str;
void cb(ConstEncoderMsgPtr &_msg)
{
  // Dump the message contents to stdout.
  str =  _msg->DebugString();
}

int main(int argc, char** argv){
	mTimer timer(500);
	TelemInterface* telem = new TelemInterface;
	kinematics.set_telem(telem);
	kinematics.on();
	absolute_rotation.on();
	int time = 0;
	timer.start();
	while(time < 20){
		if(timer.getInterrupt()){
			timer.reset();
			run_all_tasks();
			telem->print();
			time++;
		}
	}
	std::cout << "prova" << std::endl;
}

#endif
