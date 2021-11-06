#include <iostream>
#include <cstring>

int main(){

std::string line, line1;
unsigned int i{0};
	while(std::getline(std::cin,line))
	{
		if(i==0) line1 = line;

		if(line1==line)	++i;
		else
		{
		std::cout<<i<<' '<<line1<<std::endl;
		line1 = line;
		i = 1;
		}
	}
	if(i==0) std::cout<<"WARNING: empty file inserted \n"
			  <<"Please check input file"<<std::endl;
	else std::cout<<i<<' '<<line1<<std::endl;
return 0;
}
