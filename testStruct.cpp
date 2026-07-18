#include <iostream> 
#include <string.h> 

struct Person{ 
    std::string name;
    int age;
};


int main(){ 
    Person Annelot; 
    Person Ryan; 

    std::cout<<Annelot.name; 

    Annelot.name = "Annelot"; 
    std::cout << Annelot.name; 
    return 0; 
}