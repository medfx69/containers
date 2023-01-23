#include "vector.hpp"
int main()
{
	vector<int> vec(12,4);
	vector<int>::iterator t = vec.begin();
	vec.insert(t, 5);
	while (t < vec.end())
		std::cout << *(t++) << std::endl;
}