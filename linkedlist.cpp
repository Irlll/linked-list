#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} * tail;

int isEmpty(Node *h)
{
    if (h == NULL)
        return 1;
    else
        return 0;
}

void printlist(Node *h)
{
    if (isEmpty(h) == 1)
    {
        printf("Node masih kosong");
    }
    else
    {
        struct Node *temp1, *temp2;
        temp1 = h;
        temp2 = tail;
        temp1->prev = NULL;
        temp2->next = NULL;
        while (temp1 != NULL)
        {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }
    }
}

Node *tambahDepan(int databaru, Node *h)
{
    Node *baru;
    baru = new Node;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty(h) == 1)
    {
        h = tail = baru;
        h->next = h;
        h->prev = h;
    }
    else
    {
        // head->next = baru;
        h->prev = baru;
        baru->prev = tail; // pivotnya tail
        baru->next = h;
        tail->next = baru;
        h = baru;
        baru = NULL;
    }
    printf("Add %d : ", databaru);
    return h;
}

Node *tambahBelakang(int databaru, Node *h)
{
    Node *baru;
    baru = new Node;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty(h) == 1)
    {
        h = tail = baru;
        h->next = h;
        h->prev = h;
    }
    else
    {
        // head->next = baru;
        h->prev = baru;
        baru->prev = tail; // pivotnya tail
        baru->next = h;
        tail->next = baru;
        tail = baru;
        baru = NULL;
    }
    printf("Add %d : ", databaru);
    return h;
}

Node *hapusDepan(Node *h)
{
    if (isEmpty(h) == 1)
    {
        printf("Empty");
    }
    else
    {
        int d = h->data;
        Node *temp;
        temp = h;
        temp->prev = NULL;
        temp = temp->next;
        h->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        h = temp;
        temp = NULL;
        printf("Delete %d : ", d);
    }
    return h;
}

Node *hapusBelakang(Node *h)
{
    if (isEmpty(h) == 1)
    {
        printf("Empty");
    }
    else
    {
        int d = tail->data;
        Node *temp;
        temp = tail;
        temp->next = NULL;
        temp = temp->prev;
        tail->prev = NULL;
        temp->next = h;
        h->prev = temp;
        tail = temp;
        temp = NULL;
        printf("Delete %d : ", d);
    }
    return h;
}

Node *tambahTengah(int databaru, Node *h)
{
    Node *baru, *bantu, *bantu2;
    int d = databaru;
    int counter = 0;
    baru = new Node;
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;

    if (isEmpty(h) == 1)
    {
        h = tail = baru;
        h->next = h;
        h->prev = h;
    }
    else
    {
        bantu = h;
        while (bantu->next != tail && counter < 2)
        {
            bantu = bantu->next;
            counter++;
        }
        bantu2 = bantu->next;
        bantu->next = baru;
        bantu2->prev = baru;
        baru->next = bantu2;
        baru->prev = bantu;
        bantu = NULL;
        bantu2 = NULL;
        baru = NULL;
    }
    printf("Add %d : ", d);
    return h;
}

Node *hapusTengah(Node *h)
{
    if (isEmpty(h) == 1)
    {
        printf("Empty");
    }
    else
    {
        Node *bantu, *hapus;
        int d, counter = 0;
        bantu = h;
        while (bantu->next->next != tail && counter < 1)
        {
            bantu = bantu->next;
            counter++;
        }
        hapus = bantu->next;
        d = hapus->data;
        bantu->next = hapus->next;
        hapus->next->prev = bantu;
        hapus->prev = NULL;
        hapus->next = NULL;
        delete hapus;
        printf("Delete %d : ", d);
    }
    return h;
}

int main()
{
    Node *head;
    head = NULL;
    tail = NULL;
    printlist(head);
    printf("\n\n===TAMBAH NODE DI DEPAN===");
    printf("\n");
    head = tambahDepan(1, head);
    printlist(head);
    printf("\n");
    head = tambahDepan(2, head);
    printlist(head);
    printf("\n");
    head = tambahDepan(3, head);
    printlist(head);
    printf("\n\n===TAMBAH NODE DI BELAKANG===");
    printf("\n");
    head = tambahBelakang(4, head);
    printlist(head);
    printf("\n");
    head = tambahBelakang(5, head);
    printlist(head);
    printf("\n");
    head = tambahBelakang(6, head);
    printlist(head);
    printf("\n\n===TAMBAH NODE DI TENGAH===");
    printf("\n");
    head = tambahTengah(7, head);
    printlist(head);
    printf("\n");
    printf("\n===HAPUS NODE DI DEPAN===\n");
    head = hapusDepan(head);
    printlist(head);
    printf("\n");
    printf("\n===HAPUS NODE DI BELAKANG===\n");
    head = hapusBelakang(head);
    printlist(head);
    printf("\n");
    printf("\n===HAPUS NODE DI TENGAH===\n");
    head = hapusTengah(head);
    printlist(head);
    printf("\n");

    printf("\nHEAD: %d", *head);
    printf("\nTAIL: %d", *tail);
    printf("\n");

    /* Node *temp1;
     temp1 = head;
     temp1 = temp1->prev;
     printf("%d", *temp1); */

    Node *temp2;
    temp2 = tail;
    temp2 = temp2->next;
    printf("next tail : %d", *temp2);
}
