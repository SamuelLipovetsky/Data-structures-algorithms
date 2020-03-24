#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
string a;
string b;
int l = 0;
int lcs[81][81];
printLcs()
{
    for (int i = 1; i < a.size() + 1; i++)
    {
        for (int j = 1; j < b.size() + 1; j++)
        {
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }
    cout << lcs[a.size()][b.size()];
}
int set_zero()
{
    //checar os tamanhos
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            lcs[i][j] = 0;
        }
    }
}
int getall()
{
    vector<char> all[81];

    int tam[81] = {};
    int usados[81][25] = {};
    for (int i = 1; i < a.size() + 1; i++)
    {
        for (int j = 1; j < b.size() + 1; j++)
        {

            if (a[i - 1] == b[j - 1] && usados[lcs[i - 1][j - 1]][b[j - 1] - 97] == 0)
            {
                all[lcs[i - 1][j - 1]].push_back(a[i - 1]);
                usados[i - 1][b[j - 1] - 97] = 1;
                tam[i - 1]++;
            }
        }
    }

    for (int i = 0; i < l; i++)
    {
        cout << "{ ";
        for (auto j : all[i])
        {
            cout << j << " ";
        }
        cout << "} \n ";
    }
}
int Common()
{
    set_zero();

    for (int i = 0; i < a.size() + 1; i++)
    {
        for (int j = 0; j < b.size() + 1; j++)
        {
            if (j > 0 && i > 0)
            {
                if (a[i - 1] == b[j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else
                {
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }
    }
    // printLcs();
    l = lcs[a.size()][b.size()];
}
int main()
{
    int m;
    // cin >> m;
    string aa, bb;
    // for (int i = 0; i < m; i++)
    // {
    getline(cin, a);
    getline(cin, b);
    Common();
    getall();
    // }
}