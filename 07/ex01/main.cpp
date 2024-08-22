#include "iter.hpp"

// Example functions to be used with iter
void printInt(const int& x) {
	std::cout << x << " ";
}

void printDouble(const double& x) {
	std::cout << x << " ";
}

template <typename T>
void printElement(const T& x) {
	std::cout << x << " ";
}

int main() {
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Integer array: ";
	iter(intArray, intArrayLength, printInt);
	std::cout << std::endl;

	// Test with an array of doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Double array: ";
	iter(doubleArray, doubleArrayLength, printDouble);
	std::cout << std::endl;

	// Test with an array of strings using a template function
	std::string strArray[] = {"hello", "world", "iter", "template"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	iter(strArray, strArrayLength, printElement<std::string>);
	std::cout << std::endl;

	// Test with a const array
	const int constIntArray[] = {10, 20, 30, 40, 50};
	size_t constIntArrayLength = sizeof(constIntArray) / sizeof(constIntArray[0]);

	std::cout << "Const integer array: ";
	iter(constIntArray, constIntArrayLength, printInt);
	std::cout << std::endl;

	return 0;
}