#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    string g;
    vector<set<char>> s;
    s.resize(8);
    s[0] = {'A', 'B', 'C'};
    s[1] = {'D', 'E', 'F'};
    s[2] = {'G', 'H', 'I'};
    s[3] = {'J', 'K', 'L'};
    s[4] = {'M', 'N', 'O'};
    s[5] = {'P', 'Q', 'R', 'S'};
    s[6] = {'T', 'U', 'V'};
    s[7] = {'W', 'X', 'Y', 'Z'};
    while (getline(cin, g))
    {
        if (!cin)
        {
            break;
        }
        string temp;

        for (auto i : g)
        {
            if (i == '-')
            {
                temp += '-';
            }
            else if (isdigit(i))
            {
                temp += i;
            }

            else
            {

                for (int j = 0; j < 8; j++)
                {
                    if (s[j].count(i) > 0)
                    {
                        temp += (char)(j + 50);

                        break;
                    }
                }
            }
        }
        cout << temp << endl;
    }
}
