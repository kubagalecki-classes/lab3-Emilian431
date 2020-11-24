#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int IloscTowaru = 0;
    unsigned int IloscZaglowcow = 0;
    // Twoja implementacja tutaj
    
    
    if (towar ==0)
    {
      return IloscZaglowcow;
    }
    Stocznia stocznia{};
    while(IloscTowaru < towar )
    {
    Statek* s1 = stocznia();  
    IloscTowaru += (s1->transportuj());
    if(dynamic_cast<Zaglowiec*>(s1))
      {
          ++IloscZaglowcow;
      }
    delete s1;
    }
    return IloscZaglowcow;
}