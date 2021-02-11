#include "testfilereader.hpp"
#include <QDebug>
TEST_F(TestFileReader, create)
{
	reader->quit();
	ASSERT_TRUE(true);
}

TEST_F(TestFileReader, init)
{
	auto init_val = reader->init();
	reader->quit();
	ASSERT_EQ(init_val, 1);
}

TEST_F(TestFileReader, run)
{
	QList<qint64> listvalues;
	QObject::connect(reader, &Helper::FileReader::readNumber, [&](qint64 val) {listvalues << val; });
	reader->init();
	reader->start();
	reader->wait();
	ASSERT_EQ(listvalues, QList<qint64>() << 2 << 3 << 4);
}

TEST_F(TestFileReader, runException)
{
	bool flag = false;
	QObject::connect(reader, &Helper::FileReader::error, [&](QString val) {flag=true; });
	reader->start();
	reader->wait();
	ASSERT_TRUE(flag);
}

TEST_F(TestFileReader, done)
{
	qint64 val = 0;
	QObject::connect(reader, &Helper::FileReader::done, [&](qint64 value) {val = value; });
	reader->init();
	reader->start();
	reader->wait();
	ASSERT_EQ(val,3);
}