#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
class dj
{
public:
    int no;
    int dist;
    int go_to;

    friend bool operator>(const dj &obj, const dj &obj1)
    {
        return obj.dist > obj1.dist;
    }
    friend bool operator<(const dj &obj, const dj &obj1)
    {
        return obj.dist < obj1.dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, k, x, y, t;
    int adj[251][251];
    int visitados[251];
    int dists[251];
    int go_to[251];
    int sum[251];
    int temp, min;
    // while (1)
    // {
    cin >> n >> m >> c >> k;
    // if (n == 0)
    // break;
    for (int i = 0; i < n; i++)
    {
        visitados[i] = 0;
        dists[i] = INT32_MAX;
        go_to[i] = -1;
        sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            adj[i][k] = INT32_MAX;
            adj[k][i] = INT32_MAX;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        adj[x][y] = t;
        adj[y][x] = t;
    }

    priority_queue<int, vector<dj>, greater<dj>> q;
    dists[k] = 0;
    dj t1;
    t1 = {
        k,
        0,
        -1,
    };
    q.push(t1);
    while (q.size() > 0)
    {
        visitados[q.top().no] = 1;
        temp = 0;

        for (int i = 0; i < n; i++)
        {

            if (adj[q.top().no][i] != INT32_MAX && visitados[i] == 0)
            {

                temp = adj[q.top().no][i] + dists[q.top().no];

                if (dists[i] > temp)
                {

                    dists[i] = temp;

                    go_to[i] = q.top().no;
                }
                dj te = {i, dists[i], -1};
                q.push(te);
            }
        }
        q.pop();
    }

    int total = 0;
    int k1 = k;
    c--;
    cout << dists[c - 1];
    // }
}