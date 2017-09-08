#include <time.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <chrono>
#include "SoftTimer.h"
#include "mTimer.h"

using namespace std;



void tapposto(int signum){
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	printf("seconds->%d\n",timeinfo->tm_sec);
	alarm(5);
}


void f(){
	time_t my_time;
	struct tm * timeinfo;	
	time (&my_time);
	timeinfo = localtime (&my_time);
	printf("seconds->%d\n",timeinfo->tm_sec);
}

#if 1
int main(){
	mTimer timer(5000);
	timer.start();
	while(1){
		if(timer.getInterrupt()){
			cout << "Timer\n";
			timer.reset();
		}
	}
}
#endif
