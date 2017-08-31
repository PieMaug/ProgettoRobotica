#ifndef __MOTOR
#define __MOTOR

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <signal.h>
#include <gazebo/common/common.hh>
#include "control_interface.h"

class Motor{
	public:
		Motor();
		~Motor();
		void start();
		void stop();
		void set_force(float,float);
	private:
		int id_shm;
		int id_sem;
		int pid;
		struct sembuf WAIT[1] = {{0,-1,0}};
		struct sembuf SIGNAL[1] = {{0,+1,0}};
		float* shm;	
};	

#endif
