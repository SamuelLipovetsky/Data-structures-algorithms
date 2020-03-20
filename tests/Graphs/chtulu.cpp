#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#include <iostream>

#define loop(n) for (int i = 0; i < n; ++i)

#define dloop(n, m)             \
    for (int i = 0; i < n; ++i) \
        for (int j = 0; j < m; ++j)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int adj[100][100] = {};
    int m, n, x, y;
    cin >> m >> n;

    loop(n)
    {
        cin >> x >> y;
        adj[x - 1][y - 1] = 1;
        adj[y - 1][x - 1] = 1;
    }

    //bfs

    int used[100] = {};
    int count = 0;

    queue<int> q;

    q.emplace(0);
    while (q.size() > 0)
    {
        used[q.front()] = 1;
        for (int i = 0; i < n; i++)
        {
            if (adj[q.front()][i] == 1 && !used[i])
            {
                q.emplace(i);
            }
        }

        q.pop();
    }

    loop(m)
    {
        if (used[i] == 1)
        {
            count++;
        }
    }
    if (m - n == 0 && count == m)
    {
        cout << "FHTAGN!";
    }
    else
    {
        cout << "NO";
    }
}
