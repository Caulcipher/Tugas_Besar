#include <iostream>
#include <conio.h>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

//ALGORITMA KASIR MINI MARKET
/*  Menu Pilihan Customer/Pihak Mini Market (CHECK)
    Customer: member(mendapatkan diskon 5%)/umum
    1. Tabel Input Identitas(PIN)(member)(check)
    2. Tabel Nama, Deskripsi dan harga barang(check)
    3. Input Barang yang ingin dibeli(check)
    4. Tabel Barang Yang dibeli dan harga
    5. Tabel Checkout (Total yang perlu dibeli, input Uang yang digunakan untuk membeli barang, Total Kembalian)

    Pihak Mini Market:
    1. Tabel Input Identitas(PIN)
    2. Tabel menu:  a. Input Barang Baru(Nama barang,Deskripsi barang, Harga barang)
                    - b. Mengubah harga -
*/

//Fungsi Pemisah angka
string thousandSeparator(int n)
{
    string ans = "";
    string num = to_string(n);
    int count = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {count++;ans.push_back(num[i]);

        if (count == 3)
            {ans.push_back('.');
            count = 0;}
    }

    reverse(ans.begin(), ans.end());

    if (ans.size() % 4 == 0)
    {ans.erase(ans.begin());}

    return ans;
}
//Fungsi checkout
int checkout(int sum)
{
    int uang;
    time_t now = time(0);char* dt = ctime(&now);

    system ("cls");
    cout<<"\t\tSOPFEE\n\n";
    cout<<"Sekaran Gunung Pati, Semarang \n\n";
    cout<<"Nama Kasir \t "<< dt <<"\n";
    cout<<"RECEIPT \n";
    cout<<"----------------------------------------- \n";
    cout<<"\t\t\tTOTAL = Rp "<<thousandSeparator(sum)<<"\n";
    cout<<"----------------------------------------- \n\n";
    cout<<"Order No.14328109328 \n";
    cout<<"CASH \t\t\t Rp ";cin>>uang;
    cout<<"\n\nKembalian = Rp "<<thousandSeparator(uang-sum)<<"\n\n";
    cout<<"Terimakasih Telah Berbelanja di Shopfee. \n\n";
    cout<<"Customer Sevice: 0812-xxxx-xxx \n\n";

    exit(0);
    return 0;
}

//Fungsi Menu
int menuKeranjang(){
    int barang,harga,jumlah,total;
    string benda;
    double sum = 0.0;

    cout<<"Total Belanja Saat ini: Rp "<<thousandSeparator(sum)<<"\n"<<endl;

    daftar_menu:
    cout<<"\tMenu\n";
    cout<<"1.Indomie\t2.Susu\n";
    cout<<"3.Roti\t\t4.Meses\n";
    cout<<"\nUntuk Checkout, pilih 0 \n";

    menu:
        do{

        cout<<"\nPilih barang yang anda mau: ";cin>>barang;

        if (barang==1){benda="indomie";harga = 2500;}
        else if (barang==2){benda="Susu";harga = 8000;}
        else if (barang==3){benda="Roti";harga = 15000;}
        else if (barang==4){benda="Meses";harga = 7500;}
        else if (barang==0){checkout(sum);}
        else{cout<<"barang tidak ada, silahkan memilih ulang \n"<<endl;goto menu;}

        cout<<"Jumlah barang yang di inginkan: ";cin>>jumlah;
        total = harga * jumlah;

        cout<<benda<<" Rp "<<thousandSeparator(harga)<<".....x"<<jumlah<<" = Rp "<<thousandSeparator(total)<<"\n";
        sum += (total);

        getch();
        system ("cls");
        cout<<"Total Belanja Saat ini: Rp "<<thousandSeparator(sum)<<"\n"<<endl;
        goto daftar_menu;

        }while(barang != 0);
}

//Fungsi PIN
int Password(){
    int PIN;string Username;
    cout<<"\nMasukan Username dan PIN anda\n";
    cout<<"Uermame: ";cin>>Username;
    cout<<"PIN: ";cin>>PIN;

    if(Username=="Customer" && PIN==123456)
        {cout<<"Password is Correct\n"<<endl;system ("cls");}
    else
    {cout<<"Maaf Username atau PIN yang anda masukan salah, silahkan coba lagi\n"<< Password() <<endl;}
}

int Menu_Customer(){
    int member_or_not;
    cout<<"1.Member\n2.Non Member\n";cin>>member_or_not;cout<<"\n";
    system ("cls");

    if(member_or_not==1)
        {
        cout<<"\tMEMBER\n";
        Password();
        menuKeranjang();
        }
        else if(member_or_not==2)
        {menuKeranjang();}
    else
    {cout<<"!ERROR: MENU YANG ANDA PILIH TIDAKLAH VALID, PILIHLAH MENU YANG TERTERA PADA PROGRAM!\n\n"<<Menu_Customer()<<endl;}
}

int Menu_Employee(){
    Password();
}

//Program utama
int main(){
    int Menu1;
    cout<<"WELLCOME TO SHOPFEE\n\n";
    cout<<"1.Customer\n2.Shopfee Employee\n";cin>>Menu1;cout<<"\n";
    system ("cls");
    if(Menu1==1){Menu_Customer();}
        else if(Menu1==2){Menu_Employee();}
    else
    {cout<<"!ERROR: MENU YANG ANDA PILIH TIDAKLAH VALID, PILIHLAH MENU YANG TERTERA PADA PROGRAM!\n\n"<<main()<<endl;}
}
