//Mergesort and Merge code created with reference to pseudocode from textbook
//Partial collaboration with Patrick Doran

#include <iostream>

#define MAX_INT 2147483647

using namespace std;
  
int* Merge(int* sortinglist, int first, int mid, int last)
{
    int x = mid - first + 1;
    int y = last - mid;
    
    int* left = new int[x + 1];
    int* right = new int[y + 1];

    int lc = 1;
    int rc = 1;

    for (int lc = 1; lc <= x; lc++)
    {
        left[lc] = sortinglist[first + lc - 1];
    }

    for (int rc = 1; rc <= y; rc++)
    {
        right[rc] = sortinglist[mid + rc];
    }

    for (int k = first; k <= last; k++)
    {
        if (lc >= x + 1)
        {
            sortinglist[k] = right[rc];
            rc = rc + 1;
        }
        else if (rc >= y + 1)
        {
            sortinglist[k] = left[lc];
            lc = lc + 1;
        }
        else
        {
            if (left[lc] <= right[rc])
            {
                sortinglist[k] = left[lc];
                lc = lc + 1;
            }
            else
            {
                sortinglist[k] = right[rc];
                rc = rc + 1;
            }
        }
        
    }

}

void Mergesort(int* array, int begin, int end)
{
    if(begin < end)
    {
        int middle = (begin + end)/2;
        Mergesort(array, begin, middle);
        Mergesort(array, middle + 1, end);
        Merge(array, begin, middle, end);
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

    int a = 0;
    int b = thelistsize - 1;

    Mergesort(thelist, a, b);

    for (int i = 0; i < thelistsize; i++)
    {
        cout << thelist[i] << ";";
    }
}