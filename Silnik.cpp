//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Silnik.h"
#include "Samochod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tadd_silnik *add_silnik;
//---------------------------------------------------------------------------
__fastcall Tadd_silnik::Tadd_silnik(TComponent* Owner)
        : TForm(Owner)
{
}

double c_silnik, po;
string r_silnik;
        
//---------------------------------------------------------------------------
void __fastcall Tadd_silnik::Button1Click(TObject *Sender)
{
        if(rodzaj->Text == "" || pojemnosc->Text == "" || cena->Text == "")
        {
                Application->MessageBoxA("WprowadŸ brakuj¹ce dane", "B³¹d zapisu", MB_OK | MB_ICONSTOP);
        }
     else
     {
       r_silnik = rodzaj->Text.c_str();
       po = pojemnosc->Text.ToDouble();
       c_silnik = cena->Text.ToDouble();

       Silnik nowy(r_silnik, po, c_silnik);

       nowy.zapis();
       Application->MessageBoxA("Silnik zosta³ dodany do bazy", "Gratulacje!", MB_OK);
       add_silnik->Next();

        Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);
        //add_silnik->Visible = true;
        //add_silnik->ShowModal();
      }

      rodzaj->Text = "";
      pojemnosc->Text = "";
      cena->Text = "";
     
}
//---------------------------------------------------------------------------

void __fastcall Tadd_silnik::Button2Click(TObject *Sender)
{
        add_silnik->Close();        
}
//---------------------------------------------------------------------------

