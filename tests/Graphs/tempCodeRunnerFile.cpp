   for (int k = 0; k < len; k++)
        {
            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                {
                    if (distancias[i][j][k] != max)
                    {
                        distancias[i][j][k] = 0;
                        cout << distancias[i][j][k] << " ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
            cout << endl;
            cout << endl;
        }