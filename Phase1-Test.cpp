#include "GUI\Input.h"
#include "GUI\Output.h"
//This is a test code to test the Input and Output classes

int main()
{

	Point P;
	Point P2;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(P);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states

	pOut->PrintMessage("Drawing Simple Assignment statements, Click to continue");

	//Drawing empty assignment statement
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, " = ");

	//Drawing edited (non-empty) assignment statement
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing highlighted assignment statement
	P.x = 100;	P.y = 400;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements, Click to continue");

	//TODO: Add code to draw other types of assignment statements here

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement, Click to continue");

	//TODO: Add code to draw different Conditional statements here
	pIn->GetPointClicked(P);
	pOut->DrawConditionalStat(P, UI.Statement_Width, UI.Statement_HI, pIn->GetString(pOut));

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement, Click to continue");
	pIn->GetPointClicked(P);  //Omar
	pOut->DrawInputOutput(P, UI.Parallelogram_Width, UI.Parallelogram_HI, pIn->GetString(pOut));    //Omar


	//TODO: Add code to draw different Read statements here

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement, Click to continue");
	pIn->GetPointClicked(P);  //Omar
	pOut->DrawInputOutput(P, UI.Parallelogram_Width, UI.Parallelogram_HI, pIn->GetString(pOut));    //Omar

	//TODO: Add code to draw different Write statements here

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements, Click to continue");
	pIn->GetPointClicked(P);
	pOut->DrawStartEnd(P, UI.Start_Radius, "Start");
	pIn->GetPointClicked(P);
	pOut->DrawStartEnd(P, UI.Start_Radius, "End");

	//TODO: Add code to draw different Start & End statements here

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector, Click to continue");
	pIn->GetPointClicked(P);  //Omar
	pOut->PrintMessage("Click on the start point of the connector");
	pIn->GetPointClicked(P);
	pOut->PrintMessage("Click on the end point of the connector");
	pIn->GetPointClicked(P2);  //Omar
	pOut->DrawConnector(P, P2, UI.Connector_Width);

	//TODO: Add code to draw different Connectors here

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings and values");

	//TODO: Add code here to 
	// 1- Read a string from the user and print it

	// 2- Read a double value from the user and print it

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	//TODO:  You must add a case for each action
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_START_STAT:
			pIn->GetPointClicked(P);
			pOut->DrawStartEnd(P, UI.Start_Radius, "Start");
			pOut->PrintMessage("Action: add start statement , Click anywhere");
			break;

		case ADD_SMPL_ASSIGN:
			pIn->GetPointClicked(P);
			pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, pIn->GetString(pOut));
			pOut->PrintMessage("Action: add assignment statement , Click anywhere");
			break;

		case ADD_VAR_ASSIGN:
			pIn->GetPointClicked(P);
			pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, pIn->GetString(pOut));
			pOut->PrintMessage("Action: add variable assignment statmen, Click anywhere");
			break;

		case ADD_SO_ASSIGN:
			pIn->GetPointClicked(P);
			pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, pIn->GetString(pOut));
			pOut->PrintMessage("Action: add single operator assignment, Click anywhere");
			break;

		case ADD_CONDITION:
			pIn->GetPointClicked(P);
			pOut->DrawConditionalStat(P, UI.Statement_Width, UI.Statement_HI, pIn->GetString(pOut));
			pOut->PrintMessage("Action: add conditional statement , Click anywhere");
			break;

		case ADD_CONNECTOR:
			pIn->GetPointClicked(P);  //Omar
			pIn->GetPointClicked(P2);  //Omar
			pOut->DrawConnector(P, P2, UI.Connector_Width);
			pOut->PrintMessage("Action: add a connector , Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: Select items, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Delete Items");
			pOut->ClearDrawArea();
			break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;

		case DSN_MODE:
			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;


		case EXIT:
			break;
		}
	} while (ActType != EXIT);

	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(P);




	delete pIn;
	delete pOut;
	return 0;
}