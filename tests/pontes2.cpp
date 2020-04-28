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

int adj[1000][1000];
void Dijkstra(int n)
{

    int buracos[n];
    int usados[n];
    for (int i = 0; i < n; i++)
    {
        buracos[i] = max;
        usados[i] = 0;
    }

    buracos[0] = 0;
    priority_queue<pair<int, int>> fila;

    fila.push(make_pair(0, 0));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;
        usados[atual] = 0;
        fila.pop();
        for (int i = 0; i < n; i++)
        {
            if (adj[atual][i] != max && usados[i] == 0)
            {
                int elemento = i;

                int custo = adj[atual][i];
                if (buracos[elemento] > buracos[atual] + custo)
                {

                    buracos[elemento] = buracos[atual] + custo;
                    fila.push(make_pair(buracos[elemento], elemento));
                }
            }
        }
    }
    cout << buracos[n - 1] << "\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, t;
    cin >> n >> m;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            adj[i][j] = max;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        adj[x][y] = t;
        adj[y][x] = t;
    }
    Dijkstra(n + 2);
}