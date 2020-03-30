#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#define max 9999999;
using namespace std;
typedef pair<int, int> node;
typedef vector<vector<node>> graph;
int teste = 1;
void prim(graph g)
{
    vector<pair<int, int>> all;
    set<int> setu;
    vector<int> u;
    setu.insert(0);
    u.push_back(0);
    int min = 0;
    int to_add;
    int d = 5;
    int atual;
    while (true)
    {
        min = max;
        to_add = 0;
        int aa;
        if (u.size() == g.size())
        {
            break;
        }
        for (int i = 0; i < u.size(); i++)
        {
            atual = u[i];
            for (int j = 0; j < g[atual].size(); j++)
            {
                int custo = g[atual][j].first;
                int prox = g[atual][j].second;
                if (custo < min && setu.count(prox) == 0)
                {
                    min = custo;
                    to_add = g[atual][j].second;
                    aa = atual;
                }
            }
        }

        all.push_back(make_pair(aa, to_add));
        u.push_back(to_add);
        setu.insert(to_add);
    }
    cout << "Teste " << teste << "\n";

    teste++;
    for (auto i : all)
    {
        if (i.first < i.second)
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        else
            cout << i.second + 1 << " " << i.first + 1 << "\n";
    }
    cout << "\n";
}

int main()
{
    graph g;
    int n, m, x, y, c;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            g[x - 1].push_back(make_pair(c, y - 1));
            g[y - 1].push_back(make_pair(c, x - 1));
        }
        prim(g);
    }
}
