#include <iostream>
#include <vector>
#include <utility>

template<typename T>
auto Build_Transpose(T& A, const int Ncol, const int Nrow){
    auto B = A;
    for(int i{0}; i<Nrow; ++i){
        for(int j{0}; j<Ncol; ++j){
            std::swap(B[j*Nrow+i], A[i*Ncol+j]);
        }
    }
    return B;
}

template<typename S>
void print_Matrix(const S& A, const int Ncol){
    int i{0};
    for (const auto& x : A){
        if(i<Ncol){
            std::cout << x << " ";
            ++i;
        }
        else{
            std::cout << "\n"; 
            std::cout << x << " ";
            i = 1;}      

    }
  std::cout << std::endl;
}

int main(int argc, char * argv[]){
    
    if(argc < 2){
       std::cout<<"Wrong input, please insert after the executable \n";
       std::cout<< "the number of rows and number of columns of the matrix"<< std::endl;
       exit(-1);
    }
    std::vector<double> A_matrix;
    int Ncol = std::stoi(argv[1]);
    int Nrow = std::stoi(argv[2]);

    for(int i{0}; i < Nrow*Ncol; ++i){
        A_matrix.push_back(i);}

    print_Matrix(A_matrix, Ncol);
    std::cout<<"\n";

    auto B = A_matrix;
    B = Build_Transpose(A_matrix, Ncol, Nrow);
    print_Matrix(B, B.size()/Ncol);
    return 0;
}