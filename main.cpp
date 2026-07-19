#include <iostream>
#include <string.h>
#include <unordered_map>
#include <queue> 

struct Node { 
    char character; 
    int frequency; 

    Node* left; 
    Node* right; 

   Node (char character , int frequency): character(character ), frequency (frequency), left (nullptr), right(nullptr){}
};

struct comparator {
    bool operator ()(Node* a, Node* b){
        return a->frequency > b->frequency;
        
    }
};

std::unordered_map<char,int> frequencyMap; 
std::priority_queue<Node*, std::vector<Node*>, comparator> nodePriorityQueue;  


void countFrequencies(std::string);
void makeNodes();

int main (){
    
    std::string userInput; 

    std::cout<<"Please provide me a string that I can encode\n"; 
    std::getline(std::cin,userInput); 


    // We want to count the frequencies of the string that has been provided, and store them somewhere
    countFrequencies(userInput);

    std::cout<<"The frequencies are as followed:\n";
    for (const auto& pair : frequencyMap){
            std::cout << pair.first << " : " << pair.second << '\n';
        }
    
    makeNodes();
    
    
    return 0;
}

void makeNodes(){
    for (const auto& [character,frequency] : frequencyMap){
        nodePriorityQueue.push(new Node(character,frequency));
    }

    std::cout<<"This is the current priority queue:\n";
    while (!nodePriorityQueue.empty()) {
    Node* n = nodePriorityQueue.top();   // grab the top pointer
    nodePriorityQueue.pop();             // remove it
    std::cout << n->character << " : " << n->frequency << "\n";
    //           ^^ use -> to reach into the node the pointer points at
    }

}


void countFrequencies (std::string inputString){ 
    for (int i=0; i<inputString.length(); i++){
        frequencyMap[inputString[i]]++;
    }
}