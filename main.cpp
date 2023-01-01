/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/01 03:17:06 by mmardi           ###   ########.fr       */
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
	// {
	// 	ft::vector<int> myvector;
	// 	myvector.push_back(1);
	// 	myvector.push_back(2);
	// 	myvector.push_back(3);
	// 	myvector.push_back(4);
	// 	myvector.push_back(5);
	// 	ft::vector<int>::reverse_iterator firs = myvector.rbegin();
	// 	ft::vector<int>::reverse_iterator end = myvector.rend();
	// 	ft::vector<int> second(firs, end);
	// 	for (size_t i = 0; i < second.size(); i++)
	// 	{
	// 		std::cout << second[i] << std::endl;
	// 	}
	// }
	{
		// std::allocator<int> a;
		// a.allocate(-1);
		std::vector<int> myvector(10);
		std::cout << " -- " <<myvector.capacity()<< std::endl;
		std::vector<int>::iterator firs = myvector.begin();
		myvector.insert(firs,15, 9);
		std::cout << myvector.capacity() << std::endl;
		for (size_t i = 0; i < myvector.capacity(); i++)
		{
			std::cout << myvector[i] << std::endl;
		}
		// std::cout << " -- " <<*firs << std::endl;
	}
}