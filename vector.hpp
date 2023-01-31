#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include "ft.hpp"




template < class T, class Alloc = std::allocator<T> > class vector{
	private:
		T *v_data;
		Alloc alloc;
		size_t v_size;
		size_t v_capacity;
	public:
		class iterator
		{
		    public:
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
		class reverse_iterator {
    		public:
    		    reverse_iterator() {}
    		    reverse_iterator(T* ptr) : mPtr(ptr) {}
    		    reverse_iterator(const reverse_iterator& other) : mPtr(other.mPtr) {}
    		    reverse_iterator(const iterator& other) : mPtr(other.mPtr) {}
    		    reverse_iterator& operator++() {
    		        --mPtr;
    		        return *this;
    		    }
    		    reverse_iterator& operator--() {
    		        ++mPtr;
    		        return *this;
    		    }
    		    reverse_iterator operator++(int) {
    		        reverse_iterator temp(*this);
    		        --mPtr;
    		        return temp;
    		    }
    		    reverse_iterator operator--(int) {
    		        reverse_iterator temp(*this);
    		        ++mPtr;
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
    		    bool operator==(const reverse_iterator& other) {
    		        return mPtr == other.mPtr;
    		    }
    		    bool operator!=(const reverse_iterator& other) {
    		        return mPtr != other.mPtr;
    		    }
    		    bool operator<(const reverse_iterator& other) {
    		        return mPtr > other.mPtr;
    		    }
    		    bool operator>(const reverse_iterator& other) {
    		        return mPtr < other.mPtr;
    		    }
    		    bool operator<=(const reverse_iterator& other) {
    		        return mPtr >= other.mPtr;
    		    }
    		    bool operator>=(const reverse_iterator& other) {
					return mPtr <= other.mPtr;
				}
				reverse_iterator operator+(const int& n) {
				return reverse_iterator(mPtr - n);
				}
				reverse_iterator operator-(const int& n) {
				return reverse_iterator(mPtr + n);
				}
				reverse_iterator& operator+=(const int& n) {
				mPtr -= n;
				return *this;
				}
				reverse_iterator& operator-=(const int& n) {
				mPtr += n;
				return *this;
				}
				T& operator[](const int& index) {
				return (mPtr - index);
				}
			private:
				T mPtr;
		};
		typedef const iterator const_iterator;
		typedef T& reference;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef const T& const_reference;
		typedef const reverse_iterator const_reverse_iterator;
		vector::iterator begin() { return vector::iterator(v_data); }
		vector::iterator end()   { return vector::iterator(&v_data[v_size - 1]); } 
		vector::const_iterator begin() const{ return vector::const_iterator(&v_data[0]); }
		vector::const_iterator end()   const{ return vector::const_iterator(&v_data[v_size - 1]); } 
		vector::reverse_iterator begin(T) { return vector::const_reverse_iterator(&v_data[v_size - 1]); }
		vector::reverse_iterator end(T)   { return vector::const_reverse_iterator(&v_data[0]); } 
		vector::const_reverse_iterator begin(T)const { return vector::const_reverse_iterator(&v_data[v_size - 1]); }
		vector::const_reverse_iterator end(T)  const { return vector::const_reverse_iterator(&v_data[0]); } 

	// // constractors -----------------------------------------------------------------------------------------------------------
		explicit vector(){
			v_data = this->alloc.allocate(1);
			this->alloc.construct(v_data, 0);
			v_size = 0;
			v_capacity = 1;
		}
		explicit vector (size_type n, const value_type& val = value_type(),  const allocator_type& alloc = allocator_type()){
			(void) alloc;
			v_data = this->alloc.allocate(n * 10);
			for(size_t i = 0; i < n ; i++){
				this->alloc.construct(v_data + i, val);
			}
			v_size = n;
			v_capacity = n * 10;
		}
		template <class InputIterator> 
		vector (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, allocator_type>::type = allocator_type()){
		    InputIterator tmp;

		    v_size = std::distance(&first, &last);
			v_data = this->alloc.allocate(v_size * 10);
		    v_capacity = v_size * 10;
		    for (size_type t1 = 0; first <= last; t1++, first++){
		    	alloc.construct(v_data + t1, *first);
		    }
		}
		vector(const vector& x){
			size_t i = 0;
			vector::iterator it = x.begin();

			v_data = alloc.allocate(x.size() * 10);
			v_size = x.size();
			v_capacity = x.size();
			for (it ; it < x.end(); it++, i++)
				alloc.construct(v_data + i, *it);
		}
	// // -----------------------------------------------------------------------------------------------------------


	
	// destractors -----------------------------------------------------------------------------------------------------------
		~vector(){
			for (size_type i = 0; i < v_capacity; i++)
				this->alloc.destroy(v_data + i);
			this->alloc.deallocate(v_data, v_capacity);
		}
	// ---------------------------------------------------------------------------------------------------------
	
	// // member functions  -----------------------------------------------------------------------------------------------------------
		size_t size(){
			return v_size;
		}
		template <class InputIterator> 
		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, allocator_type >::type = allocator_type()){
			InputIterator tmp;

			v_size = std::distance(&first, &last);

			if (v_capacity < v_size){
				for (size_type i = 0; i < v_capacity; i++)
					this->alloc.destroy(v_data + i);
				this->alloc.deallocate(v_data, v_capacity);
				v_data = this->alloc.allocate(v_size * 1.5);
				v_capacity = v_size * 1.5;
			}
			for (int i = 0; first <= last; i++, first++)
				alloc.construct(v_data + i, *first);
		}
		void assign(size_t n, T t){
			if (v_capacity < n){
				for (size_type i = 0; i < v_capacity; i++)
					this->alloc.destroy(v_data + i);
				this->alloc.deallocate(v_data, v_capacity);
				v_data = this->alloc.allocate(n * 1.5);
				v_capacity = n * 1.5;
			}
			for(size_t i = 0; i < n ; i++){
				this->alloc.construct(v_data + i, t);
			}
			v_size = n;
		}
		reference at(size_type n){
			return &v_data[n];
		}
		const_reference at(size_type n) const{
			return &v_data[n];
		}
		reference back(){
			return &v_data[v_size -1];
		}
		const_reference back() const{
			return &v_data[v_size -1];
		}
		size_type capacity() const{
			return v_capacity;
		}
		void clear(){
			for (size_type i = 0; i < v_capacity; i++)
				alloc.destroy(v_data + i);
			alloc.deallocate(v_data, v_capacity);
			v_size = 0;
			v_capacity = 0;
		}
		bool empty() const{
			if (v_size == 0)
				return true;
			return false;
		}
		vector::iterator erase (vector::iterator position){
			while (position < this->end()){
				*position = *(position + 1);
				position++;
			}
		}
		vector::iterator erase (vector::iterator first, vector::iterator last){
			while (last < this->end()){
				*first = *last;
				last++;
				first++;
			}
		}
		reference front(){
			return &v_data[0];
		}
		const_reference front() const{
			return &v_data[0];
		}
		allocator_type get_allocator() const{
			return alloc;
		}
		vector::iterator insert (vector::iterator position, const value_type& val){
			vector::iterator t1;

			if (v_size + 1 > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + 1) * 1.5);
				for (int i = 0; i < v_size; i++)
					alloc.construct(tmp +i, *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity   + 1) * 1.5;
				v_data = tmp;
			}
			alloc.construct(this->end() + 1, *this->end());
			for (t1 = this->end(); position < t1; t1--)
				*t1 = *(t1 - 1);
			*t1 = val;
			v_size++;
			return position;
		}
		void insert (iterator position, size_type n, const value_type& val){
			vector::iterator t1;

			if (v_size + n > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + n) * 1.5);
				for (int i = 0; i < v_size; i++)
					alloc.construct(tmp + i, *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity + n) * 1.5;
				v_data = tmp;
			}
			for (t1 = this->end(); position < t1; t1--){
				if (t1 + n >  this->end())
					alloc.construct(t1 + n, *t1);
				else
					*(t1 + n) = *t1;
			}
			while (t1 < position + n){
				*t1 = val;
				t1++;
			}
			v_size += n;
		}
		template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, allocator_type>::type =  allocator_type()){
			int n = 0;
			vector::iterator t1;

			n = std::distance(&first, &last);
			if (v_size + n > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + n) * 1.5);
				for (int i = 0; i < v_size; i++)
					alloc.construct(tmp + i, *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity + n) * 1.5;
				v_data = tmp;
			}
			for (t1 = this->end(); position < t1; t1--)
				alloc.construct(t1 + n, *t1);
			while (first < last){
				*t1 = *first;
				t1++;
				first++;
			}
			v_size += n;
			
		}
		size_type max_size() const{
			return v_capacity;
		}
		size_type size() const{
			return v_size;
		}
		reference operator[] (size_type n){
			return *(v_data + n);
		}
		const_reference operator[] (size_type n) const{
			return *(v_data + n);
		}
		vector& operator=(const vector& x){
			vector::iterator t1;
			vector::iterator t2;


			for (size_type i = 0; i < v_capacity; i++)
				alloc.destroy(v_data + i);
			alloc.deallocate(v_data, v_capacity);
			v_data = alloc.allocate(x.capacity());
			v_capacity = x.capacity();
			for (t1 = x.begin(), t2 = this->begin(); t1 <= x.end(); t1++, t2++)
				alloc.construct(t2, *t1);
			v_size = x.size();
			return *this;
		}
		void pop_back(){
			v_size--;
		}
		void push_back (const value_type& val){
			if (v_size + 1 > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + 1) * 1.5);
				for (int i = 0; i < v_size; i++)
					tmp[i] = v_data[i];
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity   + 1) * 1.5;
				v_data = tmp;
			}
			alloc.construct(v_data + v_size, val);
			v_size++;
		}
		reverse_iterator rbegin(){
			return v_data[v_size - 1];
		}
		const_reverse_iterator rbegin() const{
			return v_data[v_size - 1];
		}
		reverse_iterator rend(){
			return v_data[0];
		}
		const_reverse_iterator rend() const{
			return v_data[0];
		}
		void reserve (size_type n){
			for (size_type i = 0; i < v_capacity; i++)
				alloc.destroy(v_data + i);
			alloc.deallocate(v_data, v_capacity);
			v_data = alloc.allocate(n);
			v_capacity = n;
			v_size = 0;
		}
		void resize (size_type n, value_type val = value_type()){
			if (v_size > n){
				v_size = n;
				return ;
			}
			if (n > v_capacity){
				T* tmp;
				tmp = alloc.allocate(n * 1.5);
				for (int i = 0; i < v_size; i++)
					alloc.construct(tmp + i, v_data[i]);
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = n * 1.5;
				v_data = tmp;
			}

			for (int i = v_size; i < n ; i++)
				alloc.construct(v_data + i, val);
			v_size = n;
		}

		void swap (vector& x){
			vector tmp;

			tmp = x;
			x = this;
			this = tmp;
		}
	// // -----------------------------------------------------------------------------------------------------------

};




#endif