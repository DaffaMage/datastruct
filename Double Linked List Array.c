#include <stdio.h>
#include <stdlib.h>
#define MAX 6
#define LAST 0

int aData[MAX], aNext[MAX], aBack[MAX];

void regArray(int spot, int value)
{
    aData[spot] = value;
}

void linkArray(int spot, int link)
{
    aNext[spot] = link;
    aBack[link] = spot;
    aNext[link] = LAST;
}

void printArrayF(int start)
{
    int spot = start;
    do
    {
        printf("%d\n",aData[spot]);
        spot = aNext[spot];
    }while(spot);
    printf("\n");
}

void printArrayB(int start)
{
    int spot = start;
    do
    {
        printf("%d\n",aData[spot]);
        spot = aBack[spot];
    }while(spot);
    printf("\n");
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

    printArrayF(1);
    printArrayB(4);

    return 0;
}
