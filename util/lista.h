#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

template <class T>
class lista
{
private:
    nodo<T> *_first, *_end;//_end punta all'ultimo nodo, non alla "cella" successiva
    static nodo<T> *copia(nodo<T>* f, nodo<T>*& l);

public:
    //costruttore lista
    lista();
    //costruttore di copia di lista
    lista(const lista& l);
    //distruttore di lista
    ~lista();
    //operatore di assegnazione
    lista& operator=(const lista& d);
    //lista vuota
    bool isEmpty() const;
    //inserimento in testa
    void insertFront(const T& t);
    //inserimento in coda
    void insertBack(const T& t);
    //iteratore
    class constiterator {
        friend class lista<T>;
      private:
        nodo<T> *_ptr;
        bool _pastTheEnd; // true sse constiterator è "past-the-end"
        constiterator(nodo<T>* p, bool pte=false);
      public:
        constiterator(): _ptr(nullptr), _pastTheEnd(false) {}

        T& operator*() const{
          return _ptr->getInfo();
        }

        T* operator->() const{
          return &(_ptr->getInfo());
        }

        constiterator& operator++();

        //++ postifisso

        constiterator& operator--();

        bool operator==(const constiterator& x) const;

        bool operator!=(const constiterator& x) const;
      };
    constiterator begin() const;

    constiterator end() const;

    T& front() const;

    T& back() const;
    
    //manca il remove
};

#endif // LISTA_H
