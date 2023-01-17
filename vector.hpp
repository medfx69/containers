#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>


template < class T, class Alloc = std::allocator<T> > class vector{
	private:
		T *v_data;
		Alloc alloc;
		size_t v_size;
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

		iterator begin() { return iterator(&v_data[0]); }
		iterator end()   { return iterator(&v_data[v_size - 1]); } 
		revers_iterator begin(T) { return revers_iterator(&v_data[v_size - 1]); }
		revers_iterator end(T)   { return revers_iterator(&v_data[0]); } 
	// 	typedef typename iterator;
	// 	typedef typename const_iterator;
	// // constractors -----------------------------------------------------------------------------------------------------------
	// 	vector(){
	// 		v_data = alloc.allocate(1);
	// 		v_size = 1;
	// 	}
	// 	vector(size_t n, T t){
	// 		alloc.deallocate(v_data, v_size);
	// 		v_data = alloc.allocate(n);
	// 		for(int i = 0; i > n ; i++){
	// 			v_data[i] = t;
	// 		}
	// 	}
	// 	vector(iterator start, iterator end){
	// 		int i;
	// 		iterator tmp;

	// 		tmp = start;
	// 		for (i = 0; tmp < end; tmp++)
	// 			i++;
	// 		alloc.deallocate(v_data, v_size);
	// 		v_data = alloc.allocate(i +1);
	// 		v_size = i + 1;
	// 		for (i = 0; start < end; i++)
	// 			v_data[i] = *(start++);

	// 	}
	// 	vector(vector<T> start);
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
	// 	template <class InputIterator>  void assign (InputIterator first, InputIterator last);	
	// 	void assign (size_t n, const T& val);
	// // -----------------------------------------------------------------------------------------------------------

};




#endif