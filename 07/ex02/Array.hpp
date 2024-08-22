/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Array.hpp										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: edecorce <edecorce@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/01 19:50:57 by edecorce		  #+#	#+#			 */
/*   Updated: 2024/08/01 19:53:38 by edecorce		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
	private:
		T* data;
		unsigned int length;

	public:
		Array() : data(nullptr), length(0) {}
		Array(unsigned int n) : data(new T[n]()), length(n) {}
		Array(const Array& other) : data(new T[other.length]), length(other.length) {
			for (unsigned int i = 0; i < length; ++i) {
				data[i] = other.data[i];
			}
		}
		~Array() {
			delete[] data;
		}
		Array& operator=(const Array& other) {
			if (this == &other) return *this;

			delete[] data;

			length = other.length;
			data = new T[length];
			for (unsigned int i = 0; i < length; ++i) {
				data[i] = other.data[i];
			}

			return *this;
		}
		T& operator[](unsigned int index) {
			if (index >= length) {
				throw std::out_of_range("Index out of bounds");
			}
			return data[index];
		}
		const T& operator[](unsigned int index) const {
			if (index >= length) {
				throw std::out_of_range("Index out of bounds");
			}
			return data[index];
		}
		unsigned int size() const {
			return length;
		}
};

#endif
