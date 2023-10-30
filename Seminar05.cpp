#include <iostream>
#include <string>
using namespace std;

class Masina
{
private:
	//atribute
	string producator;
	string model;
	float pret;
	int anProductie;

public:
	/*
	Masina() 
	{
		producator = "N/A";
		model = "N/A";
		pret = 0;
		anProductie = 1990;
	}


	Masina(string producator, string model, int anProductie)// : Masina()
	{
		this->producator = producator;
		(*this).model = model;
		this->pret = 0;
		this->anProductie = anProductie;
	}
	*/

	//constructor cu parametri ce joaca si rol de constructor implicit
	Masina(string producator = "N/A", string model = "N/A", int anProductie = 1990)
	{
		this->producator = producator;
		// -> echivalent cu *.
		(*this).model = model;
		this->pret = 0;
		this->anProductie = anProductie;
	}

	//constructor de copiere
	Masina(const Masina& m)
	{
		this->producator = m.producator;
		this->model = m.model;
		this->pret = m.pret;
		this->anProductie = m.anProductie;
	}

	//destructor
	~Masina()
	{
		cout << "apel destructor" << endl;
	}

	//metoda de acces (getter)
	string getProducator()
	{
		return producator;
	}

	int getAnProductie()
	{
		return anProductie;
	}

	//metode de acces (setter)
	void setAnProductie(int anProductie)
	{
		if (anProductie > 1800 && anProductie < 2024)
		{
			this->anProductie = anProductie;
		}
	}
};

int main()
{
	Masina m1;
	Masina m2("BMW", "X3", 2008);
	cout << m2.getProducator() << endl;

	m2.setAnProductie(2015);
	cout << m2.getAnProductie() << endl;

	Masina* pm = new Masina();
	cout << pm->getProducator() << endl;
	delete pm;

	Masina m3(m2);
	Masina m4 = m2;

	//vector de obiecte
	Masina* vm = new Masina[3];
	cout << vm[0].getProducator() << endl;
	delete[] vm;
}