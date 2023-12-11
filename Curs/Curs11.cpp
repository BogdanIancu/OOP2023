#include <iostream>
#include <string>
using namespace std;

class Animal
{
	char* nume = nullptr;
public:
	virtual void scoateSunet()
	{
	}

	virtual ~Animal()
	{
		cout << "destructor animal";
	}
};

class Pisica : public Animal
{
private:
	int* mancare = nullptr;
	int nrZile = 0;
public:
	void scoateSunet()
	{
		cout << "miau" << endl;
	}

	~Pisica()
	{
		cout << "destructor pisica";
	}
};

class Caine : public Animal
{
	void scoateSunet()
	{
		cout << "ham" << endl;
	}
};

int main()
{
	Pisica pisica;
	Caine caine;
	Animal* animale[]{&pisica, &caine};
	for (int i = 0; i < 2; i++)
	{
		animale[i]->scoateSunet();
	}

	Animal* a = new Pisica();
	a->scoateSunet();
	delete a;
	cout << "end" << endl;
}