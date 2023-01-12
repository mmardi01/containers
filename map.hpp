#ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include "pair.hpp"
#include "redBlackTree.hpp";
template <class Key,class T,class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map{
	public:
		typedef Key 										key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type,T> 					value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef std::ptrdiff_t 								difference_type;
		typedef size_t										size_type;
	private:
		
		
};
#endif