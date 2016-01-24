//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Klient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tnew_egzemplarz *new_egzemplarz;
//---------------------------------------------------------------------------
__fastcall Tnew_egzemplarz::Tnew_egzemplarz(TComponent* Owner)
        : TForm(Owner)
{
         int liczba3;
          ifstream inf;
          inf.open("dane\\egzemplarz\\id_egzemplarz.dat");
          while (!inf.eof())
          {
                inf >> liczba3;
          }
          inf.close();
          ostringstream ss;
          ss << liczba3;
          string str = ss.str();
          AnsiString zmienna = str.c_str();
          ID->Caption = zmienna;

}
//---------------------------------------------------------------------------
void __fastcall Tnew_egzemplarz::Button2Click(TObject *Sender)
{
          if(imie->Text == "" || nazwisko->Text == "" || pesel->Text == "" || ID->Caption == "")
        {
                Application->MessageBoxA("Wprowad� brakuj�ce dane", "B��d", MB_OK | MB_ICONSTOP);

        }

        else
        {
                string im, nazw, pes;

                im = imie->Text.c_str();
                nazw = nazwisko->Text.c_str();
                pes = pesel->Text.c_str();

                Klient nowy(im, nazw, pes);

                string id;
                id = ID->Caption.c_str();

                ofstream test("dane\\klient\\baza_klient.dat", ios::app);
                if (!test) return;
                test << nowy.imie_k << endl;
                test << nowy.nazwisko_k << endl;
                test << nowy.pesel << endl;
                test << id << endl;
                test.close();

                imie->Text = "";
                nazwisko->Text = "";
                pesel->Text = "";

                add_egzemplarz->ShowModal();
                new_egzemplarz->Close();

        }

        int liczba3;
          ifstream inf;
          inf.open("dane\\egzemplarz\\id_egzemplarz.dat");
          while (!inf.eof())
          {
                inf >> liczba3;
          }
          inf.close();
          ostringstream ss;
          ss << liczba3;
          string str = ss.str();
          AnsiString zmienna = str.c_str();
          ID->Caption = zmienna;



}
//---------------------------------------------------------------------------
void __fastcall Tnew_egzemplarz::Button3Click(TObject *Sender)
{
        new_egzemplarz->Close();        
}
//---------------------------------------------------------------------------

