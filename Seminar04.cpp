#include<iostream>
#include<string>

using namespace std;

enum zi { luni = 1, marti = 2, miercuri = 3, joi = 4 };

union id {
	short v1;
	int v2;
	long long v3;
};

struct Carte {
	int nrPag;
	float pret;
	char titlu[21];
};

class Student {
public:
	//atribute
	string nume;

	//metoda
	void afisareNume() {
		cout << "Nume student: " << nume << endl;
	}

	//constructor implicit
	Student() {
		nume = "Anonim";
		grupa = 1000;
	}

	//constructor cu parametri
	Student(string n, int g, float m) {
		nume = n;
		grupa = g;
		medie = m;
	}

	//getter
	int getGrupa() {
		return grupa;
	}

	//setter
	void setGrupa(int valoare) {
		if (valoare > 0 && valoare < 10000) {
			grupa = valoare;
		}
	}

private:
	int grupa = 0;
	float medie = 1;
};

int main()
{
	zi z = zi::luni;
	cout << z << endl;
	zi z2 = (zi)4;
	cout << z2 << endl;

	id i;
	i.v1 = 50;
	//atributele dintr-un union
	//sunt salvate toate in aceeasi zona de memorie
	cout << i.v1 << endl;
	cout << i.v3 << endl;

	i.v3 = 11000;
	cout << i.v1 << endl;
	cout << sizeof(id) << endl;

	Carte c{ 50, 15, "Vocabular" };
	cout << c.titlu << endl;

	Carte c2;
	c2.nrPag = 50;
	c2.pret = 25;
	strcpy_s(c2.titlu, "Programare");
	cout << c2.nrPag << " " << c2.pret << " " << c2.titlu << endl;
	cout << sizeof(c2) << endl;

	Student s1;
	s1.nume = "Marius";
	cout << s1.nume << endl;
	s1.afisareNume();

	Student s2("Andrei", 12, 8);
	s2.setGrupa(123);
	cout << s2.getGrupa() << endl;
}