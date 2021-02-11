#include "sumaction.hpp"

namespace Helper {
	void SumAction::getnewdata(qint64 data)
	{
        Action::getnewdata(data);
        if (((data > 0) && (m_data > (max - data))) ||
            ((data < 0) && (m_data < (min - data)))) {
            emit overflow();
        }
        m_data += data;
    }
}