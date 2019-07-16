#include <iostream>
#include <utility>
#include <vector>

int main()
{
   std::vector<int> vec{1, 2, 3, 4, 5};
   auto mvec = std::move(vec);
   std::cout << mvec.size() << std::endl;
   std::cout << vec.size() << std::endl;
   std::cout << mvec[1] << std::endl;
   return 0;
}
