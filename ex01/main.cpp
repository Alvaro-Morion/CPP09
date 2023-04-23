/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:15:22 by amorion-          #+#    #+#             */
/*   Updated: 2023/04/23 12:17:01 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stack>
#include<string>
#include<iostream>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error\n";
		return(1);
	}
	std::stack<int> rpn;
	std::string	line(argv[1]);
	try
	{
		int num;
		std::string n;

		for (std::string::iterator it = line.begin(), end = line.end(); it != end; ++it)
		{
			while(isspace(*it))
				it++;
			if(isdigit(*it))
			{
				n = "";
				while(isdigit(*it))
				{
					n += *it;
					it++;
				}
				if(n.length() != 1)
				{
					std::cout << "Error\n";
					return(1);
				}
				else
					rpn.push(std::atoi(n.c_str()));
			}
			else if(rpn.size >= 2 && (*it == '-' || *it == '+' || *it == '*' || *it == '/'))
			{
				switch(*it)
				{
					case '+':
						num = rpn.top();
						rpn.pop();
						num += rpn.top();
						rpn.pop();
						rpn.push(num);
						break;
					case '-':
						num = rpn.top();
						rpn.pop();
						num = rpn.top() - num;
						rpn.pop();
						rpn.push(num);
						break;
					case '*':
						num = rpn.top();
						rpn.pop();
						num *= rpn.top();
						rpn.pop();
						rpn.push(num);
						break;
					case '/':
						num = rpn.top();
						rpn.pop();
						num /= rpn.top();
						rpn.pop();
						rpn.push(num);
						break;
				}
			}
			else
			{
				std::cout << "Error\n";
				return(1);
			}
		}
		if(rpn.size() == 1)
		{
			std::cout << rpn.top();
			return(0);
		}
		else
		{
			std::cout << "Error\n";
			return(1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(1);
	}
	
}
