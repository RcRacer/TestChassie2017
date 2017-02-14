// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANSpeedController.h"
#include "SmartDashboard/SmartDashboard.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class ShooterSubsystem: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	double rpm1, rpm2, init1, init2;
	double percentDiff;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> talonController;
	std::shared_ptr<CANTalon> talonController2;
	std::shared_ptr<SpeedController> feederMotor;
	std::shared_ptr<SpeedController> augerMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void TurnOnRPM();
	void TurnOff();
	void PrintValues();
	void TurnOnThrottle();
	void TurnOnFeederMotor();
	void increaseRPM();
	void decreaseRPM();
	void returnOriginalRPM();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif

