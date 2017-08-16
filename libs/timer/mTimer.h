#ifndef MTIMER
#define MTIMER

#include <ctime>
#include <pthread.h>
#include <signal.h>
#include <chrono>

void * timer_func(void*);

class mTimer{
	private:
		int time;
		bool ti;
		pthread_t timer_thread;
	public:
		mTimer(int time);
		int getTime();
		void setTime(int time);
		void start();
		void stop();
		void set();
		void reset();
		bool getInterrupt();  
};


#endif
