#include "Classes/headers/medico.h"
Medico::Medico(const us_int & morti, const us_int & savlati, const us_int& s,const string& m,const string& n, const string& c, const us_int& e, const string& mese)
    : Persona(n,c,e,s,m), n_pazienti_morti(morti), n_pazienti_salvati(savlati), mese(mese) {}

Medico* Medico::clone() const
{
    return new Medico(*this);
}
us_int Medico::get_morti() const
{
    return n_pazienti_morti;
}
us_int Medico::get_salvati() const
{
    return n_pazienti_salvati;
}
string Medico::get_info() const
{
    return Persona::get_info() + "|" + std::to_string(n_pazienti_morti) + "|" + std::to_string(n_pazienti_salvati) + "|" + mese;
}
void Medico::set_morti(const us_int &val)
{
    n_pazienti_morti = val;
}
void Medico::set_salvati(const us_int &val)
{
    n_pazienti_salvati = val;
}
void Medico::draw_specific_info(Visitor* v)
{
    v->drawMedico(this);
}
bool Medico::operator==(const Medico& i ) const
{
    if(Persona::operator ==(i))
    {
        return true;
    }
    return false;
}
string Medico::get_mese() const
{
    return mese;
}
void Medico::set_mese(const string& val)
{
    mese = val;
}
