#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        string temp;
        cin >> temp;
        if (temp[0] == '*')
            break;
        int t = temp.size();
        int flag = 0;
        for (int i = 1; i <= t; i++)
        {
            if (flag)
                break;
            if (t % i == 0)
            {
                string sub = temp.substr(0, i);
                int p = sub.size();
                int ind = 0;
                while (ind + p <= t)
                {
                    if (sub != temp.substr(ind, p))
                    {

                        break;
                    }
                    if (ind + p == t)
                    {
                        flag = 1;
                        cout << t / p << endl;
                        break;
                    }
                    ind += p;
                }
            }
        }
    }
}
