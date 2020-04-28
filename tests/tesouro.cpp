#include <iostream>
#include <set>
using namespace std;
int mem[101] = {};
set<int> a;
set<int> b;
int x, y, n;
int dp[101][11000] = {};
int problem(int l, int index)
{
    cout << l << endl;
    if (index >= 0)
    {
        if (!dp[index][l])
        {
            int result;
            if (l - mem[index] > 0)
            {
                result = problem(l - mem[index], index - 1);
                dp[index - 1][l - mem[index]] = result;
                result = problem(l, index - 1 - 1);
                dp[index - 1][l] = result;
            }
            else if (l - mem[index - 1] < 0)
            {
                result = problem(l, index - 1);
                dp[index - 1][l] = result;
            }
        }
        else
        {
            return dp[index][l];
        }
    }
}
int main()
{
    int teste = 1;

    cin >> x;
    cin >> y;
    cin >> n;
    while (x)
    {

        int total = x + y;
        for (int i = 0; i < n; i++)
        {
            cin >> mem[i];
            total += mem[i];
        }

        int control = 0;
        if (total % 2 == 0)
        {
            problem(n, total / 2 - x + total / 2 - y);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < total / 2 - x + total / 2 - y; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Teste " << teste << endl;
        if (control)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        cout << endl;

        teste++;
        cin >> x;
        cin >> y;
        cin >> n;
    }
}
