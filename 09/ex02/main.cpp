#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Fonction pour valider et convertir les arguments en entiers positifs
std::vector<int> parseArguments(int argc, char* argv[]) {
	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i) {
		int number;
		try {
			number = std::stoi(argv[i]);
			if (number < 0) {
				throw std::invalid_argument("Negative number");
			}
			numbers.push_back(number);
		} catch (const std::invalid_argument&) {
			throw std::runtime_error("Error: Invalid input");
		}
	}
	return numbers;
}

// Merge sort adapté pour std::deque
void mergeSortDeque(std::deque<int>& deq) {
	if (deq.size() <= 1) return;

	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

	mergeSortDeque(left);
	mergeSortDeque(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

// Merge sort adapté pour std::list
void mergeSortList(std::list<int>& lst) {
	if (lst.size() <= 1) return;

	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator it = lst.begin();
	std::advance(it, lst.size() / 2);

	left.splice(left.begin(), lst, lst.begin(), it);
	right.splice(right.begin(), lst, lst.begin(), lst.end());

	mergeSortList(left);
	mergeSortList(right);

	lst.merge(left);
	lst.merge(right);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	try {
		numbers = parseArguments(argc, argv);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	// Afficher la séquence avant le tri
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Trier avec std::deque et mesurer le temps
	std::deque<int> deq(numbers.begin(), numbers.end());
	std::clock_t startDeque = std::clock();
	mergeSortDeque(deq);
	std::clock_t endDeque = std::clock();
	double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

	// Trier avec std::list et mesurer le temps
	std::list<int> lst(numbers.begin(), numbers.end());
	std::clock_t startList = std::clock();
	mergeSortList(lst);
	std::clock_t endList = std::clock();
	double durationList = 1000000.0 * (endList - startList) / CLOCKS_PER_SEC;

	// Afficher la séquence après le tri (en utilisant std::deque pour la sortie)
	std::cout << "After: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Afficher le temps pris par chaque conteneur
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque: " 
			  << durationDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::list: " 
			  << durationList << " us" << std::endl;

	return 0;
}
