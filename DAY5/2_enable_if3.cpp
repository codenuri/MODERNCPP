#include <iostream>
#include <type_traits>


template<typename T> 

std::enable_if< std::is_integral_v<T>, T>::type

gcd(T a, T b)
{

	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);		 
	gcd(3.1, 5.4);	
	gcd(3.1f, 5.4f); 
}
