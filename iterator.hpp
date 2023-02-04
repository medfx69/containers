#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <memory>
#include <iostream>
#include <iterator>

template<
    class Category,
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T&
	> struct iterator{
		    public:
				typedef Category iterator_category;
        		typedef T value_type;
        		typedef Distance difference_type;
        		typedef Pointer pointer;
        		typedef Reference reference;

		        iterator(){}
		        iterator(T* ptr){
		            mPtr = ptr;
		        }
		        iterator(const iterator& other) { mPtr = other.mPtr; }

		        iterator& operator++() {
		            mPtr++;
		            return *this;
		        }
		        iterator& operator--() {
		            mPtr--;
		            return *this;
		        }
		        iterator operator++(int) {
		            iterator temp(*this);
		            mPtr++;
		            return temp;
		        }
		        iterator operator--(int) {
		            iterator temp(*this);
		            mPtr--;
		            return temp;
		        }
		        T& operator*() {
		            return *mPtr;
		        }
		        T* operator->() {
		            return mPtr;
		        }
		        const T& operator*() const {
		            return *mPtr;
		        }
		        const T* operator->() const {
		            return mPtr;
		        }
		        bool operator==(const iterator& other) {
		            return mPtr == other.mPtr;
		        }
		        bool operator!=(const iterator& other) {
		            return mPtr != other.mPtr;
		        }
				bool operator<(const iterator& other) {
				    return mPtr < other.mPtr;
						}
				bool operator>(const iterator& other) {
				    return mPtr > other.mPtr;
				}
				bool operator<=(const iterator& other) {
				    return mPtr <= other.mPtr;
				}
				bool operator>=(const iterator& other) {
				    return mPtr >= other.mPtr;
				}
				iterator operator+(const int& n) {
				    return iterator(mPtr + n);
				}
				iterator operator-(const int& n) {
				    return iterator(mPtr - n);
				}
				size_t operator-(const iterator& n) {
				    return mPtr - n.mPtr;
				}
				iterator& operator+=(const int& n) {
				    mPtr += n;
				    return *this;
				}
				iterator& operator-=(const int& n) {
				    mPtr -= n;
				    return *this;
				}
				T& operator[](const int& index) {
				    return mPtr[index];
				}
			private:
			        T* mPtr;
		};
#endif