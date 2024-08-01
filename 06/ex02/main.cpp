/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:32:49 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/01 15:34:41 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
	Base* p = generate();
	identify(p);
	identify(*p);

	delete p;
	return 0;
}