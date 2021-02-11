#include <gtest/gtest.h>
#include <filereader.hpp>
#include <QFileInfo>
const char * filename = ":/data.dat";
class TestFileReader : public ::testing::Test
{
protected:
	void SetUp()
	{
        if(QFileInfo(filename).exists())
	      reader = new Helper::FileReader(filename);
        else
         throw std::runtime_error("no file!");
	}
	void TearDown()
	{
		reader->wait();
		reader->deleteLater();
	}
	Helper::FileReader* reader;

};
