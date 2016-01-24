//---------------------------------------------------------------------------

#ifndef SilnikH
#define SilnikH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <iostream>
#include <sstream>


//---------------------------------------------------------------------------
class Tadd_silnik : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *rodzaj;
        TEdit *pojemnosc;
        TEdit *cena;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tadd_silnik(TComponent* Owner);
};

class Silnik
{

public:
        int id_silnik;
	string rodzaj_silnik;
	double pojemnosc;
        double cena_silnik;

	Silnik(string rs, double p, double cs)
	{
		rodzaj_silnik = rs;
		pojemnosc = p;
		cena_silnik = cs;
	}

        void zapis()
        {
                int liczba;
                ifstream infile;
                infile.open("dane\\silnik\\id_silnik.dat");
                while (!infile.eof())
                {
                        infile >> liczba;
                }
                infile.close();
                Silnik::id_silnik = liczba;

                ofstream outfile("dane\\silnik\\baza_silnik.dat", ios::app);
                if (!outfile) return;
                outfile << Silnik::rodzaj_silnik << endl;
                outfile << Silnik::pojemnosc << endl;
                outfile << Silnik::cena_silnik << endl;
                outfile << Silnik::id_silnik << endl;

                outfile.close();

                Silnik::id_silnik++;
                ofstream outfile2("dane\\silnik\\id_silnik.dat");
                if (!outfile2) return;
                outfile2 << Silnik::id_silnik << endl;
                outfile2.close();
        }
};
//---------------------------------------------------------------------------
extern PACKAGE Tadd_silnik *add_silnik;
//---------------------------------------------------------------------------
#endif
