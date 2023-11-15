#include <iostream>
#include <string>
using namespace std;

string emptyString = "";

class Facultate
{
private:
	char* denumire;
	int numarStudenti;
	string* specializari;
	int nrSpecializari;

public:
	Facultate()
	{
		denumire = nullptr;
		numarStudenti = 0;
		specializari = nullptr;
		nrSpecializari = 0;
	}

	Facultate(const char* denumire, string* specializari, int nrSpecializari)
	{
		if (denumire != nullptr)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
		numarStudenti = 0;
		if (specializari != nullptr && nrSpecializari > 0)
		{
			this->nrSpecializari = nrSpecializari;
			this->specializari = new string[nrSpecializari];
			for (int i = 0; i < nrSpecializari; i++)
			{
				this->specializari[i] = specializari[i];
			}
		}
		else
		{
			this->specializari = nullptr;
			this->nrSpecializari = 0;
		}
	}

	Facultate(const Facultate& f)
	{
		if (f.denumire != nullptr)
		{
			this->denumire = new char[strlen(f.denumire) + 1];
			strcpy_s(this->denumire, strlen(f.denumire) + 1, f.denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
		numarStudenti = f.numarStudenti;
		if (f.specializari != nullptr && f.nrSpecializari > 0)
		{
			this->nrSpecializari = f.nrSpecializari;
			this->specializari = new string[nrSpecializari];
			for (int i = 0; i < nrSpecializari; i++)
			{
				this->specializari[i] = f.specializari[i];
			}
		}
		else
		{
			this->specializari = nullptr;
			this->nrSpecializari = 0;
		}
	}

	~Facultate()
	{
		if (denumire != nullptr)
		{
			delete[] denumire;
		}
		if (specializari != nullptr)
		{
			delete[] specializari;
		}
	}

	Facultate& operator=(const Facultate& f)
	{
		if (this != &f)
		{
			if (denumire != nullptr)
			{
				delete[] denumire;
			}
			if (specializari != nullptr)
			{
				delete[] specializari;
			}

			if (f.denumire != nullptr)
			{
				this->denumire = new char[strlen(f.denumire) + 1];
				strcpy_s(this->denumire, strlen(f.denumire) + 1, f.denumire);
			}
			else
			{
				this->denumire = nullptr;
			}
			numarStudenti = f.numarStudenti;
			if (f.specializari != nullptr && f.nrSpecializari > 0)
			{
				this->nrSpecializari = f.nrSpecializari;
				this->specializari = new string[nrSpecializari];
				for (int i = 0; i < nrSpecializari; i++)
				{
					this->specializari[i] = f.specializari[i];
				}
			}
			else
			{
				this->specializari = nullptr;
				this->nrSpecializari = 0;
			}
		}
		return *this;
	}

	void setDenumire(char* denumire)
	{
		if (denumire != nullptr)
		{
			if (this->denumire != nullptr)
			{
				delete[] this->denumire;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
	}

	string getDenumire()
	{
		if (denumire != nullptr)
		{
			return denumire;
		}
		return "";
	}

	bool operator!()
	{
		return numarStudenti == 0;
	}

	Facultate& operator++()
	{
		this->numarStudenti++;
		return *this;
	}

	Facultate operator++(int)
	{
		Facultate f = *this;
		this->numarStudenti++;
		return f;
	}

	Facultate operator+(int numarSuplimentarStudenti)
	{
		Facultate f = *this;
		f.numarStudenti += numarSuplimentarStudenti;
		return f;
	}

	void operator+=(int numarSuplimentarStudenti)
	{
		this->numarStudenti += numarSuplimentarStudenti;
	}

	string& operator[](int index)
	{
		if (index >= 0 && index < nrSpecializari)
		{
			return specializari[index];
		}
		else
		{
			return emptyString;
		}
	}

	explicit operator int()
	{
		return numarStudenti;
	}

	bool operator()(int numarMinim)
	{
		return numarStudenti > numarMinim;
	}

	friend ostream& operator<<(ostream& out, Facultate f);
	friend istream& operator>>(istream& in, Facultate& f);
};

Facultate operator+(int numarSuplimentarStudenti, Facultate f)
{
	return f + numarSuplimentarStudenti;
}

ostream& operator<<(ostream& out, Facultate f)
{
	out << "Denumire: ";
	if (f.denumire != nullptr)
	{
		out << f.denumire;
	}
	out << endl;
	out << "Numar studenti: ";
	out << f.numarStudenti << endl;
	out << "Numar specializari: " << f.nrSpecializari << endl;
	if (f.specializari != nullptr) 
	{
		out << "Specializari: ";
		for (int i = 0; i < f.nrSpecializari; i++)
		{
			out << f.specializari[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, Facultate& f)
{
	string buffer;
	cout << "Denumire: ";
	in >> buffer;
	if (f.denumire != nullptr)
	{
		delete[] f.denumire;
	}
	f.denumire = new char[buffer.length() + 1];
	strcpy_s(f.denumire, buffer.length() + 1, buffer.c_str());

	cout << "Numar studenti: ";
	in >> f.numarStudenti;
	cout << "Numar specializari: ";
	in >> f.nrSpecializari;

	if (f.specializari != nullptr)
	{
		delete[] f.specializari;
		f.specializari = nullptr;
	}

	if (f.nrSpecializari <= 0)
	{
		f.nrSpecializari = 0;
	}
	else
	{
		f.specializari = new string[f.nrSpecializari];
		for (int i = 0; i < f.nrSpecializari; i++)
		{
			cout << "Introduceti specializarea: ";
			in >> f.specializari[i];
		}
	}
	return in;
}

int main()
{
	Facultate f1;
	cout << f1.getDenumire();
	string specializari[]{ "IE", "Cibernetica", "Statistica" };
	Facultate f2("CSIE", specializari, 3);
	Facultate f3(f2);
	Facultate f4;
	f4 = f3;
	cout << !f1;
	Facultate f5 = ++f1;
	Facultate f6 = f1++;
	Facultate f7 = f1 + 50;
	f7 += 50;
	Facultate f8 = 30 + f1;
	cout << f1 << f2 << endl;

	cin >> f1;
	cout << f1 << endl;
	cout << f2[1] << endl;
	f2[1] = "Cibernetica Economica";
	int nrStudenti = (int)f2;
	cout << nrStudenti << endl;
	cout << f7(100);
}