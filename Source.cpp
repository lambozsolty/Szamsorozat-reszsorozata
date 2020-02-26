#include <iostream> 
#include <vector> 
#include <cmath> 
#include <ctime>

using namespace std;

void backTracking(vector<int>&, vector<vector<int> >&, vector<int>&, int);
vector<vector<int>> reszSorozat(vector<int>&);
void kiir(vector<vector<int>>);
vector<int> generalSzamok(int);

int ertekadasok;

int main(int argc, const char* argv[])
{ 
    if(argc != 3)
    {
        cout << "Hibas input!" << endl;

        exit(1);
    }


    if (atoi(argv[2]) != 1)
    {
        cout << "Csak a sima backtracking van implementalva!" << endl;
    }
    else
    {
        vector<int> sorozat = generalSzamok(atoi(argv[1]));

        cout << "Generalt szamsorozat: ";

        for (int i = 0; i < sorozat.size(); i++)
        {
            cout << sorozat.at(i) << " ";
        }

        cout << endl;

        vector<vector<int>> eredmeny = reszSorozat(sorozat);

        //kiir(eredmeny);

        cout << "Ertekadasok szama: " << ertekadasok << endl;
    }
    
    return 0;

}

void backTracking(vector<int>& sorozat, vector<vector<int> >& eredmeny, vector<int>& reszs, int index)
{
    ertekadasok++;

    eredmeny.push_back(reszs);

    for (int i = index; i < sorozat.size(); i++)
    {
        reszs.push_back(sorozat[i]);

        backTracking(sorozat, eredmeny, reszs, i + 1);

        reszs.pop_back();
    }

    return;
}


vector<vector<int> > reszSorozat(vector<int>& sorozat)
{
    vector<int> reszs;
    vector<vector<int>> eredmeny;

    backTracking(sorozat, eredmeny, reszs, 0);

    return eredmeny;
}

void kiir(vector<vector<int>> eredmeny)
{
    for (int i = 0; i < eredmeny.size(); i++)
    {
        for (int j = 0; j < eredmeny[i].size(); j++)
        {
            cout << eredmeny[i][j] << " ";
        }

        cout << endl;
    }
}

vector<int> generalSzamok(int n)
{
    srand(time(NULL));

    vector<int> sorozat;

    for (int i = 0; i < n; i++)
    {
        sorozat.push_back(rand() % 10);
    }

    return sorozat;
}
