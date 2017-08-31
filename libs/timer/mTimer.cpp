#include "mTimer.h"

using namespace std::chrono;

mTimer::mTimer(int time){
	ti = false;
	setTime(time);
}


void mTimer::setTime(int _time){
	time = _time;
}

int mTimer::getTime(){
	return time;
}

void mTimer::start(){
	ti = false;
	int t = time;
	pthread_create(&timer_thread,NULL,timer_func,this);
}

void mTimer::stop(){
	pthread_kill(timer_thread,9);
}

void mTimer::set(){
	ti = true;
}

void mTimer::reset(){
	ti = false;
}

bool mTimer::getInterrupt(){
	return ti;
}

void * timer_func(void* arg){
	mTimer* timer = (mTimer*)arg;
	time_point<high_resolution_clock> start, actual;
	start = high_resolution_clock::now();
	while(1){
		actual = high_resolution_clock::now();
		duration<double>diff = actual - start;
		if( 1000 * diff.count() >= timer->getTime()){
            timer->set();
			start = actual;
		}
	}
}
