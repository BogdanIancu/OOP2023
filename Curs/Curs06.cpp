#include <iostream>
using namespace std;


class TelefonMobil
{
private:
	string producator;
	int* durataZilnicaUtilizare;
	int nrZile;

public:
	TelefonMobil()
	{
		producator = "";
		durataZilnicaUtilizare = new int[1];
		durataZilnicaUtilizare[0] = 2;
		nrZile = 1;
	}

	TelefonMobil(int* durataZilnicaUtilizare, int nrZile) : TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr && nrZile > 0)
		{
			this->nrZile = nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] = durataZilnicaUtilizare[i];
			}
		}
	}

	TelefonMobil(const TelefonMobil& t)
	{
		producator = t.producator;

		if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
		{
			this->nrZile = t.nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] = t.durataZilnicaUtilizare[i];
			}
		}
		else
		{
			durataZilnicaUtilizare = nullptr;
			nrZile = 0;
		}
	}

	~TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr)
		{
			delete[] durataZilnicaUtilizare;
			durataZilnicaUtilizare = nullptr;
		}
	}

	TelefonMobil& operator=(const TelefonMobil& t)
	{
		if (this != &t)
		{
			if (durataZilnicaUtilizare != nullptr)
			{
				delete[] durataZilnicaUtilizare;
				durataZilnicaUtilizare = nullptr;
			}

			producator = t.producator;

			if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
			{
				this->nrZile = t.nrZile;
				this->durataZilnicaUtilizare = new int[nrZile];
				for (int i = 0; i < nrZile; i++)
				{
					this->durataZilnicaUtilizare[i] = t.durataZilnicaUtilizare[i];
				}
			}
			else
			{
				durataZilnicaUtilizare = nullptr;
				nrZile = 0;
			}
		}
		return *this;
	}

	int getDurataZilnicaUtilizare(int index)
	{
		return durataZilnicaUtilizare[index];
	}
};

int x = 5;

int& functie()
{
	return x;
}


int main()
{
	int nrElemente = 3;
	int* vector = new int[nrElemente];
	vector[0] = 2;
	vector[1] = 1;
	vector[2] = 3;
	TelefonMobil t1(vector, 3);
	vector[0] = 20;

	int durata = t1.getDurataZilnicaUtilizare(2);
	cout << durata << endl;

	TelefonMobil t2(t1);
	TelefonMobil t3 = t1;
	TelefonMobil t4;
	t4 = t2;
	t2 = t4 = t1;
	
	int a = functie();
	cout << a << endl;
}