#include <gtest/gtest.h>
#include <actionsexecutor.hpp>

class TestActionsExecutor : public ::testing::Test
{
protected:
	void SetUp()
	{
		executor = new ActionsExecutor(":/data.dat");
	}
	void TearDown()
	{
		executor->deleteLater();
	}
	ActionsExecutor * executor;
};