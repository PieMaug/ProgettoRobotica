#include "Motor.h"
#include <iostream>

Motor::Motor(){
	if((id_sem = semget(IPC_PRIVATE, 1, IPC_CREAT|IPC_EXCL|0600)) == -1){
		perror("Semget");
		exit(1);
	}
	if((id_shm = shmget(IPC_PRIVATE, 2*sizeof(float), IPC_CREAT|IPC_EXCL|0600)) == -1){
		perror("Shmget");
		exit(1);
	}
}

Motor::~Motor(){
	semctl(id_sem,0,IPC_RMID,NULL);
	shmctl(id_shm,IPC_RMID,NULL);
}

void Motor::start(){
	if((pid = fork()) == 0){
		std::cout << "Il figlio parte" << std::endl;
		ControlInterface* ctl = new ControlInterface;
		std::cout << "ControlInterface" << std::endl;
		float* force;
		if((force = (float *)shmat(id_shm,NULL,SHM_RDONLY)) == (float* )-1){
			perror("shmat figlio");
			exit(1);
		}
		std::cout << "Il figlio entra nel ciclo" << std::endl;
		int i = 0;
		while(1){
			semop(id_sem, WAIT, 1);
			ctl->set_joints_torques(0.01*force[0],0.01*force[1]);	
		}
	}else{
		if( (shm = (float*)shmat(id_shm,NULL,0)) == (float*)-1){
			perror("shmat padre");
			exit(1);
		} 
	}
}


void Motor::set_force(float left, float right){
	shm[0] = left;
	shm[1] = right;
	semop(id_sem,SIGNAL,1);
}

void Motor::stop(){
	kill(pid,9);
}
