#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>


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
				iterator(T* ptr){
					mPtr = ptr;
				}
			    iterator& operator++(){
				    this->mPtr++;
				    return *this;
				}
			    iterator& operator--()
				{
				    this->mPtr--;
				    return *this;
				}

			    iterator operator++(int){
				    iterator temp = *this;
				    this->mPtr++;
				    return temp;
				}
			    iterator operator--(int){
				    iterator temp = *this;
				    this->mPtr--;
				    return temp;
				}
			    T& operator*(){
				    return *this->mPtr;
				}
			    bool operator==(const iterator& iter){
				    return this->mPtr == iter.mPtr;
				}
			    bool operator!=(const iterator& iter){
				    return this->mPtr != iter.mPtr;
				}

			private:
			    T* mPtr;
		};
		class revers_iterator
		{
			public:
				revers_iterator(T* ptr){
					mPtr = ptr;
				}
			    revers_iterator& operator++(){
				    this->mPtr--;
				    return *this;
				}
			    revers_iterator& operator--()
				{
				    this->mPtr++;
				    return *this;
				}

			    revers_iterator operator++(int){
				    revers_iterator temp = *this;
				    this->mPtr++;
				    return temp;
				}
			    revers_iterator operator--(int){
				    revers_iterator temp = *this;
				    this->mPtr++;
				    return temp;
				}
			    T& operator*(){
				    return *this->mPtr;
				}
			    bool operator==(const revers_iterator& iter){
				    return this->mPtr == iter.mPtr;
				}
			    bool operator!=(const revers_iterator& iter){
				    return this->mPtr != iter.mPtr;
				}
			private:
			    T* mPtr;
		};

		typedef const iterator const_iterator;
		typedef T& reference;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef const T& const_reference;
		typedef const revers_iterator const_revers_iterator;
		iterator begin() { return iterator(&v_data[0]); }
		iterator end()   { return iterator(&v_data[v_size - 1]); } 
		const_iterator begin() const{ return iterator(&v_data[0]); }
		const_iterator end()   const{ return iterator(&v_data[v_size - 1]); } 
		revers_iterator begin(T) { return revers_iterator(&v_data[v_size - 1]); }
		revers_iterator end(T)   { return revers_iterator(&v_data[0]); } 
		const_revers_iterator begin(T)const { return revers_iterator(&v_data[v_size - 1]); }
		const_revers_iterator end(T)  const { return revers_iterator(&v_data[0]); } 

	// // constractors -----------------------------------------------------------------------------------------------------------
		vector(){
			v_data = alloc.allocate(0);
			v_size = 0;
			v_capacity = 0;
		}
		vector(size_t n, T t){
			v_data = alloc.allocate(n * 10);
			for(int i = 0; i < n ; i++){
				v_data[i] = t;
			}
			v_size = n;
			v_capacity = n * 10;
		}
		vector(iterator start, iterator end){
			int i;
			iterator tmp;

			tmp = start;
			for (i = 0; tmp < end; tmp++)
				i++;
			v_data = alloc.allocate((i +1) * 10);
			v_size = i + 1;
			v_capacity = (1 + i) * 10;
			for (i = 0; start < end; i++)
				v_data[i] = *(start++);

		}
		vector(const vector<T, Alloc>& start){
			iterator it = start.begin();

			v_data = alloc.allocate(start.size() * 10);
			v_size = start.size();
			v_capacity = start.size();
			for (it ; it < start.end(); it++)
				this->v_data = *it;
		}
	// // -----------------------------------------------------------------------------------------------------------


	
	// // destractors -----------------------------------------------------------------------------------------------------------
	// 	~vector();
	// // -----------------------------------------------------------------------------------------------------------

	
	
	
	
	// // operators -----------------------------------------------------------------------------------------------------------
	// 	vector<T> & operator=(const vector<T> & vec);
	// 	T& operator[](size_t index);
	// 	const T& operator[](size_t index);
	// // -----------------------------------------------------------------------------------------------------------
	
	
	
	
	// // member functions  -----------------------------------------------------------------------------------------------------------
		size_t size(){
			return v_size;
		}
		void assign(iterator start, iterator end){
			int i;
			iterator tmp;

			tmp = start;
			for (i = 0; tmp < end; tmp++)
				i++;
			if (v_capacity < i){
				alloc.deallocate(v_data, v_capacity);
				v_data = alloc.allocate((i +1) * 1,5);
				v_capacity = (i +1) * 1,5;
			}
			v_size = i;
			for (i = 0; start < end; i++)
				v_data[i] = *(start++);

		}
		void assign(size_t n, T t){
			if (v_capacity < n){
				alloc.deallocate(v_data, v_capacity);
				v_data = alloc.allocate(n * 1,5);
				v_capacity = n * 1,5;
			}
			v_size = n;
			for(int i = 0; i < n ; i++){
				v_data[i] = t;
			}
		}
		reference at(size_type n){
			return &v_data[n];
		}
		const_reference at(size_type n) const{
			return &v_data[n];
		}
		reference back(){
			return &v_data[v_size];
		}
		const_reference back() const{
			return &v_data[v_size];
		}
		size_type capacity() const{
			return v_capacity;
		}
		void clear(){
			alloc.deallocate(v_data, v_capacity);
			v_size = 0;
			v_capacity = 0;
		}
		bool empty() const{
			if (size == 0)
				return true;
			return false;
		}
		iterator erase (iterator position){
			while (position < this->end()){
				*position = *(position + 1);
				position++;
			}
		}
		iterator erase (iterator first, iterator last){
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
	// // -----------------------------------------------------------------------------------------------------------

};




#endif