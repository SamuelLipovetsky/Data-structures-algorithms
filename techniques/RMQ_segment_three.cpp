#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <set>
#include <time.h>
#define infinito 99999
using namespace std;
int tamanho_lista;
//return  2* the nearest power of 2 to a input minus 1
//this func may be more efficient count the set bits and looking for most significant bit
int get_power(int a)
{

    int pot = 0;
    while (pow(2, pot) < a)
    {
        pot++;
    }
    return pow(2, pot) * 2 - 1;
}
// Build a array with a size of 2 * n  -1,where n is the nearest power of 2 to the input size
// in the first call, int high represents the last index of input and int position represents the first index of the three representation
void build_three(int input[], int three[], int low, int high, int position)
{

    //if the low and high indexes are the same , there is nothing to compare ,so just return the input at that position;
    //ex : smalestt int from index[2:2]==index[2]
    if (low == high)
    {

        three[position] = input[low];
        return;
    }
    //if there is more than one element to compare, build both side of the three, and compare them;
    else
    {

        int mid = low + (high - low) / 2;
        //index of left side is (2*positon+1)
        //index of rigth side is (2* position+2)
        build_three(input, three, low, mid, 2 * position + 1);
        build_three(input, three, mid + 1, high, (2 * position) + 2);
        // the three is build bottom up so,the value x at index position will be the smallest value between the left and right sides of the three,
        // also,since the three is represented by a array the value x at index position will be min(three[index of left side] and three[index of right side])
        three[position] = min(three[2 * position + 1], three[(2 * position) + 2]);
    }
}
//this function return the smallest int in a certain range
// there are 3 rules to min_range_querry :
//      if the range of the querry COMPLETELY overlap the range of the function call (low:hig) ,  return the value seg_three[position]
//      if there is no overlap beetwen the two ranges , return a dummy max value
//      else , return the min beetwen the righ and left sides of the three
int min_range_querry(int seg_three[], int querry_low, int querry_high, int low, int high, int position)
{
    if (querry_low <= low && querry_high >= high)
        return seg_three[position];
    if (querry_low > high || querry_high < low)
        return infinito;
    else
    {
        int mid = (low + high) / 2;
        return min(min_range_querry(seg_three, querry_low, querry_high, low, mid, 2 * position + 1),
                   min_range_querry(seg_three, querry_low, querry_high, mid + 1, high, 2 * position + 2));
    }
}
int main(int argc, const char *argv[])
{
    int tamanho = 4;
    int test[tamanho] = {-4, 2, 4, 0};
    tamanho_lista = get_power(tamanho);
    int lista[tamanho_lista];
    for (int i = 0; i < tamanho_lista; i++)
    {
        lista[i] = infinito;
    }
    build_three(test, lista, 0, tamanho - 1, 0);
    cout << min_range_querry(lista, 1, 3, 0, tamanho - 1, 0);
}
