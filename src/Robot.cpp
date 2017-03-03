// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveBase> Robot::driveBase;
std::shared_ptr<GearPneumatics> Robot::gearPneumatics;
std::shared_ptr<IntakeMot> Robot::intakeMot;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
bool Robot::teleop = false;
bool Robot::centered = false;
bool Robot::targeting = false;
bool Robot::autoBack = false;
bool Robot::intrpt = false;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveBase.reset(new DriveBase());
    gearPneumatics.reset(new GearPneumatics());
    intakeMot.reset(new IntakeMot());
    shooterSubsystem.reset(new ShooterSubsystem());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();

	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
		SmartDashboard::PutString("DB/String 7", "BLUE");

}
	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed){
		SmartDashboard::PutString("DB/String 7", "RED");

}

	if (SmartDashboard::GetBoolean("DB/Button 0", false)) {
		SmartDashboard::PutBoolean("DB/Button 1", false);
		SmartDashboard::PutBoolean("DB/Button 2", false);
		SmartDashboard::PutString("DB/String 0", "Left Pos Gear Auto");
	} else if (SmartDashboard::GetBoolean("DB/Button 1", false)) {
		SmartDashboard::PutBoolean("DB/Button 0", false);
		SmartDashboard::PutBoolean("DB/Button 2", false);
		SmartDashboard::PutString("DB/String 0", "Right Pos Gear Auto");
	} else if (SmartDashboard::GetBoolean("DB/Button 2", false)) {
		SmartDashboard::PutBoolean("DB/Button 0", false);
		SmartDashboard::PutBoolean("DB/Button 1", false);
		SmartDashboard::PutString("DB/String 0", "Mid Pos Gear Auto");
	} else {
		SmartDashboard::PutString("DB/String 0", "Doing Nadda");
	}
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	//SmartDashboard::PutString("DB/String 0", "Left Enc: " + std::to_string(Robot::driveBase->getLeftEncPos()));
	SmartDashboard::PutString("DB/String 1", "Right Enc: " + std::to_string(Robot::driveBase->getRightEncPos()));
	SmartDashboard::PutString("DB/String 2", "Gyro: " + std::to_string(Robot::driveBase->getGAngle()));
	SmartDashboard::PutString("DB/String 3", "Sonar: " + std::to_string(Robot::driveBase->SonarInches()));
	SmartDashboard::PutString("DB/String 5", "Accel:" + std::to_string(Robot::driveBase->GetMomentum()));
	SmartDashboard::PutString("DB/String 6", "ShooterS: " + std::to_string(Robot::driveBase->ShootInches()));
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();



	Robot::teleop = true;
	Robot::driveBase->ResetEncoders();
	Robot::driveBase->ResetGyro();
	Robot::intrpt = true;
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutString("DB/String 0", "Left Enc: " + std::to_string(Robot::driveBase->getLeftEncPos()));
	SmartDashboard::PutString("DB/String 1", "Right Enc: " + std::to_string(Robot::driveBase->getRightEncPos()));
	SmartDashboard::PutString("DB/String 2", "Gyro: " + std::to_string(Robot::driveBase->getGAngle()));
	SmartDashboard::PutString("DB/String 3", "Sonar: " + std::to_string(Robot::driveBase->SonarInches()));
	SmartDashboard::PutString("DB/String 5", "Accel:" + std::to_string(Robot::driveBase->GetMomentum()));
	SmartDashboard::PutString("DB/String 6", "ShooterS: " + std::to_string(Robot::driveBase->ShootInches()));
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

