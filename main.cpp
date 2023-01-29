#include "vector.hpp"
int main()
{
	// vector<int> vec(12,4);
	vector<int> vec1(12,3);
	vector<int>::iterator t1 = vec1.begin();
	vector<int>::iterator t2 = vec1.end();

	// vec.assign(t1,t2);
	vector<int> vec2(t1, t2);
	vector<int> vec4(12,3);
	vec1[2] = vec2[3];
	vec4 = vec2;
	vector<int>::iterator t = vec4.begin();
	while (t < vec4.end())
		std::cout << *(t++) << std::endl;
	vec4.resize(100, 9);
	t = vec4.begin();
	while (t < vec4.end())
		std::cout << *(t++) << std::endl;
}