/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:19:56 by amorion-          #+#    #+#             */
/*   Updated: 2023/10/28 18:04:30 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN &src)
{
	this->stack=src.stack;
}

RPN 	&RPN::operator=(RPN const &rhs)
{
	this->stack = rhs.stack;
	return(*this);
}

RPN::~RPN()
{}

void	RPN::InsertNumber(int const n)
{
	if ((n < 0) || (n >= 10))
		throw(std::exception());
	else
		this->stack.push(n);
}

void	RPN::Operate(std::string const sign)
{
	std::string valid_operators("+-*/");
	if(sign.size() != 1 || valid_operators.find(sign) == std::string::npos)
		throw(std::exception());
	if(this->stack.size() < 2)
		throw(std::exception());
	int a, b;
	b = this->stack.top();
	this->stack.pop();
	a = this->stack.top();
	this->stack.pop();
	switch(sign[0])
	{
		case('+'):
			this->stack.push(a + b);
			break;
		case('-'):
			this->stack.push(a - b);
			break;
		case('*'):
			this->stack.push(a * b);
			break;
		case('/'):
			this->stack.push(a / b);
			break;
	}
}

void	RPN::DisplayResult() const
{
	if(this->stack.size() != 1)
		throw(std::exception());
	else
		std::cout << this->stack.top() << std::endl;
}
		
	
