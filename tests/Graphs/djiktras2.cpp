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
void printQueue(priority_queue<int, vector<dj>, greater<dj>> q)
{
    //printing content of queue
    while (!q.empty())
    {
        cout << q.top().dist << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, i, j, t, inicio, fim;
    while (true)
    {

        priority_queue<int, vector<dj>, greater<dj>> q;
        vector<tuple<int, int, int>> graph;
        cin >> n >> m;
        if (n == 0 || m == 0)
            break;
        int dist[250];
        int used[250];
        for (int i = 0; i < 250; i++)
        {
            dist[i] = INT32_MAX;
            used[i] = 0;
        }

        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> t;

            graph.push_back(make_tuple(i - 1, j - 1, t));
        }
        cin >> inicio >> fim;
        inicio--;
        fim--;
        dist[inicio] = 0;
        dj c = {inicio, 0, inicio};
        q.push(c);
        while (q.size() > 0)
        {
            used[q.top().no] = 1;
            int atual = q.top().no;
            q.pop();
            for (int i = 0; i < m; i++)
            {

                if (get<0>(graph[i]) == atual && used[get<1>(graph[i])] == 0)
                {
                    int temp = dist[atual] + get<2>(graph[i]);
                    if (temp < dist[get<1>(graph[i])])
                    {
                        dist[get<1>(graph[i])] = temp;
                        dj te = {
                            get<1>(graph[i]),
                            dist[get<1>(graph[i])],
                            atual};
                        q.push(te);
                    }
                }
            }
        }
        if (dist[fim] != INT32_MAX)
            cout << dist[fim] << endl;
        else
        {
            cout << -1 << endl;
        }
    }
}