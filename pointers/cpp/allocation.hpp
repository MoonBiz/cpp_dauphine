#ifndef ALLOCATION_HPP
#define ALLOCATION_HPP

#include <memory>
#include <iostream>

namespace dauphine
{
    
	/* class volatility
    {
    public:

        volatility();
        ~volatility();

        double get_volatility(double maturity, double strike) const;
    };

    volatility* make_volatility();

    class underlying
    {
    public:

        underlying(volatility* vol);
        ~underlying();

        volatility* get_volatility();

    private:

        volatility* p_volatility;
    };

    class option
    {
    public:

        option(underlying* underlying, volatility* vol);
        ~option();

    private:

        underlying* p_underlying;
        volatility* p_volatility;
    };
    
	*/
    // PART 2
    
    class data_model;
    class product;

    using data_model_ptr = std::shared_ptr<data_model>;
    using product_ptr = std::shared_ptr<product>;

    class data_model
    {
    public:

        data_model(product_ptr prod);
        ~data_model();

    private:

        product_ptr p_product;
    };

    class product
    {
    public:

        product();
        ~product();
    };

    class pricer
    {
    public:

        pricer(product_ptr prod, data_model_ptr data);
        ~pricer();

    private:

        product_ptr p_product;
        data_model_ptr p_data;
    };
	void product::set_data_model(data_model_ptr)
	{
		p_data = data_model_ptr;
	}

	pricer::pricer(product_ptr prod, data_model_ptr data)
		: p_product(prod), p_data(data)
	{
		p_product->set_data_model(p_data);
		std::cout << "pricer constructor" << std::endl;
	}
}

#endif
