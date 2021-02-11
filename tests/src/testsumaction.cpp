#include "testsumaction.hpp"

TEST_F(TestSumAction, Sum1)
{
	action->getnewdata(1);
	action->onDone();
	ASSERT_EQ(action->getData(), 11);
}
TEST_F(TestSumAction, SumMax)
{
	auto max = std::numeric_limits<qint64>().max();
	bool over = false;
	QObject::connect(action, &Helper::SumAction::overflow, [&]() {over = true; });
	action->getnewdata(max);
	action->onDone();
	ASSERT_TRUE(over);
}
TEST_F(TestSumAction, SumMin)
{
	auto min = std::numeric_limits<qint64>().min();
	bool over = false;
	action->getnewdata(-11);
	QObject::connect(action, &Helper::SumAction::overflow, [&]() {over = true; });
	action->getnewdata(min);
	action->onDone();
	ASSERT_TRUE(over);
}