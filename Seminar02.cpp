#include <iostream>
using namespace std;

void afisare(int x)
{
    cout << x << endl;
}

int main()
{
    //pointer la int
    //e recomandat ca pointerii sa nu ramana neinitializati
    int* p = nullptr;
    int x = 2;
    afisare(x);

    //operatorul & extrage adresa unei variabile
    p = &x;
    //valoarea lui p (o adresa)
    cout << p << endl;
    //dereferentiere (extragerea valorii de la adresa salvata in p)
    cout << *p << endl;
    //adresa lui p
    cout << &p << endl;

    //un pointer ocupa 4 bytes pe arhitectura x86
    //si 8 bytes pe arhitectura x64
    cout << sizeof(p) << endl;
    //cresterea adresei cu 3 x sizeof(int)
    int* q = p + 3;
    cout << q << endl;

    //scade adresa cu sizeof(int)
    p--;
    cout << p << endl;

    //diferenta a doi pointeri reprezinta
    //numarul de variabile de acel tip care
    //pot incapea intre cele doua adrese
    cout << q - p << endl;

    //void* reprezinta un vector la orice tip de data
    void* t = &x;

    //nu poate fi folosit in mod direct, ci doar dupa
    //ce specificam prin cast tipul de pointer
    //cout << *t << endl; <- va genera eroare de compilare
    cout << *((int*)t) << endl;

    //definirea unei referinte
    //se comporta ca un pointer, dar extrage adrese
    //si se dereferentiaza automat
    int& r = x;
    x++;
    cout << r << endl;

    //dimensiunea unui vector static trebuie sa fie constanta
    const int n = 10;
    int v[n];
    //variabila aferenta unui vector retina adresa primului element
    cout << v;
    v[3] = 9;
    //echivalent cu v[3]
    cout << *(v + 3) << endl;
    //dimensiunea unui vector alocat static se poate calcula
    //impartind dimensiunea intregului vector la
    //dimensiunea unui element
    cout << sizeof(v) / sizeof(v[0]) << endl;
}