// Flight_Computer_Software_State_Diagram.cpp : Defines the entry point for the console application.
// Rob Skebo
// Computer Engineer
// SPAWAR Pacific
// San Diego, California
// 1/26/2014

// Design Pattern: Nested case switch statements

// Aknowledgements:
// Ken Garcia: New Professional Supervisor - mentorship
// Austin Mroczek: Space Systems Branch Head, Computer Engineer - state diagram contributions
// Paul Kaplan: Space Systems Support - computer, monitor, mouse, and keyboard aquisition
// Dmitriy Obukhov: Space Systems Electrical Engineer - state diagram contributions
// Lance Kalleberg: Aerospace Engineer - state diagram contributions
// Arne Odland: Computer Scientist - interface development environment advice
// Eric Jensen: computer system administration
// Mei-Yen Chang: computer system administration
// Stackoverflow: http://stackoverflow.com/questions/3060946/implementing-a-state-machine-in-c-how

// Known Bugs:
// 1. if the user enters a character instead of a boolean, then the program goes into an infinite loop

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

int _tmain(int argc, _TCHAR* argv[])
{
// Type Definition Enumeration for FALSE = 0 and TRUE = 1
	typedef enum 
	{ 
		FALSE = 0, 
		TRUE = 1 
	} Boolean;

	// Type Definition Enumeration of Modes (i.e. circles on the state diagram)
	typedef enum
	{
		Off_0 = 0,
		WakeUp_1 = 1,
		Safe_2 = 2,
		Deploy_3 = 3,
		BuiltInTest_4 = 4,
		Normal_5 = 5,
		SavePower_6 = 6,
		ManualGroundCommand_7 = 7
	} EnumState;

	// Define and initialize the Boolean transitions (i.e. arrows on state diagram)
	Boolean DeploymentTrigger = FALSE;
	Boolean NoLight = FALSE;
	Boolean SenseLight = FALSE;
	Boolean AntennaNotDeployed = FALSE;
	Boolean RepeatedFailure = FALSE;
	Boolean NoMission = FALSE;
	Boolean AntennaDeployed = FALSE;
	Boolean BITTestNotDone = FALSE;
	Boolean BITTestBad = FALSE;
	Boolean BITTestGood = FALSE;
	Boolean WatchdogAlarm = FALSE;
	Boolean DoMission = FALSE;
	Boolean Timer = FALSE;
	Boolean UploadCommand = FALSE;

	//  Initial computer monitor output to user
		printf("Flight Computer State Diagram");
		printf("\n");
		printf("\n");
		printf("Flight Computer is in the 'Initial State'");
		printf("\n");
		printf("\n");

	EnumState state = Off_0;

	// Always run this while loop
	while(1)
	{
		switch( state )
		{
			//////////////
			// OFF MODE	//
			//////////////
			case Off_0 :
				printf("------------------");
				printf("\n");
				printf("We are in Off mode");
				printf("\n");
				printf("------------------");
				printf("\n");
				printf("\n");
				// Get DepoymentTrigger transition input
				printf("Is DeploymentTrigger transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &DeploymentTrigger); // scan file secure
				printf("DeploymentTrigger is: %i", DeploymentTrigger);
				printf("\n");

				// Error check if transition is Boolean value
				if((DeploymentTrigger != 0) && (DeploymentTrigger != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}
				printf("\n");

// REMOVE STARTING HERE				

				//if((DeploymentTrigger != 0) && (DeploymentTrigger != 1))
				//if(1)
				//int i;
				//if(sscanf(str, "%d", &i) != 0) //It's an int.
				//int i;
				//if(sscanf(DeploymentTrigger, "%i", &i) != 0) //It's an int.)
				//int index1;
				//atoi(DeploymentTrigger[index1]);
				//isbool(DeploymentTrigger);

// REMOVE STOPPING HERE

				// Transition decision logic
				if(DeploymentTrigger == FALSE)
					state = Off_0;
				
				else if(DeploymentTrigger == TRUE)
    				state = WakeUp_1;

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;
				
			/////////////////
			// WAKEUP MODE //	
			/////////////////
			case WakeUp_1 :
				printf("---------------------");
				printf("\n");
				printf("We are in WakeUp mode");
				printf("\n");
				printf("---------------------");
				printf("\n");
				printf("\n");
				// Get NoLight transition input
				printf("Is NoLight transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &NoLight); // scan file secure
				printf("NoLight is: %i", NoLight);
				printf("\n");

				// Error check if transition is Boolean value
				if((NoLight != 0) && (NoLight != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}
				printf("\n");
				printf("\n");
				// Get SenseLight transition input
				printf("Is SenseLight transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &SenseLight); // scan file secure
				printf("SenseLight is: %i", SenseLight);
				printf("\n");

				// Error check if transition is Boolean value
				if((SenseLight != 0) && (SenseLight != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}
				printf("\n");


				// Transition decision logic
				if((NoLight == FALSE) && (SenseLight == FALSE))
					state = WakeUp_1;
				
				else if((NoLight == TRUE) && (SenseLight == FALSE))
    				state = Off_0;

				else if((NoLight == FALSE) && (SenseLight == TRUE))
					state = Safe_2;

				else if((NoLight == TRUE) && (SenseLight == TRUE))
				{
					printf("*** Error: Only one transition may be TRUE for WakeUp mode");
					printf("\n");
					printf("\n");
					state = WakeUp_1;
				}
				
				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			/////////////////
			// SAFE MODE   //	
			/////////////////
			case Safe_2 :
				printf("-------------------");
				printf("\n");
				printf("We are in Safe mode");
				printf("\n");
				printf("-------------------");
				printf("\n");
				printf("\n");
				// Get AntennaNotDeployed transition input
				printf("Is AntennaNotDeployed transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &AntennaNotDeployed); // scan file secure
				printf("AntennaNotDeployed is: %i", AntennaNotDeployed);
				printf("\n");

				// Error check if transition is Boolean value
				if((AntennaNotDeployed != 0) && (AntennaNotDeployed != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");
				// Get RepeatedFailure transition input
				printf("Is RepeatedFailure transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &RepeatedFailure); // scan file secure
				printf("RepeatedFailure is: %i", RepeatedFailure);
				printf("\n");

				// Error check if transition is Boolean value
				if((RepeatedFailure != 0) && (RepeatedFailure != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");
				// Get NoMission transition input
				printf("Is NoMission transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &NoMission); // scan file secure
				printf("NoMission is: %i", NoMission);
				printf("\n");

				// Error check if transition is Boolean value
				if((NoMission != 0) && (NoMission != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");
				// Get BITTestNotDone transition input
				printf("Is BitTestNotDone transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &BITTestNotDone); // scan file secure
				printf("BITTestNotDone is: %i", BITTestNotDone);
				printf("\n");

				// Error check if transition is Boolean value
				if((BITTestNotDone != 0) && (BITTestNotDone != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Transition decision logic
				if((AntennaNotDeployed == FALSE) && (RepeatedFailure == FALSE) && (NoMission == FALSE) && (BITTestNotDone == FALSE))
					state = Safe_2;
				
				else if((AntennaNotDeployed == TRUE) && (RepeatedFailure == FALSE) && (NoMission == FALSE) && (BITTestNotDone == FALSE))
    				state = Deploy_3;

				else if((AntennaNotDeployed == FALSE) && (RepeatedFailure == TRUE) && (NoMission == FALSE) && (BITTestNotDone == FALSE))
					state = ManualGroundCommand_7;

				else if((AntennaNotDeployed == FALSE) && (RepeatedFailure == FALSE) && (NoMission == TRUE) && (BITTestNotDone == FALSE))
					state = SavePower_6;
				
				else if((AntennaNotDeployed == FALSE) && (RepeatedFailure == FALSE) && (NoMission == FALSE) && (BITTestNotDone == TRUE))
					state = BuiltInTest_4;

				else
				{
					printf("*** Error: Only one transition may be TRUE for Safe mode");
					printf("\n");
					printf("\n");
				}

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			/////////////////
			// DEPLOY MODE //	
			/////////////////
			case Deploy_3 :
				printf("---------------------");
				printf("\n");
				printf("We are in Deploy mode");
				printf("\n");
				printf("---------------------");
				printf("\n");
				printf("\n");
				// Get AntennaDeployed transition input
				printf("Is AntennaDeployed transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &AntennaDeployed); // scan file secure
				printf("AntennaDeployed is: %i", AntennaDeployed);
				printf("\n");

				// Error check if transition is Boolean value
				if((AntennaDeployed != 0) && (AntennaDeployed != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Transition decision logic
				if(AntennaDeployed == FALSE)
					state = Deploy_3;
				
				else if(AntennaDeployed == TRUE)
    				state = Safe_2;

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			////////////////////////
			// BUILT IN TEST MODE //	
			////////////////////////			
			case BuiltInTest_4 :
				printf("--------------------------");
				printf("\n");
				printf("We are in BuiltInTest mode");
				printf("\n");
				printf("--------------------------");
				printf("\n");
				printf("\n");
				// Get BITTestBad transition input
				printf("Is BITTestBad transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &BITTestBad); // scan file secure
				printf("BITTestBad is: %i", BITTestBad);
				printf("\n");

				// Error check if transition is Boolean value
				if((BITTestBad != 0) && (BITTestBad != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");
				// Get BITTestGood transition input
				printf("Is BITTestGood transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n"); 
				scanf_s("%i", &BITTestGood); // scan file secure
				printf("BITTestGood is: %i", BITTestGood);
				printf("\n");

				// Error check if transition is Boolean value
				if((BITTestGood != 0) && (BITTestGood != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Transition decision logic
				if((BITTestBad == FALSE) && (BITTestGood == FALSE))
					state = BuiltInTest_4;
				
				else if((BITTestBad == TRUE) && (BITTestGood == FALSE))
    				state = Safe_2;

				else if((BITTestBad == FALSE) && (BITTestGood == TRUE))
    				state = Normal_5;

				else if((BITTestBad == TRUE) && (BITTestGood == TRUE))
				{
					state = BuiltInTest_4;
					printf("*** Error: Only one transition may be TRUE for BuiltInTest mode");
					printf("\n");
					printf("\n");
				}

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			/////////////////
			// NORMAL MODE //	
			/////////////////
			case Normal_5 :
				printf("---------------------");
				printf("\n");
				printf("We are in Normal mode");
				printf("\n");
				printf("---------------------");
				printf("\n");
				printf("\n");
				// Get NoMission transition input
				printf("Is NoMission transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &NoMission); // scan file secure
				printf("NoMission is: %i", NoMission);
				printf("\n");

				// Error check if transition is Boolean value
				if((NoMission != 0) && (NoMission != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Get WatchdogAlarm transition input
				printf("Is WatchdogAlarm transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &WatchdogAlarm); // scan file secure
				printf("WatchdogAlarm is: %i", WatchdogAlarm);
				printf("\n");

				// Error check if transition is Boolean value
				if((WatchdogAlarm != 0) && (WatchdogAlarm != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Transition decision logic
				if((NoMission == FALSE) && (WatchdogAlarm == FALSE))
					state = Normal_5;
				
				else if((NoMission == TRUE) && (WatchdogAlarm == FALSE))
    				state = SavePower_6;

				else if((NoMission == FALSE) && (WatchdogAlarm == TRUE))
    				state = Off_0;

				else if((NoMission == TRUE) && (WatchdogAlarm == TRUE))
				{
					state = Normal_5;
					printf("*** Error: Only one transition may be TRUE for Normal mode");
					printf("\n");
					printf("\n");
				}

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			/////////////////////
			// SAVE POWER MODE //	
			/////////////////////
//			case SavePower_6 :
//				printf("We are in SavePower mode");
//				printf("\n");
//				break;
			case SavePower_6 :
				printf("------------------------");
				printf("\n");
				printf("We are in SavePower mode");
				printf("\n");
				printf("------------------------");
				printf("\n");
				printf("\n");
				// Get DoMission transition input
				printf("Is DoMission transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &DoMission); // scan file secure
				printf("DoMission is: %i", DoMission);
				printf("\n");

				// Error check if transition is Boolean value
				if((DoMission != 0) && (DoMission != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");
				// Get Timer transition input
				printf("Is Timer transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n"); 
				scanf_s("%i", &Timer); // scan file secure
				printf("Timer is: %i", Timer);
				printf("\n");

				// Error check if transition is Boolean value
				if((Timer != 0) && (Timer != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}

				printf("\n");

				// Transition decision logic
				if((DoMission == FALSE) && (Timer == FALSE))
					state = SavePower_6;
				
				else if((DoMission == TRUE) && (Timer == FALSE))
    				state = Normal_5;

				else if((DoMission == FALSE) && (Timer == TRUE))
    				state = Safe_2;

				else if((DoMission == TRUE) && (Timer == TRUE))
				{
					state = SavePower_6;
					printf("*** Error: Only one transition may be TRUE for SavePower mode");
					printf("\n");
					printf("\n");
				}

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			////////////////////////////////
			// MANUAL GROUND COMMAND MODE //	
			////////////////////////////////
//			case ManualGroundCommand_7 :
//				printf("We are in ManualGroundCommand mode");
//				printf("\n");
//				break;

			case ManualGroundCommand_7 :
				printf("----------------------------------");
				printf("\n");
				printf("We are in ManualGroundCommand mode");
				printf("\n");
				printf("----------------------------------");
				printf("\n");
				printf("\n");
				// Get UploadCommand transition input
				printf("Is UploadCommand transition TRUE?");
				printf("\n");
				printf("Enter 1 for TRUE");
				printf("\n");
				printf("Enter 0 for FALSE");
				printf("\n");
				scanf_s("%i", &UploadCommand); // scan file secure
				printf("UploadCommand is: %i", UploadCommand);
				printf("\n");

				// Error check if transition is Boolean value
				if((UploadCommand != 0) && (UploadCommand != 1))
				{
					printf("\n");
					printf("***Error: Enter a Boolean value i.e. 0 or 1");
					printf("\n");
				}
				printf("\n");

				// Transition decision logic
				if(UploadCommand == FALSE)
					state = ManualGroundCommand_7;
				
				else if(UploadCommand == TRUE)
    				state = Safe_2;

				// Switch state to the same mode or a different mode
				switch( state) // Warning no 'case' or 'default' label - this is OK

				printf("\n");
				break;

			default:
				printf("Invalid mode. Please restart the program.");
				printf("\n");
				break;
		// End of case switch statement
		}
	
	// End of while loop
	}

	return 0;
// End of Main() function
}
