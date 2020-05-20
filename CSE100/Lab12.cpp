#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

struct connect
{
    int to;
    int weight;
};

int main()
{
    vector<vector<connect*>> thelist;
    vector<connect*> otherlist = {};
    int totalvert = 0;
    int totaledge = 0;

    cin >> totalvert;
    cin >> totaledge;

    for(int i = 0; i < totalvert; i++) //set up the vector of vectors; the outer vector is used as the "source" between connections
    {                                  //the inner vector keeps track of the connections with the struct, which tracks the "destination" and the weight of the edge
        thelist.push_back(otherlist);
    }

    int source;
    int dest;
    int cost;
    for(int j = 0; j < totaledge; j++)
    {
        cin >> source >> dest >> cost;

        connect* temp = new connect();
        temp->to = dest;
        temp->weight = cost;
        thelist[source].push_back(temp);
    }

    vector<int> completelist = {}; //a vector is set up to keep track of which nodes are a part of the MST; 0 is added after output because 0 is the root
    vector<vector<int>> output; //a double vector that tracks what each node's parent is (ex: output[1][0] = 0, means that 1's parent is 0.)

    for(int filler = 0; filler < totalvert; filler++)
    {
        output.push_back(completelist);
    }

    completelist.push_back(0);

    while(completelist.size() != totalvert) //Prim's algorithm adds to the MST by doing the following:
    {                                       //follow the edge with the lightest weight of the nodes already in the MST; since 0 is always the root, include 0 in the MST and find the lightest edge
        int parent;                         //add the connected node to the MST if the node does not create a cycle
        int pos;                            //repeat 2 - 3 until every node has been connected
        int minweight = MAX_INT;
        for(int k = 0; k < completelist.size(); k++) //this for loop scans the nodes in the MST
        {
            for(int r = 0; r < thelist[completelist[k]].size(); r++)// this for loop scans the connections of the current observed node in the MST
            {
                if(minweight > thelist[completelist[k]][r]->weight) //find the minimum weight
                {
                    int skip = 0;
                    for(int s = 0; s < completelist.size(); s++)
                    {
                        if(thelist[completelist[k]][r]->to == completelist[s]) //disregard the connection if it has already been accounted for in the MST
                        {
                            skip = 1;
                            break;
                        }   
                    }
                    if(skip != 1) //set the connection as the minimum edge if the node is not a part of the MST
                    {
                        minweight = thelist[completelist[k]][r]->weight;
                        pos = thelist[completelist[k]][r]->to;
                        parent = completelist[k];
                    }
                }
            }
            for(int t = 0; t < thelist.size(); t++) //the way the graph is set up essentially simulates a directed graph; to circumvent this,
            {                                       //the code will scan graph for the current node as the "destination" (ex: starting at the beginning, with just 0 in the MST,
                for(int x = 0; x < thelist[t].size(); x++) //after considering all the connections in which 0 is the "source" (ex: input is 0 1 40), it then looks for instances
                {                                           //in which 0 is the "destination" (ex: input is 5 0 20))
                    if(thelist[t][x]->to == completelist[k] && minweight > thelist[t][x]->weight)
                    {
                        int skip = 0;
                        for(int y = 0; y < completelist.size(); y++)
                        {
                            if(completelist[y] == t)
                            {
                                skip = 1;
                                break;
                            }
                        }
                        if(skip != 1)
                        {
                            minweight = thelist[t][x]->weight;
                            pos = t;
                            parent = thelist[t][x]->to;
                        }
                    }
                }
            }
        }
        completelist.push_back(pos); //once the edge with the lightest weight of the nodes in the MST has been found, add the new node to the MST
        output[pos].push_back(parent); //mark the node's parent
    }
    for(int i = 0; i < output.size(); i++)
    {
        for(int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << endl;
        }
    }
}