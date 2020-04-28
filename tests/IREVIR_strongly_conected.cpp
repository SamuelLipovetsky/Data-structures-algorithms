#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n, m;
int v, w, p;
int adj[2000][2000];
int adj2[2000][2000];
int main()
{

    scanf("%d %d", &n, &m);
    while (1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = false;
                adj[j][i] = false;
                adj2[i][j] = false;
                adj2[j][i] = false;
            }
        }

        int to_begin = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &v, &w, &p);
            if (p == 1)
            {
                adj[v - 1][w - 1] = true;
                adj2[w - 1][v - 1] = true;
            }
            else
            {
                adj[v - 1][w - 1] = true;
                adj[w - 1][v - 1] = true;
                adj2[v - 1][w - 1] = true;
                adj2[w - 1][v - 1] = true;
            }
        }

        int g = 1;
        int usado[n] = {};
        queue<int> queu;
        int c = 0;
        queu.emplace(to_begin);
        while (queu.size() > 0)
        {
            if (usado[queu.front()] == 0)
                c++;
            usado[queu.front()] = 1;

            for (int i = 0; i < n; i++)
            {
                if (usado[i] == 0)
                {
                    if (adj[queu.front()][i] == 1)
                    {

                        queu.emplace(i);
                    }
                }
            }
            queu.pop();
        }
        if (c != n)
        {
            g = 0;
        }

        if (g)
        {

            int usados[n] = {};
            int count = 0;
            queue<int> que;
            que.emplace(to_begin);
            while (que.size() > 0)
            {
                if (usados[que.front()] == 0)
                    count++;
                usados[que.front()] = 1;

                for (int i = 0; i < n; i++)
                {
                    if (usados[i] == 0)
                    {
                        if (adj2[que.front()][i] == 1)
                        {

                            que.emplace(i);
                        }
                    }
                }
                que.pop();
            }

            if (count != n)
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
        if (n)
        {
            scanf("%d", &m);
        }
        else
        {
            break;
        }
    }
    return 0;
}
