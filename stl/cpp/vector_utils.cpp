#include <iostream>
#include <algorithm>
#include "vector_utils.hpp"
#include <numeric>
#include <iterator>
#include <cmath>
#include <functional>

namespace dauphine
{
	void print(const std::vector<double>& v)
	{
		for (auto iter = v.begin(); iter != v.end(); ++iter)
		{
			std::ostream_iterator<double> out_it(std::cout, ", ");
			std::copy(v.begin(), v.end(), out_it);
			std::cout << std::endl;
		}
		//	std::cout << *iter << ",";
		//}
		//std::cout << std::endl;
		// for (size_t i = 0; i< v.size(); ++i)
		// {
		// 	std::cout << v[i] << ",";
		// }
		// std::cout << std::endl;

	}

	double mean(const std::vector<double> v)
	{
		double res = std::accumulate(v.begin(), v.end(), 0, std::multiplies<double>());
//		for (size_t i = 0; i < v.size(); ++i)
//		{
//			res += v[i];
//		}
		return std::pow(res,1/v.size());
	}
	
	void extend_vector(std::vector<double>& v)
	{
		size_t size = v.size();
		v.resize(2 * size);
		std::transform(v1.begin(), v1.begin() + size_t, v1.begin() + size_t, [](double arg) {return 2 * arg; });
		//v.reserve(2 * size);
		//for (size_t i= 0; i < size; ++i)
		//{
		//	v.push_back(2 * v[i]);
		//}
	}

	void append(const std::vector<double>& src, std::vector<double>& dst)
	{
		size_t src_size = src.size();
		size_t dst_size = dst.size();
		dst.resize(dst_size + src_size);
		std::copy(src.begin(), src.end(), dst.begin()+dst_size);
		//for (size_t i = 0; i < src_size; ++i)
			//{
			//dst[i + dst_size] = src[i];
			//}
	}

}