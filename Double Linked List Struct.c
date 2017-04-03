///NAMA : MUHAMMAD DAFFA ABIYYU RAHMAN
///NRP  : 2916100010

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct Data
{
    int value;
    struct Data* next;
    struct Data* back;
};

struct Data* createData(int input)
{
    struct Data* piece = malloc(sizeof (*piece));
    piece->value = input;
    piece->next = NULL;
    piece->back = NULL;
    return piece;
};

void setNext(struct Data* currentpiece, struct Data* nextpiece)
{
    currentpiece->next = nextpiece;
    nextpiece->back = currentpiece;
}

void printList(struct Data* iterate, int forward)
{
    while (iterate)
    {
        printf("%d\n",iterate->value);
        if (forward == TRUE)
            iterate = iterate->next;
        else
            iterate = iterate->back;
    }
    printf("\n");
}

int main()
{
    struct Data* address1 = createData(10);
    struct Data* address2 = createData(5);
    struct Data* address3 = createData(7);
    struct Data* address4 = createData(6);
    struct Data* address5 = createData(4);

    struct Data* start = address1; //First
    struct Data* iterate = start; //Linking

    setNext(address1, address3); //1-3
    setNext(address3, address2); //3-2
    setNext(address2, address5); //2-5
    setNext(address5, address4); //5-4

    printList(iterate, TRUE); //Print all link list values forward

    start = address4;
    iterate = start;

    printList(iterate, FALSE); //Print all link list values backward

    return 0;
}
