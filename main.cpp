/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/30 01:48:45 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include <memory>
#include <iterator> // std::iterator, std::input_iterator_tag

using namespace std;

int main()
{
	ft::vector<int> b;
	// b.push_back(1);
	// b.push_back(2);
	// b.push_back(3);
	// b.push_back(4);
	// b.push_back(5);
	ft::vector<int>::const_iterator a = b.end();
	(void)a;
	// vector<int>::iterator k = b.end();
	// while (a != k) {
	// 	cout << *a++ << endl;
	// }
	
	// // std::cout << *k << std::endl;
	// int z = a - k;
	// std::cout <<z  << std::endl;

	return 0;
}
