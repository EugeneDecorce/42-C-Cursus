/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:57:21 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 15:09:43 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl = Harl();
	harl.complain("DEBUG");
	harl.complain("debug");
	harl.complain("INFO");
	harl.complain("info");
	harl.complain("WARNING");
	harl.complain("warning");
	harl.complain("ERROR");
	harl.complain("error");
	return (0);
}