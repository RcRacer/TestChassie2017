// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoGearPlacement.h"
#include "AutoTurn.h"
#include "AutoForward.h"
#include "GearVision.h"
#include "AutoSonar.h"
#include "GearRelease.h"
#include "AutoBackOut.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoGearPlacement::AutoGearPlacement(int position): CommandGroup() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
                      // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

	if (position == 1) {
		//RIGHT POS
		AddSequential(new AutoForward(-.3, -6.5));
		AddSequential(new AutoTurn(.4, -25));
		AddSequential(new GearVision());
		//AddSequential(new AutoSonar());
		AddSequential(new GearRelease());
		AddSequential(new AutoBackOut(.2, 1));
		AddSequential(new GearRelease());
	} else if (position == 0) {
		//LEFT POS
		AddSequential(new AutoForward(-.3, -6));
		AddSequential(new AutoTurn(.4, 25));
		AddSequential(new GearVision());
		AddSequential(new GearRelease());
		AddSequential(new AutoBackOut(.2, 1));
		AddSequential(new GearRelease());
	} else if (position == 2) {
		//MID POS
		AddSequential(new AutoForward(-.3, -2));
		AddSequential(new GearVision());
		//AddSequential(new AutoSonar());
		AddSequential(new GearRelease());
		AddSequential(new AutoBackOut(.2, 1));
		AddSequential(new GearRelease());
	}
 }
