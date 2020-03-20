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
    int pre;

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
    int n, m, i, j, t, inicio, fim;

    priority_queue<int, vector<dj>, greater<dj>> q;

    int adj[200][200] = {};
    int visited[200] = {};
    int dists[200] = {};
    int pre[200] = {};
    while (1)
    {
        cin >> n >> m;
        if (n == 0 || m == 0)
        {
            break;
        }

        for (int i = 0; i < 200; i++)
        {
            dists[i] = INT32_MAX;
            visited[i] = 0;
            pre[i] = 0;
            for (int j = 0; j < 200; j++)
            {
                adj[i][j] = 0;
            }
        }

        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> t;
            adj[i - 1][j - 1] = t;
        }

        cin >> inicio >> fim;

        fim--;
        inicio--;
        dists[inicio] = 0;
        dj in;
        in = {inicio, 0, inicio};
        q.push(in);
        int temp = 0;
        int go = 0;
        int min = INT32_MAX;
        int d = 5;

        while (q.size() > 0)
        {
            visited[q.top().no] = 1;
            temp = 0;
            // printQueue(q);

            min = INT32_MAX;
            for (int i = 0; i < n; i++)
            {

                if (adj[q.top().no][i] != 0 && visited[i] == 0)
                {

                    temp = adj[q.top().no][i] + dists[q.top().no];
                    if (dists[i] > temp)
                    {
                        dists[i] = temp;
                        pre[i] = q.top().pre;
                    }
                    dj te = {i, dists[i], q.top().no};
                    q.push(te);
                }
            }

            q.pop();
        }
        if (dists[fim] == INT32_MAX)
            cout << -1 << endl;
        else
            cout << dists[fim] << endl;
    }
}