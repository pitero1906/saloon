//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "druk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfaktura *faktura;
//---------------------------------------------------------------------------
__fastcall Tfaktura::Tfaktura(TComponent* Owner)
        : TForm(Owner)
{
        int licznik, i;
          ifstream info;
          info.open("dane\\sprzedaz\\id_sprzedaz.dat");
          while (!info.eof())
          {
                info >> licznik;
          }
          info.close();

         int id_faktura;
          id_faktura = licznik-1;
          //id_faktura++;

           ostringstream s;
          s << id_faktura;
          string str = s.str();

          string sciezka;
          sciezka = "dane\\sprzedaz\\" + str + ".dat";


         ifstream infile1;
        infile1.open(sciezka.c_str());

        string tab[26];

        for(i =0; i<26; i++)
        {
           getline(infile1, tab[i]);
        }

        infile1.close();

         for(i = 0; i<26; i++)
        {
                 Mem->Lines->Add(tab[i].c_str());

         }

}

void __fastcall Tfaktura::PrintMemo(TMemo *Memo, TPrintDialog *PrintDialog)
{
 int trips;
 int dups;
 int firstpg;
 int lastpg;
 bool needsnewpg = false;

 pages->Text = Memo->Text;

 if(!PrintDialog->Execute())
  return; //je¿eli u¿ytkownik nie naciœnie OK, drukowanie zostanie anulowane.

 if(!PrintDialog->Collate)
 {
  trips = 1;
  dups  = PrintDialog->Copies;
 }
 else
 {
  trips = PrintDialog->Copies;
  dups  = 1;
 }

 if(PrintDialog->PrintRange == prAllPages)
 {
  firstpg = PrintDialog->MinPage; //Minimalna iloœæ drukowanych stron.
  lastpg  = PrintDialog->MaxPage; //Maksymalna iloœæ drukowanych stron.
 }
 else
 {
  firstpg = PrintDialog->FromPage; //Numer strony od której rozpocznie siê drukowanie.
  lastpg  = PrintDialog->ToPage;   //Numer strony na której skoñczy siê drukowanie
 }

 Printer()->BeginDoc(); //Inicjowanie pracy drukarki.

 Printer()->Title = "Faktura VAT"; //Tytu³ wydruku.

 for(int x = 0; x < trips; x++)             //dla ka¿dego obiegu
  for(int y = firstpg - 1; y < lastpg; y++) //dla ka¿dej strony
   for(int z = 0; z < dups; z++)            //dla ka¿dej otwartej strony
   {
    if(needsnewpg)
    Printer()->NewPage();

    PrintPage(y); //drukuj t¹ stronê.
    needsnewpg = true; //dalsze strony potrzebuj¹ przerw.
   }

 Printer()->EndDoc();
}
//--------------------------------
void __fastcall Tfaktura::PrintPage(int page)
{
 int pageline = 0;

 Printer()->Canvas->TextOut(20, (10 + Printer()->Canvas->TextHeight("Jakiœ tekst")) * pageline,
 "Jeszcze jeden tekst" + IntToStr(page + 1));
 pageline += 2;

 for(__int8 line = 0; line < pages->Count; line++)
 {
  __int8 h = (10 + Printer()->Canvas->TextHeight("dowolny tekst"));
  Printer()->Canvas->TextOut(20, h * pageline, pages->Strings[line].c_str());
  pageline++;
  if(pageline *h >= Printer()->PageHeight)
  {
   pageline = 0;
   Printer()->NewPage();
  }
 }
}
//--------------------------------
void __fastcall Tfaktura::FormShow(TObject *Sender)
{
currentpage = 0;
 pages = new TStringList;
}


//---------------------------------------------------------------------------
void __fastcall Tfaktura::Button1Click(TObject *Sender)
{
        PrintMemo(Mem, Print);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

