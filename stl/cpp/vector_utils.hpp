#ifndef VECTOR_UTILS_HPP
#define VECTOR_UTILS_HPP

#include <vector>

namespace dauphine
{
	void print(const std::vector<double>& v);
	double mean(const std::vector<double> v);
	void extend_vector(std::vector<double>& v);
	void append(const std::vector<double>& src, std::vector<double>& dst);
}

#endif
