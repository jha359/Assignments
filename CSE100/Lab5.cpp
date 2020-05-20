//Code created with reference to pseudocode in the textbook
#include <iostream>
#include <stdlib.h>

#define MAX_INT 2147483647

using namespace std;

int Partition(int* array, int start, int end)
{
    int x = array[end];
    int i = start - 1;
    int temp = 0;
    for(int j = start; j <= end - 1; j++)
    {
        if(array[j] <= x)
        {
            i = i + 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    return i + 1;
}

int RandomPartition(int* array, int start, int end)
{
    int i = rand() % (start - end) + start;
    int temp = array[end];
    array[end] = array[start];
    array[start] = temp;

    return Partition(array, start, end);
}

void RandomQuicksort(int* array, int start, int end)
{
    if(start < end)
    {
        int q = RandomPartition(array, start, end);
        RandomQuicksort(array, start, q - 1);
        RandomQuicksort(array, q + 1, end);
    }
}

int main(int argc,char **argv)
{
    int* thelist;
    int thelistsize = 0;

    cin >> thelistsize;
    thelist = new int[thelistsize];

    for (int i = 0; i < thelistsize; i++)
    {
        cin >> thelist[i];
    }

    RandomQuicksort(thelist, 0, thelistsize - 1);

    for(int j = 0; j < thelistsize; j++)
    {
        cout << thelist[j] << ";";
    }
}
