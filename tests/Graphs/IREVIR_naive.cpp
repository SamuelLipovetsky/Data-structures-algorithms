#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n, m;
int v, w, p;
int adj[2000][2000] = {};
int main()
{
    scanf("%d %d", &n, &m);
    while (n)
    {
        int adj[n][n] = {};
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &v, &w, &p);
            if (p == 1)
            {
                adj[v - 1][w - 1] = 1;
            }
            else
            {
                adj[v - 1][w - 1] = 1;
                adj[w - 1][v - 1] = 1;
            }
        }
        int g = 1;
        set<int> usados;
        queue<int> queue;
        set<int> complete;
        int control = 1;
        for (int j = 0; j < n; j++)
        {
            usados.clear();
            queue.empty();
            queue.emplace(j);
            while (queue.size() > 0)
            {

                usados.insert(queue.front());
                control = 1;
                for (int i = 0; i < n; i++)
                {
                    if (adj[queue.front()][i])
                    {
                        control = 0;
                    }
                    if (usados.count(i) == 0)
                    {
                        if (adj[queue.front()][i])
                        {

                            queue.emplace(i);
                        }
                    }
                }

                if (control)
                {
                    g = 0;
                    break;
                }

                queue.pop();
            }
            if (control)
            {
                g = 0;
                break;
            }
            if (usados.size() != n)
            {
                g = 0;
            }
        }

        if (g == 1)
        {
            printf("1 \n");
        }
        else
        {
            printf("0 \n");
        }
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        scanf("%d", &m);
    }
    return 0;
}
