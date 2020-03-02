#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n, m;
int x, y;
int t = 1;
bool adj[100][100] = {false};
int main()
{
    scanf("%d %d", &n, &m);
    int g = 1;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = false;
                adj[j][i] = false;
            }
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            adj[x - 1][y - 1] = true;
            adj[y - 1][x - 1] = true;
        }

        //bfs
        queue<int> q;
        set<int> usados;
        q.emplace(0);
        int ultimo = -1;
        int g = 1;
        while (q.size() > 0)
        {

            for (int i = 0; i < n; i++)
            {
                if (adj[q.front()][i])
                {
                    if (usados.count(i) == 0 && i != q.front())
                    {
                        q.emplace(i);
                    }
                    else
                    {
                        if (i != q.front() && usados.count(i) > 0 )
                            g = 0;
                    }
                }
            }

            usados.insert(q.front());
            ultimo = q.front();

            q.pop();
        }

        printf("Instancia %d \n", t);
        t++;
        if (g)
        {
            printf("sim \n \n");
        }
        else
        {
            printf("nao \n \n");
        }

        if (cin.eof())
        {
            break;
        }
        scanf("%d %d", &n, &m);
    }
}
