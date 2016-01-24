//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sprzedaz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tzakup *zakup;
//---------------------------------------------------------------------------
__fastcall Tzakup::Tzakup(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tzakup::Button3Click(TObject *Sender)
{
        zakup->Close();        
}
//---------------------------------------------------------------------------

void __fastcall Tzakup::FormCreate(TObject *Sender)
{
        Image->Picture->LoadFromFile("img\\tlo.bmp");
        int ile_egzemplarz, i, licznik_egzemplarz;
        ifstream infile;
        string cos;
        infile.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        vector<string> nowyWektor;
        while (!infile.eof())
        {
              infile >> cos;
              nowyWektor.push_back(cos);
        }
        infile.close();
        licznik_egzemplarz = nowyWektor.size();
        ile_egzemplarz = nowyWektor.size() / 13;
        string id_e;

        string *tab_egz = new string[licznik_egzemplarz];

        ifstream infile1;
        infile1.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        for(i =0; i<licznik_egzemplarz; i++)
        {
           getline(infile1, tab_egz[i]);
        }

         for(i = 0; i<ile_egzemplarz; i++)
        {
                 id_e = tab_egz[11*i];
                 id->Items->Add(id_e.c_str());


        }
     ///// tablica tab_samochod[] jest zapelniona danymi z pliku baza_samochod

        infile1.close();

        delete [] tab_egz;
}
//---------------------------------------------------------------------------

void __fastcall Tzakup::idChange(TObject *Sender)
{
        imie->Text = "";
        nazwisko->Text = "";
        pesel->Text = "";

        cena->Caption = "?";
        oc->Checked = false;
        ac->Checked = false;
        rabat->Text = "0";

         int  licznik, i;
        string comboSamochod;

        comboSamochod = id->Text.c_str();
        licznik = atoi(comboSamochod.c_str());

         int licznik_samochod;
        ifstream in;
        string cos;
        in.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        vector<string> nowyWektor;
        while (!in.eof())
        {
              in >> cos;
              nowyWektor.push_back(cos);
        }
        in.close();
        licznik_samochod = nowyWektor.size();

        string *tab_samoDane = new string[licznik_samochod];

        ifstream inf1;
        inf1.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(inf1, tab_samoDane[i]);
        }
         inf1.close();

        ///////////////////////////////////////////////////////////////////////


        string tab_egz[11];
        int start = 11*licznik-11;

        for(i = 0; i<11; i++) tab_egz[i] = tab_samoDane[start+i];

        model->Caption = tab_egz[3].c_str();
        silnik->Caption = (tab_egz[4] + " l.").c_str();
        nadwozie->Caption = (tab_egz[5] + " drzwi").c_str();
        rok->Caption = tab_egz[6].c_str();

        delete [] tab_samoDane;

        if(tab_egz[7] == "1") klima->Caption = "TAK";
        else klima->Caption = "NIE";

        if(tab_egz[8] == "1") alusy->Caption = "TAK";
        else alusy->Caption = "NIE";

        if(tab_egz[9] == "1") komp->Caption = "TAK";
        else komp->Caption = "NIE";

        if(tab_egz[10] == "1") skora->Caption = "TAK";
        else skora->Caption = "NIE";

        /////////////////////// wczytujemy foto //////////////////////

        int id2;
        string napis, combo, temp;

        combo = id->Text.c_str();

        napis = combo.c_str();

        temp = "img\\foto_eg\\" + napis + ".bmp";

        ifstream file;
        file.open(temp.c_str());
        Image->Picture->Bitmap->LoadFromFile(temp.c_str());

        ////////////////////////////////
        /////////////////////// wczytujemy dane klienta jesli sa  ////////////////

        int  licznik1;
        string comboegz;

        comboegz = id->Text.c_str();
        licznik1 = atoi(comboegz.c_str());

         int licznik_eg;
        ifstream in1;
        string cos1;
        in1.open("dane\\klient\\baza_klient.dat");
        vector<string> nowyWektor1;
        while (!in1.eof())
        {
              in1 >> cos1;
              nowyWektor1.push_back(cos1);
        }
        in1.close();
        licznik_eg = nowyWektor1.size();

        string *tab_eDane = new string[licznik_eg];

        ifstream inf2;
        inf2.open("dane\\klient\\baza_klient.dat");
        for(i =0; i<licznik_eg; i++)
        {
           getline(inf2, tab_eDane[i]);
        }
         inf2.close();

        ///////////////////////////////////////////////////////////////////////
        string im, naz, pes;

         for(i =0; i<licznik_eg; i++)
        {
           if(atoi(tab_eDane[i].c_str()) == licznik1)
           {
                im = tab_eDane[i-3];
                naz = tab_eDane[i-2];
                pes = tab_eDane[i-1];
                imie->Text = im.c_str();
                nazwisko->Text = naz.c_str();
                pesel->Text = pes.c_str();
           }

        

        }

        delete [] tab_eDane;







}
//---------------------------------------------------------------------------

void __fastcall Tzakup::Button1Click(TObject *Sender)
{
        if(id->Text == "") Application->MessageBoxA("Wybierz ID egzemplarza", "B³¹d obliczeñ", MB_OK | MB_ICONSTOP);

        else
        {
             int  licznik, i;
        string comboSamochod;

        comboSamochod = id->Text.c_str();
        licznik = atoi(comboSamochod.c_str());

         int licznik_samochod;
        ifstream in;
        string cos;
        in.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        vector<string> nowyWektor;
        while (!in.eof())
        {
              in >> cos;
              nowyWektor.push_back(cos);
        }
        in.close();
        licznik_samochod = nowyWektor.size();

        string *tab_samoDane = new string[licznik_samochod];

        ifstream inf1;
        inf1.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(inf1, tab_samoDane[i]);
        }
         inf1.close();

        ///////////////////////////////////////////////////////////////////////


        string tab_egz[11];
        int start = 11*licznik-11;

        for(i = 0; i<11; i++) tab_egz[i] = tab_samoDane[start+i];

        double ce_egz, ce_oc, ce_ac, suma_ceny, rabacik, final_cena;

        ce_egz = atof(tab_egz[2].c_str());

        if(oc->Checked == true) ce_oc = 0.05 * ce_egz;
        else ce_oc = 0;

        if(ac->Checked == true) ce_ac = 0.02 * ce_egz;
        else ce_ac = 0;

        suma_ceny = ce_egz + ce_oc + ce_ac;

        rabacik = atof(rabat->Text.c_str()) * suma_ceny * 0.01;
        final_cena = suma_ceny - rabacik;


        string show;
        ostringstream oss;
        oss << final_cena;
        show = oss.str() + " z³";

        cena->Caption = show.c_str();


        }
}
//---------------------------------------------------------------------------


void __fastcall Tzakup::Button2Click(TObject *Sender)
{
         if(id->Text == "" || imie->Text == "" || nazwisko->Text == "" || pesel->Text == "")
        {
                Application->MessageBoxA("WprowadŸ brakuj¹ce dane", "B³¹d zapisu", MB_OK | MB_ICONSTOP);
        }

         if(cena->Caption == "?") Application->MessageBoxA("Najpierw oblicz cenê", "B³¹d zapisu", MB_OK | MB_ICONSTOP);

        else
        {


                string oce, ace;

                if(oc->Checked == true) oce = "Wykupiono pakiet OC";
                else oce = "Brak OC";

                if(ac->Checked == true) ace = "Wykupiono pakiet AC";
                else ace = "Brak AC";

              int licznik;
          ifstream info;
          info.open("dane\\sprzedaz\\id_sprzedaz.dat");
          while (!info.eof())
          {
                info >> licznik;
          }
          info.close();

          Sprzedaz s1;
          s1.id_sprzedaz = licznik;

          ostringstream s;
          s << licznik;
          string str = s.str();

          string sciezka;
          sciezka = "dane\\sprzedaz\\" + str + ".dat";

            ofstream outfile(sciezka.c_str(), ios::app);
                if (!outfile) return;
                outfile << "Faktura VAT nr " << s1.id_sprzedaz << endl;
                outfile << endl;
                outfile << "Dane Klienta:" << endl;
                outfile << "Imiê:  " << imie->Text.c_str() << endl;
                outfile << "Nazwisko:  " << nazwisko->Text.c_str() << endl;
                outfile << "PESEL:  " << pesel->Text.c_str() << endl;
                outfile << endl;
                outfile << "Parametry samochodu:" << endl;
                outfile << "Model:  " << model->Caption.c_str() << endl;
                outfile << "Silnik:  " << silnik->Caption.c_str() << endl;
                outfile << "Nadwozie:  " << nadwozie->Caption.c_str() << endl;
                outfile << "Rok produkcji:  " << rok->Caption.c_str() << endl;
                outfile << endl;
                outfile << "Dodatki:" << endl;
                outfile << "Klimatyzacja:  " << klima->Caption.c_str() << endl;
                outfile << "Aluminiowe felgi:  " << alusy->Caption.c_str() << endl;
                outfile << "Komputer:  " << komp->Caption.c_str() << endl;
                outfile << "Skórzane fotele:  " << skora->Caption.c_str() << endl;
                outfile << endl;
                outfile << "Ubezpieczenie:" << endl;
                outfile << oce << endl;
                outfile << ace << endl;
                outfile << endl;
                outfile << "Rabat:  " << rabat->Text.c_str() << " %" << endl;
                outfile << endl;
                outfile << "Cena koñcowa:  " << cena->Caption.c_str() << endl;

                outfile.close();


                 //faktura->Visible = true;
                s1.id_sprzedaz++;

                ofstream outfile2("dane\\sprzedaz\\id_sprzedaz.dat");
                if (!outfile2) return;
                outfile2 << s1.id_sprzedaz << endl;
                outfile2.close();


         ///////////////////////////////// usuwanie egzemplarza //////////////
     /*
        int  licznik2, i;
        string comboSamochod;

        comboSamochod = id->Text.c_str();
        licznik2 = atoi(comboSamochod.c_str());

         int licznik_samochod;
        ifstream in;
        string cos;
        in.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        vector<string> nowyWektor;
        while (!in.eof())
        {
              in >> cos;
              nowyWektor.push_back(cos);
        }
        in.close();

        licznik_samochod = nowyWektor.size();

        int start = 11*licznik2-11;


        string *tab_samoDane = new string[licznik_samochod];

        ifstream inf1;
        inf1.open("dane\\egzemplarz\\baza_egzemplarz.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(inf1, tab_samoDane[i]);
        }
         inf1.close();

         int n;
         n = licznik_samochod - 11;
        string *tab = new string[n];

        for(i = 0; i<start; i++)
        {
          tab[i] = tab_samoDane[i];
        }

        for(i = start+11; i<licznik_samochod; i++)
        {
                tab[i-11] = tab_samoDane[i];
        }

        ofstream outfile1("dane\\egzemplarz\\baza_egzemplarz.dat");

        for(i = 0; i<n; i++)
        {
           outfile1 << tab[i] << endl;
         }

         outfile1.close();

        delete [] tab_samoDane;
        delete [] tab;
       */
                ////////////////////////////////////////////


                Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);




        }

}
//---------------------------------------------------------------------------

