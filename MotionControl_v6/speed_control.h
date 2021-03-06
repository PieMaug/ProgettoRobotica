/*
 * speed_control.h
 */

#ifndef __SPEED_CONTROL_H
#define __SPEED_CONTROL_H

#include <stdbool.h>
#include "pid.h"
#include "periodic_task.h"
#include "kinematics.h"
#include "Motor.h"
//#include "pwm.h"
#define MAX_PWM 100

void set_pwm(int,int);

class SpeedControlTask : public PeriodicTask {
 public:
    SpeedControlTask(Kinematics & kin);
	~SpeedControlTask();
    virtual void run();
    virtual void off(bool stop_pwm = true);
    virtual void set_params(float kp, float ki, float kd);
    virtual void set_targets(float l, float r) { m_target_left = l; m_target_right = r; on(); };
    virtual void set_motors(int l, int r) { m_pwm_left = l; m_pwm_right = r; motor->set_force(l, r); };
    virtual int pwm_left() { return m_pwm_left;};
    virtual int pwm_right() { return m_pwm_right;};
    virtual void get_current_speeds(float & l, float & r) {
        l = m_kinematics.speed_left();
        r = m_kinematics.speed_right();	

    };
	void motor_on() { motor->start();}
	void motor_off() { motor->stop();}
    //aggiunto da Orlando e Ciccotta
    virtual float get_target_left(){return m_target_left;};
    virtual float get_target_right(){return m_target_right;};

 protected:
	Motor* motor;
    Kinematics & m_kinematics;
    int m_pwm_left, m_pwm_right;
    float m_target_left, m_target_right;
    Pid m_left_pid, m_right_pid;
};

#endif
