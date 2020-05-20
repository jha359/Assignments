#include <iostream>
#include <string>
#include <vector>


#define MAX_INT 2147483647

using namespace std;

//Collaborated with Patrick Doran and used cplusplus.com for help

int main(int argc,char **argv)
{
    int thelistsize = 0;
    cin >> thelistsize;

    vector<vector<int>> thelist;
    vector<int> otherlist = {};

    for(int i = 0; i < thelistsize; i++)
    {
        thelist.push_back(otherlist);
    }
    string userinput;

    cin >> userinput;

    while(userinput != "e")
    {
        if(userinput.at(0) == 'i')
        {
            string tempinput = userinput.erase(0,1);
            int numinput = stoi(tempinput);
            int function = numinput % thelistsize;

            thelist[function].insert(thelist[function].begin(), numinput);

            cin >> userinput;
        }
        else if(userinput.at(0) == 'd')
        {
            string tempinput = userinput.erase(0,1);
            int numinput = stoi(tempinput);
            int function = numinput % thelistsize;
            int foundit = 0;

            for(int i = 0; i < thelist[function].size(); i++)
            {
                if(thelist[function][i] == numinput)
                {
                    foundit = 1;
                }
                if(foundit == 1)
                {
                    thelist[function].erase(thelist[function].begin() + i);
                    cout << numinput << ":DELETED;" << endl;
                    break;
                }
            }
            if(foundit == 0)
            {
                cout << numinput << ":DELETE_FAILED;" << endl;
            }
        }
        else if(userinput.at(0) == 's')
        {
            string tempinput = userinput.erase(0,1);
            int numinput = stoi(tempinput);
            int function = numinput % thelistsize;
            int foundit = 0;

            for(int i = 0; i < thelist[function].size(); i++)
            {
                if(thelist[function][i] == numinput)
                {
                    foundit = 1;
                }
                if(foundit == 1)
                {
                    cout << numinput << ":FOUND_AT" << function << "," << i << ";" << endl;
                    break;
                }
            }
            if(foundit == 0)
            {
                cout << numinput << ":NOT_FOUND;" << endl;
            }

            cin >> userinput;
        }
        else if(userinput == "o")
        {
            for(int i = 0; i < thelistsize; i++)
            {
                cout << i << ":";
                for(int j = 0; j < thelist[i].size(); j++)
                {
                    cout << thelist[i][j] << "->";
                }
                cout << ";" << endl;
            }

            cin >> userinput;
        }
        else
        {
            cin >> userinput;
        }
    }
}