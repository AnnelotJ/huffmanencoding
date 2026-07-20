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
std::unordered_map<char,std::string> codes;
std::priority_queue<Node*, std::vector<Node*>, comparator> nodePriorityQueue;



void countFrequencies(std::string);
void makeNodes();
void merge(Node*, Node*); 
void walk (Node* node, std::string); 

int main (){
    
    std::string userInput; 

    std::cout<<"Please provide me a string that I can encode\n"; 
    std::getline(std::cin,userInput); 


    // We want to count the frequencies of the string that has been provided, and store them somewhere
    countFrequencies(userInput);

    // std::cout<<"The frequencies are as followed:\n";
    // for (const auto& pair : frequencyMap){
    //         std::cout << pair.first << " : " << pair.second << '\n';
    //     }
    

    makeNodes();

    while(nodePriorityQueue.size() > 1){
        Node* a = nodePriorityQueue.top(); 
        nodePriorityQueue.pop(); 
        Node* b = nodePriorityQueue.top(); 
        nodePriorityQueue.pop(); 
        merge(a,b); 
    }
    
    Node* root = nodePriorityQueue.top(); 
    nodePriorityQueue.pop();
    // std::cout<<"The frequency of the root node is: " << root->frequency <<"\n";

    walk(root, ""); 

    // So this is the map that has been created
    std::cout<< "The code table is as followed:\n";
    for (const auto& [character, code] : codes) {
    std::cout << character << " : " << code << "\n";
    }

    // lets encode the strin now
    std::string stringEncode= ""; 
    for (int i =0; i < userInput.size(); i++){ 

        stringEncode = stringEncode + codes[userInput[i]];
    }
    std::cout<< stringEncode << "\n" ;

    
    
    return 0;
}

void walk (Node* node, std::string code){
    // Checking if it is a leaf
    if (node->left == nullptr and node->right == nullptr){
        codes[node->character] = code;
    }

    else {
        walk(node->left, code + "0");
        walk(node->right, code + "1");
    }
}

void merge(Node* a, Node* b){
    // A is the smaller node and B is the bigger node 
    int parentFreq = a->frequency + b->frequency; 
    
    Node* parent = new Node('\0', parentFreq); 

    parent->left = b; 
    parent->right = a; 

    auto copyNodePriorityQueue = nodePriorityQueue;
    nodePriorityQueue.push(parent);


}

void makeNodes(){
    for (const auto& [character,frequency] : frequencyMap){
        nodePriorityQueue.push(new Node(character,frequency));
    }
    auto copyNodePriorityQueue = nodePriorityQueue;

    // std::cout<<"This is the current priority queue:\n";
    // while (!copyNodePriorityQueue.empty()) {
    // Node* n = copyNodePriorityQueue.top();   
    // copyNodePriorityQueue.pop();             
    // std::cout << n->character << " : " << n->frequency << "\n";

    // }

}


void countFrequencies (std::string inputString){ 
    for (int i=0; i<inputString.length(); i++){
        frequencyMap[inputString[i]]++;
    }
}