// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "GearBackCmd.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

GearBackCmd::GearBackCmd(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveBase.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void GearBackCmd::Initialize() {
	SetTimeout(1.5);
}

// Called repeatedly when this Command is scheduled to run
void GearBackCmd::Execute() {
	Robot::driveBase->BetterDriveMethod(0.10, 0.10);
}

// Make this return true when this Command no longer needs to run execute()
bool GearBackCmd::IsFinished() {
	if (Robot::driveBase->SonarInches() > -3 || IsTimedOut()) //an inch from the flat surface; the extra 4 are from the extruding gear thing where we put the gear to put it to the airship
		return true;
    return false;
}

// Called once after isFinished returns true
void GearBackCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearBackCmd::Interrupted() {

}
