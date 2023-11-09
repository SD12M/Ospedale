#include "Classes/headers/infermiere.h"
Infermiere::Infermiere(const us_int& numero, const string& mes, const us_int& s,const string& m,const string& n, const string& c, const us_int& e)
    : Persona(n,c,e,s,m), n_interventi(numero), mese(mes) {}
Infermiere* Infermiere::clone() const
{
    return new Infermiere(*this);
}
us_int Infermiere::get_interventi() const
{
    return n_interventi;
}
string Infermiere::get_mese() const
{
    return mese;
}
string Infermiere::get_info() const
{
    return get_mansione() + "|" + get_nome() + "|" + get_cognome()
           + "|" + std::to_string(get_età()) +  "|" + std::to_string(get_stipendio())
           + "|" + std::to_string(n_interventi) + "|" + mese;
}
void Infermiere::set_assistiti(const us_int &valore)
{
    n_interventi = valore;
}
void Infermiere::set_mese(const string &valore)
{
    mese = valore;
}
void Infermiere::draw_specific_info(Visitor* v)
{
    v->drawInfermiere(this);
}

bool Infermiere::operator==(const Infermiere& i ) const
{
    if(Persona::operator==(i))
    {
        return true;
    }
    return false;
}

