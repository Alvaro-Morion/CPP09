#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	this->vector = src.vector;
	this->deque = src.deque;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	this->vector = rhs.vector;
	this->deque = rhs.deque;
	return(*this);
}

template <typename T>
void	PmergeMe::Parse(T &container, std::string input)
{
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); )
	{
		if(line.length() > 0)
		{
			try{
				int n = std::atoi(line.c_str());
				if(n < 0)
					throw NegativeException();
				container.push_back(n);
			}
			catch (const std::invalid_argument &ex){
				throw InvalidArgumentException();
			}
		}
	}
	if(container.size() == 0)
		throw EmptyException();
}

template <typename T>
size_t	PmergeMe::PrintContainer(T &container)
{
	size_t size = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); it++, size++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return(size);
}

size_t	PmergeMe::PrintVector(void)
{
	return(PrintContainer(this->vector));
}

size_t	PmergeMe::PrintDeque(void)
{
	return(PrintContainer(this->deque));
}

template <typename T>
T	PmergeMe::MergeInsertionSort(T &container)
{
	T b;
	T a;
	for (typename T::iterator iter = container.begin();	iter < container.end(); iter = iter + 2)
	{
		if ((iter + 1) == container.end())
			b.push_back(*iter);
		else if (*iter < *(iter + 1))
		{
			a.push_back(*iter);
			b.push_back(*(iter + 1));
		}
		else
		{
			b.push_back(*iter);
			a.push_back(*(iter + 1));
		}
	}
	if(a.size() > 1)
		a = MergeInsertionSort(a);
	typename T::iterator iter;
	while(b.size())
	{
		iter = a.begin();
		while(iter != a.end() && *iter <= b.back())
			iter++;
		a.insert(iter, b.back());
		b.pop_back();
	}
	return(a);

}

template <typename T>
void	PmergeMe::Sort(T &container, std::string input)
{
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	this->Parse(container, input);
	container = this->MergeInsertionSort(container);
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
}

void	PmergeMe::VectorSort(std::string input)
{
	Sort(this->vector, input);
}

void	PmergeMe::DequeSort(std::string input)
{
	Sort(this->deque, input);
}

const char *PmergeMe::NegativeException::what() const throw()
{
	return("Error:\nNegative Argument\n");
}

const char *PmergeMe::EmptyException::what() const throw()
{
	return("Error:\nEmpty Container\n");
}

const char *PmergeMe::InvalidArgumentException::what() const throw()
{
	return("Error:\nInvalid Argument\n");
}
