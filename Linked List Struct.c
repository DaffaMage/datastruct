///NAMA : MUHAMMAD DAFFA ABIYYU RAHMAN
///NRP  : 2916100010

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

    printList(iterate); //Print all link list values forward

    return 0;
}
