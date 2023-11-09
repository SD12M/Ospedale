#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include "ConstVisitor.h"
#include "visitor_insert.h"

using std::string;

typedef unsigned short int us_int;
class Persona
{
private:
    string nome;
    string cognome;
    us_int età;
    us_int stipendio;
    string mansione;
public:
    Persona(const string&, const string&, const us_int&, const us_int&, const string&);
    string get_nome() const;
    string get_cognome() const;
    us_int get_età() const;
    us_int get_stipendio() const;
    string get_mansione() const;
    void set_stipendio(const us_int&);

    bool operator==(const Persona&) const;
    virtual void draw_specific_info(Visitor*) = 0;
    virtual string get_info() const;
    virtual ~Persona() = default;
    virtual Persona* clone() const = 0;
};
#endif // PERSONA_H
