#include <gtest/gtest.h>
#include <QCoreApplication>
int main(int argc ,char *argv[])
{
    QCoreApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}