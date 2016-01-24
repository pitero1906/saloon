//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Samochod.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tadd_samochod *add_samochod;
//---------------------------------------------------------------------------
__fastcall Tadd_samochod::Tadd_samochod(TComponent* Owner)
        : TForm(Owner)
{


        
        ////// dodawanie modeli do widoku/////////////
        int ile_model, i, licznik_model;
        ifstream infile;
        string cos;
        infile.open("dane\\model\\baza_model.dat");
        vector<string> nowyWektor;
        while (!infile.eof())
        {
              infile >> cos;
              nowyWektor.push_back(cos);
        }
        infile.close();
        licznik_model = nowyWektor.size();
        ile_model = (nowyWektor.size()-1) / 3;
        string napis;

        string *tab_model = new string[licznik_model];

        ifstream infile1;
        infile1.open("dane\\model\\baza_model.dat");
        for(i =0; i<licznik_model; i++)
        {
           getline(infile1, tab_model[i]);
        }

        for(i = 0; i<ile_model; i++)
        {
                 napis = tab_model[3*i +2] + ".  " + "|  " + tab_model[3*i] + "  ||  " + tab_model[3*i+1] + " z³";
                 model->Items->Add(napis.c_str());
                 napis = "";

        }

        infile1.close();


         delete [] tab_model;
        //////////////////////// koniec ///////////////////////////////////////

         ////// dodawanie silnika do widoku/////////////
        int ile_silnik, licznik_silnik;
        ifstream infile2;
        string cos1;
        infile2.open("dane\\silnik\\baza_silnik.dat");
        vector<string> nowyWektor1;
        while (!infile2.eof())
        {
              infile2 >> cos1;
              nowyWektor1.push_back(cos1);
        }
        infile2.close();
        licznik_silnik = nowyWektor1.size();
        ile_silnik = (nowyWektor1.size()-1) / 4;
        string napis1;

        string *tab_silnik = new string[licznik_silnik];

        ifstream infile3;
        infile3.open("dane\\silnik\\baza_silnik.dat");
        for(i =0; i<licznik_silnik; i++)
        {
           getline(infile3, tab_silnik[i]);
        }

        for(i = 0; i<ile_silnik; i++)
        {
                 napis1 = tab_silnik[4*i +3] + ".  " + "|  " + tab_silnik[4*i] + "  " + tab_silnik[4*i+1] + " l." + "  || " +tab_silnik[4*i +2] + " z³";
                 silnik->Items->Add(napis1.c_str());
                 napis1 = "";

        }

        infile3.close();


         delete [] tab_silnik;
        //////////////////////// koniec ///////////////////////////////////////


         ////// dodawanie nadwozie do widoku/////////////
        int ile_nadwozie, licznik_nadwozie;
        ifstream infile4;
        string cos2;
        infile4.open("dane\\nadwozie\\baza_nadwozie.dat");
        vector<string> nowyWektor2;
        while (!infile4.eof())
        {
              infile4 >> cos2;
              nowyWektor2.push_back(cos2);
        }
        infile4.close();
        licznik_nadwozie = nowyWektor2.size();
        ile_nadwozie = (nowyWektor2.size()-1) / 4;
        string napis2;

        string *tab_nadwozie = new string[licznik_nadwozie];

        ifstream infile5;
        infile5.open("dane\\nadwozie\\baza_nadwozie.dat");
        for(i =0; i<licznik_nadwozie; i++)
        {
           getline(infile5, tab_nadwozie[i]);
        }

        for(i = 0; i<ile_nadwozie; i++)
        {
                 napis2 = tab_nadwozie[4*i +3] + ".  " + "|  " + tab_nadwozie[4*i] + "  " + tab_nadwozie[4*i+1] + " drzwi" + "  || " + tab_nadwozie[4*i +2] + " z³";
                 nadwozie->Items->Add(napis2.c_str());
                 napis2 = "";

        }

        infile5.close();


         delete [] tab_nadwozie;
        //////////////////////// koniec ///////////////////////////////////////
}
//---------------------------------------------------------------------------






void __fastcall Tadd_samochod::Button2Click(TObject *Sender)
{
         if(model->Text == "" || silnik->Text == "" || nadwozie->Text == "" || rok_produkcji->Text == "" || klima->Text == "" || alusy->Text == "" || komp->Text == "" || skora->Text == "")
        {
                Application->MessageBoxA("WprowadŸ brakuj¹ce dane", "B³¹d zapisu", MB_OK | MB_ICONSTOP);
        }

        else
        {
          string comboModel, comboSilnik, comboNadwozie, id_modi, id_sili, id_nadi;
          int poz_model, poz_silnik, poz_nadwozie, id_mod, id_sil, id_nad;
          comboModel = model->Text.c_str();
          comboSilnik = silnik->Text.c_str();
          comboNadwozie = nadwozie->Text.c_str();

          poz_model = comboModel.find('.');
          poz_silnik = comboSilnik.find('.');
          poz_nadwozie = comboNadwozie.find('.');

          id_modi = comboModel.substr(0, poz_model);
          id_sili = comboSilnik.substr(0, poz_silnik);
          id_nadi = comboNadwozie.substr(0, poz_nadwozie);

          id_mod = atoi(id_modi.c_str());
          id_sil = atoi(id_sili.c_str());
          id_nad = atoi(id_nadi.c_str());

          int start_model, start_silnik, start_nadwozie;
          string temp_model, temp_silnik, temp_nadwozie;
          start_model = comboModel.find('|');
          start_silnik = comboSilnik.find('|');
          start_nadwozie = comboNadwozie.find('|');
          temp_model = comboModel.substr(start_model+3,comboModel.find("||")-start_model-3);
          temp_silnik = comboSilnik.substr(start_silnik+3,comboSilnik.find("||") - start_silnik-3);
          temp_nadwozie = comboNadwozie.substr(start_nadwozie+3,comboNadwozie.find("||") - start_nadwozie-3);


          ofstream test("dane\\samochod\\baza_samochod.dat", ios::app);
                if (!test) return;
                test << id_mod << endl;
                test << temp_model << endl;
                test << id_sil << endl;
                test << temp_silnik << endl;
                test << id_nad << endl;
                test << temp_nadwozie <<endl;
                test.close();

          int liczba3;
          ifstream inf;
          inf.open("dane\\samochod\\id_samochod.dat");
          while (!inf.eof())
          {
                inf >> liczba3;
          }
          inf.close();
          ostringstream ss;
          ss << liczba3;
          string str = ss.str();
          AnsiString zmienna = str.c_str();

         // foto->Picture->SaveToFile("img\\" + zmienna + ".jpg");

          int year;
          double kl, al, kom, sk;

          year = rok_produkcji->Text.ToInt();
          kl = klima->Text.ToDouble();
          al = alusy->Text.ToDouble();
          kom = komp->Text.ToDouble();
          sk = skora->Text.ToDouble();

          int model_indeks;
          model_indeks = 3*id_mod -3;
          string n_mod;
          double c_mod;

          int i, licznik_model;
        ifstream infile;
        string cos;
        infile.open("dane\\model\\baza_model.dat");
        vector<string> nowyWektor;
        while (!infile.eof())
        {
              infile >> cos;
              nowyWektor.push_back(cos);
        }
        infile.close();
        licznik_model = nowyWektor.size();
        string napis;

        string *tab_model = new string[licznik_model];

        ifstream infile1;
        infile1.open("dane\\model\\baza_model.dat");
        for(i =0; i<licznik_model; i++)
        {
           getline(infile1, tab_model[i]);
        }

          n_mod = tab_model[model_indeks];
          c_mod = (double)atoi(tab_model[model_indeks +1].c_str());

          delete [] tab_model;
        ///////////////////////////////////////////////////////////////////////

        string r_sil;
        double poj, c_sil;
        int silnik_indeks;
        silnik_indeks = 4*id_sil -4;
         int licznik_silnik;
        ifstream infile2;
        string cos1;
        infile2.open("dane\\silnik\\baza_silnik.dat");
        vector<string> nowyWektor1;
        while (!infile2.eof())
        {
              infile2 >> cos1;
              nowyWektor1.push_back(cos1);
        }
        infile2.close();
        licznik_silnik = nowyWektor1.size();
        string napis1;

        string *tab_silnik = new string[licznik_silnik];

        ifstream infile3;
        infile3.open("dane\\silnik\\baza_silnik.dat");
        for(i =0; i<licznik_silnik; i++)
        {
           getline(infile3, tab_silnik[i]);
        }

        r_sil = tab_silnik[silnik_indeks];
        poj = (double)atoi(tab_silnik[silnik_indeks +1].c_str());
        c_sil = (double)atoi(tab_silnik[silnik_indeks +2].c_str());

        delete [] tab_silnik;

        //////////////////////////////////////////////////////////////////

         int nadwozie_indeks, drz_nad;
         nadwozie_indeks = 4*id_nad -4;
         string r_nad;
         double c_nad;
          int licznik_nadwozie;
        ifstream infile4;
        string cos2;
        infile4.open("dane\\nadwozie\\baza_nadwozie.dat");
        vector<string> nowyWektor2;
        while (!infile4.eof())
        {
              infile4 >> cos2;
              nowyWektor2.push_back(cos2);
        }
        infile4.close();
        licznik_nadwozie = nowyWektor2.size();
        string napis2;

        string *tab_nadwozie = new string[licznik_nadwozie];

        ifstream infile5;
        infile5.open("dane\\nadwozie\\baza_nadwozie.dat");
        for(i =0; i<licznik_nadwozie; i++)
        {
           getline(infile5, tab_nadwozie[i]);
        }

        r_nad = tab_nadwozie[nadwozie_indeks];
        c_nad = (double)atoi(tab_nadwozie[nadwozie_indeks +2].c_str());
        drz_nad = atoi(tab_nadwozie[nadwozie_indeks +1].c_str());


        delete [] tab_nadwozie;


        //////////////////////////////////////////////////

        ////////////////////tworzenie obiektow//////////////////////

        Model nModel(n_mod, c_mod);
        Silnik nSilnik(r_sil, poj, c_sil);
        Nadwozie nNadwozie(r_nad, drz_nad, c_nad);


        Samochod nowy(nModel.nazwa_model, nModel.cena_model, nNadwozie.rodzaj_nadwozie, nNadwozie.drzwi, nNadwozie.cena_nadwozie, nSilnik.rodzaj_silnik, nSilnik.pojemnosc, nSilnik.cena_silnik, year, kl, al, kom, sk);

        nModel.id_model = id_mod;
        nSilnik.id_silnik = id_sil;
        nNadwozie.id_nadwozie = id_nad;

        nowy.zapis();
        Application->MessageBoxA("Samochód zosta³ dodany do bazy", "Gratulacje!", MB_OK);
        //add_samochod->Next();

         Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);

        }
       model->Text = "";
       silnik->Text = "";
       nadwozie->Text = "";
       rok_produkcji->Text = "";
       klima->Text = "";
       alusy->Text = "";
       komp->Text = "";
       skora->Text = "";

}
//---------------------------------------------------------------------------


void __fastcall Tadd_samochod::Button3Click(TObject *Sender)
{
        add_samochod->Close();
}
//---------------------------------------------------------------------------







