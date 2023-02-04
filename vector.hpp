#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include  <iterator>


namespace ft{
	template<bool, class  T >
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
	    typedef integral_constant<T,v> type;
	    static const T value = v;
	    operator T() { return value; }
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
		        iterator(value_type* ptr){
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
		        bool operator==(const iterator& other)const {
		            return mPtr == other.mPtr;
		        }
		        bool operator!=(const iterator& other) const{
		            return mPtr != other.mPtr;
		        }
				bool operator<(const iterator& other) const {
				    return mPtr < other.mPtr;
						}
				bool operator>(const iterator& other) const{
				    return mPtr > other.mPtr;
				}
				bool operator<=(const iterator& other) const {
				    return mPtr <= other.mPtr;
				}
				bool operator>=(const iterator& other) const{
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
			        value_type* mPtr;
		};
		template<
		class Iter,
    	class Category,
    	class T,
    	class Distance = std::ptrdiff_t,
    	class Pointer = T*,
    	class Reference = T&
		>
		class reverse_iterator{
    		public:
				typedef Iter iterator_type;
				typedef Category iterator_category;
        		typedef T value_type;
        		typedef Distance difference_type;
        		typedef Pointer pointer;
        		typedef Reference reference;
    		    reverse_iterator() {}
    		    reverse_iterator(T* ptr) : mPtr(ptr) {}
    		    reverse_iterator(const reverse_iterator& other) : mPtr(other.mPtr) {}
    		    reverse_iterator(const iterator<std::random_access_iterator_tag, T>& other) : mPtr(other.mPtr) {}
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
				T* mPtr;
		};

		

	template < class T, class Alloc = std::allocator<T> > class vector{
	private:
		T *v_data;
		Alloc alloc;
		size_t v_size;
		size_t v_capacity;
	public:
		typedef ft::iterator<std::random_access_iterator_tag , const T> const_iterator;
		typedef ft::iterator<std::random_access_iterator_tag, T> iterator;
		typedef T& reference;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef const T& const_reference;
		typedef ft::reverse_iterator<iterator, std::random_access_iterator_tag, T> reverse_iterator;
		typedef ft::reverse_iterator<iterator, std::random_access_iterator_tag, const T> const_reverse_iterator;
		iterator begin() { return iterator(v_data); }
		iterator end()   { return iterator(v_data + v_size); } 
		const_iterator begin() const{ return const_iterator(&v_data[0]); }
		const_iterator end()   const{ return const_iterator(&v_data[v_size - 1]); } 
		// reverse_iterator begin(T) { return const_reverse_iterator(&v_data[v_size - 1]); }
		// reverse_iterator end(T)   { return const_reverse_iterator(&v_data[0]); } 
		// const_reverse_iterator begin(T)const { return const_reverse_iterator(&v_data[v_size - 1]); }
		// const_reverse_iterator end(T)  const { return const_reverse_iterator(&v_data[0]); } 

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

		    v_size = std::distance(first, last);
			v_data = this->alloc.allocate(v_size * 10);
		    v_capacity = v_size * 10;
		    for (size_type t1 = 0; first < last; t1++, first++){
		    	alloc.construct(v_data + t1, *first);
		    }
		}
		vector(const vector& x){
			vector::const_iterator it = x.begin();

			v_data = alloc.allocate(x.size() * 10);
			v_size = x.size();
			v_capacity = x.size();
			for (size_t i = 0;it < x.end(); it++, i++)
				alloc.construct(v_data + i, *it);
		}
	// // -----------------------------------------------------------------------------------------------------------


	
	// destractors -----------------------------------------------------------------------------------------------------------
		~vector(){
			if (v_data){
				for (size_type i = 0; i < v_capacity; i++)
					this->alloc.destroy(v_data + i);
				this->alloc.deallocate(v_data, v_capacity);
			}
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
			size_t i;

			v_size = std::distance(first, last);
			if (v_capacity < v_size){
				for (size_type i = 0; i < v_capacity; i++)
					this->alloc.destroy(v_data + i);
				this->alloc.deallocate(v_data, v_capacity);
				v_data = this->alloc.allocate(v_size * 1.5);
				v_capacity = v_size * 1.5;
			}
			for (i = 0; first < last; i++, first++)
				alloc.construct(v_data + i, *first);
			v_size = i;
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
			return v_data[n];
		}
		const_reference at(size_type n) const{
			return v_data[n];
		}
		reference back(){
			return v_data[v_size -1];
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
			v_data = 0;
		}
		bool empty() const{
			if (v_size == 0)
				return true;
			return false;
		}
		vector::iterator erase (vector::iterator position){
			vector::iterator tmp = position;
			while (position < this->end()){
				*position = *(position + 1);
				position++;
			}
			v_size--;
			return tmp;
		}
		vector::iterator erase (vector::iterator first, vector::iterator last){
			vector::iterator tmp = last;
			while (last < this->end()){
				*first = *last;
				last++;
				first++;
			}
			v_size -= std::distance(first, last);
			return tmp;
		}
		reference front(){
			return v_data[0];
		}
		const_reference front() const{
			return v_data[0];
		}
		allocator_type get_allocator() const{
			return alloc;
		}
		vector::iterator insert (vector::iterator position, const value_type& val){
			vector::iterator t1;

			if (v_size + 1 > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + 1) * 1.5);
				for (size_t i = 0; i < v_size; i++)
					alloc.construct(&tmp[i], *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity   + 1) * 1.5;
				v_data = tmp;
			}
			alloc.construct(&v_data[v_size], *this->end());
			for (t1 = this->end(); position < t1; t1--)
				*t1 = *(t1 - 1);
			*t1 = val;
			v_size++;
			return position;
		}
		void insert (iterator position, size_type n, const value_type& val){
			vector::iterator t1;
			size_t i;

			if (v_size + n > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + n) * 1.5);
				for (size_t i = 0; i < v_size; i++)
					alloc.construct(tmp + i, *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity + n) * 1.5;
				v_data = tmp;
			}
			if (position < this->end())
			{
				for (t1 = this->end() -1, i = v_size; position != t1 && std::distance(position, this->end()) > 0; t1--, i--){
					if (t1 + n >  this->end())
						alloc.construct(v_data + n + i, *t1);
					std::cout<< "hello\n";
				}
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
			size_t i;

			n = std::distance(first, last);
			if (v_size + n > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + n) * 1.5);
				for (size_t i = 0; i < v_size; i++)
					alloc.construct(tmp + i, *(v_data + i));
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity + n) * 1.5;
				v_data = tmp;
			}
			for (t1 = this->end(), i = v_size; position < t1; t1--, i--){
				alloc.construct(v_data + n + i, 0);
				*(t1 + n) = *t1;

			}
			while (first < last){
				*t1 = *first;
				t1++;
				first++;
			}
			v_size += n;
			
		}
		size_type max_size() const{
			return alloc.max_size();
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
			vector::const_iterator t1;
			vector::const_iterator t2 = x.end();
			size_t i;


			for (size_type i = 0; i < v_capacity; i++)
				alloc.destroy(v_data + i);
			alloc.deallocate(v_data, v_capacity);
			v_data = alloc.allocate(x.capacity());
			v_capacity = x.capacity();
			for (t1 = x.begin(), i = 0; t1 < t2; t1++, i++){
				alloc.construct(v_data + i, *t1);
			}
			v_size = x.size();
			return *this;
		}
		void pop_back(){
			v_size--;
			alloc.destroy(v_data + v_size);
		}
		void push_back (const value_type& val){
			if (v_size + 1 > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + 1) * 1.5);
				for (size_t i = 0; i < v_size; i++)
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
			return &v_data[v_size - 1];
		}
		const_reverse_iterator rbegin() const{
			return &v_data[v_size - 1];
		}
		reverse_iterator rend(){
			return (v_data - 1);
		}
		const_reverse_iterator rend() const{
			return (v_data - 1);
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
				for (size_t i = 0; i < v_size; i++)
					alloc.construct(tmp + i, v_data[i]);
				for (size_type i = 0; i < v_capacity; i++)
					alloc.destroy(v_data + i);
				alloc.deallocate(v_data, v_capacity);
				v_data = 0;
				v_capacity = n * 1.5;
				v_data = tmp;
			}

			for (size_t i = v_size; i < n ; i++)
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
		friend void swap (vector& x, vector& y){
			vector tmp;

			tmp = x;
			x = y;
			y = tmp;
		}
		friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			if (lhs.size() == rhs.size()){
				iterator it1;
				iterator it2;

				for (it1 = lhs.begin(), it2 = rhs.begin(); it1 < lhs.end() && it2 < rhs.end(); it1++, it2++){
					if (*it1 != *it2)
						return false;
				}
				if ( it1 == lhs.end() || it2 == rhs.end())
					return true;
			}
			return false;
		}
		friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			if (lhs.size() == rhs.size()){
				iterator it1;
				iterator it2;

				for (it1 = lhs.begin(), it2 = rhs.begin(); it1 < lhs.end() && it2 < rhs.end(); it1++, it2++){
					if (*it1 != *it2)
						return true;
				}
				if ( it1 == lhs.end() || it2 == rhs.end())
					return false;
			}	
			return true;
		}

		friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			iterator first1 = lhs.begin();
			iterator first2 = rhs.begin();
			iterator last1 = lhs.end();
			iterator last2 = rhs.end();

  			while (first1!=last1)
  			{
  			  if (first2==last2 || *first2<*first1) return false;
  			  else if (*first1<*first2) return true;
  			  ++first1; ++first2;
  			}
  			return (first2!=last2);
		}
		friend bool operator<=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			iterator first1 = lhs.begin();
			iterator first2 = rhs.begin();
			iterator last1 = lhs.end();
			iterator last2 = rhs.end();

  			while (first1!=last1)
  			{
  			  if (*first2<*first1) return false;
  			  else if (*first1<*first2) return true;
  			  ++first1; ++first2;
  			}
  			return (first2==last2);
		}
		friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			iterator first1 = lhs.begin();
			iterator first2 = rhs.begin();
			iterator last1 = lhs.end();
			iterator last2 = rhs.end();

  			while (first1!=last1)
  			{
  			  if (first2==last2 || *first2>*first1) return false;
  			  else if (*first1>*first2) return true;
  			  ++first1; ++first2;
  			}
  			return (first2!=last2);
		}

		friend bool operator>=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			iterator first1 = lhs.begin();
			iterator first2 = rhs.begin();
			iterator last1 = lhs.end();
			iterator last2 = rhs.end();

  			while (first1!=last1)
  			{
  			  if (*first2>*first1) return false;
  			  else if (*first1>*first2) return true;
  			  ++first1; ++first2;
  			}
  			return (first2==last2);
		}
	};
}
#endif