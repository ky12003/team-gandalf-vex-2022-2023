#include "intake.h"
#include "DrivingFunctions.h"
#include "vex.h"
#include "launcher.h"
#include "robot-config.h"
#include "Pneumatics.h"
#include "Roller.h"
////////////////////////////////////Buttons List
//Fly-Wheel :             X         
//Feeder:                 Y
//Intake forward:         R1
//Intake reverse:         R2
//Expansion:              A
//Roller:                 L1
//Roller reverse:         L2


void ArcadeDrive()
{

 if (controller1.ButtonR1.pressing())
 {
   run_intake();
 } 
 else if (controller1.ButtonR2.pressing())
 {
  run_intake_reverse();
 } 
 else 
 {
   intake.stop();
 }  

 if(abs(controller1.Axis3.value()) > 8 || abs(controller1.Axis1.value()) > 8)
 {
    left_all.spin(forward, (controller1.Axis3.value() + controller1.Axis1.value() ), pct);
    right_all.spin(forward, (controller1.Axis3.value() - controller1.Axis1.value() ), pct);
  } 
  else 
  {
    // left_back.setBrake(brake);
    // left_middle.setBrake(brake);
    // right_back.setBrake(brake);
    // left_front.setBrake(brake);
    // right_front.setBrake(brake);
    // right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
  }
 

}

void TankDrive()
{
 float current = (inertial_sensor.rotation(deg));
  printf("rotation: %f\n",current);

  if(abs(controller1.Axis3.value()) > 5 || abs(controller1.Axis2.value()) > 5) {
    left_all.spin(forward,controller1.Axis3.value(), pct); 
    right_all.spin(forward,controller1.Axis2.value() , pct); 
  } else {
    // left_back.setBrake(brake);
    // left_middle.setBrake(brake);
    // right_back.setBrake(brake);
    // left_front.setBrake(brake); 
    // right_front.setBrake(brake);
    // right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
  }
   if(controller1.ButtonX.pressing())
 {
   fly_wheel_one_reverse();
   fly_wheel_two_reverse();
 }else{
   fly_wheel_one_forward();
   fly_wheel_two_forward();
 }
  ///////////////////////////////////////////////////////////////////////////////
  






  ///////////////////////////////////////////////////////////////////////////////
  


  
  
  if (controller1.ButtonL2.pressing())
  run_roller_reverse();
  else roller.stop();


  // if(controller1.ButtonL1.pressing())
  // run_roller();
  // else if ((controller1.ButtonL2.pressing()))
  // run_roller_reverse();
  // else
  // roller.stop();


  if(controller1.ButtonY.pressing())
  feeder.set(false);
  else if(controller1.ButtonY.pressing()==false)
  feeder.set(true);
  
}

