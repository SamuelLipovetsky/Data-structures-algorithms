#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
map<string, int> mapa_inv;
map<int, string> mapa;
string a, b;
string temp;
vector<vector<char>> all;
typedef vector<vector<pair<int, int>>> graph;
map<int, string> mapa_caminho;
graph g;

int crit_table[100][100];

int bfs(int a, int b)
{
    vector<int> usados_local;
    usados_local.resize(g.size(), 0);
    queue<int> fila;
    fila.emplace(0);
    int aa = a;
    int bb = b;
    usados_local[0] = 1;
    while (fila.size() > 0)
    {
        int atual = fila.front();

        for (int i = 0; i < g[atual].size(); i++)
        {
            int elemento = g[atual][i].first;
            if (atual == aa && i == b)
            {

                continue;
            }
            else
            {
                if (usados_local[elemento] == 0)
                {
                    usados_local[elemento] = 1;
                    fila.emplace(elemento);
                }
            }
        }
        fila.pop();
    }
    int d = 0;

    for (int i = 0; i < usados_local.size(); i++)
    {

        if (usados_local[i] == 1)
        {
            d++;
        }
    }

    // cout << d;
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    while (true)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                crit_table[i][j] = 0;
            }
        }

        g.clear();
        g.resize(n);
        cin.ignore();
        if (n == 0 || m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);

            mapa_inv[temp] = i;
        }

        for (int i = 0; i < m; i++)
        {
            getline(cin, temp);
            int control = 0;
            mapa_caminho[i] = temp;
            a.clear();
            b.clear();
            for (auto i : temp)
            {
                if (i == ' ')
                    control = 1;
                else if (control == 0)
                    a += i;
                else
                    b += i;
            }
            g[mapa_inv[b]].push_back(make_pair(mapa_inv[a], i));
        }

        vector<int> order;

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                int elemento = g[i][j].first;
                if (bfs(i, j) < n)
                {
                    if (crit_table[i][elemento] == 0)
                    {
                        crit_table[i][elemento] = 1;
                        order.push_back(g[i][j].second);
                    }
                }
            }
        }

        sort(order.begin(), order.end());
        if (order.size() == 0)
        {
            cout << "Nenhuma" << endl
                 << endl;
        }
        else
        {
            for (auto i : order)
            {
                // cout << i.first << " " << i.second << endl;
                cout << mapa_caminho[i] << endl;
            }
            cout << endl;
        }
    }
}