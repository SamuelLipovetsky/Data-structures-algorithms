#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <string>

using namespace std;
bool s(string a, string b)
{
    if (a.substr(3, a.size() - 1) == b.substr(3, b.size() - 1))
    {
        return a[0] < b[0];
    }

    return a.substr(3, a.size() - 1) < b.substr(3, b.size() - 1);
}
bool artigos[100][100] = {false};
map<string, int> hash;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    cin >> a;
    int t = 1;
    set<string> usados;
    map<string, int> hash;
    vector<string> r;
    vector<int> pos;
    while (1)
    {
        int count = 0;
        usados.clear();
        hash.clear();
        string nome;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                artigos[i][j] = false;
            }
        }

        r.clear();
        for (int i = 0; i <= a; i++)
        {
            getline(cin, nome);
            string temp;
            pos.clear();
            for (int j = 0; j < nome.size(); j++)
            {
                if (nome[j] == ',' || j == nome.size() - 1)
                {
                    if (usados.count(temp) == 0)
                    {
                        usados.insert(temp);
                        r.push_back(temp);
                        j++;
                        pos.push_back(count);

                        hash.insert(make_pair(temp, count));
                        count++;
                        temp.clear();
                    }
                    else
                    {
                        pos.push_back(hash[temp]);
                        temp.clear();
                        j++;
                    }
                }
                else
                {
                    temp.push_back(nome[j]);
                }
            }
            for (auto i : pos)
            {
                for (auto j : pos)
                {
                    if (i != j)
                    {
                        artigos[i][j] = true;
                        artigos[j][i] = true;
                    }
                }
            }
        }

        int dist[usados.size()] = {0};
        sort(r.begin(), r.end(), s);
        if (usados.count("P. Erdos") > 0)
        {
            int to_search = hash["P. Erdos"];
            //bfs
            queue<int> q;
            q.emplace(to_search);
            bool u[usados.size()] = {false};
            while (q.size() > 0)
            {
                u[q.front()] = true;
                for (int i = 0; i < usados.size(); i++)
                {
                    if (!u[i])
                    {
                        if (artigos[q.front()][i])
                        {
                            q.emplace(i);
                            if (i != to_search)
                            {
                                if (dist[i] == 0)
                                    dist[i] = dist[q.front()] + 1;
                                else
                                {
                                    dist[i] = min(dist[q.front()] + 1, dist[i]);
                                }
                            }
                        }
                    }
                }
                q.pop();
            }

            cout << "Teste " << t << endl;
            t++;
            for (auto i : r)
            {
                if (i != "P. Erdos")
                {
                    if (dist[hash[i]] == 0)
                    {
                        cout << i << ": "
                             << "infinito" << endl;
                    }
                    else
                        cout << i << ": " << dist[hash[i]] << endl;
                }
            }
            cout << endl;
        }
        else
        {
            cout << "Teste " << t << endl;
            t++;
            for (auto i : r)
            {
                if (i != "P. Erdos")
                {
                    cout << i << ": "
                         << "infinito" << endl;
                }
            }
            cout << endl;
        }

        cin >> a;
        if (!a)
        {
            break;
        }
    }
}