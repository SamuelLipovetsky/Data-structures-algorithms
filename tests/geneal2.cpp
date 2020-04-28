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
map<int, vector<char>> mapa;
map<vector<char>, int> mapa_inv;
map<vector<char>, vector<char>> pf;
int ind = 0;
int maior = 0;
vector<vector<int>> adj;
set<vector<char>> usados;
// vector<pair<int, int>> to_add;
vector<char> a1;
vector<char> a2;

int func(int a, int b)
{
    // cout << a << " " << b << " ";
    if (a == b)
    {
    }

    if (adj[a][b] != infinito)
    {
        if (adj[a][b] != infinito && adj[a][b] >= maior)
        {
            a1 = mapa[a];
            a2 = mapa[b];
            maior = adj[a][b];
        }

        return adj[a][b];
    }
    if (adj[a][b] != infinito && adj[a][b] > maior)
    {
        a1 = mapa[a];
        a2 = mapa[b];
        maior = adj[a][b];
    }
    if (pf.count(mapa[a]) == 0 && pf.count(mapa[b]) == 0)
    {
        return infinito;
    }

    if (pf.count(mapa[a]) == 0)
    {
        int m = 1 + func(mapa_inv[pf[mapa[b]]], a);
        if (m < infinito)
        {
            adj[a][b] = m;
            adj[b][a] = m;
            if (adj[a][b] != infinito && adj[a][b] > maior)
            {
                a1 = mapa[a];
                a2 = mapa[b];
                maior = adj[a][b];
            }
            return m;
        }
    }
    else if (pf.count(mapa[b]) == 0)
    {

        int m = 1 + func(mapa_inv[pf[mapa[a]]], b);
        if (m < infinito)
        {
            adj[a][b] = m;
            adj[b][a] = m;
            if (adj[a][b] != infinito && adj[a][b] > maior)
            {
                a1 = mapa[a];
                a2 = mapa[b];
                maior = adj[a][b];
            }
            return m;
        }
    }

    else
    {

        int m;
        int aa = func(mapa_inv[pf[mapa[a]]], b);
        int bb = func(mapa_inv[pf[mapa[b]]], a);

        m = 1 + min(aa, bb);

        if (m < infinito)
        {
            adj[a][b] = m;
            adj[b][a] = m;
            if (adj[a][b] != infinito && adj[a][b] > maior)
            {
                a1 = mapa[a];
                a2 = mapa[b];
                maior = adj[a][b];
            }
        }

        return m;
    }
}
int print()
{
    int t = min(a1.size(), a2.size());
    for (int i = 0; i < t; i++)
    {

        if (a1[i] > a2[i])
        {

            for (auto i : a2)
            {
                cout << i;
            }
            cout << " ";
            for (auto i : a1)
            {
                cout << i;
            }
            cout << " ";
            return 0;
        }
        else if (a1[i] < a2[i])
        {

            for (auto i : a1)
            {
                cout << i;
            }
            cout << " ";
            for (auto i : a2)
            {
                cout << i;
            }
            cout << " ";
            return 0;
        }
    }
    if (t == a1.size())
    {
        for (auto i : a1)
        {
            cout << i;
        }
        cout << " ";
        for (auto i : a2)
        {
            cout << i;
        }
        cout << " ";
    }
    else
    {
        for (auto i : a2)
        {
            cout << i;
        }
        cout << " ";
        for (auto i : a1)
        {
            cout << i;
        }
        cout << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

        int cnn = 0;
        if (usados.count(pai) == 0)
        {

            mapa[ind] = pai;
            mapa_inv[pai] = ind;
            usados.insert(pai);
            ind++;
        }
        if (usados.count(filho) == 0)
        {

            mapa[ind] = filho;
            mapa_inv[filho] = ind;
            usados.insert(filho);
            ind++;
        }
        // to_add.push_back(make_pair(mapa_inv[pai], mapa_inv[filho]));
        pf[filho] = pai;
    }
    adj.resize(usados.size());
    for (int i = 0; i < usados.size(); i++)
    {
        adj[i].resize(usados.size(), infinito);
    }

    // for (auto i : to_add)
    // {
    //     adj[i.first][i.second] = 1;
    //     adj[i.second][i.first] = 1;
    // }
    for (int i = 0; i < usados.size(); i++)
    {
        adj[i][i] = 0;
    }
    for (int i = 0; i < usados.size(); i++)
    {
        for (int j = 0; j < usados.size(); j++)
        {
            func(i, j);
        }
    }
    print();
    cout << maior << endl;
    // for (int i = 0; i < usados.size(); i++)
    // {
    //     for (int j = 0; j < usados.size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
