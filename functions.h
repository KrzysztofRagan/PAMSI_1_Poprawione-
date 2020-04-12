#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#ifndef MAX_RANDOM_VALUE
    #define MAX_RANDOM_VALUE 100 //You must to redefine this constant if You would like to generate diffriend max random value
#endif
#include <algorithm>

using namespace std;
template <class Item>
Item** createArray(int size, int count)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    Item **array=new Item*[count];
    for(int i=0;i<count;i++)
        array[i]=new Item[size];
    return array;
}
template <class Item>
void copyArray(Item ** array, Item ** arrayCopy, int size, int count)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    for(int i=0;i<count;i++)
    copy(array[i],array[i]+size,arrayCopy[i]);
}
template <class Item>
void fillRandomly(Item ** array, int size, int count, double precentage)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    if(precentage<0 || precentage>100)
        throw "Precentage must be positive and lower than 100";
    int rightOrderCount=static_cast<int>(precentage*size/100);
    for(int j=0;j<count;j++)
    {
        for(int i=0;i<size;++i)
            array[j][i]=rand()%MAX_RANDOM_VALUE;
        sort(array[j],array[j]+rightOrderCount);
    }

}
template <class Item>
void fillRandomlyInOrder(Item ** array, int size, int count, double order=0) // 0 for revers order
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    for(int j=0;j<count;j++)
    {
        for(int i=0;i<size;++i)
            array[j][i]=rand()%MAX_RANDOM_VALUE;
        sort(array[j],array[j]+size);
        if(static_cast<int>(order)==0)
            reverse(array[j],array[j]+size);
    }
}

template <class Item>
void displayArray(Item ** array, int size, int count)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    for(int j=0;j<count;j++)
    {
        for(int i=0;i<size;++i)
            cout << array[j][i] << " ";
        cout<<endl;
    }
}
template <class Item>
bool checkArrayOrder(Item * array, int size, int count)
{
    if(size<1)
        throw "Table size must be greater than 1 element";
    if(count<1)
        throw "Table size must be greater than 1 element";
    for(int j=0;j<count;j++)
    {
        for(int i=0;i<size-1;++i)
            if(array[j][i]>array[j][i+1])
                return false;
    }
    return true;
}
#endif // FUNCTIONS_H
