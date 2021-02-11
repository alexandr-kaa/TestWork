#include "testactionsexecutor.hpp"

TEST_F(TestActionsExecutor, create)
{
	ASSERT_TRUE(true);
}

TEST_F(TestActionsExecutor, run)
{
	executor->init();
	executor->run();
	executor->wait();
	ASSERT_EQ(executor->getSum(), 10);
	ASSERT_EQ(executor->getSub(), -8);
	ASSERT_EQ(executor->getXor(), 4);
}