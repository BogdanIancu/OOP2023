#include<iostream>
#include<string>
using namespace std;

//clasa abstracta
class Impozabil
{
public:
	//metoda virtuala pura
	virtual float calculImpozit() = 0;
};

class Locuinta : public Impozabil
{
protected:
	float suprafataUtila;
	int pret;

public:
	Locuinta()
	{
		suprafataUtila = 15;
		pret = 100000;
	}

	Locuinta(float suprafataUtila, int pret)
	{
		this->suprafataUtila = suprafataUtila;
		this->pret = pret;
	}

	//supradefinire metoda virtuala pura
	float calculImpozit() override
	{
		return 5 * suprafataUtila;
	}

	//metoda virtuala
	virtual float pretCuTVA()
	{
		if (pret <= 100000)
		{
			return pret * 1.05;
		}
		else
		{
			return pret * 1.19;
		}
	}

};

class Masina : public Impozabil
{
protected:
	float pret;
	float capacitateCilindrica;
public:
	Masina()
	{
		pret = 5000;
		capacitateCilindrica = 0;
	}
	Masina(float pret, float capacitateCilindrica)
	{
		this->pret = pret;
		this->capacitateCilindrica = capacitateCilindrica;
	}

	float calculImpozit() override
	{
		return 50 * capacitateCilindrica;
	}

	void setCapacitateCilindrica(float capacitate)
	{
		capacitateCilindrica = capacitate;
	}
};

//derivare multipla
class Autorulota : public Masina, public Locuinta
{
protected:
	int nrLocuri;

public:
	Autorulota()
	{
		nrLocuri = 2;
		suprafataUtila = 5;
		Masina::pret = 10000;
		Locuinta::pret = 0;
	}
	Autorulota(int pret, int nrPersoane, float suprafataUtila) : Locuinta(suprafataUtila, 0), Masina(pret, 0)
	{
		this->nrLocuri = nrPersoane;
	}

	float getPret()
	{
		return Masina::pret + Locuinta::pret;
	}

	//supradefiniri
	float pretCuTVA() override
	{
		return getPret() * 1.19;
	}

	float calculImpozit() override
	{
		return Masina::calculImpozit();
	}
};

void f()
{
	cout << "Hello, world!";
}

void g()
{
	cout << "Goodbye!";
}


int main()
{
	Locuinta l1(30, 50000);
	cout << l1.pretCuTVA() << endl;
	Autorulota a1(10000, 2, 7);
	cout << a1.pretCuTVA() << endl;
	Locuinta* p = nullptr;
	p = &l1;
	cout << p->pretCuTVA() << endl;
	p = &a1;
	cout << p->pretCuTVA() << endl;
	cout << sizeof(l1) << endl;

	Impozabil* i = new Masina(10000, 1.9);
	cout << i->calculImpozit() << endl;
	delete i;

	a1.setCapacitateCilindrica(2.5);

	Masina* m;
	m = &a1;

	i = m;
	cout << i->calculImpozit() << endl;

	//definire pointer la functie
	//ce nu are parametri si returneaza void
	void (*pf)();
	pf = f;
	cout << "Introduceti o valoare: ";
	int x;
	cin >> x;
	if (x % 2 == 0)
	{
		pf = f;
	}
	else
	{
		pf = g;
	}
	pf();

	//supradefinirea utilizeaza
	//pointeri la functie pentru
	//a identifica functia potrivita
	//la momentul executiei
}