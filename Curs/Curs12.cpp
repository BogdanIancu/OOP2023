#include <iostream>
using namespace std;

class Comparabil
{
public:
	virtual int compara(Comparabil* c) = 0;

	bool operator<(Comparabil& c)
	{
		return (this->compara(&c) == -1);
	}
};


class Student : public Comparabil
{
public:
	string nume;
	float medie = 0;

	int compara(Comparabil* c)
	{
		Student* s = (Student*)c;
		if (this->medie < s->medie)
		{
			return -1;
		}
		else if(this->medie > s->medie)
		{
			return 1;
		}
		return 0;
	}
};

class FiguraGeometrica
{
public:
	virtual float perimetru() = 0;
	virtual float arie() = 0;
};

class Patrat : public FiguraGeometrica
{
public:
	int lungime;

	float perimetru()
	{
		return lungime * 4;
	}

	float arie()
	{
		return lungime * lungime;
	}
};

class Cerc : public FiguraGeometrica
{
public:
	int raza;

	float perimetru()
	{
		return 2 * 3.14 * raza;
	}

	float arie()
	{
		return 3.14 * raza * raza;
	}
};

class Aplicatie
{
public:
	FiguraGeometrica* fig;

	void desen()
	{
		cout << "A fost desenata o figura geometrica cu perimetrul " <<
			fig->perimetru() << " si aria " << fig->arie();
	}
};

int main()
{
	Student s1;
	s1.medie = 9.5;
	Student s2;
	s2.medie = 9;
	cout << s1.compara(&s2) << endl;
	cout << (s2 < s1) << endl;

	FiguraGeometrica* p;
	Cerc* c = new Cerc();
	c->raza = 4;
	p = c;
	cout << p->arie();

	Aplicatie a;
	a.fig = c;
	a.desen();
}