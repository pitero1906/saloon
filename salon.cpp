//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("menu.cpp", mainmenu);
USEFORM("Silnik.cpp", add_silnik);
USEFORM("Nadwozie.cpp", add_nadwozie);
USEFORM("Model.cpp", add_model);
USEFORM("Samochod.cpp", add_samochod);
USEFORM("Egzemplarz.cpp", add_egzemplarz);
USEFORM("Klient.cpp", new_egzemplarz);
USEFORM("Sprzedaz.cpp", zakup);
USEFORM("druk.cpp", faktura);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tmainmenu), &mainmenu);
                 Application->CreateForm(__classid(Tadd_silnik), &add_silnik);
                 Application->CreateForm(__classid(Tadd_nadwozie), &add_nadwozie);
                 Application->CreateForm(__classid(Tadd_model), &add_model);
                 Application->CreateForm(__classid(Tadd_samochod), &add_samochod);
                 Application->CreateForm(__classid(Tadd_egzemplarz), &add_egzemplarz);
                 Application->CreateForm(__classid(Tnew_egzemplarz), &new_egzemplarz);
                 Application->CreateForm(__classid(Tzakup), &zakup);
                 Application->CreateForm(__classid(Tfaktura), &faktura);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
