#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
int adj[20][20] = {};
int size = 0;
int problem(int n, int atual, set<int> hate, set<int> usados)
{

    usados.insert(atual);
    for (int j = 0; j < n; j++)
    {
        if (adj[atual][j])
        {
            hate.insert(j);
        }
        else
        {
            if (hate.count(j) == 0 and usados.count(j) == 0)
            {
                usados.insert(j);
                if (usados.size() > size)
                {
                    size = usados.size();
                    for (auto x : usados)
                    {
                        cout << x << " ";
                    }
                    cout << endl;
                }
                problem(n, j, hate, usados);
            }
            else
            {
                return 0;
            }
        }
    }
}
int main()
{

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int testes = 1;

        for (int i = 0; i < n; i++)
        {
            int atual = 1;

            while (1)
            {
                cin >> atual;

                if (atual == 0)
                {
                    break;
                }
                adj[i][atual - 1] = 1;
                adj[atual - 1][i] = 1;
            }
        }
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            size = 0;
            set<int> hate;
            set<int> usados;
            problem(n, i, hate, usados);
        }
        cout << "Testes " << testes << endl;
        cout << size << endl;
        testes++;
    }
}
