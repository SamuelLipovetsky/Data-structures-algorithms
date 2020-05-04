#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define infinito 9999999
vector<pair<int, int>> all;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    all.clear();
    int p, k, n;
    int e, s;

    for (int w = 0; w < 10; w++)
    {
        cin >> p >> k;
        cin >> n;
        all.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> e >> s;
            if (e > k || s < p)
            {
                continue;
            }
            if ((e >= p && e <= k))
            {
                if (s <= k)
                {
                    all.push_back(make_pair(e, 0));
                    all.push_back(make_pair(s, 1));
                }
                else
                {
                    all.push_back(make_pair(e, 0));
                    all.push_back(make_pair(k, 1));
                }
            }
            else if ((s >= p && s <= k))
            {
                if (e >= p)
                {
                    all.push_back(make_pair(e, 0));
                    all.push_back(make_pair(s, 1));
                }
                else
                {
                    all.push_back(make_pair(p, 0));
                    all.push_back(make_pair(s, 1));
                }
            }
            else
            {

                all.push_back(make_pair(p, 0));
                all.push_back(make_pair(k, 1));
            }
        }
        if (all.size() == 0)
        {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        sort(all.begin(), all.end());

        int i = 0;
        int m = infinito;
        int counter = 0;
        n = all.size();
        int mx = 0;
        while (i < n)
        {

            int a = all[i].first;
            int b = all[i].second;

            if (b == 0)
            {
                if (i < n - 1)
                {
                    int a_prox = all[i + 1].first;
                    int b_prox = all[i + 1].second;
                    if (all[i] == all[i + 1])
                    {
                        counter++;
                        while (i < n - 1 && all[i] == all[i + 1] && all[i].second == 0)
                        {
                            i++;
                            counter++;
                        }
                    }
                    else
                    {
                        counter++;
                    }
                }
                else
                {
                    counter++;
                }
            }
            else if (a < k)
            {
                counter--;
            }
            m = min(counter, m);

            i++;
        }
        if (all[0].first > p || all[n - 1].first < k)
            m = 0;
        counter = 0;
        for (auto i : all)
        {
            if (i.second == 0)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            mx = max(counter, mx);
        }

        cout << m << " " << mx << endl;
    }
}
