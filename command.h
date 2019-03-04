#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand(double value) : Command() {
			std::cout<< "opcommand constr" <<std::endl;
			this->root = new Op(value);
		};
		

};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Command* l, Command* r) : Command() {
			this->root = new Add(l->get_root(),r->get_root());
		};

		AddCommand(Command* l, double r) : Command() {
			Op* o = new Op(r);			
		       	this->root = new Add(l->get_root(),o);					          
	  	};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
		SubCommand(Command* l, Command* r) : Command() {
			this->root = new Sub(l->get_root(),r->get_root());
		};
		SubCommand(Command* l, double r) : Command() {			
			Op* o = new Op(r);					           
	   		this->root = new Sub(l->get_root(),o);					
		};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
		MultCommand(Command* l, Command* r) : Command() {
			this->root = new Mult(l->get_root(),r->get_root());
		};
		MultCommand(Command* l, double r) : Command() {			
			Op* o = new Op(r);					           
	   		this->root = new Mult(l->get_root(),o);					
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
		SqrCommand(Command* l) : Command() {
			this->root = new Sqr(l->get_root());
		};
};

#endif //__COMMAND_CLASS__
