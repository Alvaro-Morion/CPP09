#include "./DataSource.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Invalid nummber of arguments\n";
	if (!strstr(argv[1], ".txt\0"))
		std::cerr << "Invalid file extension" << std::endl;
	
	try
	{
		DataSource	data;
		//std::cout << data << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(1);
	}
	return(0);
}