#ifndef MEDICO_H
#define MEDICO_H
#include "persona.h"
class Medico : public Persona
{
private:
    us_int n_pazienti_morti;
    us_int n_pazienti_salvati;
    string mese;
public:
    Medico(const us_int&, const us_int&,const us_int&,const string&,const string&, const string&, const us_int&, const string&);
    us_int get_morti() const;
    us_int get_salvati() const;
    string get_mese() const;

    void set_morti(const us_int&);
    void set_salvati(const us_int&);
    void set_mese(const string&);

    bool operator==(const Medico&) const;
    virtual string get_info() const final;
    virtual void draw_specific_info(Visitor*) final;
    virtual ~Medico() = default;
    virtual Medico* clone() const final;
};

#endif // MEDICO_H
