#include <iostream>
#include <ctime>
using namespace std;

#define MAX_RANDOM_VALUE 10 //ustawiamy maksymalną wartość liczby losowej - domyślnie 100

#include "functions.h" //funkcje pomocnicze takie jak createArray, fillRandomly itd...
#include "quicksort.h" //sortowanie szybkie
#include "mergesort.h" //sortowanie przez scalanie
#include "introspectivesort.h" //sortowanie introspektywne hybrydowe

#define TYP int
#define SIZE 10000 //wielkość tablicy
#define COUNT 100 //ilość powtórzeń
#define PREC 0  //wartość 0 dla pierwszego przypadku, czyli tablicy całkowicie losowej
                //wartość inna dla PREC procent początkowo uporządkowanych elementów (25,50,75....)
                //dla tworzenia tablicy uporządkowanej w odwrotnej kolejności PREC wynosi 0
                //dla tworzenia tablicy uporządkowanej w normalnej kolejności PREC ma dowolną wartość poza 0

#define fillArray(x,y,z,o) fillRandomly(x,y,z,o)        //funkcja wypełniająca tablicę w sposób losowy
                                                    //lub wypełniająca tablicę w sposób losowy z PREC procent uporządkowanych elementów
                                                    //w przypadku generowania tablicy w sposób uporządkowany należy zakomentować tą linię
//#define fillArray(x,y,z,o) fillRandomlyInOrder(x,y,z,o)   //w przypadku generowania tablicy w sposób losowy należy zakomentować tą linię
int main()
{
    clock_t start;
    long czas1=0,czas2=0,czas3=0;
    bool error1=false,error2=false,error3=false;
    try {

        cout<<"Czas wykonywania algorytmów sortowania dla "<<COUNT<<" tablic o wielkości "<<SIZE<<" elementów:"<<endl;

        srand(static_cast<unsigned int>(time(nullptr)));

        TYP **tablica = createArray<TYP>(SIZE,COUNT);
        TYP **tablica1 =createArray<TYP>(SIZE,COUNT);
        TYP **tablica2 =createArray<TYP>(SIZE,COUNT);
        TYP **tablica3 =createArray<TYP>(SIZE,COUNT);

        fillArray(tablica,SIZE,COUNT,PREC);
        if(SIZE<30 && COUNT<10)
            displayArray(tablica,SIZE,COUNT);

        copyArray(tablica,tablica1,SIZE,COUNT);
        copyArray(tablica,tablica2,SIZE,COUNT);
        copyArray(tablica,tablica3,SIZE,COUNT);


        ///** sortowanie szybkie **//////
        start = clock();
        for (int i=0;i<COUNT;i++)
            quickSort<TYP>(tablica1[i],SIZE);
        czas1=clock()-start;

        if(!checkArrayOrder(tablica1,SIZE,COUNT))
        {
            cout<<"Sortowanie szybkie nieudane!"<<endl;
            error1=true;
        }

        ///** sortowanie przez scalanie **//////
        start = clock();
        for (int i=0;i<COUNT;i++)
            mergeSort<TYP>(tablica2[i],SIZE);
        czas2=clock()-start;

        if(!checkArrayOrder(tablica2,SIZE,COUNT))
        {
            cout<<"Sortowanie przez scalanie nieudane!"<<endl;
            error2=true;
        }

        ///** sortowanie introspektywne **//////
        start = clock();
        for (int i=0;i<COUNT;i++)
            introspectiveSort<TYP>(tablica3[i],SIZE);
        czas3=clock()-start;

        if(!checkArrayOrder(tablica3,SIZE,COUNT))
        {
            cout<<"Sortowanie introspektywne nieudane!"<<endl;
            error3=true;
        }


        cout<<"Sortowanie przez scalanie: średni czas wykonywania: "<<1000.0*czas2/CLOCKS_PER_SEC<<"ms,\t";
        cout<<(error2?"Sortowanie niektórych tablic nie powiodło się":"Wszystkie tablice posortowano poprawnie.")<<endl;

        cout<<"Sortowanie szybkie:        średni czas wykonywania: "<<1000.0*czas1/CLOCKS_PER_SEC<<"ms,\t";
        cout<<(error1?"Sortowanie niektórych tablic nie powiodło się":"Wszystkie tablice posortowano poprawnie.")<<endl;

        cout<<"Sortowanie introspektywne: średni czas wykonywania: "<<1000.0*czas3/CLOCKS_PER_SEC<<"ms,\t";
        cout<<(error3?"Sortowanie niektórych tablic nie powiodło się":"Wszystkie tablice posortowano poprawnie.")<<endl;

    } catch (const char * err) {
        cerr<<endl<<err<<endl;
    }
    return 0;
}
