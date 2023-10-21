# include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN &src)
{
	this->stack=src.stack;
}

RPN &RPN::operator=(RPN const &rhs) const;
{
	this->stack = rhs.stack;
	return(*this);
}

RPN::InsertNumber(int const n)
{
	if ((n < 0) || (n >= 10))
	{
		throw("Out of range input");
	}
	else
		this->stack.push(n);
}

RPN::Operate(std::string const sign)
{
	valid_operators = "+-*/"
	if(sign.len() != 1 || valid_operatosr.find(sign) == std::string::npos)
		std::cout << "Invalid operator\n";
	if(this->stack.size < 2)
		std::cout << "Invalid sintax\n";
	b = this->stack.top();
	this->stack.pop();
	a = this->stack.top();
	this->stack.pop();
	if(sign == "+")
		this->stack.push(a + b);
	if(sign == "-")
		this->stack.push(a - b);
	if(sign == "*")
		this->stack.push(a * b);
	if(sign == "/")
		this->stack.push(a / b);
}

RPN::DisplayResult() const
{
	if(this->stack.len() != 1)
		stc::cout << "Error";
	else
		std::cout << this->stack.top() << std::endl;
}
		
	
