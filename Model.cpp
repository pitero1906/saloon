//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Model.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tadd_model *add_model;
//---------------------------------------------------------------------------
__fastcall Tadd_model::Tadd_model(TComponent* Owner)
        : TForm(Owner)
{
}

string n_model;
double c_model;

//---------------------------------------------------------------------------
void __fastcall Tadd_model::Button1Click(TObject *Sender)
{
         if(nazwa->Text == "" || cena->Text == "")
        {
                Application->MessageBoxA("WprowadŸ brakuj¹ce dane", "B³¹d zapisu", MB_OK | MB_ICONSTOP);
        }
     else
     {
       n_model = nazwa->Text.c_str();
       c_model = cena->Text.ToDouble();

       Model nowy(n_model, c_model);

       nowy.zapis();
       Application->MessageBoxA("Model zosta³ dodany do bazy", "Gratulacje!", MB_OK);

        Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);

      }

      nazwa->Text = "";
      cena->Text = "";

}
//---------------------------------------------------------------------------
void __fastcall Tadd_model::Button2Click(TObject *Sender)
{
        add_model->Close();
}
//---------------------------------------------------------------------------
