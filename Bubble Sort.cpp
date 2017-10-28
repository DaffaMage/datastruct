///CREDITS : Muhammad Achsan Hujjatul Islam

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int totalEntry,temp=0, i=0, j=0;
    cout << "input total entry number : " ;cin >> totalEntry;

    int Data[totalEntry];

    for (i=0;i<totalEntry;i++)
    {
        cin >> Data[i];
    }

    ///SORT
    for (i=1;i<totalEntry;i++)
    {
        getchar();
        cout << "NEXT PHASE : " << i << endl << endl;
        for (j=0;j<totalEntry;j++)
        {
            if (Data[j]>Data[j+1])
            {
                temp = Data[j+1];
                Data[j+1] = Data[j];
                Data[j] = temp;
            }
            cout << Data[j] << endl;
        }
    }

    return 0;
}
