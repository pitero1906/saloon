//---------------------------------------------------------------------------

#ifndef EgzemplarzH
#define EgzemplarzH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <iostream>
#include <sstream>
#include "Wyposazenie.h"
#include "Samochod.h"
#include <vector>
#include "Model.h"
#include "Silnik.h"
#include "Nadwozie.h"


#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
class Tadd_egzemplarz : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TCheckBox *klima;
        TCheckBox *alusy;
        TCheckBox *komp;
        TCheckBox *skora;
        TButton *Button1;
        TLabel *cena;
        TImage *foto;
        TComboBox *info;
        TGroupBox *GroupBox5;
        TLabel *id;
        void __fastcall infoChange(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tadd_egzemplarz(TComponent* Owner);
};

class Egzemplarz
:public Samochod, public Wyposazenie
{
public:
        int id_egzemplarz;
        double cena_koncowa;
        int ilosc_e;

        Egzemplarz(string n_model, double c_model, string r_nadwozie, int d_nadwozie, double c_nadwozie, string r_silnik, double p_silnik, double c_silnik, int r, double c_klima, double c_alusy, double c_komp, double c_skora, int ilosc, bool kl, bool al, bool ko, bool sk)
        :Samochod(n_model, c_model, r_nadwozie, d_nadwozie, c_nadwozie, r_silnik, p_silnik, c_silnik, r, c_klima, c_alusy, c_komp, c_skora), Wyposazenie(kl, al, ko, sk)
        //:Model(n_model, c_model), Silnik(r_silnik, p_silnik, c_silnik), Nadwozie(r_nadwozie, d_nadwozie, c_nadwozie)
        {
                ilosc_e = ilosc;
        }


        void zapis()
        {
                int liczba;
                ifstream infile;
                infile.open("dane\\egzemplarz\\id_egzemplarz.dat");
                while (!infile.eof())
                {
                        infile >> liczba;
                }
                infile.close();
                Egzemplarz::id_egzemplarz = liczba;


                ofstream outfile("dane\\egzemplarz\\baza_egzemplarz.dat", ios::app);
                if (!outfile) return;
                outfile << Egzemplarz::id_egzemplarz << endl;
                outfile << Egzemplarz::ilosc_e << endl;
                outfile << Egzemplarz::cena_koncowa << endl;
                outfile << Model::nazwa_model << endl;
                outfile << Silnik::rodzaj_silnik << " " << Silnik::pojemnosc << endl;
                outfile << Nadwozie::rodzaj_nadwozie << " " << Nadwozie::drzwi << endl;
                outfile << Samochod::rok_produkcji << endl;
                outfile << Wyposazenie::klima << endl;
                outfile << Wyposazenie::alusy << endl;
                outfile << Wyposazenie::komp << endl;
                outfile << Wyposazenie::skora << endl;

                outfile.close();

                Egzemplarz::id_egzemplarz++;
                ofstream outfile2("dane\\egzemplarz\\id_egzemplarz.dat");
                if (!outfile2) return;
                outfile2 << Egzemplarz::id_egzemplarz << endl;
                outfile2.close();
        }

};



//---------------------------------------------------------------------------
extern PACKAGE Tadd_egzemplarz *add_egzemplarz;
//---------------------------------------------------------------------------
#endif
