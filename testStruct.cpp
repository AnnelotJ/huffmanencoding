#include <iostream> 
#include <string.h> 
#include <queue>

struct Person{ 
    std::string name;
    int age;

    Person (int age): age(age){}

};


int main(){ 
    Person annelot(12);
    Person Ryan ;
    
    std::cout<<annelot.age; 
    std::cout << Ryan.age; 



// std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
// pq.push(3);
// pq.push(1);
// pq.push(8);

// while (!pq.empty()) {
//     std::cout << pq.top() << " ";
//     pq.pop();
// }


    return 0; 
}