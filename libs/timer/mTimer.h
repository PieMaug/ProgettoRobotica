#ifndef MTIMER
#define MTIMER

#include <ctime>
#include <pthread.h>
#include <signal.h>
#include <chrono>

using namespace std::chrono;

void * timer_func(void*);

class mTimer{
	private:
		int time;
		bool ti, go;
		pthread_t timer_thread;
		time_point<high_resolution_clock> init, actual;
	public:
		mTimer(int time);
		int getTime();
		void setTime(int time);
		void start();
		void stop();
		void set();
		void reset();
		bool getInterrupt();
		bool continuing() {return go;}  
		time_point<high_resolution_clock> get_init() {return init;};
		time_point<high_resolution_clock> get_actual() {return actual;};
		void set_init(time_point<high_resolution_clock> t) { init = t;};
		void set_actual(time_point<high_resolution_clock> t) { actual = t;};

};


#endif
