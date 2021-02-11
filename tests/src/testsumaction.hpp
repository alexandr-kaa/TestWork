#include <gtest/gtest.h>
#include <sumaction.hpp>

class TestSumAction : public ::testing::Test
{
protected:
	void SetUp()
	{
		action = new Helper::SumAction(10);
	}
	void TearDown()
	{
		action->onDone();
		action->wait();
		action->deleteLater();
	}
	Helper::SumAction* action;
};