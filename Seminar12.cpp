#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

template <typename T>
T suma(T a, T b)
{
	return a + b;
}

template <class T1, class T2>
T1 suma(T1 a, T2 b)
{
	return a + b;
}


template <typename T = int, int n = 10>
class Vector
{
private:
	T elemente[n];
public:
	T& operator[](int index)
	{
		if (index >= 0 && index < n)
			return elemente[index];
		else
			throw exception("invalid index");
	}
};

int main()
{
	int x = 10;
	int y = 12;
	cout << suma<int>(x, y);
	cout << endl;
	float a = 12.2;
	float b = 14.4;
	cout << suma<float>(a, b);
	cout << endl;
	cout << suma<float, int>(a, x);
	cout << endl;
	Vector<int, 4> v1;
	v1[0] = 14;
	cout << v1[0];
	Vector<> v2;
	Vector<float> v3;

	cout << endl;
	vector<int> vector1;
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(7);
	for (int i = 0; i < vector1.size(); i++)
	{
		cout << vector1[i] << " ";
	}
	cout << endl;

	vector1.pop_back();
	for (vector<int>::iterator it = vector1.begin();
		it != vector1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<float> l1;
	l1.push_back(3.4);
	l1.push_front(7.8);
	l1.insert(++l1.begin(), 15.77);
	for (list<float>::iterator it = l1.begin();
		it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<char> s1;
	s1.insert('a');
	s1.insert('d');
	s1.insert('c');
	s1.insert('c');

	for (set<char>::iterator it = s1.begin();
		it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<char>::iterator i = s1.find('b');
	if (i != s1.end())
	{
		cout << "Gasit.";
	}
	else
	{
		cout << "caracterul b nu se afla in set.";
	}
	cout << endl;

	map<string, long> m;
	m.insert(make_pair("Popescu", 712345678));
	m.insert(pair<string, long>("Ionescu", 787654321));
	cout << m["Popescu"] << endl;

	for (map<string, long>::iterator it = m.begin();
		it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}