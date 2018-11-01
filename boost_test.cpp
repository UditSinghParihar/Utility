#include <boost/multiprecision/cpp_int.hpp>
#include <boost/version.hpp>

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char const *argv[]){
	std::cout << "Using Boost "     
          << BOOST_VERSION / 100000     << "."  // major version
          << BOOST_VERSION / 100 % 1000 << "."  // minor version
          << BOOST_VERSION % 100                // patch level
          << std::endl;

	return 0;
}