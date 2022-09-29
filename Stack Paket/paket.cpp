#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int maks = 11;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void push(int x)
{
    if(x>maks)
    {
        gotoxy(1,9);cout << "Mohon maaf stack Anda penuh!!!";
        x = x-1;
        gotoxy(1,10);cout<<"Press Any Key...";
        getch();
    }
    else
    {
        gotoxy(1,9);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[x].jenis_brg;
        gotoxy(1,10);cout<<"Inputkan Berat           :";
        cin>>kirim[x].berat;
        gotoxy(1,11);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[x].kota;
    }
}


void tampildata(int x)
{
    gotoxy(1,9);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(1,20-a);
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
}

void pop(int x)
{
    if(x=1)
    {
        gotoxy(1,10);cout << "Mohon maaf stack Anda kosong!!!";
    }
    else
    {
        gotoxy(1,10);cout<<"Data terakhir yang Anda hapus(pop) adalah :"<<endl;
        gotoxy(1,11);cout<<kirim[x].jenis_brg<<" ";
        cout<<kirim[x].berat<<" Kg ";
        cout<<kirim[x].kota<<endl<<endl;
    }

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int top=1;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data (push)";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir (pop)"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            {
                push(top);
                top++;
            }
        if(pilih==2)
            {
                top--;
                pop(top);
            }
        if(pilih==3)
            tampildata(top);

    }
    while(pilih!=9);
    return 0;
}
