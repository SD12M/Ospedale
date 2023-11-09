#ifndef INFERMIERE_H
#define INFERMIERE_H
#include "persona.h"
class Infermiere : public Persona
{
private:
    us_int n_interventi;
    string mese;
public:
    Infermiere(const us_int&, const string&,const us_int&,const string&, const string&, const string&,const us_int&);
    us_int get_interventi() const;
    string get_mese() const;
    void set_assistiti(const us_int&);
    void set_mese(const string&);

    bool operator==(const Infermiere&) const;
    virtual string get_info() const final;
    virtual void draw_specific_info(Visitor*) final;
    virtual ~Infermiere() = default;
    virtual Infermiere* clone() const final;
};
#endif // INFERMIERE_H
