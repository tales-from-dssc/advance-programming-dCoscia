#include <iostream>
#include <cstring>

void get_double();
void get_int();

int main()
{
	unsigned int i{1};
	std::string line;
	while(i!=0)
	{
		std::cout<<"To get integers type: int \n\n"
	        	 <<"To get doubles type: double\n\n";
		std::getline(std::cin,line);

		if(line=="int")
		{	
		 std::cout<<"\n"<<"Insert numbers, the machine stops when an integer is inserted"
			  <<std::endl;
		 get_int();
		 break;
		}
	        if(line=="double")
                {
		 std::cout<<"\n"<<"Insert numbers, the machine stops when a double is inserted"
                          <<std::endl;
      		 get_double();
                 break;
		}
	std::cout<<"\n"<<"WARNING: wrong input, try again\n\n\n";
	std::cout<<"--------------------------------------------"<<std::endl;
	}
return 0;
}


void get_int(){
	double i;
	while(std::cin >> i)
	{
	if(i-int(i)==0) break;
	std::cin.clear();
        std::cin.ignore();
	}
	std::cout<<"INTEGER FOUND: "<<i<<std::endl;
}

void get_double(){
        double i;
        while(std::cin >> i)
        {
	if(i-int(i) != 0) break;
        std::cin.clear();
        std::cin.ignore();
        }
        std::cout<<"DOUBLE FOUND: "<<i<<std::endl;
}
