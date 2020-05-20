#include <iostream>

//Collaboration with Patrick Doran

#define MAX_INT 2147483647

using namespace std;
  
int main(int argc,char **argv)
{
    int* thelist;
    int thelistsize = 0;
    int temp;

    cin >> thelistsize;
    thelist = new int[thelistsize];

    for (int i = 0; i < thelistsize; i++)
    {
        cin >> thelist[i];
    }

    for (int i = 1; i < thelistsize; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (thelist[j] < thelist[j-1])
            {
                temp = thelist[j];
                thelist[j] = thelist[j-1];
                thelist[j-1] = temp;
            }
        }
        
        for(int k = 0; k <= i; k++)
        {
            cout << thelist[k] << ";";
        }
        
        cout << endl;

    }

    delete[] thelist;


}