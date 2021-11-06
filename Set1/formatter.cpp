#include <iostream>
#include <cstring>

std::string Cut_string(std::string line,unsigned int counterStop);

int main(){
	
	std::string line;
	unsigned int counterStop{40};
	while(std::getline(std::cin,line))
	{	
		if(line.size()<=counterStop)
		{
			std::cout<<line<<std::endl; 
		}
		else
		{
		line = Cut_string(line,counterStop);
		std::cout<<line<<std::endl; 
		}
	}
	return 0;
}


std::string Cut_string(std::string line,unsigned int counterStop)
{
	char empty_str = ' ';
	std::string small_line, empty = " ";
	if(line[counterStop] == empty_str)
	{
		line.erase(line.begin()+counterStop,line.end());
		return line;
	}

	int first_blank_space = line.find(" ");
	if(first_blank_space>=counterStop)
	{
		return empty ;                                                                             // returning and empty space //
	}
	small_line = line.substr(0, first_blank_space);			// Getting everything before 'line' //
	return small_line;
}
