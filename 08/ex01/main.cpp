#include "Span.hpp"

int main() {
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span bigSpan(10000);
		for (int i = 0; i < 10000; ++i) {
			bigSpan.addNumber(rand());
		}
		std::cout << "Shortest Span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in bigSpan: " << bigSpan.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span rangeSpan(10);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(8);
		vec.push_back(9);
		vec.push_back(10);
		rangeSpan.addNumber(vec.begin(), vec.end());

		std::cout << "Shortest Span in rangeSpan: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span in rangeSpan: " << rangeSpan.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}


// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }