#include <iostream>
#include "vector_utils.hpp"
#include "additional_exercises.hpp"

int main(int argc, char* argv[])
{
	std::vector<double> v = { 1.,2.,3.,4. };
	std::vector<double> w = { 10.,12.,13.,14. };
	dauphine::print(v);
	double d = dauphine::mean(v);
	std::cout << d << std::endl;
	dauphine::extend_vector(v);
	dauphine::append(v, w);
    return 0;
}

