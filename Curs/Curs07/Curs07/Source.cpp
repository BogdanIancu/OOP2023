#include "TelefonMobil.h"
#include <iostream>
using namespace std;

int main()
{
	TelefonMobil t1;
	t1.nivelBaterie = 50;
	t1.incarca(20);
	cout << t1.nivelBaterie << endl;
}