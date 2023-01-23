#include "vector.hpp"
int main()
{
	// vector<int> vec(12,4);
	vector<int> vec1(12,3);
	vector<int>::iterator t1 = vec1.begin();
	vector<int>::iterator t2 = vec1.end();

	// vec.assign(t1,t2);
	vector<int> vec2(&t1,&t2);
	vector<int>::iterator t = vec2.begin();
	while (t < vec2.end())
		std::cout << *(t++) << std::endl;
}