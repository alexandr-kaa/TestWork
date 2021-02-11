#include "filereader.hpp"

#include <QDataStream>

#include <QFile>

#include <exception>

namespace Helper{

FileReader::FileReader(const QString &fileName, QObject *parent):QThread(parent)
{
    m_fileName=fileName;
    m_stream.setDevice(&m_file);
}

qint64 FileReader::init()
{
    m_file.setFileName(m_fileName);
    if (!m_file.open(QIODevice::ReadOnly))
    {
        emit error(u8"File open error");
    }
    qint64 data = 0;
    if (!m_stream.atEnd())
    {
        m_stream >> data;
        return data;
    }
    else
    {
        emit error(u8"Empty file");
    }
}

void FileReader::run()
{
    qint64 data = 0;
    qint64 counter = 0;
    if (!m_file.isOpen())
        emit error(u8"File is not opened!");
    while (!m_stream.atEnd())
    {
        m_stream>>data;
        emit readNumber(data);
        counter++;
    }
    emit done(counter);
}

}
