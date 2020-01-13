#include <iostream>
// don't use namespace std, it is a bad practice.
void DemoFunction()
{
  std::cout << “In Demonstration Function\n”;
}
int main()
{
  std::cout << “In main function. \n” ;
  DemoFunction();
  std::cout << “Back in main function.”;
  return 0;
}
