//---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <fstream.h>
#include <iostream>
#include <sstream>

//---------------------------------------------------------------------------
class Tadd_model : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *nazwa;
        TEdit *cena;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tadd_model(TComponent* Owner);
};

class Model
{
public:
	string nazwa_model;
        double cena_model;
        int id_model;

	Model(string n, double cm)
	{
		nazwa_model = n;
		cena_model = cm;
	}

	void zapis()
	{
                int liczba;
                ifstream infile;
                infile.open("dane\\model\\id_model.dat");
                while (!infile.eof())
                {
                        infile >> liczba;
                }
                infile.close();
                Model::id_model = liczba;

                ofstream outfile("dane\\model\\baza_model.dat", ios::app);
                if (!outfile) return;
                outfile << Model::nazwa_model << endl;
                outfile << Model::cena_model << endl;
                outfile << Model::id_model << endl;

                outfile.close();

                Model::id_model++;
                ofstream outfile2("dane\\model\\id_model.dat");
                if (!outfile2) return;
                outfile2 << Model::id_model << endl;
                outfile2.close();
	}
};

//---------------------------------------------------------------------------
extern PACKAGE Tadd_model *add_model;
//---------------------------------------------------------------------------
#endif
