#include <iostream>
using namespace std;

class BatteryAlreadyFullException : public exception
{
public:
	BatteryAlreadyFullException(const char* message) : exception(message)
	{

	}
};

class TelefonMobil
{
protected:
	int nivelBaterie;
public:
	TelefonMobil()
	{
		nivelBaterie = 0;
	}

	TelefonMobil(int nivelBaterie)
	{
		if (nivelBaterie >= 0)
		{
			this->nivelBaterie = nivelBaterie;
		}
	}

	void incarca(int nivel)
	{
		if (nivelBaterie <= 99)
		{
			nivelBaterie += nivel;
		}
		else
		{
			throw BatteryAlreadyFullException("Baterie deja plina");
		}
	}
};


class TelefonMobilPliabil : public TelefonMobil
{
private:
	int nivelBaterie;
	int dimensiunePliat;
public:
	//apel implicit constructor din clasa de baza
	TelefonMobilPliabil()
	{
		dimensiunePliat = 0;
		TelefonMobil::nivelBaterie = 10;
		nivelBaterie = 5;
	}

	TelefonMobilPliabil(int nivelBaterie, int dimensiunePliat) : TelefonMobil(nivelBaterie)
	{
		this->dimensiunePliat = dimensiunePliat;
	}
	//apel explicit constructor din clasa de baza
};


int main()
{
	try
	{
		TelefonMobil tm1;
		TelefonMobilPliabil t1;
		tm1 = t1;
		TelefonMobilPliabil t2(100, 15);
		//TelefonMobilPliabil t3 = tm1;
		TelefonMobil* ptm = &tm1;
		TelefonMobilPliabil* ptmp = &t1;
		ptm = ptmp;
		t2.incarca(50);
	}
	catch (BatteryAlreadyFullException& e)
	{
		cout << e.what();
	}
	catch (exception& e)
	{
		cout << e.what();
	}
}