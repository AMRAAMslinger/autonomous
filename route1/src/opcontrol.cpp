#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER)
pros::MotorGroup left_motors({1,3}); //Left motor group
pros::MotorGroup right_motors({-2,-4});  //right motor group(reversed)

void opcontrol(){
    while(true){

        //Gets Value of Joysticks
        int foward = controller.get_analog(ANALOG_LEFT_X);
        int turn = controller.get_analong(ANALOG_LEFT_Y);

        int left_power = forward + turn;
        int right_power = forward - turn;

        left_motors.move(left_power);
        right_motors.move(right_power);

        pros::delay(15);
    }
}
