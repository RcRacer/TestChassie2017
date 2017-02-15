// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVEBASE_H
#define DRIVEBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <ADXRS450_Gyro.h>
#include "CANTalon.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveBase: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> left1;
	std::shared_ptr<CANTalon> left2;
	std::shared_ptr<CANTalon> right1;
	std::shared_ptr<CANTalon> right2;
	std::shared_ptr<RobotDrive> robotDrive41;
	std::shared_ptr<Ultrasonic> sonar;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Gyro *g;
	Accelerometer *accel;
	std::shared_ptr<Solenoid> TargetLight;
	std::shared_ptr<Solenoid> WarningLight;
public:
	DriveBase();
	void InitDefaultCommand();
	double getGAngle();
	void ResetGyro();
	void SetExp();
	void DriveWithJoysticks();
	void DriveWithGamepad();
	void ResetEncoders();
	bool CompareEncoders(double distance);
	double getLeftEncPos();
	double getRightEncPos();
	void driveMethod(float left, float right);
	void straightAutonMethod(double speed, double method);
	void setCoastBreak(bool type);
	bool CenterRobot(int t, bool move);
	void VisionDrive();
	void setSonar();
	double SonarInches();
	void BetterDriveMethod(double left, double right);
	double GetMomentum();
	void TargetIndicator(bool light);
	void WarningIndicator(bool light);
	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
