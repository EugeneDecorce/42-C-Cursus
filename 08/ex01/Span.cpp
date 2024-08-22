/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:10:38 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/05 14:13:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize(0) {}

// Parameterized constructor
Span::Span(unsigned int N) : maxSize(N) {}

// Copy constructor
Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

// Assignment operator
Span& Span::operator=(const Span &other) {
	if (this != &other) {
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

// Destructor
Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize) {
		throw SpanFullException();
	}
	numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (numbers.size() + std::distance(begin, end) > maxSize) {
		throw SpanFullException();
	}
	numbers.insert(numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw NotEnoughElementsException();
	}
	std::vector<int> sortedNumbers(numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw Span::NotEnoughElementsException();
	}
	int minElement = *std::min_element(numbers.begin(), numbers.end());
	int maxElement = *std::max_element(numbers.begin(), numbers.end());
	return maxElement - minElement;
}