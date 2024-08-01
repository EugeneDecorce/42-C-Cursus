/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:16:05 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/01 15:25:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";

	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);

	if (deserializedData == &originalData) {
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
	} else {
		std::cout << "Deserialization failed!" << std::endl;
	}

	return 0;
}
