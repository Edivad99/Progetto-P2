#ifndef NODO_H
#define NODO_H

template<class T>
class lista;

/*template<class T>
class constiterator;*/

template<class T>
class nodo
{
    friend class lista<T>;
    //friend class constiterator<T>;
private:
    T _info;
    nodo *_prev, *_next;
public:
    //manca il costruttore di default di T, quindi che succede al nodo se invoco questo?
    //nodo();
    nodo(const T& t, nodo *prev=nullptr, nodo *next=nullptr);
    ~nodo();
    T getInfo() const;
};

#endif // NODO_H
