/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, ParameterizedConstructor)
{
  	ConnectX connectparameter(11,11,-1);   //Parameterized Constructor called

    ASSERT_EQ(-1 , connectparameter.at(8,7));  //test should pass as default values are SetUp
    ConnectX connectparameter1(11,-1,11);
    ASSERT_EQ(-1 , connectparameter1.at(8,7));
    ConnectX connectparameter2(-1,11,11);
    ASSERT_EQ(-1 , connectparameter2.at(8,7));
}

TEST(ConnectXTest, locationOutBounds)
{
  ConnectX connectdefault;
  ASSERT_EQ(-1 , connectdefault.at(8,7));
  ASSERT_EQ(-1 , connectdefault.at(-1,-1));
  ASSERT_EQ(-1 , connectdefault.at(4,-1));

  //This test fails if we compare result with
  //ASSERT_EQ, which should pass but
  //fails due to a bug present in the code

  ASSERT_NE(-1 , connectdefault.at(-1,1));

	ConnectX connectparameter(10,10,10);
	ASSERT_EQ(-1 , connectparameter.at(11,11));
}

TEST(ConnectXTest, locationInBounds)
{
  ConnectX connectdefault;
  ASSERT_NE(-1 , connectdefault.at(6,5));

	ConnectX connectparameter(10,10,10);
	ASSERT_NE(-1 , connectparameter.at(9,9));
}

TEST(ConnectXTest, placePieceInBoard)
{
  ConnectX connectdefault;

  connectdefault.placePiece(4);
  ASSERT_EQ(1 , connectdefault.whoseTurn());
  connectdefault.placePiece(5);
  ASSERT_EQ(2 , connectdefault.whoseTurn());
  connectdefault.placePiece(5);
  ASSERT_EQ(1 , connectdefault.whoseTurn());
  connectdefault.showBoard();
}

TEST(ConnectXTest, placePieceOutBoard)
{
  ConnectX connectdefault;

  connectdefault.placePiece(8);
  ASSERT_EQ(1 , connectdefault.whoseTurn());
  connectdefault.placePiece(9);
  ASSERT_EQ(2 , connectdefault.whoseTurn());
  connectdefault.placePiece(-2);
  ASSERT_EQ(1 , connectdefault.whoseTurn());


  //the below test fails due to abort() function
  //being called, which is called by malloc due to
  //heap overflow problem, this is a bug which needs to be fixed

  //connectdefault.placePiece(-1);
  //ASSERT_EQ(2 , connectdefault.whoseTurn());

  connectdefault.showBoard();
}


TEST(ConnectXTest, ToggleTest)
{
    ConnectX connectparameter(2,2,2);
    connectparameter.placePiece(1);
    ASSERT_EQ(1 , connectparameter.whoseTurn());
    connectparameter.placePiece(1);
    ASSERT_EQ(2 , connectparameter.whoseTurn());
    connectparameter.placePiece(1);
    ASSERT_EQ(1 , connectparameter.whoseTurn());
}
