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
		vector::iterator begin() { return vector::iterator(&v_data[0]); }
		vector::iterator end()   { return vector::iterator(&v_data[v_size - 1]); } 
		const_iterator begin() const{ return vector::iterator(&v_data[0]); }
		const_iterator end()   const{ return vector::iterator(&v_data[v_size - 1]); } 
		reverse_iterator begin(T) { return reverse_iterator(&v_data[v_size - 1]); }
		reverse_iterator end(T)   { return reverse_iterator(&v_data[0]); } 
		const_reverse_iterator begin(T)const { return reverse_iterator(&v_data[v_size - 1]); }
		const_reverse_iterator end(T)  const { return reverse_iterator(&v_data[0]); } 

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
			vector::iterator it = start.begin();

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
	// 	vector & operator=(const vector & vec);
	// 	T& operator[](size_t index);
	// 	const T& operator[](size_t index);
	// // -----------------------------------------------------------------------------------------------------------
	
	
	
	
	// // member functions  -----------------------------------------------------------------------------------------------------------
		size_t size(){
			return v_size;
		}
		void assign(vector::iterator start, vector::iterator end){
			int i;
			vector::iterator tmp;

			tmp = start;
			for (i = 0; tmp < end; tmp++)
				i++;
			if (v_capacity < i){
				alloc.deallocate(v_data, v_capacity);
				v_data = alloc.allocate((i +1) * 1.5);
				v_capacity = (i +1) * 1.5;
			}
			v_size = i;
			for (i = 0; start < end; i++)
				v_data[i] = *(start++);

		}
		void assign(size_t n, T t){
			if (v_capacity < n){
				alloc.deallocate(v_data, v_capacity);
				v_data = alloc.allocate(n * 1.5);
				v_capacity = n * 1.5;
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

			if (v_capacity +1 > v_capacity){
				T *tmp;
				tmp = alloc.allocate((v_capacity + 1) * 1.5);
				for (int i = 0; i < v_size; i++)
					tmp[i] = v_data[i];
				alloc.deallocate(v_data, v_capacity);
				v_capacity = (v_capacity + 1) * 1.5;
				v_size++;
				v_data = tmp;
			}
			for (t1 = this->end(); position < t1; t1--)
				*t1 = *(t1 - 1);
			*t1 = val;
			return position;
		}
	// // -----------------------------------------------------------------------------------------------------------

};




#endif