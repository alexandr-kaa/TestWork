#ifndef XORACTION_HPP
#define XORACTION_HPP
#include "action.hpp"
namespace Helper {
 class XorAction : public Action{
 public:
     explicit XorAction(qint64 data, QObject* parent=nullptr) : Action(data, parent) {}
 public slots:
    void getnewdata(qint64 data);
 };
}
#endif
