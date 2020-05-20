#include <iostream>

#define MAX_INT 2147483647

using namespace std;

//Code created with reference to pseudocode from textbook
//Collaborated with Patrick Doran
void MaxHeapify(int* tree, int node, int treesize)
{
    int leftpos = 2 * node;
    int rightpos = (2 * node) + 1;
    int largest = 0;
    int temp = 0;

    if(leftpos < treesize && tree[leftpos] > tree[node])
    {
        largest = leftpos;
    }
    else
    {
        largest = node;
    }

    if(rightpos < treesize && tree[rightpos] > tree[largest])
    {
        largest = rightpos;
    }

    if(largest != node)
    {
        temp = tree[node];
        tree[node] = tree[largest];
        tree[largest] = temp;

        MaxHeapify(tree, largest, treesize);
    }
}

void BuildMaxHeap(int* tree, int treesize)
{
    for (int i = (treesize / 2); i >= 0; i--)
    {
        MaxHeapify(tree, i, treesize);
    }
}

void Heapsort(int* tree, int treesize)
{
    BuildMaxHeap(tree, treesize);

    int temp = 0;

    for(int i = treesize - 1; i >= 1; i--)
    {
        temp = tree[0];
        tree[0] = tree[i];
        tree[i] = temp;

        treesize = treesize - 1;

        MaxHeapify(tree, 0, treesize);
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

    Heapsort(thelist, thelistsize);

    for(int j = 0; j < thelistsize; j++)
    {
        cout << thelist[j] << ";";
    }

    return 0;
}