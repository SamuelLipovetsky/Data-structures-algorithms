#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define _DEBUG
using namespace std;
#define infinito 9999999
bool check_nine(string numero)
{
    int tamanho = numero.size();
    for (int i = 0; i < tamanho; i++)
    {
        if (numero[i] != '9')
            break;
        if (i == tamanho - 1)
        {
            string temp;
            temp += '1';
            for (int i = 0; i < tamanho - 1; i++)
            {
                temp += '0';
            }
            temp += '1';
            cout << temp << endl;
            return true;
        }
    }
    return false;
}
void impar(string numero)
{
    //refletindo o lado direito no esqueirdo (1passo)
    int tamanho = numero.size();
    int j = floor(tamanho / 2);
    string new_string = numero.substr(0, j + 1);
    new_string += numero.substr(0, j);
    reverse(new_string.begin() + j + 1, new_string.end());
    int meio = j;

    //caso : o primeiro passo ja deu o proximo palindromo
    int control = 0;
    int flag = 1;
    for (int i = 0; i < tamanho; i++)
    {

        if ((int)new_string[i] - '0' < (int)numero[i] - '0')
        {
            cout << new_string << endl;
            flag = 1;
            break;
        }
        if ((int)new_string[i] - '0' < (int)numero[i] - '0')
        {
            flag = 0;
            break;
        }
        if (i == tamanho - 1)
        {
            if ((int)new_string[i] - '0' <= (int)numero[i] - '0')
            {
                flag = 0;
                break;
            }
        }
    }
    if (!flag)
    {
        // caso : primeiro passo resultou em um numero menor que n e o meio NAO É o numero 9/;
        if (new_string[j] != '9')
        {

            string temp = new_string.substr(0, j);
            temp += to_string((int)(new_string[j] - '0') + 1);
            temp += temp.substr(0, j);
            reverse(temp.begin() + j + 1, temp.end());
            cout << temp << endl;
        }
        // caso : primeiro passo resultou em um numero menor que n e o meio É o numero 9/;
        else
        {
            int meio = j;
            while (new_string[j] == '9')
            {
                j--;
            }
            string temp = new_string.substr(0, j);
            temp += to_string((int)(new_string[j] - '0') + 1);
            for (int k = j; k < meio; k++)
            {
                temp += '0';
            }
            temp += temp.substr(0, meio);
            reverse(temp.begin() + meio + 1, temp.end());
            cout << temp << endl;
        }
    }
    else
    {
        cout << new_string << endl;
    }
}
void par(string numero)
{
    //1 passo
    int tamanho = numero.size();
    int meio = tamanho / 2;
    string new_string = numero.substr(0, meio);
    new_string += numero.substr(0, meio);
    reverse(new_string.begin() + meio, new_string.end());

    // cout << new_string << endl;
    //caso : o primeiro passo gerou o proximo palindromo
    int control = 0;
    int flag = 1;
    for (int i = 0; i < tamanho; i++)
    {

        if ((int)new_string[i] - '0' < (int)numero[i] - '0')
        {
            cout << new_string << endl;
            flag = 1;
            break;
        }
        if ((int)new_string[i] - '0' < (int)numero[i] - '0')
        {
            flag = 0;
            break;
        }
        if (i == tamanho - 1)
        {
            if ((int)new_string[i] - '0' <= (int)numero[i] - '0')
            {
                flag = 0;
                break;
            }
        }
    }

    if (!flag)
    {
        //caso : o primeiro passo gerou um palindrom menor e os meios NAO SAO 9
        if (new_string[meio] != '9')
        {
            string temp = new_string.substr(0, meio - 1);
            temp += to_string((int)new_string[meio] - '0' + 1);
            temp += temp;
            reverse(temp.begin() + meio, temp.end());
            cout << temp << endl;
        }
        //caso : o primeiro passo gerou um palindrom menor e os meios  SAO 9
        else
        {
            int cont = meio;
            while (new_string[meio] == '9')
            {
                meio--;
            }
            string temp = new_string.substr(0, meio);
            temp += to_string((int)new_string[meio] - '0' + 1);
            for (int i = meio + 1; i < cont; i++)
            {
                temp += '0';
            }
            temp += temp;
            reverse(temp.begin() + cont, temp.end());
            cout << temp << endl;
        }
    }
}
int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // cin.ignore();
    string temp;
    for (int i = 0; i < n; i++)
    {

        // getline(cin, temp);
        cin >> temp;
        // temp = temp.substr(0, temp.size());

        if (!check_nine(temp))
        {
            if (temp.size() % 2 == 0)
            {
                par(temp);
            }
            else
            {
                impar(temp);
            }
        }
    }
}