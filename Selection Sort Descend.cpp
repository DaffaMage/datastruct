#include <iostream>

using namespace std;

int main()
{
    int a[10] = {10,20,35,30,45,40,60,75,90,15};
    int i,j,n=10,temp;

    ///SORT TURUN
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (a[j]>a[i])
            {
                cout << "exchange value : " << a[i] << " and " << a[j] << endl;
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        cout << "The " << i << " Sort" << endl;
        for (j=0;j<n;j++)
        {
            cout << a[j] << endl;
        }
    }

    return 0;
}
