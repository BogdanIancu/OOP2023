#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int notaInvalida = -1;

//exceptie personalizata
class NoGradesException : public exception
{
public:
	NoGradesException()
	{
	}

	NoGradesException(const char* message) : exception(message)
	{
	}
};

class Student
{
private:
	const int nrMatricol;
	string nume;
	int* note;
	int nrNote;
	static string universitate;

public:
	Student() : nrMatricol(0)
	{
		nume = "Anonim";
		note = nullptr;
		nrNote = 0;
	}

	Student(int _nrMatricol, string _nume, int* _note, int _nrNote) : nrMatricol(_nrMatricol)
	{
		nume = _nume;
		if (_note != nullptr && _nrNote > 0)
		{

			note = new int[_nrNote];
			nrNote = _nrNote;
			for (int i = 0; i < nrNote; i++)
			{
				note[i] = _note[i];
			}
		}
		else
		{
			note = nullptr;
			nrNote = 0;
		}
	}

	Student(const Student& s) : nrMatricol(s.nrMatricol)
	{
		nume = s.nume;
		if (s.nrNote > 0 && s.note != nullptr)
		{
			note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
			{
				note[i] = s.note[i];
			}
			nrNote = s.nrNote;
		}
		else
		{
			note = nullptr;
			nrNote = 0;
		}
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			if (note != nullptr)
			{
				delete[] note;
				note = nullptr;
			}

			nume = s.nume;
			if (s.nrNote > 0 && s.note != nullptr)
			{
				note = new int[s.nrNote];
				for (int i = 0; i < s.nrNote; i++)
				{
					note[i] = s.note[i];
				}
				nrNote = s.nrNote;
			}
			else
			{
				note = nullptr;
				nrNote = 0;
			}
		}
		return *this;
	}

	~Student()
	{
		if (note != nullptr)
		{
			delete[] note;
			note = nullptr;
		}
	}

	int getNrNote() {
		return nrNote;
	}

	int* getNote() {
		if (note != nullptr)
		{
			int* copie = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
			{
				copie[i] = note[i];
			}
			return copie;
		}
		return nullptr;
	}

	int getNote(int index)
	{
		if (index >= 0 && index < nrNote)
		{
			return note[index];
		}
		return -1;
	}

	void setNote(int* _note, int _nrNote)
	{
		if (_note != nullptr && _nrNote > 0)
		{
			if (this->note != nullptr)
			{
				delete[] note;
			}
			nrNote = _nrNote;
			note = new int[_nrNote];
			for (int i = 0; i < _nrNote; i++)
			{
				note[i] = _note[i];
			}
		}

	}

	static string getUniversitate()
	{
		return universitate;
	}

	static void setUniversitate(string universitate)
	{
		Student::universitate = universitate;
	}

	bool operator!()
	{
		return note == nullptr;
	}

	Student& operator++()
	{
		if (note != nullptr)
		{
			for (int i = 0; i < nrNote; i++)
			{
				note[i] += 1;
			}
		}
		return *this;
	}

	Student operator++(int i)
	{
		Student copie = *this;
		if (note != nullptr)
		{
			for (int i = 0; i < nrNote; i++)
			{
				note[i] += 1;
			}
		}
		return copie;
	}

	int operator+(int valoare)
	{
		if (note != nullptr)
		{
			return note[0] + valoare;
		}
		else
			return valoare;
	}

	explicit operator int()
	{
		return nrNote;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < nrNote)
		{
			return note[index];
		}
		else
		{
			return notaInvalida;
		}
	}

	bool operator()(int value)
	{
		float suma = 0;
		for (int i = 0; i < nrNote; i++)
		{
			suma += note[i];
		}
		if (nrNote == 0 && value >= 0)
		{
			//aruncare exceptie
			throw NoGradesException("Nr note = 0");
		}
		else return (suma / nrNote) >= value;
	}

	//scriere date obiect in fisier binar
	void serializare()
	{
		ofstream f("student.bin", ios::binary);
		f.write((char*)&nrNote, sizeof(nrNote));
		for (int i = 0; i < nrNote; i++)
		{
			f.write((char*)&note[i], sizeof(note[i]));
		}
		int length = nume.length();
		f.write((char*)&length, sizeof(length));
		f.write(nume.c_str(), length + 1);
		f.close();
	}

	//citire date obiect din fisier binar
	void deserializare()
	{
		ifstream f("student.bin", ios::binary);
		f.read((char*)&nrNote, sizeof(nrNote));
		delete[] note;
		note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
		{
			f.read((char*)&note[i], sizeof(note[i]));
		}
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		nume = buffer;
		delete[] buffer;
		f.close();
	}

	friend Student operator+(Student s1, Student s2);
	friend ostream& operator<<(ostream& out, Student s);
	friend istream& operator>>(istream& in, Student& s);
	friend ifstream& operator>>(ifstream& f, Student& s);
};
string Student::universitate = "ASE";

Student operator+(Student s1, Student s2)
{
	s1.nume += s2.nume;
	return s1;
}

int operator+(int valoare, Student s)
{
	if (s.getNote() != nullptr)
	{
		return s.getNote(0) + valoare;
	}
	else
		return valoare;
}

//operator de afisare modificat pentru a fi utilizat
//si pentru afisare in fisier text
ostream& operator<<(ostream& out, Student s)
{
	cout << "nr Matricol: " << s.nrMatricol << endl;
	cout << "Nume Student: ";
	out << s.nume << endl;

	cout << "Nr note: ";
	out << s.nrNote << endl;
	cout << "Note: ";
	for (int i = 0; i < s.nrNote; i++) {
		out << s.note[i] << " ";
	}
	return out;
}

//operator de citire de la consola
istream& operator>>(istream& in, Student& s)
{
	cout << "Nume: ";
	in >> s.nume;
	int nrNote = 0;
	int* note = nullptr;
	cout << "Nr note: ";
	in >> nrNote;
	if (nrNote > 0)
	{
		note = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			cout << "Nota " << i << ": ";
			in >> note[i];
		}
		s.setNote(note, nrNote);
		delete[] note;
	}
	return in;
}

//operator de citire din fisier
ifstream& operator>>(ifstream& f, Student& s)
{
	if (f.is_open())
	{
		getline(f, s.nume);
		int nrNote = 0;
		int* note = nullptr;
		f >> nrNote;
		if (nrNote > 0)
		{
			note = new int[nrNote];
			for (int i = 0; i < nrNote; i++) {
				f >> note[i];
			}
			s.setNote(note, nrNote);
			delete[] note;
		}
	}
	return f;
}

int main()
{
	Student s1;
	int note[]{ 10,8,9 };
	Student s2(123, "Ion Popescu", note, 3);
	note[0] = 4;
	Student s3(s2);
	Student s4 = s2;
	s1 = s2;
	cout << s2.getNrNote() << endl;
	int v[]{ 4, 6, 7, 5 };
	s2.setNote(v, 4);
	int* vectorNote = s2.getNote();
	for (int i = 0; i < s2.getNrNote(); i++)
	{
		cout << vectorNote[i] << endl;
	}
	delete[] vectorNote;
	cout << s2.getNote(1) << endl;
	cout << Student::getUniversitate() << endl;
	Student::setUniversitate("POLI");
	cout << s1.getUniversitate() << endl;
	Student s5 = s1 + s2;
	cout << !s1 << endl;
	Student s6;
	cout << !s6 << endl;
	Student s7 = ++s2;
	for (int i = 0; i < s7.getNrNote(); i++)
	{
		cout << s7.getNote(i) << " ";
	}
	cout << endl;
	Student s8 = s2++;
	cout << s8.getNote(0) << endl;
	cout << s2.getNote(0) << endl;
	cout << s2 + 3 << endl;
	cout << 3 + s2 << endl;
	cout << s8 << endl;
	Student s9;
	cout << endl;
	int x = (int)s9;
	cout << x << endl;

	s8[0] = 10;
	cout << s8[0] << endl;

	//gestionare exceptie cu try-catch
	try
	{
		Student s10;
		cout << s10(4) << endl;
		cout << s8(8) << endl;
	}
	catch(NoGradesException& e)
	{
		cerr << e.what() << endl;
	}
	catch(...)
	{
		cerr << "orice eroare :)" << endl;
	}

	ofstream f;
	f.open("fisier.txt");
	f << s8;
	f.close();

	ifstream g("fisier.txt");
	Student s11;
	g >> s11;
	g.close();

	s8.serializare();
	Student s12;
	s12.deserializare();
}