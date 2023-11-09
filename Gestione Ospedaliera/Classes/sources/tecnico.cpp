#include "Classes/headers/tecnico.h"
Tecnico::Tecnico(const us_int& i, const string& mes,const us_int&s, const string &m,const string&n, const string&c,const us_int&e)
    : Persona(n,c,e,s,m), n_interventi(i), mese(mes) {}

Tecnico* Tecnico::clone() const
{
    return new Tecnico(*this);
}
string Tecnico::get_mese() const
{
    return mese;
}
us_int Tecnico::get_interventi() const
{
    return n_interventi;
}
string Tecnico::get_info() const
{
    return get_mansione() + "|" + get_nome() + "|" + get_cognome()
        + "|" + std::to_string(get_età()) +  "|" + std::to_string(get_stipendio())
        + "|" + std::to_string(n_interventi) + "|" + mese;
}
void Tecnico::draw_specific_info(Visitor* v)
{
    v->drawTecnico(this);
}
void Tecnico::set_interventi(const us_int & valore)
{
    n_interventi = valore;
}
void Tecnico::set_mese(const string &valore)
{
    mese = valore;
}

bool Tecnico::operator==(const Tecnico& i ) const
{
    if(Persona::operator==(i))
    {
        return true;
    }
    return false;
}

