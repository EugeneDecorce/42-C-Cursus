/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ScalarConverter.cpp								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: edecorce <edecorce@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/01 14:19:14 by edecorce		  #+#	#+#			 */
/*   Updated: 2024/08/01 14:19:35 by edecorce		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter deconstructor called" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	char char_value = '\0';
	int int_value = 0;
	float float_value = 0.0f;
	double double_value = 0.0;
	char* end;

	// Attempt to convert the literal to a double
	double_value = std::strtod(literal.c_str(), &end);

	// Convert to char
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
		char_value = literal[1];
		if (std::isprint(char_value))
			std::cout << "char: '" << char_value << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')) {
		int_value = static_cast<int>(double_value);
		if (int_value >= std::numeric_limits<char>::min() && int_value <= std::numeric_limits<char>::max()) {
			char_value = static_cast<char>(int_value);
			if (std::isprint(char_value))
				std::cout << "char: '" << char_value << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		} else {
			std::cout << "char: Impossible to convert" << std::endl;
		}
	} else {
		std::cout << "char: Impossible to convert" << std::endl;
	}

	// Convert to int
	if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')) {
		if (double_value >= std::numeric_limits<int>::min() && double_value <= std::numeric_limits<int>::max()) {
			int_value = static_cast<int>(double_value);
			std::cout << "int: " << int_value << std::endl;
		} else {
			std::cout << "int: Impossible to convert" << std::endl;
		}
	} else {
		std::cout << "int: Impossible to convert" << std::endl;
	}

	// Convert to float
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		float_value = static_cast<float>(double_value);
		std::cout << "float: " << float_value << "f" << std::endl;
	} else {
		float_value = static_cast<float>(double_value);
		std::cout << "float: " << float_value << "f" << std::endl;
	}

	// Convert to double
	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		std::cout << "double: " << double_value << std::endl;
	} else {
		std::cout << "double: " << double_value << std::endl;
	}
}