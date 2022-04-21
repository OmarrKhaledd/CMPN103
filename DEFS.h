#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	ADD_START_STAT, //Add start statement    
	ADD_END_STAT,    //Add end statement 

	ADD_INPUT,
	ADD_OUTPUT,

	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_SO_ASSIGN,  //Add a single operator assignment

	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)

	ADD_CONNECTOR, //Add a connector between two statements

	EDIT_STAT,	//Edit a statement

	SELECT,		//Select a statement, a connector

	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)

	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	EXIT,		//Exit the application
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE	//Switch to simulatiom mode
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	ITM_SMPL_ASSIGN,//simple assignment statement.  x=5;   
	ITM_VAR_ASSIGN, //variable assigned a variable. x=y;
	ITM_SO_ASSIGN, //Single Operators assignment statements. x=y+2; supports (*,/,+,-)
	ITM_CONDITION,		//conditional statement
	ITM_CONNECTOR,  //insert connector 
	ITM_READ,       //Reads statement from keyboard/ input device
	ITM_WRITE,      //writes value/ message to screem/output device
	ITM_EDIT_STAT,  //edit a statement 
	ITM_DELETE,     //Delete a figure(s)
	ITM_SELECT,     //Select a statement, a connector
	ITM_MOVE,       //Move a figure(s)
	ITM_EXIT,		//Exit
	ITM_RESIZE,     //Resize a figure(s)                             *BAHGA
	ITM_SAVE,       //Save the whole graph to a file
	ITM_LOAD,       //Load a graph from a file
	ITM_DSN_MODE,   //Switch to Design mode
	ITM_SIM_MODE,   //Switch to simulatiom mode
	ITM_START,      //start the flowchart           *BAHGA
	ITM_END,        //end the flowchart
	ITM_INPUT,
	ITM_OUTPUT,

	//TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_RUN,	//Run
	ITM_STP,	//Step by step
	
	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};

enum IconPlace 
{
	first = 0,
	second = 80,
	third = 160,
	fourth = 240,
	fifth = 320,
	sixth = 400,
	seventh = 480,
	eighth = 560,
	ninth = 640,
	tenth = 720,
	eleventh = 800,
	twelvth = 880,
	thirteenth = 960,
	fourteenth = 1040,
	fifteenth = 1120,
	sixteenth = 1200,
	seventeenth = 1280
};


#ifndef NULL
#define NULL 0
#endif

#endif