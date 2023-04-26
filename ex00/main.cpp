/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:45:12 by amorion-          #+#    #+#             */
/*   Updated: 2023/04/26 10:45:15 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Invalid nummber of arguments\n";
	if (!strstr(argv[1], ".txt\0"))
		std::cout << "Invalid file extension" << std::endl;
	try
	{
		BitcoinExchange	data;
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
			std::cout << "Error: invalid file header: " << line << std::endl;
			file.close();
			return(1);
		}
		while(std::getline(file, line))
		{
			strdate = line.substr(0, line.find(" | "));
			amount = stof(line.substr().erase(0, line.find(" | ") + 3));
			if(!strptime(strdate.c_str(),"%Y-%m-%d", &date))
				std::cout << "Error: bad input => " << line << std::endl;
			else if(amount < 0)
				std::cout << "Error: Not a positive number.\n";
			else if (amount > 1000)
				std::cout << "Error: Too large a number.\n";
			else
				 data.Evaluate(mktime(&date), amount);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return(1);
	}
	return(0);
}
