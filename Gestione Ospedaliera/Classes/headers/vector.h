#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include "Classes/headers/infermiere.h"
#include "Classes/headers/tecnico.h"
#include "Classes/headers/medico.h"
using std::string;


typedef unsigned int u_int;
template <class T>
class Vector
{
private:
    T* buffer;
    u_int current_size;
    u_int current_capacity;

    void resize(u_int);
public:
    // costruttore a 0, 1, 2 parametri.
    Vector(u_int size = 0, u_int capacity = 10);
    // costruttore di copia
    Vector(const Vector<T>&);
    // distruttore
    ~Vector();

    // operatore di subscripting
    T& operator[](u_int i) const;

    class iterator
    {
    private:
        T* current;
    public:
        iterator(T* v);
        // costruttore di copia.
        iterator(const iterator&);

        // costruttore di default
        iterator();

        // operatori di somma prefisso e postfisso.
        iterator& operator++();
        iterator operator++(int);

        // operatori di dereferenziazione
        T& operator*() const;
        T* operator->() const;

        // operatori di ugaglianza e disuguaglianza.
        bool operator==(const iterator& i) const;
        bool operator!=(const iterator& i) const;
    };

    // Funzioni begin e end classe iteratore.
    iterator begin() const;
    iterator end() const;

    // Funzione per aggiungere un elemento.
    void push_back(const T& t);

    void clear();

    void erase(u_int pos);
    void erase(const iterator&);

    // Funzione per determinare se ci sono elementi nel vettore.
    bool empty() const;

    // Funzione che ritorna il numero corrente di elementi nel vettore.
    unsigned int size() const;

    // metodi di ricerca
    string search_eta(const u_int&, const u_int&) const;
    string search_stipendio(const u_int&, const u_int&) const;
    bool find_presence(const Infermiere&) const;
    bool find_presence(const Medico&) const;
    bool find_presence(const Tecnico&) const;

};
/* Funzioni della classe Vector */
template <class T>
bool Vector<T>::find_presence(const Medico& medico) const
{
    bool ok_insert = true;
    for(u_int i = 0; i < current_size; i++)
    {
        if(dynamic_cast<Medico*>(buffer[i]))
        {
            Medico* med = static_cast<Medico*>(buffer[i]);

            if((*med == medico)) // stessa persona
            {
                if(med->get_mese() == medico.get_mese()) // stesso mese e stessa persona : no insert.
                {
                    return false;
                }
                else // nella ricerca per ora vorremmo inserire il dato
                {
                    ok_insert = true;
                }
            }
            else // non è la stessa persona
            {
                ok_insert = true;
            }
        }
    }
    return ok_insert;
}
template <class T>
bool Vector<T>::find_presence(const Infermiere& infermiere) const
{
    bool ok_insert = true;
    for(u_int i = 0; i < current_size; i++)
    {
        if(dynamic_cast<Infermiere*>(buffer[i]))
        {
            Infermiere* inf = static_cast<Infermiere*>(buffer[i]);

            if((*inf == infermiere)) // stessa persona
            {
                if(inf->get_mese() == infermiere.get_mese()) // stesso mese e stessa persona : no insert.
                {
                    return false;
                }
                else // nella ricerca per ora vorremmo inserire il dato
                {
                    ok_insert = true;
                }
            }
            else // non è la stessa persona
            {
                ok_insert = true;
            }
        }
    }
    return ok_insert;
}
template <class T>
bool Vector<T>::find_presence(const Tecnico& tecnico) const
{
    bool ok_insert = true;
    for(u_int i = 0; i < current_size; i++)
    {
        if(dynamic_cast<Tecnico*>(buffer[i]))
        {
            Tecnico* tec = static_cast<Tecnico*>(buffer[i]);

            if((*tec == tecnico)) // stessa persona
            {
                if(tec->get_mese() == tecnico.get_mese()) // stesso mese e stessa persona : no insert.
                {
                    return false;
                }
                else // nella ricerca per ora vorremmo inserire il dato
                {
                    ok_insert = true;
                }
            }
            else // non è la stessa persona.
            {
                ok_insert = true;
            }
        }
    }
    return ok_insert;
}
template <class T>
string Vector<T>::search_eta(const u_int& min, const u_int& max) const
{
    string values_found;
    for(u_int i = 0; i < current_size; i++)
    {
        u_int eta =  buffer[i]->get_età();
                    if(eta >= min && eta <= max)
        {
            values_found.append(buffer[i]->get_info());
            values_found.append("&&");
        }
    }
    return values_found;
}
template <class T>
string Vector<T>::search_stipendio(const u_int& min, const u_int& max) const
{
    string values_found;
    for(u_int i = 0; i < current_size; i++)
    {
        u_int stipendio =  buffer[i]->get_stipendio();
        if(stipendio >= min && stipendio <= max)
        {
            values_found.append(buffer[i]->get_info());
            values_found.append("&&");
        }
    }
    return values_found;
}
template <class T>
typename Vector<T>::iterator Vector<T>::begin() const
{
    if(current_size == 0)
    {
        return Vector<T>::iterator();
    }
    return Vector<T>::iterator(buffer);
}
template <class T>
typename Vector<T>::iterator Vector<T>::end() const
{
    if(current_size == 0)
    {
        return Vector<T>::iterator();
    }
    return Vector<T>::iterator(buffer + current_size);
}

template <class T>
Vector<T>::Vector(u_int size, u_int capacity) : buffer(new T[capacity]), current_size(size), current_capacity(capacity) {}

template <class T>
Vector<T>::~Vector()
{
    if(buffer)
    {
        for(u_int i = 0; i < current_size; i++)
        {
            auto t = buffer[i];
            delete t;
            t = nullptr;
            buffer[i] = nullptr;
        }
        delete [] buffer;
    }
}
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
    current_size = v.current_size;
    current_capacity = v.current_capacity;
    buffer = new T[v.current_capacity];
    for(unsigned short int i = 0; i < v.current_size; i++)
    {
        if(v[i])
        {
            buffer[i] = new int (*v.buffer[i]);
        }
    }
}
template <class T>
void Vector<T>::resize(u_int new_capacity)
{
    if(new_capacity < current_size)
        return;

    T* new_buffer = new T[new_capacity];
    for(u_int i = 0; i < current_capacity; i++)
    {
        if(buffer[i] != nullptr)
        {
            new_buffer[i] = buffer[i];
            continue;
        }
        new_buffer[i] = nullptr;
    }

    current_capacity = new_capacity;

    T* temp = buffer;
    buffer = new_buffer;
    delete [] temp;
}

template <class T>
void Vector<T>::erase(u_int pos)
{
    if (!(pos <= current_size))
        return;

    auto tmp = buffer[pos];
    delete tmp;
    tmp = nullptr;
    buffer[pos] = nullptr;

    if (current_size < current_capacity / 2)
        current_capacity /= 2;

    T* new_buffer = new T[current_capacity];

    u_int j = 0;
    for (u_int i = 0; i < current_size; i++) {
        if (i == pos)
            continue;
        new_buffer[j++] = buffer[i];
    }

    delete[] buffer;
    buffer = new_buffer;
    current_size--;
}
template <class T>
void Vector<T>::push_back(const T& t)
{
    if (current_size == current_capacity)
        resize(2*current_capacity);

    buffer[current_size] = t;
    ++current_size;
}
template <class T>
u_int Vector<T>::size() const
{
    return current_size;
}
template <class T>
T& Vector<T>::operator[](u_int i) const
{

    return buffer[i];
}
template <class T>
void Vector<T>::clear()
{
    for(u_int i = 0; i < current_size; i++)
    {
        auto t = buffer[i];
        delete t;
        t = nullptr;
        buffer[i] = nullptr;
    }
    current_size = 0;
}
template <class T>
bool Vector<T>::empty() const
{
    return current_size == 0;
}

/* Fine definizione funzioni della classe Vector */


/* Funzioni della classe iteratore (non costante) */
template <class T>
Vector<T>::iterator::iterator() : current(nullptr){}
template <class T>
Vector<T>::iterator::iterator(const iterator &i): current(i.current){}

template <class T>
Vector<T>::iterator::iterator(T* v) : current(v){}

template <class T>
bool Vector<T>::iterator::operator==(const iterator& i) const
{
    return current == i.current;
}
template <class T>
bool Vector<T>::iterator::operator!=(const iterator& i) const
{
    return current != i.current;
}
template <class T>
typename Vector<T>::iterator Vector<T>::iterator::operator++(int)
{
    Vector<T>::iterator vl(*this);
    current++;
    return vl;
}
template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++()
{
    current++;
    return *this;
}
template <class T>
T& Vector<T>::iterator::operator*() const
{
    return *current;
}
template <class T>
T* Vector<T>::iterator::operator->() const
{
    return &(*current);
}
/* Fine definizione funzioni della classe iteratore (non costante) */
#endif
