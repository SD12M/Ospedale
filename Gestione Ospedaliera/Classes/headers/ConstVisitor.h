#ifndef CONSTVISITOR_H
#define CONSTVISITOR_H
class Medico;
class Infermiere;
class Tecnico;
class Visitor
{
public:
    virtual void drawMedico(Medico* const) = 0;
    virtual void drawInfermiere(Infermiere* const) = 0;
    virtual void drawTecnico(Tecnico* const) = 0;
};
#endif // CONSTVISITOR_H
