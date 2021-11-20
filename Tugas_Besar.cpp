#include <iostream>
#include <conio.h>
#include <ctime>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//ALGORITMA KASIR MINI MARKET
/*
1.Pemilihan Kasir
2.Melakukan Log In ke dalam sistem
3.Memasukan barang yang ingin dibeli
4.Menentukan apakah pelanggan seorang member/non-member
    jika member mendapatkan diskon 5%
5.Checkout.
*/

//Fungsi angka acak untuk nomor order di checkout
int numberRandomizer()
{
    int i, number;
    time_t nTime;
    number = 5;

    srand((unsigned) time(&nTime));
    for( i = 0 ; i < number ; i++ )
    {printf("%d", rand() % 1000);}

    return(0);
}

//Fungsi Pemisah angka
string thousandSeparator(int n)
{
    string ans = "";
    string num = to_string(n);
    int count = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {count++;ans.push_back(num[i]);
        if (count == 3)
            {ans.push_back('.');count = 0;}
    }

    reverse(ans.begin(), ans.end());

        if (ans.size() % 4 == 0)
            {ans.erase(ans.begin());}

    return ans;
}

//Fungsi checkout
int checkout(int sum,string nama,string NIM)
{
    int uang;
    double discount;
    string desc,mem;
    time_t now = time(0);
    char* dt = ctime(&now);

    cout<<"========================================="<<endl;
    cout<<"\n1.member \n2.non member \n"<<endl;
    cout<<"========================================="<<endl;

    disk:
    cin>>mem;
    if (mem=="1")
    {discount=0.95;desc="     Discount -5%";}
        else if(mem=="2")
        {discount=1;desc="      No Discount";}
    else
    {cout<<"Angka yang anda input salah, silahkan pilih ulang\n";goto disk;}

    system ("cls");
    cout<<"===============|CHECKOUT.|==============="<<endl;
    cout<<"\n\nSekaran Gunung Pati, Semarang \n\n";
    cout<<" \t\t "<< dt <<"\n";
    cout<<nama<<endl;
    cout<<NIM<<endl;
    cout<<"\nRECEIPT \n";
    cout<<"----------------------------------------- \n";
    cout<<"\t\t\tTOTAL = Rp "<<thousandSeparator(sum)<<"\n";
    cout<<"\t\t\t"<<desc<<"\n";
    cout<<"\t\t\t      = Rp "<<thousandSeparator(sum*discount)<<"\n";
    cout<<"----------------------------------------- \n\n";
    cout<<"Order No."<<numberRandomizer()<<"\n";
    cout<<"CASH\t\t\t\tRp ";cin>>uang;
    cout<<"\n\nKembalian = Rp "<<thousandSeparator(uang-(sum*discount))<<"\n";
    cout<<"----------------------------------------- \n";
    cout<<"Terimakasih Telah Berbelanja di Shopfee. \n\n";
    cout<<"Customer Sevice: 0812-xxxx-xxx \n";
    cout<<"========================================= \n";

    getch();
    exit(0);
    return 0;
}

//Fungsi Menu
int menuKeranjang(string nama,string NIM)
{
    int harga,jumlah,total;
    double sum = 0.0;
    string barang,benda;

    int N=4;
    string daftarMenu[N]={"Indomie","Susu","Roti","Meses"};
    string harga_barang[N]={"2.500","8.000","15.000","7.500"};

    cout<<"\nTotal Belanja Saat ini: Rp "<<thousandSeparator(sum)<<"\n"<<endl;


    daftar_menu:
    cout<<"==================|MENU|=================\n\n"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<=N-1; i++)
    {cout<<i+1<<". "<<daftarMenu[i]<<":\t Rp "<<harga_barang[i]<<"\n";}
    cout<<"-----------------------------------------"<<endl;
    cout<<"Untuk Checkout, pilih 0 \n";

    menu:
        do{

        cout<<"\nPilih barang yang anda mau: ";cin>>barang;

        if (barang=="1"){benda="indomie";harga = 2500;}
        else if (barang=="2"){benda="Susu";harga = 8000;}
        else if (barang=="3"){benda="Roti";harga = 15000;}
        else if (barang=="4"){benda="Meses";harga = 7500;}
        else if (barang=="0"){checkout(sum,nama,NIM);}
        else{cout<<"barang tidak ada, silahkan memilih ulang \n"<<endl;goto menu;}

        cout<<"Jumlah barang yang di inginkan: ";cin>>jumlah;
        total = harga * jumlah;

        cout<<benda<<" Rp "<<thousandSeparator(harga)<<".....x"<<jumlah<<" = Rp "<<thousandSeparator(total)<<"\n";
        sum += (total);

        getch();
        system ("cls");
        cout<<"\nTotal Belanja Saat ini: Rp "<<thousandSeparator(sum)<<"\n"<<endl;
        goto daftar_menu;

        }while(barang != "0");
        cout<<"\n========================================="<<endl;

}

//Fungsi PIN
int Password(string nama)
{
    string Username,PIN;
    cout<<"=========================================\n"<<endl;
    cout<<"      Masukan Username dan PIN anda\n";
    cout<<"\n========================================="<<endl;
    pass:
    cout<<"Username: ";cin>>Username;
    cout<<"PIN     : ";cin>>PIN;
    cout<<"========================================="<<endl;

    if(nama=="Muhammad Dylan Hikma Sanjaya" && Username=="jaynotdylan" && PIN=="123456")
        {cout<<"\nPassword is Correct\n"<<endl;
        getch();
        system ("cls");}
        else if(nama=="Yassar Ghinata" && Username=="yassar123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Stefan Enrico Joel Manurung" && Username=="stefan123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Alya Nur Afifa" && Username=="alya123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Satria Imawan" && Username=="satria123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Awangga Surya Atmaja" && Username=="surya123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
    else
    {cout<<"Username atau PIN salah, coba lagi\n========================================="<<endl;goto pass;}

}

//Program utama
int main()
{

    string cashier,nama,NIM;
    string kasir[5]={"Dylan","Yassar","Stefan","Alya","Satria"};

    cout<<"================|SHOPFEE|================"<<endl;
    cout<<"\nPilih Kasir:\n"<<endl;

    for(int i=0; i<=5-1; i++)
    {cout<<i+1<<". "<<kasir[i]<<"\n";}

    cout<<"\n========================================="<<endl;

    x:
    cin>>cashier;
    if(cashier=="1")
    {nama="Muhammad Dylan Hikma Sanjaya";       NIM="4612421028";}
        else if(cashier=="2")
        {nama="Yassar Ghinata";                 NIM="4612421010";}
        else if(cashier=="3")
        {nama="Stefan Enrico Joel Manurung";    NIM="4612421045";}
        else if(cashier=="4")
        {nama="Alya Nur Afifa";                 NIM="4612421002";}
        else if(cashier=="5")
        {nama="Satria Imawan";                  NIM="4612421050";}
        else if(cashier=="6")
        {nama="Awangga Surya Atmaja";           NIM="4612421042";}

    else
    {cout<<"Tidak ada kasir ber-angka "<<cashier<<" pada daftar di atas, silahkan pilih ulang"<<endl; goto x;}

        Password(nama);
        menuKeranjang(nama,NIM);
}
