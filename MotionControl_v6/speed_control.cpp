/*
 * speed_control.cpp
 */

#include "speed_control.h"
#include "time_defines.h"

void set_pwm(int,int){
    return;
}


SpeedControlTask::SpeedControlTask(Kinematics & kin)
    : PeriodicTask("speed_control", SPEED_PERIOD, TIME_UNIT, SPEED_JITTER),
      m_kinematics(kin),
      m_pwm_left(0),
      m_pwm_right(0),
      m_target_left(0),
      m_target_right(0)
{
	motor = new Motor;
	motor->start();
    m_left_pid.init(0.0, 0.0, 0.0, 0.0, m_real_time_period, MAX_PWM);
    m_right_pid.init(0.0, 0.0, 0.0, 0.0, m_real_time_period, MAX_PWM);
}

SpeedControlTask::~SpeedControlTask(){
	delete motor;
}


void SpeedControlTask::set_params(float kp, float ki, float kd)
{
    m_left_pid.set_params(kp, ki, kd, 0.0);
    m_right_pid.set_params(kp, ki, kd, 0.0);
}

void SpeedControlTask::off(bool stop_pwm)
{
    PeriodicTask::off();
    m_left_pid.reset();
    m_right_pid.reset();
	motor->stop();
    if (stop_pwm) {
        m_pwm_left = 0;
        m_pwm_right = 0;
        set_pwm(0, 0);
    }
}

#include <fstream>

std::ofstream foutt("pid.txt");

void SpeedControlTask::run()
{
    m_pwm_left = m_left_pid.evaluate(m_target_left, m_kinematics.speed_left());
    m_pwm_right = m_right_pid.evaluate(m_target_right, m_kinematics.speed_right());
#if 0
    set_pwm(m_pwm_left, m_pwm_right);
#else
	foutt << m_pwm_left << " " << m_pwm_right << std::endl;
	motor->set_force(m_pwm_left,m_pwm_right);
#endif
}


