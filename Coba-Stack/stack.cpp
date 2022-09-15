#include <iostream>
using namespace std;
#define size 10
int A[size];
int atas=-1;

bool iskosong()
{
    if(atas == -1)
        return true;
    else
        return false;
}

void push(int nilai)
{
    if(atas == -1)
        cout << "Stack penuh\n";
    else
    {
        atas++;
        A[atas] = nilai;
    }
}

void pop()
{
    if(iskosong())
        cout << "Stack kosong\n";
    else
        atas--;
}

void lihatStack()
{
    if(iskosong())
        cout << "Stack kosong\n";
    else
    {
        for (int i = 0; i <= atas; i++)
        {
            cout << A[i] << " ";
        }
    }
}

void lihatAtas()
{
    if(iskosong())
        cout << "Stack kosong\n";
    else
        cout << "Yang paling atas adalah " << A[atas] << endl;
}

int main()
{
    push(6);
    push(7);
    push(8);
    lihatStack();
    pop();
    lihatAtas();
    return 0;

}


