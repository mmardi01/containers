/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/01/02 02:39:18 by mmardi           ###   ########.fr       */
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
	// unsigned int i;
	ft::vector<int> foo(3, 100); // three ints with a value of 100
	ft::vector<int> bar(5, 200); // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}