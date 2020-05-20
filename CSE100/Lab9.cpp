#include <iostream>
#include <vector>
#include <stack>

#define MAX_INT 2147483647

using namespace std;

vector<vector<int>> DFS(vector<vector<int>> thelist, vector<vector<int>>DFSlist, int num)
{
    for(int i = 0; i < thelist[num].size(); i++)
    {
        int already = 0;
        for(int j = 0; j < DFSlist[0].size(); j++)
        {
            if(DFSlist[0][j] == thelist[num][i])
            {
                already = 1;
                break;
            }
        }

        if(already == 0)
        {
            DFSlist[0].push_back(num);
            DFSlist = DFS(thelist, DFSlist, thelist[num][i]);
        }
    }
    DFSlist[0].push_back(num);
    DFSlist[1].push_back(num);
    return DFSlist;
}

int main(int argc,char **argv)
{
    int totalvert = 0;
    cin >> totalvert;

    vector<vector<int>> thelist;
    vector<int> otherlist = {};

    for(int i = 0; i < totalvert; i++)
    {
        thelist.push_back(otherlist);
    }

    int totaledge = 0;
    cin >> totaledge;

    int from = 0;
    int to = 0;

    for(int j = 0; j < totaledge; j++)
    {
        cin >> from >> to;
        thelist[from].push_back(to);
    }

    vector<vector<int>> DFSlist;
    DFSlist.push_back(otherlist);
    DFSlist.push_back(otherlist);
    
    for(int k = 0; k < totalvert; k++)
    {
        int already = 0;
        for(int check = 0; check < DFSlist[0].size(); check++)
        {
            if(k == DFSlist[0][check])
            {
                already = 1;
                break;
            }
        }
        if(already == 0)
        {
            DFSlist = DFS(thelist, DFSlist, k);
        }
    }
    
    vector<vector<int>> thelist2;
    for(int i = 0; i < totalvert; i++)
    {
        thelist2.push_back(otherlist);
    }

    for(int j = 0; j < totalvert; j++)
    {
        for(int k = 0; k < thelist[j].size(); k++)
        {
            thelist2[thelist[j][k]].push_back(j);
        }
    }

    vector<vector<int>> DFSlist2;
    for(int result = 0; result < totalvert + 2; result++)
    {
        DFSlist2.push_back(otherlist);
    }

    for(int reverse = DFSlist[1].size() - 1; reverse >= 0; reverse--)
    {
        int already = 0;
        for(int check = 0; check < DFSlist2[0].size(); check++)
        {
            if(DFSlist[1][reverse] == DFSlist2[0][check])
            {
                already = 1;
                break;
            }
        }
        if(already == 0)
        {
            DFSlist2 = DFS(thelist2, DFSlist2, DFSlist[1][reverse]);
            int marker = 0;

            for(int a = 0; a < DFSlist2[1].size(); a++)
            {
                int already = 0;
                if(DFSlist2[DFSlist2[1][a] + 2].size() > 0)
                {
                    already = 1;
                    marker++;
                }

                if(already == 0)
                {
                    if(marker > 0)
                    {
                        for(int b = marker; b < DFSlist2[1].size(); b++)
                        {
                            DFSlist2[DFSlist2[1][a] + 2].push_back(DFSlist2[1][b]);
                        }
                    }
                    else
                    {
                        for(int b = 0; b < DFSlist2[1].size(); b++)
                        {
                            DFSlist2[DFSlist2[1][a] + 2].push_back(DFSlist2[1][b]);
                        }
                    }  
                }
            }
        }
    }

    for(int read = 2; read < DFSlist2.size(); read++)
    {
        int minimum = DFSlist2[read][0];
        for(int last = 0; last < DFSlist2[read].size(); last++)
        {
            if(DFSlist2[read][last] < minimum)
            {
                minimum = DFSlist2[read][last];
            }
        }
        cout << minimum << endl;
    }
}