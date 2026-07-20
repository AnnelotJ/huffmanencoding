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
        // Checking wether node a is bigger than node b
        return a->frequency > b->frequency;
        
    }
};

std::unordered_map<char,int> frequencyMap; 
std::priority_queue<Node*, std::vector<Node*>, comparator> nodePriorityQueue;  


void countFrequencies(std::string);
void makeNodes();
void merge(Node*, Node*); 

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

    while(nodePriorityQueue.size() > 1){
        Node* a = nodePriorityQueue.top(); 
        nodePriorityQueue.pop(); 
        Node* b = nodePriorityQueue.top(); 
        nodePriorityQueue.pop(); 

        std::cout<<"The first node frequency is: " << a->frequency <<"\n"; 
        std::cout<<"The second node frequency is: " << b->frequency << "\n"; 
        // merge(a,b); 

    }
    
    Node* root = nodePriorityQueue.top(); 
    nodePriorityQueue.pop();
    std::cout<<"The frequency of the root node is: " << root->frequency <<"\n";


    
    
    return 0;
}

void merge(Node* a, Node* b){
    // Check whether node A is bigger than node b 
    if (comparator(a, b)){
        // If a is bigger than b than a goes to the left and b goed to the right; 
        b.left(a);
        a.right(b)
    }
    else {
        b.left(a);
        a.right(b)

    }

}

void makeNodes(){
    for (const auto& [character,frequency] : frequencyMap){
        nodePriorityQueue.push(new Node(character,frequency));
    }
    auto copyNodePriorityQueue = nodePriorityQueue;

    std::cout<<"This is the current priority queue:\n";
    while (!copyNodePriorityQueue.empty()) {
    Node* n = copyNodePriorityQueue.top();   
    copyNodePriorityQueue.pop();             
    std::cout << n->character << " : " << n->frequency << "\n";

    }

}


void countFrequencies (std::string inputString){ 
    for (int i=0; i<inputString.length(); i++){
        frequencyMap[inputString[i]]++;
    }
}