#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define max 999999
typedef vector<vector<int>> grafo;
grafo g, dfs;
bool bfs()
{
    queue<int> fila;
    fila.emplace(0);
    vector<int> usados;
    usados.resize(g.size(), 0);
    int count = 0;
    while (fila.size() > 0)
    {
        int atual = fila.front();
        if (usados[atual] == 0)
            count++;
        usados[atual] = 1;
        for (int i = 0; i < g[atual].size(); i++)
        {
            int elemento = g[atual][i];
            if (usados[elemento] == 0)
            {
                fila.emplace(elemento);
            }
        }
        fila.pop();
    }
    if (count == g.size())
        return true;
    else
    {
        return false;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        g.clear();
        dfs.clear();
        cin >> n;
        vector<pair<char, char>> pares;
        map<pair<char, char>, int> mapa;
        g.resize(n);
        dfs.resize(n);
        pares.resize(n);
        string temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            pares[i] = make_pair(temp[0], temp[temp.size() - 1]);
        }
        vector<int> in;
        in.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pares[i].second == pares[j].first)
                {
                    dfs[i].push_back(j);
                    dfs[j].push_back(i);
                    g[i].push_back(j);
                    in[j] += 1;
                }
            }
        }
        if (bfs())
        {
            bool flag_wrong = false;
            bool flag_in = false;
            bool flag_out = false;
            for (auto i : in)
            {
                if (i == 0)
                {
                    if (flag_in == false)
                        flag_in = true;
                    else
                    {
                        flag_wrong = true;
                        break;
                    }
                }
            }
            for (auto i : g)
            {
                if (i.size() == 0)
                {
                    if (flag_out == false)
                        flag_out = true;
                    else
                    {
                        flag_wrong = true;
                        break;
                    }
                }
            }
            if (flag_wrong)
                cout << "The door cannot be opened." << endl;
            else
            {
                cout << "Ordering is possible." << endl;
            }
        }
        else
        {
            cout << "The door cannot be opened." << endl;
        }
    }
}