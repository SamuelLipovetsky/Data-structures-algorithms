#include <iostream>
#include <set>
using namespace std;

int arr[10] = {};
int perm[10] = {};
set<int> usados;
bool problem(int index, int target_sum, int atual_sum)
{

    if (index == 10 && atual_sum <= target_sum)
    {
        int total = 0;

        return true;
    }

    for (int i = 0; i < 10; i++)
    {

        if (usados.count(i) == 0 && atual_sum <= target_sum)
        {
            perm[index] = i;
            atual_sum += i * arr[index];
            usados.insert(i);
            index++;
            if (problem(index, target_sum, atual_sum))
                return true;
            index--;
            atual_sum -= i * arr[index];
            usados.erase(i);
            perm[index] = -1;
        }
    }
    return false;
}
int main()
{

    int n, any, sum;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            cin >> arr[j];
            perm[j] = -1;
        }

        cin >> sum;
        usados.clear();
        if (problem(0, sum, 0) == true)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    // int cou = 0;
    // int arr[10] = {2, 6, 8, 9, 7, 5, 4, 3, 1, 0};
    // for (int i = 0; i < 10; i++)
    // {
    //     cou += arr[i] * i;
    // }
    // cout << cou;
}
