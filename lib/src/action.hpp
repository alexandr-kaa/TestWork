#ifndef ACTION_HPP
#define ACTION_HPP
#include <QObject>
#include <QThread>

namespace Helper{

class Action:public QObject{
    Q_OBJECT
public:
    const qint64 max = std::numeric_limits < qint64 >::max();
    const qint64 min = std::numeric_limits < qint64 >::min();
    explicit  Action(qint64 data, QObject * parent=nullptr);
    qint64 getData(); 
    qint64 getCounter();
    void wait();
public slots:
    void getnewdata(qint64 data); 
    void onDone();
protected:
    qint64 m_data;
    qint64 m_counter=0;
    QThread m_thread;
};
}
#endif
