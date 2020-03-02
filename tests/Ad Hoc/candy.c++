#include <iostream>
#include <vector>
using namespace std;

int arr[100000], answer[1000], i = 0, total = 0, moves = 0, n, k, l;

int problem(int k, int l)
{
    total = 0, moves = 0;

    for (int j = k + 1; j <= l; j++)
    {
        total += arr[j];
    }
    if (total % (k - l) != 0)
    {
        cout << -1 << endl;
        if (l + 1 < i)
        {

            return problem(l + 1, l + 1 + arr[l + 1]);
        }
    }
    else
    {
        int average = total / (l - k);
        for (int j = k + 1; j <= l; j++)
        {
            if (arr[j] > average)
            {
                moves += (arr[j] - average);
            }
        }

        cout << moves << endl;
        if (l + 1 < i)
        {
            return problem(l + 1, l + 1 + arr[l + 1]);
        }
    }
}
int main()
{
    while (1)
    {
        cin >> n;
        if (n == -1)
        {

            break;
        }
        else
        {
            arr[i] = n;
            i++;
        }
    }
    int x = 0;
    problem(x, arr[x]);
}