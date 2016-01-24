//---------------------------------------------------------------------------

#ifndef KlientH
#define KlientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream.h>
#include "Egzemplarz.h"
//---------------------------------------------------------------------------
class Tnew_egzemplarz : public TForm
{
__published:	// IDE-managed Components
        TEdit *imie;
        TEdit *nazwisko;
        TEdit *pesel;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *ID;
        TLabel *Label6;
        TButton *Button2;
        TButton *Button3;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tnew_egzemplarz(TComponent* Owner);
};

class Klient
{
public:
        string imie_k;
        string nazwisko_k;
        string pesel;

        Klient(string im, string naz, string pes)
        {
                imie_k = im;
                nazwisko_k = naz;
                pesel = pes;
        }

};

//---------------------------------------------------------------------------
extern PACKAGE Tnew_egzemplarz *new_egzemplarz;
//---------------------------------------------------------------------------
#endif
