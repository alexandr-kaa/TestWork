#include <gtest/gtest.h>
#include <xoraction.hpp>

class TestXorAction : public ::testing::Test
{
protected:
	void SetUp()
	{
		action = new Helper::XorAction(10);
	}
	void TearDown()
	{
		action->onDone();
		action->wait();
		action->deleteLater();
	}
	Helper::XorAction* action;

};