#ifndef SUMACTION_HPP
#define SUMACTION_HPP
#include "action.hpp"
namespace Helper{
 class SumAction: public Action{
     Q_OBJECT
 public:
     explicit SumAction(qint64 data, QObject* parent = nullptr) :Action(data, parent) {}
 signals:
     void overflow();
 public slots:
    void getnewdata(qint64 data);
};
}
#endif
