#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#include <stdlib.h>

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
int mini(int a, int b, int c)
{
    int min = a;
    if (min >= b)
    {
        min = b;
    }
    if (min >= c)
    {
        min = c;
    }
    return min;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c, k, x, y, t;
    n = 1;
    m = 1;
    c = 1;
    k = 1;
    int adj[252][252];
    int visitados[252];
    int dists[252];
    int go_to[252];
    int sum[252];
    int temp, min;
    priority_queue<int, vector<dj>, greater<dj>> q;
    cin >> n >> m >> c >> k;
    while (n != 0 || m || 0 && c || 0 && k || 0)
    {

        for (int i = 0; i < n; i++)
        {
            visitados[i] = 0;
            dists[i] = INT16_MAX;
            go_to[i] = -1;
            sum[i] = 0;
            for (int j = 0; j < n; j++)
            {

                adj[i][j] = INT16_MAX;
                adj[j][i] = INT16_MAX;
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> t;
            adj[x][y] = t;
            adj[y][x] = t;
        }
        int total = 0;
        if (k < c - 1)
        {
            while (k < c - 1)
            {
                total += adj[k][k + 1];
                k++;
            }
            cout << total << endl;
        }
        else
        {
            for (int i = c - 1; i > 0; i--)
            {
                sum[i - 1] = sum[i] + adj[i - 1][i];
            }

            dists[k] = 0;
            dj t1;
            t1 = {
                k,
                0,
                -1,
            };
            q.push(t1);
            int min = 0;
            while (q.size() > 0)
            {
                visitados[q.top().no] = 1;
                temp = 0;
                for (int i = 0; i < n; i++)
                {
                    if (i > c - 1)
                    {
                        if (adj[q.top().no][i] != INT16_MAX && visitados[i] == 0)
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
                }
                q.pop();
            }
            int l = INT32_MAX;
            for (int i = 0; i < c - 1; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int temp = sum[i] + adj[j][i] + dists[j];
                    if (l > temp)
                    {
                        l = temp;
                    }
                }
            }
            int m = mini(abs(l), abs(dists[c - 1]), abs(adj[c - 1][k]));
            cout << m << endl;
        }
        cin >> n >> m >> c >> k;
    }
}