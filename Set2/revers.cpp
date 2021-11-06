#include <iostream>

template <typename T>
void PrintReverseArray(T arr, std::size_t N);

int main(){

	std::cout<<"Dimension of array?"<<std::endl;
	std::size_t N;
	std::cin>>N;
	double* array{new double[N]};  // allocated on the HEAP, or free-store

	std::cout<<"Insert array"<<std::endl;

	for(std::size_t i{0}; i<N; ++i)
	{
		std::cin>>array[i];
	}

	std::cout<<"Reverse array"<<std::endl;
	PrintReverseArray(array,N);

	delete[] array;			// free the memory

	return 0;
}



void PrintReverseArray(T arr, std::size_t N){	

	for(std::size_t i{1}; i <= N; ++i)
	{
		std::cout<<*(arr+N-i)<<std::endl;
	}
}
