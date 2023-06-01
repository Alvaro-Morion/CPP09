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
void	PmergeMe::MergeSort(T &container)
{
	size_t size = container.size();
	if(size > 20)
	{
		typename T::iterator mid = container.begin() + size/2;
		T left(container.begin(), mid);
		T right(mid, container.end());
		MergeSort(left);
		MergeSort(right);
		typename T::iterator ridx = right.begin();
		typename T::iterator lidx = left.begin();
		for (typename T::iterator i=container.begin(); i < container.end(); i++)
		{
			if(ridx == right.end())
				*i = *lidx++;
			else if(lidx == left.end())
				*i = *ridx++;
			else if (*ridx > *lidx)
				*i = *lidx++;
			else
				*i = *ridx++;
		}
		return;
	}
	InsertionSort(container);
}

template <typename T>
void	PmergeMe::InsertionSort(T &container)
{
	for(size_t i = 0; i < container.size(); i++)
		std::rotate(std::upper_bound(container.begin(), container.begin() + i, container[i]),
			container.begin()+i, container.begin() + i + 1);

}

template <typename T>
void	PmergeMe::Sort(T &container, std::string input)
{
	clock_t t = clock();
	this->Parse(container, input);
	this->MergeSort(container);
	t = clock() - t;
	elapsed_time = (float)t*1000000/CLOCKS_PER_SEC;
	
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
