#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int main() 
{
  srand(time(nullptr));
  while(1) {
    int n = rand() % 5;
    std::cout << n << std::endl;
    sleep(1);
  }
  
  return 0;
}
