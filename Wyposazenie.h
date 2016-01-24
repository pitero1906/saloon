//---------------------------------------------------------------------------

#ifndef WyposazenieH
#define WyposazenieH
//---------------------------------------------------------------------------

#include <fstream.h>
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------

class Wyposazenie
{
public:
        bool klima;
        bool alusy;
        bool komp;
        bool skora;

        Wyposazenie(bool kli, bool alu, bool kom, bool sko)
        {
                klima = kli;
                alusy = alu;
                komp = kom;
                skora = sko;
        }

};





//------------------------------------------------------------------------
#endif
