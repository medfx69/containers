#ifndef FT_HPP
#define FT_HPP
#include "vector.hpp"
#include <memory>


namespace ft{
	template<bool, class T>
	struct enable_if
	{};

	template <class T>
	struct enable_if<true, T>
	{
	    typedef T type;
	};
	template <class T, T v>
	struct integral_constant 
	{
	    typedef T value_type;
	    // typedef integral_constant<T,v> type;
	    static const T value = v;
	    // operator T() { return value; }
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template<typename T>
	struct is_integral : public false_type{};
	
	template<>
	struct is_integral<char> : public true_type{};
	template<>
	struct is_integral<int> : public true_type{};
	template<>
	struct is_integral<long> : public true_type{};
	template<>
	struct is_integral<short> : public true_type{};
	template<>
	struct is_integral<long long> : public true_type{};
	template<>
	struct is_integral<float> : public true_type{};
	template<>
	struct is_integral<double> : public true_type{};

	// template < class T, class Alloc = std::allocator<T> > class vector;
}
#endif