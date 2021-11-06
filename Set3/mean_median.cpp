#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstring>


int main(int argc, char *argv[]){

    std::vector<double> vect;
    std::string line;
    double sum{0},median{0};
    int counter{1};

    while(std::getline(std::cin,line)){
        double numb = std::stod(line);
        vect.push_back(numb);
        sum += std::stod(line);
        ++counter;
    }

    double average = sum/(counter - 1.0);
    std::sort(vect.begin(),vect.end());

    if(vect.size()% 2 != 0){
        median = vect[int((counter-1)*0.5)];
    }
    else{
        median = 0.5*(vect[int((counter-1)*0.5)-1] + vect[int((counter-1)*0.5)]);
    }

    std::cout<<"Average = "<<average<<"\n";
    std::cout<<"Median = "<<median<<std::endl;
    return 0;
}