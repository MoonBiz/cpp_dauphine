#include "volatility.hpp"
#include <iostream>

namespace dauphine
{
	volatility::volatility(const std::string& name)
		:m_name(name)
	{
		std::cout << "volatility_constructor" << std::endl;
	}
    const std::string& volatility::underlying_name() const
    {
        return m_name;
    }
	implied_volatility::implied_volatility(const std::string& name,const std::vector<double>& vol )
		:volatility(name), m_volatility(vol)
		{
			std::cout << "implied_volatility_constructor" << std::endl;
		}
	void implied_volatility::print() const
	{
	std::cout << "implied_volatility " << m_id << std::endl;
	}
	double volatility::get_volatility(size_t index) const
	{
		std::cout<< "volatility" << std::endl;
		return 0.;
	}
	double implied_volatility::get_volatility(size_t index) const
	{
		std::cout<< "implied_volatility"<< std::endl;
		return  m_volatility[index];
	}	
	    volatility::~volatility()
    {
        std::cout << "volatility destructor" << std::endl;
    }

    implied_volatility::~implied_volatility()
    {
        std::cout << "implied_volatility destructor" << std::endl;
    }
	bumped_volatility::bumped_volatility(volatility* vol, double bump)
        : volatility(vol->underlying_name()), p_volatility(vol), m_bump(bump)
		{
			std::cout << "bumped_volatility constructor" << std::endl;
		}
	bumped_volatility::~bumped_volatility()
		{
			std::cout << "bumped_volatility destructor" << std::endl;
			p_volatility = nullptr;
		}
	double bumped_volatility::get_volatility(size_t index) const
    {
        return p_volatility->get_volatility(index) + m_bump;
    }

    volatility* make_volatility(const std::string& ud, const std::vector<double>& vol)
    {
        return new implied_volatility(ud, vol);
    }
    volatility* make_volatility(volatility* vol, double bump)
    {
        return new bumped_volatility(vol, bump);
    }
}