#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, z;
    cin >> x >> y;

    int num[x + 2][y + 2][2] = {};
    int inicio = 0;
    int count = 0;
    vector<int> to;
    bool adj[x * y][x * y] = {};
    int index = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {

            cin >> num[i][j][0];
            num[i][j][0]++;
            num[i][j][1] = count;
            if (num[i][j][0] == 1)
            {
                to.push_back(count);
            }
            else if (num[i][j][0] == 4)
            {
                inicio = count;
            }
            count++;
            if (num[i][j - 1][0] != 3 && num[i][j - 1][0] > 0)
            {
                adj[num[i][j][1]][num[i][j - 1][1]] = true;
                adj[num[i][j - 1][1]][num[i][j][1]] = true;
            }

            if (num[i - 1][j][0] != 3 && num[i - 1][j][0] > 0)
            {
                adj[num[i][j][1]][num[i - 1][j][1]] = true;
                adj[num[i - 1][j][1]][num[i][j][1]] = true;
            }
        }
    }

    //bfs mantendo as distantcias;

    queue<int> q;
    q.emplace(inicio);
    bool usados[x * y] = {};
    int dist[x * y] = {0};
    while (q.size() > 0)
    {
        usados[q.front()] = true;
        for (int i = 0; i < x * y; i++)
        {
            if (adj[q.front()][i] && usados[i] == false)
            {
                q.emplace(i);
                if (i != inicio)
                {
                    if (dist[i] == 0)
                        dist[i] = dist[q.front()] + 1;
                    else
                    {
                        dist[i] = min(dist[q.front()] + 1, dist[i]);
                    }
                }
            }
        }
        q.pop();
    }
    int min = INT16_MAX;

    for (auto x : to)
    {
        if (dist[x] < min && dist[x] > 0)
        {
            min = dist[x];
        }
    }
    cout << min;
}
