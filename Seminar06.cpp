#include <iostream>
using namespace std;

class Student
{
private:
	string nume;
	int* note;
	int nrNote;

public:
	Student()
	{
		nume = "Anonim";
		note = nullptr;
		nrNote = 0;
	}

	Student(string _nume, int* _note, int _nrNote)
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
	
	//constructor de copiere
	Student(const Student& s)
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

	//operator= ce permite apel in cascada
	Student& operator=(const Student& s)
	{
		//evitare auto-asignare
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

	//destructor
	~Student()
	{
		if (note != nullptr)
		{
			delete[] note;
			note = nullptr;
		}
	}
};

Student functie(Student s) {
	//...
	Student copie = s;
	return copie;
}

int main()
{
	Student s1;
	int note[]{ 10,8,9 };
	Student s2("Ion Popescu", note, 3);
	note[0] = 4;
	s1 = functie(s2);
	Student s3(s2);
	//apel constructor de copiere
	Student s4 = s2;
	//apel operator=
	s1 = s2;
}