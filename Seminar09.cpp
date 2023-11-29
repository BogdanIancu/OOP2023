#include <iostream>
#include <string>
using namespace std;

int notaInvalida = -1;

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
			return true;
		}
		else return (suma / nrNote) >= value;
	}

	friend Student operator+(Student s1, Student s2);
	friend ostream& operator<<(ostream& out, Student s);
	friend istream& operator>>(istream& in, Student& s);
};
string Student::universitate = "ASE";

Student operator+(Student s1, Student s2)
{
	s1.nume += s2.nume;
	return s1;
}

Student functie(Student s) {
	//...
	Student copie = s;
	return copie;
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

ostream& operator<<(ostream& out, Student s)
{
	out << "nr Matricol: " << s.nrMatricol << endl;
	out << "Nume Student: " << s.nume << endl;
	out << "Nr note: " << s.nrNote << endl;
	out << "Note: ";
	for (int i = 0; i < s.nrNote; i++) {
		out << s.note[i] << " ";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Student& s)
{
	cout << "Nume: ";
	in >> ws;
	getline(in, s.nume);
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
	cout << endl;
	return in;
}

class StudentBursier : public Student {
private:
	char* denumireBursa;
	float valoareBursa;

public:
	StudentBursier()
	{
		denumireBursa = nullptr;
		valoareBursa = 0;
	}

	StudentBursier(int nrMatricol, string nume, const char* denumire) : Student(nrMatricol, nume, nullptr, 0)
	{
		if (denumire != nullptr)
		{
			this->denumireBursa = new char[strlen(denumire) + 1];
			strcpy_s(this->denumireBursa, strlen(denumire) + 1, denumire);
		}
		else
		{
			this->denumireBursa = nullptr;
		}
		valoareBursa = 0;
	}

	StudentBursier(const StudentBursier& sb) : Student(sb)
	{
		if (sb.denumireBursa != nullptr)
		{
			denumireBursa = new char[strlen(sb.denumireBursa) + 1];
			strcpy_s(denumireBursa, strlen(sb.denumireBursa) + 1, sb.denumireBursa);
		}
		else
		{
			denumireBursa = nullptr;
		}
		valoareBursa = sb.valoareBursa;
	}

	StudentBursier& operator=(const StudentBursier& sb)
	{
		//(Student)*this = (Student)sb;
		Student::operator=(sb);
		if (this != &sb) {
			if (denumireBursa != nullptr)
			{
				delete[] denumireBursa;
				denumireBursa = nullptr;
			}
			if (sb.denumireBursa != nullptr)
			{
				denumireBursa = new char[strlen(sb.denumireBursa) + 1];
				strcpy_s(denumireBursa, strlen(sb.denumireBursa) + 1, sb.denumireBursa);
			}
			else
			{
				denumireBursa = nullptr;
			}
			valoareBursa = sb.valoareBursa;
		}
		return *this;
	}

	~StudentBursier()
	{
		if (denumireBursa != nullptr)
		{
			delete[] denumireBursa;
			denumireBursa = nullptr;
		}
	}

	friend ostream& operator<<(ostream&, StudentBursier);
	friend istream& operator>>(istream&, StudentBursier&);
};

ostream& operator<<(ostream& out, StudentBursier sb)
{
	out << (Student)sb << endl;
	out << "Denumire Bursa: ";
	if (sb.denumireBursa != nullptr)
	{
		out << sb.denumireBursa << endl;
	}
	out << "Valoare Bursa: " << sb.valoareBursa;
	return out;
}

istream& operator>>(istream& in, StudentBursier& sb)
{
	in >> (Student&)sb;
	cout << "Denumire Bursa: ";
	char buffer[200];
	in >> ws;
	in.getline(buffer, 199);
	if (sb.denumireBursa != nullptr)
	{
		delete[] sb.denumireBursa;
	}
	sb.denumireBursa = new char[strlen(buffer) + 1];
	strcpy_s(sb.denumireBursa, strlen(buffer) + 1, buffer);
	cout << "Valoare Bursa: ";
	in >> sb.valoareBursa;
	cout << endl;
	return in;
}

int main()
{
	Student s1;
	int note[]{ 10,8,9 };
	Student s2(123, "Ion Popescu", note, 3);
	note[0] = 4;
	s1 = functie(s2);
	Student s3(s2);
	//apel constructor de copiere
	Student s4 = s2;
	//apel operator=
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
	//cin >> s9;
	//cout << s9;
	cout << endl;
	int x = (int)s9;
	cout << x << endl;

	s8[0] = 10;
	cout << s8[0] << endl;
	cout << s8(8) << endl;

	StudentBursier sb1;
	StudentBursier sb2(1, "Felicia", "Bursa de performanta");
	s5 = sb2;
	StudentBursier sb3 = sb2;
	sb1 = sb2;
	cin >> sb1;
	cout << sb1;
}