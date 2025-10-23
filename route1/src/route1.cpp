#include "main.h"

//Motor Definition
pros::MotorGroup left_motors({1,3}); //Left motor group
pros::MotorGroup right_motors({-2,-4});  //right motor group(reversed)

//Constant Speed
const int DRIVE_SPEED = 600;
const int TURN_SPEED = 500;
const int DELAY = 150;

//Helper Function to Stop All Motors
void stop_motors(){
    left_motors.move_velocity(0);
    right_motors.move_velocity(0);
}

//Function to Drive Straight(wow!)
void drive_straight(int speed, int duration_ms){
    left_motors.move_velocity(speed);
    right_motors.move_velocity(speed);
    pros::delay(250);
    stop_motors();
}

//Function to Turn(wow!)
void turn(int speed, int duration_ms){
    left_motors.move_velocity(speed); //Positive = Right
    right_motors.move_velocity(-speed); //Negative = Left
    pros::delay(duration_ms);
    stop_motors();
}

//Route itself
void route(){
    drive_straight(DRIVE_SPEED, 1500);
    turn(TURN_SPEED, 175);
    drive_straight(DRIVE_SPEED, 750);
    turn(-TURN_SPEED, 175);
    drive_straight(DRIVE_SPEED, 500);
    turn(-TURN_SPEED, 175);
    drive_straight(DRIVE_SPEED, 750);
    turn(TURN_SPEED, 250);
}

