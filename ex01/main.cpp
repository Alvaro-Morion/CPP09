/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:20:25 by amorion-          #+#    #+#             */
/*   Updated: 2023/10/28 18:04:27 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"
#include<cctype>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error\n";
		return(-1);
	}
	std::string line(argv[1]);
	RPN rpn;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		std::string substr;
		if(*it == ' ')
			continue;
		else if(isdigit(*it))
		{
			if(it + 1 != line.end() && *(it + 1) != ' ')
			{
				std::cerr << "Error\n";
				return(1);
			}
			substr += *it;
			try
			{
				rpn.InsertNumber(atoi((substr.c_str())));
			}
			catch (std::exception &e)
			{
				std::cerr << "Error\n";
				return(2);
			}
		}
		else
		{
			if (it + 1 != line.end() && *(it + 1) != ' ')
			{
				std::cerr << "Error\n";
				return(3);
			}
			substr += *it;
			try
			{
				rpn.Operate(substr);
			}
			catch (std::exception &e)
			{
				std::cerr << "Error\n";
				return(4);
			}
		}
	}
	try
	{
		rpn.DisplayResult();
	}
	catch (std::exception &e)
	{	
		std::cerr << "Error\n";
		return(5);
	}
	return(0);
}
