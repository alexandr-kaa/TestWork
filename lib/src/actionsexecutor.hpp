#ifndef ACTIONSEXECUTOR_HPP
#define ACTIONSEXECUTOR_HPP
#include "filereader.hpp"
#include "subaction.hpp"
#include "sumaction.hpp"
#include "xoraction.hpp"

#include <QString>

#include <QObject>
#include <QThread>

#include <memory>

class ActionsExecutor : public QObject
{
    Q_OBJECT
public:
    explicit ActionsExecutor(const QString & filename,QObject *parent = nullptr);
    qint64 getSum();
    qint64 getSub();
    qint64 getXor();
    void init();
    void run();
    void wait();
signals:
    void done();
    void error();
protected slots:
     void onReadDone(qint64 counter);
private:
    QString m_filename;
    std::unique_ptr<Helper::FileReader>  filereader;
    std::unique_ptr<Helper::SubAction> subaction;
    std::unique_ptr<Helper::SumAction> sumaction;
    std::unique_ptr<Helper::XorAction> xoraction;

    qint64 finishcounter = 0;
};

#endif // ACTIONSEXECUTOR_HPP
