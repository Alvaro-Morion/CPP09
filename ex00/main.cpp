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
		std::ifstream file(argv[1], std::ifstream::in);
		
		if(!file.good())
		{
			std::cerr << "Error: could not open file " << argv[1] << std::endl;
			return(1);
		}
		
		std::string line;
		std::string	strdate;
		float		amount;
		std::tm		date = {0,0,0,0,0,0,0,0,0,0,0};

		std::getline(file, line);
		if(line != "date | value")
		{
			std::cerr << "Error: invalid file header: " << line << std::endl;
			file.close();
			return(1);
		}
		while(std::getline(file, line))
		{
			strdate = line.substr(0, line.find(" | "));
			amount = stof(line.substr().erase(0, line.find(" | ") + 3));
			if(!strptime(strdate.c_str(),"%Y-%m-%d", &date))
				std::cerr << "Error: bad input => " << line << std::endl;
			else if(amount < 0)
				std::cerr << "Error: Not a positive number\n";
			else if (amount > 1000)
				std::cerr << "Error: Too large a number\n";
			else
			{
				std::cout << std::put_time(&date, "%c") << std::endl;
				 data.Evaluate(mktime(&date), amount);
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(1);
	}
	return(0);
}