#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List() //Completado
        {
            this -> start = nullptr; //El start empieza siendo nullptr
            this -> nodes = 0; //Empieza con 0 nodos.
        };

        T front() //Completado
            {
            if(!start) //Si la lista esta vacia
                throw "Lista Vacia"; //Se envia una excepcion.

            else //Si la lista tiene algun elemento
                return this -> start -> data; //Se retorna la data del Nodo head
        };

        T back() //Completado
        {
            if(!start) //Si la lista esta vacia
                throw "Lista Vacia"; //Se envia una excepcion.

            else  //Si la lista tiene algun elemento
                return this -> start -> prev -> data; //Se retorna la data del Nodo previo al head
        };

        void push_front(T value) //Completado
        {
            Node<T>* NewStart = new Node<T>; //Creamos el puntero a Nodo que sera nuevo start
            NewStart -> data = value; //Toma el valor que el parametro le da

            if (!start) //Si la lista esta vacia
                {
                    NewStart -> next = NewStart; //Se apuntara a si mismo en el next
                    NewStart -> prev = NewStart; //Se apuntara a si mismo en el prev
                }

                else //Si la lista tiene elementos
                        {
                            NewStart -> next = this -> start; //El nuevo nodo tiene como next al start actual
                            NewStart -> prev = this -> start -> prev; //Su prev es el prev del start actual
                            NewStart -> next -> prev = NewStart; //El next del start tiene como previo al start
                            NewStart -> prev -> next = NewStart; //El previo del start tiene como next al start
                        }
            this -> start = NewStart; //Pasa a convertirse en el nuevo start
            (this -> nodes)++; //Aumenta el numero de nodos en 1
        };

        void push_back(T value) //Completado
        {
            Node<T>* NewStart = new Node<T>; //Creamos el puntero al nuevo Nodo
            NewStart -> data = value; //Toma el valor que el parametro le da

            if (!start) //Si la lista esta vacia
                {
                    NewStart -> next = NewStart; //Se apuntara a si mismo en el next
                    NewStart -> prev = NewStart; //Se apuntara a si mismo en el prev
                    this -> start = NewStart; //El start se vuelve el Nodo
                }

                else
                    {
                        NewStart -> next = this -> start; //El nuevo nodo tiene como next al start actual
                        NewStart -> prev = this -> start -> prev; //Su prev es el prev del start actual
                        NewStart -> next -> prev = NewStart; //El next del start tiene como previo al start
                        NewStart -> prev -> next = NewStart; //El previo del start tiene como next al start
                    }

            (this -> nodes)++; //Aumenta el numero de nodos en 1
        };

        void pop_front() //Completado
        {
            if(!start) //Si la lista esta vacia
                throw "Lista Vacia"; //Se da la excepcion

            if(this -> nodes == 1)
                this -> start = nullptr; //Si la lista tiene un elemento, este se elimina.

            else
                {
                    this -> start -> prev -> next = this -> start -> next; //El anterior al start pasa a apuntar al siguiente al start
                    this -> start -> next -> prev = this -> start -> prev; //Y viceversa
                    Node<T>* NewNode = this -> start; //Se crea un nodo igual al start
                    this -> start = this -> start -> next; //El start pasa a ser el que le sigue al start
                    delete NewNode; //Y se elimina el nodo
                }

            (this -> nodes)--; //Se reduce el numero de nodos en 1
        };

        void pop_back() //Completado
        {
            if (!start) //Si la lista esta vacia
                throw  "Lista Vacia"; //Se da la excepcion

            if (this -> nodes == 1) //Si la lista tiene unicamente un elemento
                this -> start = nullptr; //Este se elimina

            else
            {
                Node<T>* NewNode = this -> start -> prev; //Se crea un nodo igual al anterior al start
                this -> start -> prev -> prev -> next = this -> start; //El anterior al anterior al start pasara a apuntar al start
                this -> start -> prev = this -> start -> prev -> prev; //El anterior al start pasa a ser el anterior al anterior al start
                delete NewNode; //Eliminamos el nodo
            }

            (this -> nodes)--; //Se reduce el numero de nodos en 1
        };

        T get(int position) //Completado
        {
            if (position < 0) //Si se ingresa una posicion mayor al numero de nodos o menor a 0
                throw "Inserte un valor valido"; //Se da la excepcion.

            else
                {
                    position = position % nodes; //En caso la lista vaya a loopear, se cuenta el modulo para que no lo haga.
                    Node<T>* Current = start; //Se crea un node para iterar entre los valores, que empiece en el start.
                    while(position--) //Se usa la posicion como un contador que va hasta 0
                    {
                        Current = Current -> next; //El Current se transforma en el next
                    }
                    return Current -> data; //Se devuelve el valor en el que queda el current.
                }
        };


        void concat(List<T> &other) //Completado
        {
            Iterator<T> Auxiliar = other.begin(); //Creamos un iterador auxiliar que es igual al begin del other
            while(Auxiliar != other.end()) //Mientras sea diferente al end del other
                this -> push_back(*Auxiliar); //Se push_back a lo que apunta
        };

        bool empty() //Completado
        {
            return nodes == 0; //Se retorna si esta vacia
        };
        int size() //Completado
        {
            return nodes;
        };

        void clear() //Completado
        {
            while (this -> start) //Mientras hayan elementos en la lista
                pop_front(); //Se hace pop_front
        };

        Iterator<T> begin() //Completado
        {
            return Iterator<T>(this -> start);
        }

        Iterator<T> end() //Completado
                {
                    return Iterator<T>(this -> start -> prev);
                }

        ~List() //Completado
        {
            this -> clear(); //Se aplica la funcion clear;
        };
};

#endif