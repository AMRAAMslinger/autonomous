#include "main.h"
#include "pros/misc.h"
#include "route_cp.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({1,3});
pros::MotorGroup right_motors ({-2,-4});


void move_forward(int speed, int duration_ms){
    left_motors.move_velocity(100);
    right_motors.move_velocity(100);
    pros::delay(distance_ms);

    left_motors.move_velocity(0);
    right_motor.move_velocity(0);
    pros::delay(100);
}

void opcontrol(){
    while(true){
        if (controller.get_digital(DIGITAL_A)){
            move_forward(250,1500);
            pros::delay(200);
        }
    }
}