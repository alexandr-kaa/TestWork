#include <gtest/gtest.h>
#include <subaction.hpp>

class TestSubAction : public ::testing::Test
{
protected:
	void SetUp()
	{
		action = new Helper::SubAction(1000);
	}
	void TearDown()
	{
		action->onDone();
		action->wait();
		action->deleteLater();
	}
	Helper::SubAction *action;
	
};