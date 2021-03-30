#include <stdio.h>

#include <stdlib.h>

struct Mahasiswa
{
    char *Nama;
    int Nrp;
    struct Mahasiswa *Next;
};

void Push(struct Mahasiswa **head_ref, char *nama, int nrp)
{
    struct Mahasiswa *new_node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));

    struct Mahasiswa *last = *head_ref;

    new_node->Nama = nama;
    new_node->Nrp = nrp;

    new_node->Next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->Next != NULL)
        last = last->Next;
    last->Next = new_node;
    return;
}

void Tampil(struct Mahasiswa *head_ref)
{
    do
    {
        printf("%s |%d", head_ref->Nama, head_ref->Nrp);
        printf("\n");
        head_ref = head_ref->Next;
    } while (head_ref != NULL);
}

void SearchByName(struct Mahasiswa *head_ref, char *nama)
{
    int i = 0;
    struct Mahasiswa *first = &head_ref;
    do
    {
        if (head_ref->Nama == nama)
        {
            printf("Index Ke-%d = %s |%d\n", i, head_ref->Nama, head_ref->Nrp);
            return;
        }

        head_ref = head_ref->Next;
        i++;
    } while (head_ref != NULL);

    head_ref = first;
    printf("Data dengan NAMA %s tidak ditemukan", *nama);
}

void SearchByNrp(struct Mahasiswa *head_ref, int nrp)
{
    int i = 0;
    struct Mahasiswa *first = &head_ref;
    do
    {
        if (head_ref->Nrp == nrp)
        {
            printf("Index Ke-%d = %s |%d\n", i, head_ref->Nama, head_ref->Nrp);
            return;
        }

        head_ref = head_ref->Next;
        i++;
    } while (head_ref != NULL);

    head_ref = first;
    printf("Data dengan NRP %d tidak ditemukan\n", nrp);
}

int main()
{
    struct Mahasiswa *head = NULL;
    Push(&head, "Defri", 123);
    Push(&head, "Indra", 124);
    Push(&head, "Mahardika", 125);

    SearchByName(head, "Indra");
    SearchByNrp(head, 126);
    Tampil(head);

    //   Output :
    //   Index Ke-1 = Indra |124
    //   Data dengan NRP 126 tidak ditemukan
    //   Defri |123
    //   Indra |124
    //   Mahardika |125
}