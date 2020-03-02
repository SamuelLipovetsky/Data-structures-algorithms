#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
// extract to string
#include <iostream>
#include <string>
using namespace std;
pair<unsigned long long int, unsigned long long int> dp[5001];
int main(int argc, const char *argv[])
//tomar cuidado com o CASO BASE
{
    ;
    string seq;
    getline(cin, seq);
    //cuidar do 0
    while (seq[0] != '0')
    {
        int tam = seq.size();
        dp[0].first = 1;

        if (int(seq[0]) - 48 > 2)
        {
            dp[0].second = 0;
        }
        else if (int(seq[1]) - 48 > 6)
        {
            dp[0].second = 0;
        }
        else if (tam > 2 && int(seq[2] - 48) == 0)
        {
            dp[0].second = 0;
        }
        else
        {
            dp[0].second = 1;
        }

        seq = seq + "333";

        int i = 1;
        if (seq[tam - 1] == 0 && seq[tam - 1] > 2)
        {
            cout << 0 << endl;
        }
        else
        {

            while (i < tam)
            {
                if (int(seq[i]) - 48 == 0 && int(seq[i + 1]) - 48 == 0)
                {
                    dp[tam].first = 0;
                    break;
                }

                else if (int(seq[i]) - 48 == 0)
                {
                    dp[i].first = dp[i - 1].first;
                    dp[i].second = 0;
                    i++;
                }
                else if (int(seq[i + 2] - 48) == 0)
                {
                    dp[i].first = dp[i - 1].first + dp[i - 1].second;
                    dp[i].second = 0;
                    i++;
                }
                else
                {
                    dp[i].first = dp[i - 1].first + dp[i - 1].second;

                    if (int(seq[i]) - 48 > 2)
                    {
                        dp[i].second = 0;
                    }
                    else if (int(seq[i - 1]) - 48 == 2 && int(seq[i]) - 48 > 6)
                    {
                        dp[i].second = 0;
                    }
                    else
                    {
                        dp[i].second = dp[i - 1].first;
                    }
                    i++;
                }
            }

            cout << dp[tam - 1].first << endl;
        }

        getline(cin, seq);
    }
}
