#include <iostream> 

int main (){ 

    std::cout<<"\n";
    int x =5; 
    int* y = &x; 

    std::cout<<x;
    std::cout<<"\n";
    std::cout<<y; 

    y = y+2;

    std::cout<<"\n";
    std::cout<<y; 


    std::cout<<"\n";

    return 0; 
}