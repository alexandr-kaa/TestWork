#ifndef SUBACTION_HPP
#define SUBACTION_HPP
#include "Action.hpp"

namespace Helper {
class SubAction:public Action{
    Q_OBJECT
public :
 explicit SubAction(quint64 data, QObject * parent = nullptr) : Action(data,parent){}
signals:
    void overflow();
public slots:
    void getnewdata(qint64 data);
};
}
#endif
