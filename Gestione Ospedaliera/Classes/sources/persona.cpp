#include "Classes/headers/persona.h"
Persona::Persona(const string &n, const string &c, const us_int &e, const us_int& stip,const string& m)
    : nome(n), cognome(c), età(e), stipendio(stip), mansione(m) {}

string Persona::get_cognome() const
{
    return cognome;
}
string Persona::get_nome() const
{
    return nome;
}
us_int Persona::get_età() const
{
    return età;
}
string Persona::get_mansione() const
{
    return mansione;
}
us_int Persona::get_stipendio() const
{
    return stipendio;
}
void Persona::set_stipendio(const us_int& val)
{
    stipendio = val;
}
bool Persona::operator==(const Persona& p) const
{
    if(nome == p.nome && cognome == p.cognome && età == p.età && mansione == p.mansione)
    {
        return true;
    }
    return false;
}
string Persona::get_info() const
{
    return mansione + "|" + nome + "|" + cognome
           + "|" + std::to_string(età) +  "|" + std::to_string(stipendio);
}
