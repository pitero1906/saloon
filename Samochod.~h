//---------------------------------------------------------------------------

#ifndef SamochodH
#define SamochodH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Silnik.h"
#include "Model.h"
#include "Nadwozie.h"
#include <vector>
//---------------------------------------------------------------------------
class Tadd_samochod : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TGroupBox *GB1;
        TGroupBox *GB3;
        TComboBox *model;
        TComboBox *silnik;
        TComboBox *nadwozie;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *rok_produkcji;
        TEdit *klima;
        TEdit *alusy;
        TEdit *komp;
        TEdit *skora;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tadd_samochod(TComponent* Owner);
};

class Samochod
:public Silnik, public Model, public Nadwozie
{
public:

        int id_samochod;
        int rok_produkcji;
        double cena_klima;
        double cena_alusy;
        double cena_komp;
        double cena_skora;
        double c_werPodstawowa;

        Samochod(string n_model, double c_model, string r_nadwozie, int d_nadwozie, double c_nadwozie, string r_silnik, double p_silnik, double c_silnik, int r, double c_klima, double c_alusy, double c_komp, double c_skora)
	:Model(n_model, c_model), Silnik(r_silnik, p_silnik, c_silnik), Nadwozie(r_nadwozie, d_nadwozie, c_nadwozie)
	{
		rok_produkcji = r;
                cena_klima = c_klima;
                cena_alusy = c_alusy;
                cena_komp = c_komp;
                cena_skora = c_skora;
	}

        void zapis()
        {
                int liczba;
                ifstream infile;
                infile.open("dane\\samochod\\id_samochod.dat");
                while (!infile.eof())
                {
                        infile >> liczba;
                }
                infile.close();
                Samochod::id_samochod = liczba;
                Samochod::c_werPodstawowa = Model::cena_model + Silnik::cena_silnik + Nadwozie::cena_nadwozie;

                ofstream outfile("dane\\samochod\\baza_samochod.dat", ios::app);
                if (!outfile) return;
                outfile << Samochod::c_werPodstawowa << endl;
                outfile << Samochod::cena_klima << endl;
                outfile << Samochod::cena_alusy << endl;
                outfile << Samochod::cena_komp << endl;
                outfile << Samochod::cena_skora << endl;
                outfile << Samochod::rok_produkcji << endl;
                outfile << Samochod::id_samochod << endl;

                outfile.close();

                Samochod::id_samochod++;
                ofstream outfile2("dane\\samochod\\id_samochod.dat");
                if (!outfile2) return;
                outfile2 << Samochod::id_samochod << endl;
                outfile2.close();
        }

        double licz_cene()
        {
                Samochod::c_werPodstawowa = Model::cena_model + Silnik::cena_silnik + Nadwozie::cena_nadwozie;
                return Samochod::c_werPodstawowa;
        }


};

//---------------------------------------------------------------------------
extern PACKAGE Tadd_samochod *add_samochod;
//---------------------------------------------------------------------------
#endif
