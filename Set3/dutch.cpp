#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::cout<<"Number of elements in the array?"<<std::endl;  // defining initial values
    int N, i{0};
    double value, pivot;
    std::cin>>N;

    std::vector<double> vect{} ;                              // initializing the array
    std::cout<<"\n";
    std::cout<<"Insert array elements"<<std::endl;
    while(i<N){
        std::cin>>value;
        vect.push_back(value);
        ++i;
    }
    std::cout<<"\n";

    std::cout<<"Insert Pivot number"<<std::endl;            // checking if the pivot is in the array
    while(i!=0){
    std::cin>>pivot;
    std::cout<<"\n";
    if(std::find (vect.begin(), vect.end(), pivot) != vect.end()) break;
    std::cout<<"ERROR: wrong Pivot number"<<std::endl;
    std::cout<<"Please insert a Pivot number from the list"<<std::endl;
    }
    std::cout<<"\n";

    std::cout<<"Before Dutch's flag algorithm"<<std::endl;   // printing array before dutch algorithm
    for (auto i = 0u; i < vect.size(); ++i){
        std::cout << vect[i] << " ";
        }
    std::cout<<"\n";

    int pos_first_pivot;
    int counter{0};

    for(int i{0}; i<vect.size(); ++i){                      // here the algorithm starts 
        if(vect[i]>pivot){
            auto value = vect[i];
            vect.erase(vect.begin() + i);
            vect.insert(vect.end(), value);
        }
        if(vect[i]<pivot){
            auto value = vect[i];
            vect.erase(vect.begin() + i); 
            vect.insert(vect.begin(), value); 
            pos_first_pivot++;
        }
        if(vect[i]==pivot){
            if(counter==0){
                pos_first_pivot = i;
                counter = 1;
            }
            else{
                vect.erase(vect.begin() + i);
                vect.insert(vect.begin()+pos_first_pivot, pivot);
            }
                
        }
    }

    std::cout<<"\n";
    std::cout<<"After Dutch's flag algorithm"<<std::endl;   // printing array after dutch algorithm
    for (auto i = 0u; i < vect.size(); ++i){
        std::cout << vect[i] << " ";
        }
    std::cout<<"\n";

    return 0;
}