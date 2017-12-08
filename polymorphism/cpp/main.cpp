#include <iostream>
#include "volatility.hpp"

// To compile
//
// Windows users:
// mkdir build
// cd build
// cmake -G "NMake Makefiles" ..
// nmake
//
// OSX / Linux users:
// mkdir build
// cd build
// cmake ..
// make
namespace dauphine
{
    void test_access()
    {
        volatility v("JP Morgan");
		implied_volatility iv("JP Morgan",{0.15,0.20,0.25,0.25,0.26});
		iv.print();
        //std::cout << v.underlying_name() << std::endl;
    }
	void  test_polymorphism(const volatility& vol)
	{
		std::cout << vol.underlying_name() << std::endl;
		std::cout << vol.get_volatility(0) << std::endl;
	}
	
	void  test_polymorphism()
	{
		//implied_volatility iv("JP Morgan", {0.15,0.20,0.25,0.25,0.26});
		//test_polymorphism(iv);
		//volatility v("JP Morgan");
		//test_polymorphism(v);
		
		volatility* iv = make_volatility("JP Morgan", { 0.15, 0.20, 0.25, 0.26});
        test_polymorphism(*iv);
        volatility* bv = make_volatility(iv, 0.01);
        test_polymorphism(*bv);
        delete bv;
		delete iv;
	}
	
}

int main(int argc, char* argv[])
{
    //dauphine::test_access();

	//dauphine::test_polymorphism("JP Morgan");
	dauphine::test_polymorphism();
	return 0;
	}

