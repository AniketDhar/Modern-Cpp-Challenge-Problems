#include "iostream"

int main()
{
    unsigned int limit{0};
    std::cout << "Enter upper limit: ";
    std::cin >> limit;

    unsigned long sum{0};

    for(unsigned int i = 3; i <= limit; ++i)
    {
        if((i%3 == 0) || (i%5 == 0)) 
            sum += i;
    }

    std::cout << "Sum of numbers from 3 to " << limit << " and divisible by 3 or 5 is " << sum << std::endl;
    return 0;
}
