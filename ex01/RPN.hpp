#ifndef RPN_HPP
# define RPN_HPP
# include<stack>
# include<string>
# include<iostream>

class RPN
{
	public:
		RPN();
		RPN(RPN &src);

		~RPN();
		
		RPN 	&operator=(RPN const &rhs);
		
		void	InsertNumber(int const n);
		void	Operate(std::string const sign);
		void	DisplayResult() const;

	private:
		std::stack<int> stack;

};
#endif
