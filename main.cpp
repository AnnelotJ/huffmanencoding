#include <iostream>
#include <string.h>
#include <unordered_map>
#include <queue> 

struct Node { 
    char character; 
    int frequency; 

    Node* left; 
    Node* right; 

   Node (char charachter, int frequency): character(character), frequency (frequency), left (nullptr), right(nullptr_t){}
};

std::unordered_map<char,int> frequencyMap; 
std::priority_queue<Node*, std::vector<Node*>, std::greater<int>> nodePriorityQueue;  


void countFrequencies(std::string);
void makeNodes();

int main (){
    
    std::string userInput; 

    std::cout<<"Please provide me a string that I can encode\n"; 
    std::getline(std::cin,userInput); 


    // We want to count the frequencies of the string that has been provided, and store them somewhere
    countFrequencies(userInput);

    makeNodes();
    
    // for (const auto& pair : frequencyMap){
    //         std::cout << pair.first << " : " << pair.second << '\n';
    //     }
    
    return 0;
}

void makeNodes(){
    for (const auto& [character,frequency] : frequencyMap){
        std::cout<<"hello\n";
    }

}


void countFrequencies (std::string inputString){ 
    for (int i=0; i<inputString.length(); i++){
        frequencyMap[inputString[i]]++;
    }
}