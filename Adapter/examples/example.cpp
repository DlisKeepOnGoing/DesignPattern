#include<example.h>


int main()
{
    Enumeration* enumeration = new Enumeration();
    EnumerationIteration* adaper = new EnumerationIteration(enumeration);
    adaper->fun_one();
    adaper->fun_two();
    adaper->fun_four();
    return 0;
}