// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "GearVision.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

GearVision::GearVision(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void GearVision::Initialize() {
	SetTimeout(7);
	Robot::targeting = true;
	Robot::intrpt = false;
}

// Called repeatedly when this Command is scheduled to run
void GearVision::Execute() {
	Robot::driveBase->VisionDriveStatic();
	//printf("accel=%f\n",Robot::driveBase->GetMomentum());
}

// Make this return true when this Command no longer needs to run execute()
bool GearVision::IsFinished() {
    if (IsTimedOut() || (Robot::driveBase->SonarInches()<4 && abs(Robot::driveBase->GetMomentum())<=0.00005) || Robot::intrpt) {
    	return true;
   } else {
	   return false;
   }
}

// Called once after isFinished returns true
void GearVision::End() {
	Robot::driveBase->BetterDriveMethod(0,0);
	Robot::targeting = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearVision::Interrupted() {
	Robot::driveBase->BetterDriveMethod(0,0);
	Robot::targeting = false;
	Robot::intrpt = true;
}
