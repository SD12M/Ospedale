#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Classes/headers/persona.h"

class Dipendente : public Persona
{
private:
    us_int stipendio;
    string mese;
public:
    Dipendente(const us_int&,const string&,const string&, const string&, const us_int&, const string&);
    void set_stipendio(const us_int&);
    void set_mese(const string&);

    string get_mese() const;
    us_int get_stipendio() const;
};


#endif // DIPENDENTE_H
