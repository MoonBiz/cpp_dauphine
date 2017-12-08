#include "polynomial.hpp"
#include <vector>

namespace dauphine
{
	polynomial::polynomial(double d_degree)
		:m_d_degree(d_degree)
		{
		}
	polynomial::polynomial(std::vector<double> d_coefficients)
		:m_d_coefficients(d_coefficients)
		{
		}
}

