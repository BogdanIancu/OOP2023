#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class TelefonMobil
{

public:
	TelefonMobil(string producator = "", int nivelBaterie = 0)
	{
		this->producator = producator;
		this->nivelBaterie = nivelBaterie;
	}

private:
	string producator;
	int nivelBaterie;

	friend ostream& operator<<(ostream& out, TelefonMobil t);
};

ostream& operator<<(ostream& out, TelefonMobil t)
{
	cout << "Producator: ";
	out << t.producator << endl;
	cout << "Nivel baterie: ";
	out << t.nivelBaterie << endl;
	return out;
}

int main()
{
	int x = 15;
	//cin >> x;
	cout << x << endl;
	cerr << x + 1 << endl;

	cout << hex << x << endl;
	cout << oct << x << endl;
	float y = 5.123456f;
	cout << setprecision(3) << y << endl;
	cout << setw(3) << setfill('$') << setiosflags(ios::left) << dec << x << endl;
	cout << resetiosflags(ios::showpoint);
	cout << setiosflags(ios::scientific);
	cout << y << endl;
	cout << resetiosflags(ios::scientific);

	cout << "y = ";
	cin >> y;

	char nume[30];
	cout << "Nume = ";
	cin >> ws;
	cin.getline(nume, 29);
	cout << "x = ";
	cin >> x;
	if (cin.fail())
	{
		cout << "The value is not an integer" << endl;
	}

	cout << nume << endl;

	string prenume;
	cout << "prenume = ";
	cin >> ws;
	getline(cin, prenume);
	cout << prenume << endl;

	ofstream f("fisier.txt", ios::app);
	f << "informatie 1" << endl;
	f << y << endl;
	f.close();

	ifstream g;
	g.open("fisier.txt");
	string line = "";
	getline(g, line);
	float z;
	g >> z;
	g.close();
	
	cout << line << endl;
	cout << z << endl;

	TelefonMobil t("Apple", 75);
	cout << t;

	ofstream fisier("telefon.txt");
	fisier << t;
	fisier.close();
}