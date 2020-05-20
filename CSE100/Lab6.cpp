#include <iostream>
#include<vector>

#define MAX_INT 2147483647

using namespace std;

//Collaborated with Patrick Doran and David Nguyen
vector<vector<int>> CountingSort(vector<vector<int>> A, int digit)
{
    int templist[10] = {};
    vector<vector<int>> final = A;

    for(int fill = 0; fill < 10; fill++)
    {
        templist[fill] = 0;
    }

    for(int i = 0; i < A.size(); i++)
    {
        templist[A[i][digit]] = templist[A[i][digit]] + 1;
    }

    for(int j = 1; j < 10; j++)
    {
        templist[j] = templist[j] + templist[j - 1];
    }

    for(int k = A.size() - 1; k >= 0; k--)
    {
        final[templist[A[k][digit]] - 1] = A[k];
        templist[A[k][digit]] = templist[A[k][digit]] - 1;
    }
    A = final;
    return A;
}

vector<vector<int>> RadixSort(vector<vector<int>> array)
{
    for(int i = 9; i >= 0; i--)
    {
        array = CountingSort(array, i);
    }
    return array;
}

int main(int argc,char **argv)
{
    int thelistsize = 0;
    cin >> thelistsize;

    vector<vector<int>> thelist;

    int smallinput = 0;
    for(int i = 0; i < thelistsize; i++)
    {
        vector<int> smallerlist;

        for(int j = 0; j < 10; j++)
        {
            cin >> smallinput;
            smallerlist.push_back(smallinput);
        }
        thelist.push_back(smallerlist);
    }

    thelist = RadixSort(thelist);

    for(int i = 0; i < thelistsize; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << thelist[i][j]<< ";";
        }
        cout << endl;
    }
}