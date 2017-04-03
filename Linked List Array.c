#include <stdio.h>
#include <stdlib.h>
#define MAX 6
#define LAST 0

int aData[MAX], aNext[MAX];

void regArray(int spot, int value)
{
    aData[spot] = value;
}

void linkArray(int spot, int link)
{
    aNext[spot] = link;
    aNext[link] = LAST;
}

void printArray(int start)
{
    int spot = start;
    do
    {
        printf("%d\n",aData[spot]);
        spot = aNext[spot];
    }while(spot);
}

int main()
{
    regArray(1,10);
    regArray(2,5);
    regArray(3,7);
    regArray(4,4);
    regArray(5,6);

    linkArray(1,3);
    linkArray(3,2);
    linkArray(2,5);
    linkArray(5,4);

    printArray(1);

    return 0;
}
