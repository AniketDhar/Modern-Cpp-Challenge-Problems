#include <iostream>
#include <vector>
#include <cmath>


int find_gcd(int const a, int const b)
{
    return b == 0 ? a : find_gcd(b, a%b);
}


int main()
{
    std::vector<int> input_ints;
    std::cout << "Input integers to find gcd. <Press 'Enter' to stop> " << std::endl;
    int input{0};
    
    do
    {
	std::cin >> input;
        input_ints.push_back(input);
    }while(std::cin.get() != '\n');

    int gcd = input_ints[0];
    for(int i = 1; i <  input_ints.size(); ++i)
    {
        gcd = find_gcd(input_ints[i], gcd);
    }	    

    std::cout << "GCD for entered numbers is : " << std::abs(gcd) << std::endl;
    return 0;
}

