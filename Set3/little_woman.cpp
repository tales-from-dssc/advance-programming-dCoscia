#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>


int main(){
    /* ------- Initialization ------ */
    std::string chars = "#!,0123456789@$%^&*(){}[]:;? ""  ";
    /* ----------------------------- */

    std::vector<std::string> words;
    std::string line;
    while(std::cin >> line){
        words.push_back(line);
    }

    /* Find the unique words in vector */

    std::vector<std::string> unique_words{words[0]};
    for(auto x: words){
        if(std::find(unique_words.begin(), unique_words.end(), x) == unique_words.end()){
            x.erase(std::remove_if(x.begin(), x.end(),
                        [&chars](char &c) {
                            return chars.find(c) != std::string::npos;
                        }),
                        x.end());
            unique_words.push_back(x);
        }
    }

    auto t0 = std::chrono::high_resolution_clock::now();
    std::vector<int> repeated_words_number(unique_words.size(),0);
    int i{0};
    for(auto x: unique_words){
        for(auto y: words){
            if(x==y){
                ++repeated_words_number[i];
            }
        }
        ++i;
    }
    auto t1 = std::chrono::high_resolution_clock::now();

    std::cout<<"NUMBER REPETITION"<<"           "<<"WORD"<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    for(i = 0;i<unique_words.size();++i){
    std::cout<<"      "<<repeated_words_number[i]<<"                     "<<unique_words[i]<<std::endl;}
    std::cout<<"\n";
    std::cout<<"-----------------------------------------"<<std::endl;
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
    std::cout << "Elapsed " << (1./1000.)*(elapsed.count())<< " [seconds]" << std::endl;
    return 0;
}