#ifndef IACTION_HPP
#define IACTION_HPP
#include "action.hpp"

namespace Helper{
    Action::Action(qint64 data, QObject * parent)
        :QObject(parent),
         m_data(data)
    { 
        moveToThread(&m_thread);
        m_thread.start();
    }
    qint64 Action::getData() {return m_data;}
    qint64 Action::getCounter(){ return m_counter; }
    void Action::onDone()
    {
        m_thread.quit();
    }
    void Action::wait()
    {
        m_thread.wait();
    }
    void Action::getnewdata(qint64 data)
    { 
        m_counter++; 
    }
}
#endif
