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
typedef vector<vector<int>> graph;
int mais[11];
int menos[11];
int dists[1400];
int usados[1400];
queue<int> fila;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> menos[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> mais[i];
        }
        graph g;
        g.resize(1400);
        for (int i = 0; i < 1400; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - menos[j] == 0)
                {
                    g[i].push_back(0);
                }
                if (i - menos[j] > 0 && i - menos[j] + mais[j] < 1400)
                    g[i].push_back(i - menos[j] + mais[j]);
            }
        }
        //bfs

        fila.emplace(100);

        for (int i = 0; i < 1400; i++)
        {
            dists[i] = infinito;
            usados[i] = 0;
        }

        usados[100] = 1;
        dists[100] = 0;
        while (fila.size() > 0)
        {
            int atual = fila.front();

            for (int i = 0; i < g[atual].size(); i++)
            {

                int elemento = g[atual][i];
                if (usados[elemento] == 0)
                {

                    fila.emplace(elemento);
                    usados[elemento] = 1;

                    dists[elemento] = min(dists[elemento], dists[atual] + 1);
                }
            }
            fila.pop();
        }
        if (dists[0] > 1000)
        {
            cout << "cavaleiro morreu" << endl;
        }
        else
        {
            cout << dists[0] << endl;
        }
    }
}