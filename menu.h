#ifndef __MENU_CLASS__
#define __MENU_CLASS__
#include <typeinfo>
#include <iostream>
#include <typeinfo>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
			this->history_index=0;
			this->history = {};
		};
		void execute() {
			if (history[history_index]==NULL)
			{
				std::cout<<0<<std::endl;
			}
			else
			{
				std::cout<< (this->history[history_index])->execute() << std::endl;

			}


			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
		};
		bool initialized() {
			bool isSingleOp=false;
			string s = typeid(history[0]).name();
			if (s== "OpCommand")

			{
				isSingleOp=true;
			}
			return isSingleOp;
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
		};
		void add_command(Command* cmd) {
			if (history_index >0)
			{
				vector<Command*> tmp ;
				for(int i = 0; i < history.size(); i++)
				{
					tmp.push_back(history[i]);
				}
				tmp.push_back(cmd);
				history = tmp;	
				history_index++;
			}
			else
			{
				history.push_back(cmd);
			}

		//a	history_index=history_index+1;
		//	history[history_index]=cmd;
			//Adds a command to history in the appropriate posiiton (based on history_index)
		};
		Command* get_command() {
			Command* myCommand;
			myCommand=history[history_index];
			return myCommand;
			//Returns the command in history we are currently referring to (based on history_index)
		};
		void undo() {
			if (history_index>0)
			{
				history_index=history_index-1;
			}
			else
			{
				std::cout<<"Already first command"<<std::endl;
			}
			//Moves to the last command in history (if possible) 
		};
		void redo() {
			if (history_index<history.size()-1)
			{
				history_index=history_index+1;
			}
			else
			{
				std::cout<<"Already last command"<<std::endl;
			}
			//Moves to the next command in history (if possible)
		};
};

#endif //__MENU_CLASS__
