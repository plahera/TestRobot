#include "MoveServos.h"


#define hi


MoveServos::MoveServos():Command()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

}

// Called just before this Command runs the first time
void MoveServos::Initialize()
{
	joy = Robot::oi->getDriveJoy();
}

// Called repeatedly when this Command is scheduled to run
void MoveServos::Execute()
{
#ifdef hi
	if (joy->GetPOV()==270||joy->GetPOV()==90) { // goes middle
	Robot::intakeSubsystem->MoveServoLeft(140);
	Robot::intakeSubsystem->MoveServoRight(50);
	//Wait(.5);
	//should open it
	}
	else if (joy->GetPOV()==180) // goes out. ie to shoot
	{
		Robot::intakeSubsystem->MoveServoLeft(180);
		Robot::intakeSubsystem->MoveServoRight(0);
	//	Wait(.5);
		//should close it, first action
	}
	else if (joy->GetPOV()==0) //currently goes up
	{
		Robot::intakeSubsystem->MoveServoLeft(00);
		Robot::intakeSubsystem->MoveServoRight(180);
		//should go to middle
		//Wait(.5);
	}
	SmartDashboard::PutNumber("Thingy", joy->GetPOV());
#endif

//	Robot::intakeSubsystem->MoveServos(30);
	//225-315 left
	//315-45 top
	//right: 45  -135
	//bottom: 135-225
}

// Make this return true when this Command no longer needs to run execute()
bool MoveServos::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveServos::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveServos::Interrupted()
{

}
