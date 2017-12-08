#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP
#include <vector>
#include <string>

namespace dauphine
{
    class volatility
    {
    public:
		explicit volatility(const std::string& name);
        const	std::string& underlying_name() const;
		virtual double get_volatility(size_t index) const;
		virtual ~volatility();
	protected:
		int m_id;
	private:
		std::string	m_name;
	};

    class implied_volatility : public volatility
    {public:
        implied_volatility(const std::string& name, const std::vector<double>& m_volatility );
		void print() const;
		double get_volatility(size_t index) const;
		virtual ~implied_volatility();
	private:
		std::vector<double> m_volatility;
    };
	class bumped_volatility : public volatility
	{public:
		bumped_volatility(volatility* vol, double bump);
		virtual ~bumped_volatility();
		double get_volatility(size_t index) const; 
	private:
		volatility* p_volatility;
		double m_bump;
	};
	volatility* make_volatility(const std::string& ud, const std::vector<double>& vol);
	volatility* make_volatility(volatility* vol, double bump);
}

#endif
