#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
        Iterator() //Completado
        {
            this -> current = nullptr; //Si se crea sin parametros, significa que el iterador no apunta a nada.
        };

        Iterator(Node<T>* node) //Completado
        {
            this -> current = node; //El current pasa a apuntar al nodo que se le brinda como parametro.
        };
         
        Iterator<T> operator=(Iterator<T> node) //Completado
                {
                    this -> current = node.current;
                    return *this;
                };

        bool operator!=(Iterator<T> cmp) //Completado
        {
            return cmp.current != this -> current;
        };

        Iterator<T> operator++()
                {
                    if (this -> current)
                    {
                        this -> current = this -> current -> next;
                        return *this;
                    }
                };
        Iterator<T> operator--()
            {
                if (this -> current)
                {
                    this -> current = this -> current -> prev;
                    return *this;
                }
            };

        T operator*()
        {
            return this -> current -> data;
        };
};

#endif