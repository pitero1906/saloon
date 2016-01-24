//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "menu.h"
#include "Silnik.h"
#include "Nadwozie.h"
#include "Model.h"
#include "Samochod.h"
#include "Egzemplarz.h"
#include "Klient.h"
#include "Sprzedaz.h"
#include "druk.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tmainmenu *mainmenu;
//---------------------------------------------------------------------------
__fastcall Tmainmenu::Tmainmenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tmainmenu::Silnik1Click(TObject *Sender)
{
        add_silnik->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tmainmenu::Nadwozie1Click(TObject *Sender)
{
      add_nadwozie->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tmainmenu::Model1Click(TObject *Sender)
{
      add_model->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tmainmenu::Nowysamochd1Click(TObject *Sender)
{

      add_samochod->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tmainmenu::Nowyegzemplarz1Click(TObject *Sender)
{
     add_egzemplarz->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tmainmenu::Personalizujzamwienie1Click(TObject *Sender)
{
        new_egzemplarz->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tmainmenu::Kupgotowyegzemplarz1Click(TObject *Sender)
{
      zakup->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tmainmenu::Odswiedane1Click(TObject *Sender)
{
         Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall Tmainmenu::Analizujdochody1Click(TObject *Sender)
{
        Application->MessageBoxA("Analiza dochodów dostêpna w kolejnej wersji programu", "Przepraszamy", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall Tmainmenu::Drukujfakture1Click(TObject *Sender)
{
        faktura->ShowModal();
}
//---------------------------------------------------------------------------

