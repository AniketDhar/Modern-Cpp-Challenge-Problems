#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
#include <iterator>



int find_gcd(int const a, int const b)
{
    return b == 0 ? a : find_gcd(b, a%b);
}


int find_lcm(int const a, int const b)
{
    auto g = find_gcd(a, b);
    return g ? (a*(b/g)) : 0;
}


int main()
{
    std::vector<int> input_ints;
    int input{0};

    std::cout << "Enter integers to calculate LCM. < Press 'Enter' to stop>" << std::endl;

    do 
    {
	std::cin >> input;
	input_ints.push_back(input);
    
    }while(std::cin.get() != '\n');

    int product = std::accumulate(input_ints.begin(), input_ints.end(), 1, std::multiplies<int>());
    std::cout << "product is " << product << std::endl;

    int gcd = std::accumulate(std::next(input_ints.begin()), input_ints.end(), input_ints[0], find_gcd);
    std::cout << "gcd is " << gcd <<std::endl;

    int lcm = std::accumulate(std::next(input_ints.begin()), input_ints.end(), input_ints[0], find_lcm);
    std::cout << "lcm is " << lcm <<std::endl;

    return 0;
}
