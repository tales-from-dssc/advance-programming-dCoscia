#include <iostream>
#include <cmath>

int main(){

    std::cout<<"Value of N?"<<std::endl;
    int N;
    std::cin>>N;
    bool A[N-1];

    for(int i{0}; i<N-1; ++i)
    {
        A[i] = true;
    }                                           

    int j = 0, s = 0, i_star = 0;

    for(int i{0}; i<int(std::sqrt(N)); ++i)
    {
        if(A[i])
        {
            i_star = i + 2;
            j = i_star*i_star;
            s = 1;
            while(j<=N)
            {
                A[j-2] = false;
                j = i_star*i_star + s*i_star;
                ++s;
            }
        }
    }

    std::cout<<"PRIMES"<<std::endl;
    for(int i{0}; i<N-1; ++i)
    {
        if(A[i]) std::cout<<i+2<<std::endl;
    }
    
    return 0;
}