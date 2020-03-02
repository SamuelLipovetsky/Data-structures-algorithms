#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int e, l;
int x, y;
int t = 1;
bool adj[100][100] = {false};
int main()
{
    scanf("%d %d", &e, &l);
    while (1)
    {
        for (int i = 0; i < e; i++)
        {
            for (int j = 0; j < e; j++)
            {
                adj[i][j] = false;
                adj[j][i] = false;
            }
        }

        for (int i = 0; i < l; i++)
        {
            scanf("%d %d", &x, &y);
            adj[x - 1][y - 1] = true;
            adj[y - 1][x - 1] = true;
        }

        //bfs
        queue<int> q;
        q.emplace(0);
        set<int> usados;
        usados.insert(0);
        usados.clear();
        while (q.size() > 0)
        {
            usados.insert(q.front());
            for (int i = 0; i < e; i++)
            {
                if (usados.count(i) == 0)
                {
                    if (adj[q.front()][i])
                    {

                        q.emplace(i);
                    }
                }
            }
            q.pop();
        }

        printf("Teste %d \n", t);
        t++;

        if (usados.size() == e)
        {
            printf("normal \n \n");
        }
        else
        {
            printf("falha \n \n");
        }
        scanf("%d %d", &e, &l);
        if (e == 0 || l == 0)
        {
            break;
        }
    }
}
