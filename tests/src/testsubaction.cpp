#include "testsubaction.hpp"
TEST_F(TestSubAction, sub1)
{
	action->getnewdata(1);
	ASSERT_EQ(action->getData(), 999);
}

TEST_F(TestSubAction, subMin)
{
	auto min = std::numeric_limits<qint64>().min();
	bool over = false;
	QObject::connect(action, &Helper::SubAction::overflow, [&]() {over = true; });
	action->getnewdata(min);
	ASSERT_TRUE(over);
}

TEST_F(TestSubAction, subMax)
{
	auto max = std::numeric_limits<qint64>().max();
	action->getnewdata(2000);
	bool over = false;
	QObject::connect(action, &Helper::SubAction::overflow, [&]() {over = true; });
	action->getnewdata(max);
	ASSERT_TRUE(over);
}