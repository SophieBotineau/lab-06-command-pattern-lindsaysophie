#include "gtest/gtest.h"
#include "command.h"


TEST(OpCommand, OpTest)
{
	OpCommand* oc = new OpCommand(12);
	double val = oc->execute();
	EXPECT_EQ(12, val);
}

TEST(AddCommand, AddTest)
{
	OpCommand* A = new OpCommand(12);
	OpCommand* B = new OpCommand(3);
	AddCommand* c = new AddCommand(A,B);
	double val = c->execute();			  
  	EXPECT_EQ(15, val);
}

TEST(SubCommand, SubTest)
{
	OpCommand* A = new OpCommand(5);
	OpCommand* B = new OpCommand(3);			   
   	SubCommand* c = new SubCommand(A,B);			
	double val = c->execute();					    
    	EXPECT_EQ(2, val);
}

TEST(MultCommand, MultTest)
{	       
       	OpCommand* A = new OpCommand(5);
	OpCommand* B = new OpCommand(3);			  
  	MultCommand* c = new MultCommand(A,3);			
	double val = c->execute();					    
    	EXPECT_EQ(15, val);
}

TEST(SqrCommand, SqrTest)
{	       
       	OpCommand* A = new OpCommand(5);
	SqrCommand* c = new SqrCommand(A);	
	double val = c->execute();					  
  	EXPECT_EQ(25, val);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);		  	   
       	return RUN_ALL_TESTS();
}
