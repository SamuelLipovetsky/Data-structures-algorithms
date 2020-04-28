#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define infinito 9999999
map<vector<char>, map<vector<char>, int>> mapa;
map<vector<char>, vector<char>> pf;
int count = 0;
int maior = 0;

// cout << " " << maior << endl;
int func(vector<char> a, vector<char> b)
{

    if (a == b)
    {
        mapa[a][b] = 0;
        mapa[b][a] = 0;
    }
    else
    {
        if (pf.count(a) == 0 && pf.count(b) != 0)
        {
        }
        int temp = 1 + min(func(a, pf[b]), func(pf[a], b));
        if (mapa[a][b] < temp)
        {
            mapa[a][b] = temp;
            mapa[b][a] = mapa[a][b];
        }
    }
    if (mapa[a][b] > maior)
    {
        maior = mapa[a][b];
    }
    return mapa[a][b];
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    vector<char> pai;
    vector<char> filho;

    int control = 0;
    string a;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {

        string all;
        pai.clear();
        filho.clear();
        getline(cin, all);

        control = 0;
        for (auto i : all)
        {
            if (i == ' ')
            {
                control = 1;
            }
            else if (control == 0)
            {
                pai.push_back(i);
            }
            else
            {
                filho.push_back(i);
            }
        }
        pf[filho] = pai;
        mapa[pai][filho] = 1;
        mapa[filho][pai] = 1;
    }

    for (auto &x : mapa)
    {

        for (auto &i : mapa)
        {
            func(x.first, i.first);
        }
    }
    cout << maior << endl;
    for (auto &x : mapa)
    {
        for (auto i : x.first)
        {
            cout << i;
        }
        cout << " ";
        for (auto i : x.second)
        {

            for (auto j : i.first)
            {
                cout << j;
            }
            cout << " ";

            cout << i.second << " ";
        }
        cout << endl;
    }
}
