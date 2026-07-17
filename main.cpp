#include <iostream>
#include <string.h>
#include <unordered_map>

struct Node { 
    char character; 
    int frequency; 

    Node* left; 
    Node* right; 
}

std::unordered_map<char,int> frequencyMap; 

void countFrequencies(std::string);
void makeNodes();

int main (){
    
    std::string userInput; 

    std::cout<<"Please provide me a string that I can encode\n"; 
    std::getline(std::cin,userInput); 


    // We want to count the frequencies of the string that has been provided, and store them somewhere
    countFrequencies(userInput);
    
    for (const auto& pair : frequencyMap){
            std::cout << pair.first << " : " << pair.second << '\n';
        }
    
    return 0;
}

void makeNodes(){
    
}

void countFrequencies (std::string inputString){ 

    for (int i=0; i<=inputString.length(); i++){

        if (!frequencyMap.contains(inputString[i])){ 
            frequencyMap[inputString[i]] = 1; 

        }
        else {
            frequencyMap[inputString[i]]++;
        }
    }
}