/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/31 03:15:40 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "reverse_iterator.hpp"
#include <vector>
# include <cstdlib>
#include <memory>
#include <iterator> // std::iterator, std::input_iterator_tag
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myvector(100,5);
	std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << myvector[i];
	}
	
	myvector.resize(10);
	std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << myvector[i];
	}
	myvector.shrink_to_fit();
	std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
	for (size_t i = 0; i < 100; i++)
	{
		std::cout <<" " <<myvector[i];
	}
	return 0;
}
