#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int value;
    struct Data* next;
};

struct Data* createData(int input)
{
    struct Data* piece = malloc(sizeof (*piece));
    piece->value = input;
    piece->next = NULL;
    return piece;
};

void setNext(struct Data* currentpiece, struct Data* nextpiece)
{
    currentpiece->next = nextpiece;
}

void printList(struct Data* iterate)
{
    while (iterate)
    {
        printf("%d\n",iterate->value);
        iterate = iterate->next;
    }
}

int main()
{
    int i,j,tmp;
    printf("TOTAL INPUT : ");
    scanf("%d", &i);
    struct Data* DataPiece[i+1];
    printf("\n");

    for(j=1;j<=i;j++)
    {
        printf("VALUE FOR DATA %d : ", j);
        scanf("%d", &tmp);
        DataPiece[j] = createData(tmp);
    }
    printf("\n");

    printf("SET TO 0 TO NULL DATA\n");
    for(j=1;j<=i;j++)
    {
        printf("SET LINK FOR DATA %d TO : ", j);
        scanf("%d", &tmp);
        if (tmp>0)
            setNext(DataPiece[j], DataPiece[tmp]);
    }
    printf("\n");

    printf("SET HEAD : ");
    scanf("%d", &tmp);
    printf("\n");

    printList(DataPiece[tmp]);

    return 0;
}
