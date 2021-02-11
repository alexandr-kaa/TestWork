#include "xoraction.hpp"
namespace Helper {
	void XorAction::getnewdata(qint64 data)
	{
		Action::getnewdata(data);
		m_data ^= data;
	}
}