//---------------------------------------------------------------------------

#ifndef drukH
#define drukH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Printers.hpp>
#include <Dialogs.hpp>
#include <fstream.h>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
class Tfaktura : public TForm
{
__published:	// IDE-managed Components
        TMemo *Mem;
        TPrintDialog *Print;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:
         void __fastcall PrintMemo(TMemo *Memo, TPrintDialog *PrintDialog);
        void __fastcall PrintPage(int page);
        TStringList *pages;
        int currentpage;
public:		// User declarations
        __fastcall Tfaktura(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfaktura *faktura;
//---------------------------------------------------------------------------
#endif
