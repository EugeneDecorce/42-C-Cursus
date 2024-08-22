/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:58:50 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/05 15:59:00 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

bool isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

void performOperation(std::stack<int> &s, const std::string &operatorToken) {
	if (s.size() < 2) {
		throw std::runtime_error("Error: Invalid expression");
	}

	int b = s.top();
	s.pop();
	int a = s.top();
	s.pop();
	int result;

	if (operatorToken == "+") {
		result = a + b;
	} else if (operatorToken == "-") {
		result = a - b;
	} else if (operatorToken == "*") {
		result = a * b;
	} else if (operatorToken == "/") {
		if (b == 0) {
			throw std::runtime_error("Error: Division by zero");
		}
		result = a / b;
	} else {
		throw std::runtime_error("Error: Unknown operator");
	}

	s.push(result);
}

int evaluateRPN(const std::string &expression) {
	std::stack<int> s;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			performOperation(s, token);
		} else {
			try {
				int number = std::stoi(token);
				s.push(number);
			} catch (const std::invalid_argument &) {
				throw std::runtime_error("Error: Invalid token");
			}
		}
	}

	if (s.size() != 1) {
		throw std::runtime_error("Error: Invalid expression");
	}

	return s.top();
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
		return 1;
	}
	try {
		int result = evaluateRPN(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
