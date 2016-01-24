
#ifndef UbezpieczenieH
#define UbezpieczenieH
//---------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <fstream.h>

//---------------------------------------------------------------------------

class Ubezpieczenie
{
public:
        bool AC;
        bool OC;

        Ubezpieczenie(bool ac, bool oc)
        {
                AC = ac;
                OC = oc;
        }


};

//------------------------------------------------------------------------
#endif
