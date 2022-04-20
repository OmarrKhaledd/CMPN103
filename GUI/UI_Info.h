#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\DEFS.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	int width, height;	//Window width and height
	int wx, wy;			//Window starting coordinates

	int StBrWdth;		//Status Bar Width
	int TlBrWdth;		//Tool Bar Width
	int MnItWdth;		//Menu Item Width
	
	color DrawClr;		//Drawing color
	color HiClr;		//Highlighting color
	color MsgClr;		//Messages color

	int ASSGN_WDTH;		//Assignment statement default width
	int ASSGN_HI;		//Assignment statement default height
	int Statement_Width;      //If and For Statements default width   *Omar
	int Statement_HI;         //If and For Statements default width   *Omar
	int Connector_Width;      //Corrector statement default width     *Omar
	int Connector_HI;         //Corrector statement default height    *Omar
	int Start_Radius;         //Start circle shape radius             *Omar
	int End_Radius;           //End circle shape radius               *Omar
	int Parallelogram_Width;  //Input and Output read shape width     *Omar
	int Parallelogram_HI;     //Input and Output read shape height    *Omar

}UI;	//create a single global object UI

struct Point	
{
	int x,y;
	Point(int a=0, int b=0)	//constructor
	{ x=a;	y=b;	}
};

#endif