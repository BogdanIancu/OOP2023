#include <iostream>
using namespace std;

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

	friend Student operator+(Student s1, Student s2);
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
}