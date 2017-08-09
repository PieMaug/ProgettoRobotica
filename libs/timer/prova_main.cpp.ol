#include <time.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <chrono>
#include "SoftTimer.h"


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

#if 0
int main(){
#if 0
	signal(SIGALRM,tapposto);
	alarm(5);
#else
	SoftTimer* timer = SoftTimer::get_timer(3,f);
 	timer->start();
	//cout << timer->get_time() << endl;
	//(timer->get_func())();
#endif
	while(1){
		cout << "faccio cose" << endl;
		sleep(1);
	}
	return 0;
}
#endif
