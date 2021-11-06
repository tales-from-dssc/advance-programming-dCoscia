#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){

    std::cout<<"\n";
    std::cout<<"Insert single word, then press enter to go to a new line. \n";
    std::cout<<"Press 0 to start the algorithm once all words are inserted."<<std::endl;
    std::cout<<"\n";

    std::vector<std::string> words;
    for(std::string word;std::getline(std::cin, word);){
        if(word == "0") break;
        words.push_back(word);
    }

    std::vector<std::string> unique_words{words[0]};
    for(auto x: words){
        if(std::find(unique_words.begin(), unique_words.end(), x) == unique_words.end()){
            unique_words.push_back(x);
        }
    }

    std::cout<<"------------------Words before the algorithm------------------------\n";
    std::cout<<"\n";
    for(auto x: words){
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    std::cout<<"\n";

    std::cout<<"------------------Words after the algorithm------------------------\n";
    std::cout<<"\n";
    for(auto x:unique_words){
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    std::cout<<"\n";

    return 0;
}