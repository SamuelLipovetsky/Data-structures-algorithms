#include <iostream>
#include <set>
using namespace std;

int x, y, n;
int mem[110] = {};
int problem(int n, int sum, int sum2, int sum3)
{
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < mem[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= mem[i - 1])
                subset[i][j] = subset[i - 1][j] ||
                               subset[i - 1][j - mem[i - 1]];
        }
    }

    return subset[n][sum] && subset[n][sum2] && subset[n][sum3];
}
int main()
{
    int teste = 1;

    cin >> x;
    cin >> y;
    cin >> n;
    while (n)
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
            int a1 = problem(n, total / 2 - x + total / 2 - y, total / 2 - x, total / 2 - y);
            if (a1)
            {
                control = 1;
            }
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
