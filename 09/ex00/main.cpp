/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:34:50 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/05 15:34:54 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>

std::map<std::string, float> loadData(const std::string &filename) {
	std::map<std::string, float> data;
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, priceStr;
		if (std::getline(iss, date, ',') && std::getline(iss, priceStr)) {
			try {
				float price = std::stof(priceStr);
				data[date] = price;
			} catch (const std::invalid_argument &) {
				// Invalid price, skip this line
				continue;
			}
		}
	}

	file.close();
	return data;
}

bool isValidDate(const std::string &date) {
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	// Simple check for valid YYYY-MM-DD format
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
	return true;
}

void processInputFile(const std::string &filename, const std::map<std::string, float> &data) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, valueStr;
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
			// Remove extra spaces
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

			if (!isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			try {
				float value = std::stof(valueStr);
				if (value < 0 || value > 1000) {
					std::cerr << "Error: not a positive number." << std::endl;
					continue;
				}

				std::map<std::string, float>::const_iterator it = data.lower_bound(date);
				if (it == data.end() || it->first != date) {
					if (it == data.begin()) {
						std::cerr << "Error: no valid data for the given date." << std::endl;
						continue;
					}
					--it;
				}

				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			} catch (const std::invalid_argument &) {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}

	file.close();
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	try {
		std::map<std::string, float> data = loadData("data.csv");
		processInputFile(argv[1], data);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
