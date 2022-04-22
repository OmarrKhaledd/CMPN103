#include "Output.h"
#include <string.h>

Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1440;        //Window default width changed from 900 to 1440     *Omar
	UI.height = 700;        
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 60;       //Changed width from 50 to 60, bal3ab         *Omar
	UI.TlBrWdth = 50;      //Changed width from 50 to 160, msh bal3ab -> due to icon bar image height = 160, Hn7tagha lw 3amalna icons 3la 2 lines    *Omar
	UI.MnItWdth = 80;

	UI.DrawClr = BLUE;
	UI.HiClr = YELLOW;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;
	UI.Statement_Width = 100;  //Omar
	UI.Statement_HI = 50;      //Omar
	UI.Connector_Width = 5;    //Arrow width   *Omar
	UI.Connector_HI = 10;      //Arrow height  *Omar
	UI.Start_Radius = UI.End_Radius = 50;     //Start and End radius       *Omar
	UI.Parallelogram_Width = 100;  //Input and Output read shape width     *Omar
	UI. Parallelogram_HI = 50;     //Input and Output read shape height    *Omar

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////

//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i=0;	

	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	//Adding icons for each statement needed (Ali).
	//pWind->DrawImage("images\\DesignMenu.jpg", 0, 0);

	pWind->DrawImage("images\\Variable=#.jpg", first, 0);
	pWind->DrawImage("images\\Variable.jpg", second, 0);
	pWind->DrawImage("images\\Variable =.jpg", third, 0);
	pWind->DrawImage("images\\Condition.jpg", fourth, 0);
	pWind->DrawImage("images\\Arrow.jpg", fifth, 0);
	pWind->DrawImage("images\\Copy.jpg", sixth, 0);
	pWind->DrawImage("images\\Cut.jpg", seventh, 0);
	pWind->DrawImage("images\\Paste.jpg", eighth, 0);
	pWind->DrawImage("images\\Delete.jpg", ninth, 0);
	pWind->DrawImage("images\\Save.jpg", tenth, 0);
	pWind->DrawImage("images\\Load 1.jpg", eleventh, 0);
	pWind->DrawImage("images\\Exit.jpg", twelvth, 0);
	pWind->DrawImage("images\\Move.jpg", thirteenth, 0);
	pWind->DrawImage("images\\select.jpg", fourteenth, 0);
	pWind->DrawImage("images\\Simulation.jpg", fifteenth, 0);
	pWind->DrawImage("images\\Edit.jpg",sixteenth, 0);
	pWind->DrawImage("images\\Undo.jpg", seventeenth, 0);
	pWind->DrawImage("images\\Redo.jpg", eighteenth, 0);


	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);

	//pWind->DrawLine(320, 0, 320, 50);         //Vertical red lines to seperate between icons     *Omar
	for (int i = 320; i < 1440; i = i + 80)
	{
		pWind->DrawLine(i, 0, i, UI.TlBrWdth);
	}
}

void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	pWind->DrawImage("images\\Validation.jpg", first, 60);
	pWind->DrawImage("images\\Debug.jpg", second, 60);
	pWind->DrawImage("images\\Switch Back.jpg", third, 60);
	pWind->DrawImage("images\\Generate a File.jpg", fourth, 60);
	pWind->DrawImage("images\\Simulate.jpg",fifth, 60);
	
	

	
	int i = 0;

	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);

	for (int i = 400; i < 1440; i = i + 80)
	{
		pWind->DrawLine(i, 0, i, UI.TlBrWdth);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{

	int s = Text.size() * 20;      //Where s is the size of the input text

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - s / 4, Left.y - 10, Text);

	if (s > width)
	{
		width = s;
	}

	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x - width/2, Left.y - height/2, Left.x + width/2, Left.y + height/2, FRAME);
	
}

void Output::DrawStartEnd(Point Left, int Radius, string text, bool selected)   //Function declaration     *Omar
{
	if(selected)
		pWind->SetPen(UI.HiClr, 3);	
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawCircle(Left.x, Left.y, Radius);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - 20, Left.y - 10, text);
}

void Output::DrawConditionalStat(Point Left, int width, int height, string text, bool selected)      //If statement Rhombus shape   *Omar
{

	int s = text.size() * 20;      //Where s is the size of the input text

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - s / 4, Left.y - 10, text);

	if (s > width)
	{
		width = s;
		height = width / 2;
	}


	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawLine(Left.x - width/2, Left.y, Left.x, Left.y + height/2);
	pWind->DrawLine(Left.x - width/2, Left.y, Left.x, Left.y - height/2);
	pWind->DrawLine(Left.x + width/2, Left.y, Left.x, Left.y + height/2);
	pWind->DrawLine(Left.x + width/2, Left.y, Left.x, Left.y - height/2);

}

void Output::DrawInputOutput(Point Left, int width, int height, string text, bool selected)      //Input and Output parallelogram shape     *Omar
{
	int s = text.size() * 20;      //Where s is the size of the input text

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - s/4, Left.y - 10, text);

	if (s > width)
	{
		width = s;
		height = width / 4;
	}

	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawLine(Left.x - width / 3, Left.y - height / 2, Left.x + width / 2, Left.y - height / 2);
	pWind->DrawLine(Left.x - width / 3, Left.y - height / 2, Left.x - width / 2, Left.y + height / 2);
	pWind->DrawLine(Left.x + width / 3, Left.y + height / 2, Left.x - width / 2, Left.y + height / 2);
	pWind->DrawLine(Left.x + width / 3, Left.y + height / 2, Left.x + width / 2, Left.y - height / 2);
}

void Output::DrawConnector(Point Left, Point Right, int width, bool selected)       //Arrows    *Omar     Feeha moshkela
{
	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawLine(Left.x, Left.y, Right.x, Right.y);

	pWind->SetPen(BLACK, 2);
}


//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	delete pWind;
}
