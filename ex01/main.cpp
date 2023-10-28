#include"RPN.hpp"
#include<cctype>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error\n";
		return(1);
	}
	std::string line(argv[0]);
	RPN rpn;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		std::string substr;
		if(*it == ' ')
		{}
		else if(isdigit(*it))
		{
			while(isdigit(*it))
			{
				substr += *it;
				it++;
			}
			if(*it != ' ')
			{
				std::cerr << "Error\n";
				return(1);
			}
			try
			{
				rpn.InsertNumber(atoi(substr));
			}
			catch std::exception &e
			{
				std::cerr << "Error\n";
				return(1);
			}
		}
		else
		{
			while(*it != ' ')
			{
				substr += *it;
				it++;
			}
			try
			{
				rpn.operate(substr);
			}
			catch std::exception &e
			{
				std::cerr << "Error\n";
				return(1);
			}
		}
	try
	{
		rpn.DisplayResult();
	}
	catch std::exception &e
	{	
		std::cerr << "Error\n";
		return(1);
	}
	return(0)
}
