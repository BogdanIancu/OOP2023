#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int n = 100;
	//dimensiunea unui vector static trebuie sa fie o constanta
	float v[n];
	//dimensiunea unui vector alocat static poate fi calculata
	cout << sizeof(v) / sizeof(v[0]) << endl;
	//numele vectorului este un pointer catre primul element
	cout << v << endl;

	int m = 7;
	//alocare dinamica vector cu malloc
	float* arr = (float*)malloc(m * sizeof(float));
	if (arr != NULL)
	{
		arr[2] = 20.5f;
		cout << *(arr + 2) << endl;
	}

	//dimensiunea unui vector alocat dinamic NU poate fi calculata
	//cout << sizeof(arr) / sizeof(arr[0]) << endl;

	//dezalocare cu free
	free(arr);
	//evitare dangling pointer
	arr = nullptr;

	//alocare si dezalocare cu new si delete
	float* w = new float[m];
	w[1] = 81.7f;
	//...
	delete[] w;
	w = nullptr;

	//matrice alocata static
	int mat[5][6];
	mat[0][0] = 12;
	cout << sizeof(mat) << endl; //dimensiune totala matrice in bytes
	cout << sizeof(mat) / sizeof(mat[0]) << endl;//numar linii
	cout << sizeof(mat[0]) / sizeof(mat[0][0]) << endl;// numar coloane

	//alocare dinamica matrice
	int** mx = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		mx[i] = new int[6];
	}
	//...
	
	//dezalocare matrice alocata dinamic
	for (int i = 0; i < 5; i++)
	{
		delete[] mx[i];
	}
	delete[] mx;
	mx = NULL;

	//in C stringurile sunt vectori de caractere
	char s1[8];
	strcpy_s(s1, "ceva");
	cout << s1 << endl;
	//va returna nr de bytes ocupati
	cout << sizeof(s1) << endl;
	//va returna lungimea sirului (cate caracatere sunt pana la \0)
	cout << strlen(s1) << endl;

	//alocare dinamica sir de caractere
	//pentru a salva N caractere e nevoie sa alocam N+1
	char* s2 = new char[strlen(s1) + 1];
	strcpy_s(s2, strlen(s1) + 1, s1);
	cout << s2 << endl;

	delete[] s2;
	s2 = nullptr;

	//in C++ avem tipul(clasa) string
	//ce nu necesita vectori sau alocare dinamica
	string s3 = "ceva";
	cout << s3 << endl;
	s3 += '!';
	cout << s3 << endl;

	cout << s3.length() << endl;

	//transformare din char* in string
	string s4 = s1;

	//transformare din string in char*
	const char* s5 = s3.c_str();
}