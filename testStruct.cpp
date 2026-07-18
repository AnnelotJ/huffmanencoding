#include <iostream> 
#include <string.h> 
#include <queue>

struct Person{ 
    std::string name;
    int age;
};


int main(){ 

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
pq.push(3);
pq.push(1);
pq.push(8);

while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
}


    return 0; 
}