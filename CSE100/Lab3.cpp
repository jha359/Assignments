//Collaboration with Patrick Doran
//Code written with reference to pseudocode in textbook

#include <iostream>
#include <tuple>

#define MAX_INT 2147483647

using namespace std;


tuple <int, int, int> FindMaxCross(int* array, int small, int med, int large)
{
    int sum = array[med];
    int leftsum = sum;
    int maxleft = med;
    
    for (int i = med - 1; i >= small; i--)
    {
        sum = sum + array[i];
        if(sum > leftsum)
        {
            leftsum = sum;
            maxleft = i;
        }
    }

    sum = array[med + 1];
    int rightsum = sum;
    int maxright = med;

    for (int j = med + 2; j <= large; j++)
    {
        sum = sum + array[j];
        if(sum > rightsum)
        {
            rightsum = sum;
            maxright = j;
        }
    }
    
    return make_tuple(maxleft, maxright, leftsum + rightsum);
}

tuple <int, int, int> FindMaxSub(int* array, int begin, int end)
{
    int leftlow = 0;
    int lefthigh = 0;
    int leftsum = 0;
    int rightlow = 0;
    int righthigh = 0;
    int rightsum = 0;
    int crosslow = 0;
    int crosshigh = 0;
    int crosssum = 0;

    if (begin == end)
    {
        return make_tuple(begin, end, array[begin]);
    }
    else
    {
        int between = (begin + end) / 2;
        tie(leftlow, lefthigh, leftsum) = FindMaxSub(array, begin, between);
        tie(rightlow, righthigh, rightsum) = FindMaxSub(array, between + 1, end);
        tie(crosslow, crosshigh, crosssum) = FindMaxCross(array, begin, between, end);

        if(leftsum >= rightsum && leftsum >= crosssum)
        {
            return make_tuple(leftlow, lefthigh, leftsum);
        }
        else if(rightsum >= leftsum && rightsum >= crosssum)
        {
            return make_tuple(rightlow, righthigh, rightsum);
        }
        else
        {
            return make_tuple(crosslow, crosshigh, crosssum);
        }
        
    }
}

int main(int argc,char **argv)
{
    int* thelist;
    int thelistsize = 0;
    int finallow = 0;
    int finalhigh = 0;
    int finalsum = 0;

    cin >> thelistsize;
    thelist = new int[thelistsize];

    for (int i = 0; i < thelistsize; i++)
    {
        cin >> thelist[i];
    }

    tie(finallow, finalhigh, finalsum) = FindMaxSub(thelist, 0, thelistsize - 1);

    cout << finalsum;
    return 0;
}