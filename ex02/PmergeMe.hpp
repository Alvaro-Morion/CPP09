#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <algorithm>

class	PmergeMe
{
	private:
		std::vector<int>	vector;
		std::deque<int>	deque;

		template <typename T>
			void	InsertionSort(T &container);
		template <typename T>
			void	MergeSort(T &container);
		template <typename T>
			void	Sort(T &container, std::string input);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
	
		PmergeMe	&operator=(PmergeMe const &rhs);

		void	VectorSort(std::string input);
		void	DequeSort(std::string input);

		template <typename T> 
			size_t	PrintContainer(T &container);
		
		size_t	PrintVector(void);
		size_t	PrintDeque(void);

		template <typename T>
			void	Parse(T &container, std::string input);
		
		double	elapsed_time;
		~PmergeMe();

		class NegativeException : public std::exception
		{
			public: const char *what() const throw();
		};
		class EmptyException : public std::exception
                {
			public: const char *what() const throw();
                };
		class InvalidArgumentException: public std::exception
		{
        		public: const char *what() const throw();
    		};
};
#endif
