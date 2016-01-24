//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Nadwozie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tadd_nadwozie *add_nadwozie;
//---------------------------------------------------------------------------
__fastcall Tadd_nadwozie::Tadd_nadwozie(TComponent* Owner)
        : TForm(Owner)
{
}

double c_nadwozie;
int d;
string r_nadwozie;

//---------------------------------------------------------------------------
void __fastcall Tadd_nadwozie::Button2Click(TObject *Sender)
{
        add_nadwozie->Close();
}
//---------------------------------------------------------------------------

void __fastcall Tadd_nadwozie::Button1Click(TObject *Sender)
{
         if(rodzaj->Text == "" || drzwi->Text == "" || cena->Text == "")
        {
                Application->MessageBoxA("WprowadŸ brakuj¹ce dane", "B³¹d zapisu", MB_OK | MB_ICONSTOP);
        }
     else
     {
       r_nadwozie = rodzaj->Text.c_str();
       d = drzwi->Text.ToInt();
       c_nadwozie = cena->Text.ToDouble();

       Nadwozie nowy(r_nadwozie, d, c_nadwozie);

       nowy.zapis();
       Application->MessageBoxA("Nadwozie zosta³o dodane do bazy", "Gratulacje!", MB_OK);
        Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);

      }

      rodzaj->Text = "";
      drzwi->Text = "";
      cena->Text = "";
}
//---------------------------------------------------------------------------

