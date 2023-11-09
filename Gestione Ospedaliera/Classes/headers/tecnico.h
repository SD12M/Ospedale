#ifndef TECNICO_H
#define TECNICO_H
#include "persona.h"
class Tecnico: public Persona
{
private:
    us_int n_interventi;
    string mese;
public:
    Tecnico(const us_int&, const string&,const us_int&,const string&,const string&, const string&, const us_int&);
    string get_mese() const;
    us_int get_interventi() const;
    void set_mese(const string&);
    void set_interventi(const us_int&);

    bool operator==(const Tecnico&) const;
    virtual string get_info() const final;
    virtual void draw_specific_info(Visitor*) final;
    virtual ~Tecnico() = default;
    virtual Tecnico* clone() const final;
};
#endif // TECNICO_H
