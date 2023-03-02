/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:28 by mmardi            #+#    #+#             */
/*   Updated: 2023/03/01 18:59:06 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "src/vector.hpp"
# include "src/set.hpp"
# include <vector>
# define _ratio 10000

class   test {
    public:
    test () {std::cout << "TEST CONSTRUCTOR\n";}
};

int main() {
// {
//     std::vector<int> v;
//     std::vector<int> vector;
//     vector.assign(1100 * _ratio, 11);
//     std::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     long *adr1 = reinterpret_cast<long *>(&vector);
//     long *adr2 = reinterpret_cast<long *>(&tmp);
//     vector.swap(tmp);
//     if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
//     	v.push_back(1);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.swap(tmp3);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp2);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp4);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         std::cout << v[i] << std::endl;
//     }
// }
//     std::cout << "\n////////////////////////////////////////////\n";
// {
//      std::vector<int> v;
//     ft::vector<int> vector;
//     vector.assign(1100 * _ratio, 11);
//     ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     long *adr1 = reinterpret_cast<long *>(&vector);
//     long *adr2 = reinterpret_cast<long *>(&tmp);
//     vector.swap(tmp);
//     if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
//     	v.push_back(1);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.swap(tmp3);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::cout << "__" << tmp2.size() << std::endl;
//     std::cout << "_._" << vector.size() << std::endl;
//     std::cout << "__" << tmp2.capacity() << std::endl;
//     std::swap(vector, tmp2);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     std::swap(vector, tmp4);
//     v.push_back(vector[2]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         std::cout << v[i] << std::endl;
//     }        
// }
    // std::vector<int> a;
    // std::vector<int> b;
    
    // a.push_back(1);
    // b.push_back(1);
    // b.push_back(1);
    // b.push_back(1);
    // std::cout << b.size() << std::endl;
    // std::cout << b.capacity() << std::endl;
    // b = a;
    // std::cout << b.size() << std::endl;
    // std::cout << b.capacity() << std::endl;
    ft::vector<test> vec(10);
}