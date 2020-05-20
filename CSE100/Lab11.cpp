#include <iostream>
#include <vector>
#include <queue>

#define MAX_INT 2147483647

using namespace std;

struct Node
{
    int letter = 10;
    int num = 0;
    Node* left = NULL;
    Node* right = NULL;
};

vector<Node*> Huffman(vector<Node*> thelist)
{
    int initialsize = 6;
    vector<int> visited;

    while(initialsize != 11)
    {
        int min1 = MAX_INT;
        int min1pos = -1;
        int min2 = MAX_INT;
        int min2pos = -1;

        for(int i = 0; i < thelist.size(); i++)
        {
            int skip = 0;
            if(thelist[i]->num < min1)
            {
                for(int j = 0; j < visited.size(); j++)
                {
                    if(visited[j] == thelist[i]->num)
                    {
                        skip = 1;
                        break;
                    }
                }

                if(skip != 1)
                {
                    min1 = thelist[i]->num;
                    min1pos = i;
                }
            }
        }
        visited.push_back(thelist[min1pos]->num);

        for(int k = 0; k < thelist.size(); k++)
        {
            int skip = 0;
            if(thelist[k]->num < min2)
            {
                for(int a = 0; a < visited.size(); a++)
                {
                    if(visited[a] == thelist[k]->num)
                    {
                        skip = 1;
                        break;
                    }
                }

                if(skip != 1)
                {
                    min2 = thelist[k]->num;
                    min2pos = k;
                }
            }
        }
        visited.push_back(thelist[min2pos]->num);
        
        int sum = min1 + min2;

        Node* temp = new Node();
        temp->num = sum;
        temp->letter = initialsize;
        temp->left = thelist[min1pos];
        temp->right = thelist[min2pos];
        thelist.push_back(temp);

        initialsize++;
    }

    return thelist;
}

vector<string> Traversal(vector<Node*> lastgroup, int currentpos, vector<string> code, string codes)
{
    if(lastgroup[currentpos]->left == NULL && lastgroup[currentpos]->right == NULL)
    {
        int pos = -1;
        for(int t = 0; t < 6; t++)
        {
            if(lastgroup[t]->num == lastgroup[currentpos]->num)
            {
                pos = t;
                code[pos] = codes;
                break;
            }
        }
    }
    else
    {
        codes = codes + "0";
        code = Traversal(lastgroup, lastgroup[currentpos]->left->letter, code, codes);
        codes.pop_back();
        codes = codes + "1";
        code = Traversal(lastgroup, lastgroup[currentpos]->right->letter, code, codes);
        codes.pop_back();

    }

    return code;
}

int main(int argc,char **argv)
{
    vector<Node*> thelist = {};

    for(int i = 0; i < 6; i++)
    {
        Node* temp = new Node();
        cin >> temp->num;
        temp->letter = i;

        thelist.push_back(temp);
    }

    vector<Node*> lastgroup = Huffman(thelist);
    vector<string> code = {};
    string codes = "";
    for(int num = 0; num < 6; num++)
    {
        code.push_back(codes);
    }

    code = Traversal(lastgroup, 10, code, codes);

    for(int q = 0; q < code.size(); q++)
    {
        switch (q)
        {
            case 0:
            cout << "A:" << code[0] << endl;
            break;

            case 1:
            cout << "B:" << code[1] << endl;
            break;

            case 2:
            cout << "C:" << code[2] << endl;
            break;

            case 3:
            cout << "D:" << code[3] << endl;
            break;

            case 4:
            cout << "E:" << code[4] << endl;
            break;

            case 5:
            cout << "F:" << code[5] << endl;
            break;

            default:
            break;
        }
    }
}