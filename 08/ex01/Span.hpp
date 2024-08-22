#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(int number);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const ;
		class SpanFullException : public std::exception {
			public:
				const char* what() const throw() {
					return "Span is full";
				}
		};
		class NotEnoughElementsException : public std::exception {
			public:
				const char* what() const throw() {
					return "Not enough elements in Span";
				}
		};
};

#endif
