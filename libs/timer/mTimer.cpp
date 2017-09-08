#include "mTimer.h"

mTimer::mTimer(int time){
	go = ti = false;
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
	go = true;
	int t = time;
	pthread_create(&timer_thread,NULL,timer_func,this);
}

void mTimer::stop(){
	go = false;
	pthread_join(timer_thread,NULL);
}

void mTimer::set(){
	ti = true;
}

void mTimer::reset(){
	ti = false;
	init = actual;
}

bool mTimer::getInterrupt(){
	return ti;
}

void * timer_func(void* arg){
	mTimer* timer = (mTimer*)arg;
	timer->set_init(high_resolution_clock::now());
	while(timer->continuing()){
		timer->set_actual(high_resolution_clock::now());
		duration<double>diff = timer->get_actual() - timer->get_init();
		if( 1000 * diff.count() >= timer->getTime()){
            timer->set();
			timer->set_init(timer->get_actual());
		}
	}
	return NULL;
}
