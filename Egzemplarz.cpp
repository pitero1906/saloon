//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Egzemplarz.h"
#include "Sprzedaz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tadd_egzemplarz *add_egzemplarz;
//---------------------------------------------------------------------------
__fastcall Tadd_egzemplarz::Tadd_egzemplarz(TComponent* Owner)
        : TForm(Owner)
{

        foto->Picture->LoadFromFile("img\\tlo.bmp");
        int ile_samochod, i, licznik_samochod;
        ifstream infile;
        string cos;
        infile.open("dane\\samochod\\baza_samochod.dat");
        vector<string> nowyWektor;
        while (!infile.eof())
        {
              infile >> cos;
              nowyWektor.push_back(cos);
        }
        infile.close();
        licznik_samochod = nowyWektor.size();
        ile_samochod = nowyWektor.size() / 15;
        string napis_samochod;

        string *tab_samochod = new string[licznik_samochod];

        ifstream infile1;
        infile1.open("dane\\samochod\\baza_samochod.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(infile1, tab_samochod[i]);
        }

         for(i = 0; i<ile_samochod; i++)
        {
                 napis_samochod = tab_samochod[13*i +12] + ".  " + "  " + tab_samochod[13*i +1] + "  " + tab_samochod[13*i+3] + "  " + tab_samochod[13*i +5] + "  " + tab_samochod[13*i + 11];
                 info->Items->Add(napis_samochod.c_str());
                 napis_samochod = "";

        }
     ///// tablica tab_samochod[] jest zapelniona danymi z pliku baza_samochod

        infile1.close();

         int liczba3;
          ifstream info;
          info.open("dane\\egzemplarz\\id_egzemplarz.dat");
          while (!info.eof())
          {
                info >> liczba3;
          }
          info.close();
          ostringstream s;
          s << liczba3;
          string str = s.str();
          AnsiString zmienna = str.c_str();
          id->Caption = zmienna;
       
}
//---------------------------------------------------------------------------







void __fastcall Tadd_egzemplarz::infoChange(TObject *Sender)
{
        int id;
        string napis, comboSamochod, temp;

        comboSamochod = info->Text.c_str();

        id = comboSamochod.find('.');
        napis = comboSamochod.substr(0, id);

        temp = "img\\foto_sam\\" + napis + ".bmp";

        ifstream file;
        file.open(temp.c_str());
        if (!file){
                Application->MessageBoxA("Dodaj do bazy plik *.bmp ze zdj�ciem samochodu aby wczytac", "Brak pliku *.bmp", MB_OK | MB_ICONSTOP);
                foto->Picture->LoadFromFile("img\\tlo.bmp");
        }
        else foto->Picture->Bitmap->LoadFromFile(temp.c_str());

        klima->Checked = false;
        alusy->Checked = false;
        komp->Checked = false;
        skora->Checked = false;
        cena->Caption = "?";

}
//---------------------------------------------------------------------------


void __fastcall Tadd_egzemplarz::Button1Click(TObject *Sender)
{
        if(info->Text == "") Application->MessageBoxA("Wybierz samoch�d", "B��d oblicze�", MB_OK | MB_ICONSTOP);

    else{

      int id, n, i;
        string napis, comboSamochod;

        comboSamochod = info->Text.c_str();

        id = comboSamochod.find('.');
        napis = comboSamochod.substr(0, id);

        int licznik_samochod;
        ifstream infile;
        string cos;
        infile.open("dane\\samochod\\baza_samochod.dat");
        vector<string> nowyWektor;
        while (!infile.eof())
        {
              infile >> cos;
              nowyWektor.push_back(cos);
        }
        infile.close();
        licznik_samochod = nowyWektor.size();

        string napis_samochod;

        string *tab_samochod = new string[licznik_samochod];

        ifstream infile1;
        infile1.open("dane\\samochod\\baza_samochod.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(infile1, tab_samochod[i]);
        }

        n = atoi(napis.c_str());

        double c_klima, c_alusy, c_komp, c_skora, c_podstawa, suma;
        string show;

        if(klima->Checked == true) c_klima = atof(tab_samochod[13*n - 6].c_str());
        else c_klima = 0;

        if(alusy->Checked == true) c_alusy = atof(tab_samochod[13*n - 5].c_str());
        else c_alusy = 0;

        if(komp->Checked == true) c_komp = atof(tab_samochod[13*n - 4].c_str());
        else c_komp = 0;

        if(skora->Checked == true) c_skora = atof(tab_samochod[13*n - 3].c_str());
        else c_skora = 0;

        c_podstawa = atof(tab_samochod[13*n - 7].c_str());

        suma = c_podstawa + c_skora + c_komp + c_alusy + c_klima;

        ostringstream oss;
        oss << suma;
        show = oss.str() + " z�";

        cena->Caption = show.c_str();
        }

}
//---------------------------------------------------------------------------




void __fastcall Tadd_egzemplarz::Button3Click(TObject *Sender)
{
        add_egzemplarz->Close();
}
//---------------------------------------------------------------------------

void __fastcall Tadd_egzemplarz::Button2Click(TObject *Sender)
{

          if(info->Text == "")
        {
                Application->MessageBoxA("Wprowad� brakuj�ce dane", "B��d zapisu", MB_OK | MB_ICONSTOP);
        }

        else {

        ///////// zapis foto /////////////
        int liczba3;
          ifstream inf;
          inf.open("dane\\egzemplarz\\id_egzemplarz.dat");
          while (!inf.eof())
          {
                inf >> liczba3;
          }
          inf.close();
          ostringstream ss;
          ss << liczba3;
          string str = ss.str();

          string napis;
          napis = "img\\foto_eg\\"+ str + ".bmp";

          foto->Picture->Bitmap->SaveToFile(napis.c_str());
       ////////////////////////// end ///////////////////

       ////////////// zapis danych do pliku /////////////////

       int id, licznik, i;
        string id_napis, comboSamochod;

        comboSamochod = info->Text.c_str();

        id = comboSamochod.find('.');
        id_napis = comboSamochod.substr(0, id);
        licznik = atoi(id_napis.c_str());


        //////////////////////// zapelnienie tablicy danymi z plkiu samochod ///////////

        int licznik_samochod;
        ifstream in;
        string cos;
        in.open("dane\\samochod\\baza_samochod.dat");
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
        inf1.open("dane\\samochod\\baza_samochod.dat");
        for(i =0; i<licznik_samochod; i++)
        {
           getline(inf1, tab_samoDane[i]);
        }
         inf1.close();

        ///////////////////////////////////////////////////////////////////////


        string tab_samochod[13];
        int start = 13*licznik-13;

        //  ofstream out("test.dat", ios::app);
          //      if (!out) return;
            //    out << licznik << endl;
              //  out << start << endl;
               // out << koniec << endl;
        //out.close();

          tab_samochod[0] = tab_samoDane[start];
          tab_samochod[1] = tab_samoDane[start+1];
          tab_samochod[2] = tab_samoDane[start+2];
          tab_samochod[3] = tab_samoDane[start+3];
          tab_samochod[4] = tab_samoDane[start+4];
          tab_samochod[5] = tab_samoDane[start+5];
          tab_samochod[6] = tab_samoDane[start+6];
          tab_samochod[7] = tab_samoDane[start+7];
          tab_samochod[8] = tab_samoDane[start+8];
          tab_samochod[9] = tab_samoDane[start+9];
          tab_samochod[10] = tab_samoDane[start+10];
          tab_samochod[11] = tab_samoDane[start+11];
          tab_samochod[12] = tab_samoDane[start+12];

          delete [] tab_samoDane;



        string id_model, id_silnik, id_nadwozie, klima1, alusy1, komp1, skora1, year;
        id_model = tab_samochod[0];
        id_silnik = tab_samochod[2];
        id_nadwozie = tab_samochod[4];
        year = tab_samochod[11];
        klima1 = tab_samochod[7];
        alusy1 = tab_samochod[8];
        komp1 = tab_samochod[9];
        skora1 = tab_samochod[10];

        int mod, sil, nad;
        mod = atoi(id_model.c_str());
        sil = atoi(id_silnik.c_str());
        nad = atoi(id_nadwozie.c_str());
        //////////////////////////////////////////////////


         int licznik_model;
        ifstream inmodel;
        string cos1;
        inmodel.open("dane\\model\\baza_model.dat");
        vector<string> modelWektor;
        while (!inmodel.eof())
        {
              inmodel >> cos1;
              modelWektor.push_back(cos1);
        }
        inmodel.close();
        licznik_model = modelWektor.size();

        string *tab_modelDane = new string[licznik_model];

        ifstream inmodel1;
        inmodel1.open("dane\\model\\baza_model.dat");
        for(i =0; i<licznik_model; i++)
        {
           getline(inmodel1, tab_modelDane[i]);
        }
         inmodel1.close();
        ////////////

        string tab_model[3];
        int start_model = 3*mod - 3;

        tab_model[0] = tab_modelDane[start_model];
        tab_model[1] = tab_modelDane[start_model+1];
        tab_model[2] = tab_modelDane[start_model+2];

        string naz_model;

        naz_model = tab_model[0];

        delete [] tab_modelDane;

        //////////////////////////////////////////////////////////////

        int licznik_silnik;
        ifstream insilnik;
        string cos2;
        insilnik.open("dane\\silnik\\baza_silnik.dat");
        vector<string> silnikWektor;
        while (!insilnik.eof())
        {
              insilnik >> cos2;
              silnikWektor.push_back(cos2);
        }
        insilnik.close();
        licznik_silnik = silnikWektor.size();

        string *tab_silnikDane = new string[licznik_silnik];

        ifstream insilnik1;
        insilnik1.open("dane\\silnik\\baza_silnik.dat");
        for(i =0; i<licznik_silnik; i++)
        {
           getline(insilnik1, tab_silnikDane[i]);
        }
         insilnik1.close();
        ////////////

        string tab_silnik[4];
        int start_silnik = 4*sil - 4;

        tab_silnik[0] = tab_silnikDane[start_silnik];
        tab_silnik[1] = tab_silnikDane[start_silnik+1];
        tab_silnik[2] = tab_silnikDane[start_silnik+2];
        tab_silnik[3] = tab_silnikDane[start_silnik+3];

        delete [] tab_silnikDane;

        string ro_silnik, poj_silnik;

        ro_silnik = tab_silnik[0];
        poj_silnik = tab_silnik[1];

        /////////////////////////////////////////////

          int licznik_nad;
        ifstream nadw;
        string cos3;
        nadw.open("dane\\nadwozie\\baza_nadwozie.dat");
        vector<string> nadwozieWektor;
        while (!nadw.eof())
        {
              nadw >> cos3;
              nadwozieWektor.push_back(cos3);
        }
        nadw.close();
        licznik_nad = nadwozieWektor.size();

        string *tab_nadwozieDane = new string[licznik_nad];

        ifstream nad1;
        nad1.open("dane\\nadwozie\\baza_nadwozie.dat");
        for(i =0; i<licznik_nad; i++)
        {
           getline(nad1, tab_nadwozieDane[i]);
        }
         nad1.close();
        ////////////

        string tab_nadwozie[4];
        int start_na = 4*nad - 4;

        tab_nadwozie[0] = tab_nadwozieDane[start_na];
        tab_nadwozie[1] = tab_nadwozieDane[start_na+1];
        tab_nadwozie[2] = tab_nadwozieDane[start_na+2];
        tab_nadwozie[3] = tab_nadwozieDane[start_na+3];

        delete [] tab_nadwozieDane;


        string ro_nadwozie, door;

        ro_nadwozie = tab_nadwozie[0];
        door = tab_nadwozie[1];

        ////////////////// zamiana na odpowiednie formaty zmiennych ///////////////
        double cena_k, cena_a, cena_kom, cena_s, poje, cenka_model, cenka_silnik, cenka_nadwozie;
        int il_drzwi, roczek, ilosc_egzemp;
        //string temp;

        poje = atof(poj_silnik.c_str());
        il_drzwi = atoi(door.c_str());
        roczek = atoi(year.c_str());
        cenka_model = atof(tab_model[1].c_str());
        cenka_silnik = atof(tab_silnik[2].c_str());
        cenka_nadwozie = atof(tab_nadwozie[2].c_str());
        //temp = poletxt->Text.c_str();
        ilosc_egzemp = 1;

        ////////// tworzenie obiektow //////////////////

        Model modelek(naz_model, cenka_model);
        Silnik silniczek(ro_silnik, poje, cenka_silnik);
        Nadwozie nadwo(ro_nadwozie, il_drzwi, cenka_nadwozie);
        Wyposazenie wyp(klima->Checked, alusy->Checked, komp->Checked, skora->Checked);

        if(wyp.klima == true) cena_k = atof(klima1.c_str());
        else cena_k = 0;

        if(wyp.alusy == true) cena_a = atof(alusy1.c_str());
        else cena_a = 0;

        if(wyp.komp == true) cena_kom = atof(komp1.c_str());
        else cena_kom = 0;

        if(wyp.skora == true) cena_s = atof(skora1.c_str());
        else cena_s = 0;

        Samochod samo(modelek.nazwa_model, modelek.cena_model, nadwo.rodzaj_nadwozie, nadwo.drzwi, nadwo.cena_nadwozie, silniczek.rodzaj_silnik, silniczek.pojemnosc, silniczek.cena_silnik, roczek, cena_k, cena_a, cena_kom, cena_s);

        Egzemplarz E1(modelek.nazwa_model, modelek.cena_model, nadwo.rodzaj_nadwozie, nadwo.drzwi, nadwo.cena_nadwozie, silniczek.rodzaj_silnik, silniczek.pojemnosc, silniczek.cena_silnik, samo.rok_produkcji, samo.cena_klima, samo.cena_alusy, samo.cena_komp, samo.cena_skora, ilosc_egzemp, wyp.klima, wyp.alusy, wyp.komp, wyp.skora);
        E1.cena_koncowa = samo.licz_cene() + samo.cena_klima + samo.cena_alusy + samo.cena_komp + samo.cena_skora;

        E1.zapis();

        Application->MessageBoxA("Egzemplarz zosta� dodany do bazy", "Gratulacje!", MB_OK);
        //add_egzemplarz->Next();
         Application->Terminate();
        WinExec("salon.exe",SW_NORMAL);
      }

      //poletxt->Text = "";
      info->Text = "";
      foto->Picture->LoadFromFile("img\\tlo.bmp");
      cena->Caption = "?";

      int li;
          ifstream info;
          info.open("dane\\egzemplarz\\id_egzemplarz.dat");
          while (!info.eof())
          {
                info >> li;
          }
          info.close();
          ostringstream s;
          s << li;
          string str = s.str();
          AnsiString zmienna = str.c_str();
          id->Caption = zmienna;

          klima->Checked = false;
        alusy->Checked = false;
        komp->Checked = false;
        skora->Checked = false;


}
//---------------------------------------------------------------------------


