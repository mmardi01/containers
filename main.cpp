/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2022/12/29 01:13:19 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
#include <vector>
#include <memory>
int main() {
	{
		ft::vector<int> foo(10, 100);
		ft::vector<int> bar;
		std::cout << "foo capacity: " << foo.capacity() << " foo size: " << foo.size() << std::endl;
		std::cout << "bar capacity: " << bar.capacity() << " bar size: " << bar.size() << std::endl;
		foo.swap(bar);
		std::cout << "foo capacity: " << foo.capacity() << " foo size: " << foo.size() << std::endl;
		std::cout << "bar capacity: " << bar.capacity() << " bar size: " << bar.size() << std::endl;
		std::cout << bar[9];
		}
	// std::cout <<"\n__________________________________________\n" <<std::endl;
	// {
	// ft::vector<int> foo;
	// foo.back();
	// // ft::vector<int> bar(9, 2);
	// // std::cout << "capacity of bar: " << int(bar.capacity()) << '\n';
	// // std::cout << "Size of bar: " << int(bar.size()) << '\n';
	
	// // bar = foo;
	// // for (size_t i = 0; i < bar.size(); i++)
	// // {
	// // 	std::cout << bar[i] ;
	// // }
	
	// // std::cout << std::endl;
	// // // std::cout << "capacity of foo: " << int(foo.capacity()) << '\n';
	// // std::cout << "capacity of bar: " << int(bar.capacity()) << '\n';
	// // // std::cout << "Size of foo: " << int(foo.size()) << '\n';
	// // std::cout << "Size of bar: " << int(bar.size()) << '\n';
	// }
	return 0;
}