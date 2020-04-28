#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define loop(n) for (long long int i = 0; i < n; ++i)

#define dloop(n, m)             \
    for (int i = 0; i < n; ++i) \
        for (int j = 0; j < m; ++j)
using namespace std;

signed main()
{
    int A[50010] = {};
    bool visitados[50010] = {};

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, x, y;
    cin >> n >> r;

    set<int> adj[50000];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x - 1].insert(y - 1);
        adj[y - 1].insert(x - 1);
    }

    //bfsish
    queue<int> q;
    int count = 0;
    for (int k = 0; k < n; k++)
    {

        q.emplace(k);
        while (q.size() > 0)
        {
            visitados[q.front()] = true;
            for (int i = 0; i < n; i++)
            {
                if (adj[q.front()].count(i) > 0 && !visitados[i])
                {

                    if (A[i] == 0)
                    {
                        A[i] = A[q.front()] + 1;
                    }
                    else
                    {
                        A[i] = min(A[q.front()] + 1, A[i]);
                    }

                    q.emplace(i);
                }
            }
            q.pop();
        }
        for (int j = 0; j < n; j++)
        {

            if (A[j] == r)
            {
                count++;
            }
            visitados[j] = false;
            A[j] = 0;
        }
    }
    cout << count / 2 << endl;
}
