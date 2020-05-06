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
vector<vector<int>> grafo;
vector<int> usados;
vector<int> distancias;
vector<int> usados_local;

bool protec(int posicao, int forca)
{

    int counter = 0;
    queue<int> fila;

    fila.emplace(posicao);
    usados_local.resize(usados.size(), 0);
    vector<int> to_add;
    if (forca == 0)
    {
        if (usados[posicao] == 1)
        {
            return false;
        }
        usados[posicao] = 1;
    }
    else
    {
        distancias[posicao] = 0;
        int atual = fila.front();
        while (fila.size() > 0)
        {

            atual = fila.front();

            if (usados[atual] == 1)
            {
                return false;
            }
            usados_local[atual] = 1;

            to_add.push_back(atual);
            for (auto prox : grafo[atual])
            {

                if (usados_local[prox] == 0 && distancias[atual] < forca)
                {

                    if (distancias[prox] > distancias[atual] + 1)
                    {
                        distancias[prox] = distancias[atual] + 1;
                    }
                    fila.emplace(prox);
                }
            }

            fila.pop();
        }

        for (auto i : to_add)
        {
            usados[i] = 1;
        }
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, m, t;
    int x, y;
    cin >> t;
    for (int l = 0; l < t; l++)
    {

        cin >> n >> r >> m;
        usados_local.clear();
        usados.clear();
        distancias.clear();
        grafo.clear();
        grafo.resize(n);
        usados.resize(n, 0);
        usados_local.resize(n, 0);
        distancias.resize(n, infinito);
        for (int i = 0; i < r; i++)
        {
            cin >> x >> y;
            grafo[x - 1].push_back(y - 1);
            grafo[y - 1].push_back(x - 1);
        }
        int k, s;

        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> k >> s;

            if (!protec(k - 1, s) && flag == 0)
            {

                flag = 1;
            }
        }
        int quant_usados = 0;
        for (auto i : usados)
        {
            if (i == 1)
                quant_usados++;
        }

        if (quant_usados < n)
            flag = 1;
        if (!flag)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
}