#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
	if(argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " Number List " << std::endl;
		return(1);
	}
	std::string input;
	if(argc == 2)
		input = std::string(argv[1]);
	else
	{
		for (int i = 1; i < argc; i++)
			input += std::string(argv[i]) + " ";
	}
	try{
		PmergeMe pmerge;
		std::vector<int> parsed;
		pmerge.Parse(parsed, input);
		std::cout << "Before: ";
		size_t size = pmerge.PrintContainer(parsed);
		pmerge.VectorSort(input);
		std::cout << "After: ";
		pmerge.PrintVector();
		std::cout << "Time to process a range of " << size << " elements with std::vector: " << pmerge.elapsed_time << "us\n";
		pmerge.DequeSort(input);
		std::cout << "Time to process a range of " << size << " elements with std::deque: " << pmerge.elapsed_time << "us\n";

	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return(0);
}
