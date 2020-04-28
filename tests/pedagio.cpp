#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int c, e, l, p;
int t = 1;
int x, y;
bool adj[50][50] = {false};
set<int> usados;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c >> e >> l >> p;
    while (1)
    {
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < c; j++)
            {
                adj[i][j] = false;
            }
        }
        if (c == 0)
        {
            break;
        }
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            adj[x - 1][y - 1] = true;
            adj[y - 1][x - 1] = true;
        }
        bool usados[c] = {};
        int arr[c] = {};
        queue<int> q;
        q.emplace(l - 1);
        while (q.size() > 0)
        {
            usados[q.front()] = true;

            for (int i = 0; i < c; i++)
            {
                if (adj[q.front()][i])
                {

                    if (arr[i] == 0 && i != l - 1)
                    {
                        arr[i] = arr[q.front()] + 1;
                    }
                    else if (arr[i] > arr[q.front()] + 1)
                    {
                        arr[i] = arr[q.front()] + 1;
                    }
                    if (usados[i] == 0)
                    {
                        q.emplace(i);
                    }
                }
            }
            q.pop();
        }
        vector<int> possiveis;
        possiveis.clear();
        for (int i = 0; i < c; i++)
        {
            if (arr[i] <= p && arr[i] != 0)
            {
                possiveis.push_back(i + 1);
            }
        }
        sort(possiveis.begin(), possiveis.end());
        cout << "Teste " << t << "\n";
        t++;
        for (auto i : possiveis)
        {
            cout << i << " ";
        }
        cout << "\n \n";
        cin >> c >> e >> l >> p;
    }
}
