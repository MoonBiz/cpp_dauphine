#include "uvector.hpp"

namespace dauphine
{

	uvector::uvector(std::size_t size)
		: p_data(nullptr), m_size(0)
	{
		if (size != 0)
		{
			p_data = new double[size];
			m_size = size;
		}
	}


}
