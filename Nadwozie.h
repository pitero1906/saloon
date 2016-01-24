//---------------------------------------------------------------------------

#ifndef NadwozieH
#define NadwozieH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
class Tadd_nadwozie : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *rodzaj;
        TEdit *drzwi;
        TEdit *cena;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tadd_nadwozie(TComponent* Owner);
};

class Nadwozie
{
public:
	string rodzaj_nadwozie;
        int drzwi;
        double cena_nadwozie;
        int id_nadwozie;

	Nadwozie(string rn, int d, double cn)
	{
		rodzaj_nadwozie = rn;
                drzwi = d;
		cena_nadwozie = cn;
	}

	void zapis()
	{
		int liczba;
                ifstream infile;
                infile.open("dane\\nadwozie\\id_nadwozie.dat");
                while (!infile.eof())
                {
                        infile >> liczba;
                }
                infile.close();
                Nadwozie::id_nadwozie = liczba;

                ofstream outfile("dane\\nadwozie\\baza_nadwozie.dat", ios::app);
                if (!outfile) return;
                outfile << Nadwozie::rodzaj_nadwozie << endl;
                outfile << Nadwozie::drzwi << endl;
                outfile << Nadwozie::cena_nadwozie << endl;
                outfile << Nadwozie::id_nadwozie << endl;

                outfile.close();

                Nadwozie::id_nadwozie++;
                ofstream outfile2("dane\\nadwozie\\id_nadwozie.dat");
                if (!outfile2) return;
                outfile2 << Nadwozie::id_nadwozie << endl;
                outfile2.close();
	}
};

//---------------------------------------------------------------------------
extern PACKAGE Tadd_nadwozie *add_nadwozie;
//---------------------------------------------------------------------------
#endif
