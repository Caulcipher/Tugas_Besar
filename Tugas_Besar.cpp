#include <iostream>
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

//Fungsi checkout
int Checkout(){
    cout<<"THIS IS CHECKOUT";
}
//Fungsi Harga Barang
int Milih_Barang(){
    int jumlah,total,harga,barang;
    string benda;
    cout<<"\nPilih barang yang anda mau: ";cin>>barang;
        if (barang==1){benda="indomie";harga = 2500;}
        else if (barang==2){benda="Susu";harga = 8000;}
        else if (barang==3){benda="Roti";harga = 15000;}
        else if (barang==4){benda="Meses";harga = 7500;}
    else{cout<<"barang tidak ada, silahkan memilih ulang"<<Milih_Barang()<<endl;}

    cout<<"Jumlah barang yang di inginkan: ";cin>>jumlah;
    total = harga * jumlah;
    cout<<benda<<"..... x"<<jumlah<<" = "<<total<<Milih_Barang()<<endl;
}


//Fungsi Menu Barang
int Menu_Barang(){

    cout<<"\tMenu\n";
    cout<<"1.Indomie\t2.Susu\n";
    cout<<"3.Roti\t\t4.Meses\n";
    Milih_Barang();
}

//Fungsi PIN
int Password(){
    int PIN;string Username;
    cout<<"\nMasukan Username dan PIN anda\n";
    cout<<"Uermame: ";cin>>Username;
    cout<<"PIN: ";cin>>PIN;
    if(Username=="Customer" && PIN==123456)
        {cout<<"Password is Correct\n"<<endl;}
    else
    {cout<<"Maaf Username atau PIN yang anda masukan salah, silahkan coba lagi\n"<< Password() <<endl;}
}

int Menu_Customer(){
    int member_or_not;
    cout<<"1.Member\n2.Non Member\n";cin>>member_or_not;cout<<"\n";

    if(member_or_not==1){
        cout<<"\tMEMBER\n";
        Password();
        Menu_Barang();
    }
        else if(member_or_not==2){
            Menu_Barang();
        }
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

    if(Menu1==1){Menu_Customer();}
        else if(Menu1==2){Menu_Employee();}
    else
    {cout<<"!ERROR: MENU YANG ANDA PILIH TIDAKLAH VALID, PILIHLAH MENU YANG TERTERA PADA PROGRAM!\n\n"<<main()<<endl;}
}
