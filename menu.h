//---------------------------------------------------------------------------

#ifndef menuH
#define menuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tmainmenu : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Sprzedaj1;
        TMenuItem *Dodajdobazy1;
        TMenuItem *Analizujdochody1;
        TMenuItem *Elementysamochodu1;
        TMenuItem *Nowysamochd1;
        TMenuItem *Nowyegzemplarz1;
        TMenuItem *Silnik1;
        TMenuItem *Nadwozie1;
        TMenuItem *Model1;
        TMenuItem *Kupgotowyegzemplarz1;
        TMenuItem *Personalizujzamwienie1;
        TImage *Image1;
        TLabel *Label2;
        TLabel *Label3;
        TMenuItem *Drukujfakture1;
        void __fastcall Silnik1Click(TObject *Sender);
        void __fastcall Nadwozie1Click(TObject *Sender);
        void __fastcall Model1Click(TObject *Sender);
        void __fastcall Nowysamochd1Click(TObject *Sender);
        void __fastcall Nowyegzemplarz1Click(TObject *Sender);
        void __fastcall Personalizujzamwienie1Click(TObject *Sender);
        void __fastcall Kupgotowyegzemplarz1Click(TObject *Sender);
        void __fastcall Odswiedane1Click(TObject *Sender);
        void __fastcall Analizujdochody1Click(TObject *Sender);
        void __fastcall Drukujfakture1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tmainmenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tmainmenu *mainmenu;
//---------------------------------------------------------------------------
#endif
