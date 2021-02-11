#include "actionsexecutor.hpp"
#include <QCoreApplication>
#include <stdexcept>
#include <memory>

#include <QDebug>


ActionsExecutor::ActionsExecutor(const QString & filename,QObject *parent) : QObject(parent),
    m_filename(filename)
{
}

void ActionsExecutor::onReadDone(qint64 counter)
{
    finishcounter = counter;
}

qint64 ActionsExecutor::getSub()
{
    if(subaction)
        return subaction->getData();
    throw std::runtime_error("Empty subaction");
}

qint64 ActionsExecutor::getSum()
{
    if (sumaction)
        return sumaction->getData();
    throw std::runtime_error("Empty sumaction");
}

qint64 ActionsExecutor::getXor()
{
    if (xoraction)
       return xoraction->getData();
    throw std::runtime_error("Empty xoraction");
}

void ActionsExecutor::wait()
{
    subaction->wait();
    sumaction->wait();
    xoraction->wait();
    while (!((finishcounter == subaction->getCounter()) &&
        (finishcounter == sumaction->getCounter()) &&
        (finishcounter == xoraction->getCounter())))
        QCoreApplication::sendPostedEvents(); 
}

void ActionsExecutor::init()
{
    try {
        filereader = std::make_unique<Helper::FileReader>(m_filename);
        auto res = connect(filereader.get(), &Helper::FileReader::error, [&](QString errmsg) {throw std::runtime_error(QString("FileReader error: %1").arg(errmsg).toLocal8Bit()); });
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        auto initData = filereader->init();
        subaction = std::make_unique<Helper::SubAction>(initData);
        sumaction = std::make_unique<Helper::SumAction>(initData);
        xoraction = std::make_unique<Helper::XorAction>(initData);
        res = connect(filereader.get(), &Helper::FileReader::readNumber, subaction.get(), &Helper::SubAction::getnewdata, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(filereader.get(), &Helper::FileReader::readNumber, sumaction.get(), &Helper::SumAction::getnewdata, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(filereader.get(), &Helper::FileReader::readNumber, xoraction.get(), &Helper::XorAction::getnewdata, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(filereader.get(), &Helper::FileReader::done, this, &ActionsExecutor::onReadDone, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");

        res = connect(filereader.get(), &Helper::FileReader::done, subaction.get(), &Helper::Action::onDone, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(filereader.get(), &Helper::FileReader::done, sumaction.get(), &Helper::Action::onDone, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(filereader.get(), &Helper::FileReader::done, xoraction.get(), &Helper::Action::onDone, Qt::QueuedConnection);
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(subaction.get(), &Helper::SubAction::overflow, []() {qWarning() << "Overflow sub detected!!!"; });
        if (!res)
            throw std::runtime_error(u8"Connection failed");
        res = connect(sumaction.get(), &Helper::SumAction::overflow, []() {qWarning() << "Overflow sum detected!!!"; });
        if (!res)
            throw std::runtime_error(u8"Connection failed");
    }
    catch (std::exception& ex)
    {
        qWarning(ex.what());
        emit error();
    }
}

void ActionsExecutor::run()
{
    try {
         filereader->start();
    }
    catch(std::exception & ex)
    {
     qWarning(ex.what());
    }
}

