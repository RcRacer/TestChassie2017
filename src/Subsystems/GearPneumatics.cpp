// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "GearPneumatics.h"
#include "../RobotMap.h"
#include "../Commands/GearRelease.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

GearPneumatics::GearPneumatics() : Subsystem("GearPneumatics") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    gearSolen = RobotMap::gearPneumaticsGearSolen;
    compressor = RobotMap::gearPneumaticsCompressor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    distance= Robot::driveBase->SonarInches();//distance=SonarInches
}

void GearPneumatics::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}




// Put methods for controlling this subsystem
// here. Call these from Commands.

void GearPneumatics::Release(){
	bool gearSole=gearSolen->Get();
	//if less than 8 inches set the bool to opposite of the solenoid's current position
	if((Robot::driveBase->SonarInches()<10.) | gearSolen->Get() | Robot::oi->getLeftJoystick()->GetRawButton(10)){
		gearSolen->Set(!gearSole);
	}

}

void GearPneumatics::EmergGearMethod() {
	gearSolen->Set(!(gearSolen->Get()));
}

void GearPneumatics::SetSolen(bool whatever){
	gearSolen->Set(whatever);
}
