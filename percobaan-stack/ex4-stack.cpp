#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <conio.h>

using namespace std;

struct
{
    int top;
    char baju[5][20];
} tumpukan;

void push(char tempBaju[20]);
void pop();
void awal();
int isEmpty();
int isFull();

int main()
{
    int pilih, doHapus;
    char data[20];
    string i;
    awal();
    do
    {
        system("cls");
        cout << "=================================================" << endl;
        cout << "============= Program Tumpukan Baju =============" << endl;
        cout << " 1. PUSH (Untuk memasukkan baju ke tumpukkan)    " << endl;
        cout << " 2. POP  (Untuk mengeluarkan baju dari tumpukkan)" << endl;
        cout << " 3. EXIT                                         " << endl;
        cout << "=================================================" << endl;
        cout << "=========== maximal hanya 5 tumpukan ============" << endl;

        if (!isEmpty())
        {
            for (int i = tumpukan.top; i >= 0; i--)
            {
                cout << "[" << tumpukan.baju[i] << "]" << endl;
            }
        }
        else
        {
            cout << "[tumpukan baju dalam kondisi kosong]";
        }
        cout << "\nMasukkan Pilihan : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            cout << "Masukkan Baju kedalam tumpukkan [contoh: kemeja] : ";
            cin >> data;
            push(data);
            break;
        case 2:
            cout << "Yakin akan mengeluarkan tumpukkan ? (input 1 for yes) : ";
            cin >> doHapus;
            if (doHapus == 1)
            {
                pop();
            }
            else
            {
                main();
            }
            break;
        case 3:
            cout << "Tekan enter untuk keluar :";
            break;
        default:
            cout << "ERROR!";
            break;
        }
        printf("\nPress any key to continue...");
        getch();
    } while (pilih != 3);
}

void push(char data[5])
{
    if (!isFull())
    {
        tumpukan.top = tumpukan.top + 1;
        strcpy(tumpukan.baju[tumpukan.top], data);
        cout << "Baju berhasil masuk kedalam tumpukkan";
    }
    else
    {
        cout << "Baju dalam tumpukan penuh";
    }
}

void pop()
{
    if (!isEmpty())
    {
        tumpukan.top--;
        cout << "Baju pada tumpukan ke-" << tumpukan.top + 2 << " sudah diambil";
    }
    else
    {
        cout << "Baju dalam tumpukan kosong";
    }
}

void awal()
{
    tumpukan.top = -1;
}

int isEmpty()
{
    if (tumpukan.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (tumpukan.top == 5 - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}