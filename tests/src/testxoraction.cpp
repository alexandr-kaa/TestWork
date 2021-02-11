#include "testxoraction.hpp"
TEST_F(TestXorAction, Xor1)
{
	action->getnewdata(1);
	ASSERT_EQ(action->getData(), 10 ^ 1);
}