#include "subaction.hpp"
namespace Helper {
	void SubAction::getnewdata(qint64 data)
	{
		Action::getnewdata(data);
    	if ((data > 0 && m_data < min + data) ||
			(data < 0 && m_data > max + data)) {
			emit overflow();
			}
		m_data -= data;
	}
}