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
		
		RPN &operator=(RPN const &rhs) const;
		InsertNumber(int const n);
		Operate(std::string const sign);
		DisplayResult() const;

	private:
		std::stack<int> stack;

}
#endif
