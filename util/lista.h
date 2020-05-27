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

        const T& operator*() const;

        const T* operator->() const;

        constiterator& operator++();

        constiterator operator++(int);

        constiterator& operator--();

        constiterator operator--(int);

        bool operator==(const constiterator& x) const;

        bool operator!=(const constiterator& x) const;
    };
    constiterator begin() const;

    constiterator end() const;

    T front() const;

    T back() const;

    void remove(const constiterator& x);

    void remove(const T& t);

    bool contains(const T& t) const;

    constiterator indexOf(const T& t) const;

};

template<class T>
nodo<T> *lista<T>::copia(nodo<T> *f, nodo<T> *&l)
{
    if(f==nullptr) return l=nullptr; //this._end == nullptr => lista vuota
    //la lista che sto copiando non è vuota
    nodo<T>* prec=new nodo<T>(f->_info,nullptr,nullptr); //primo nodo
    nodo<T>* succ=prec;
    nodo<T>* start=prec; //nodo da cui si parte
    while(f->_next!=nullptr) { //se il next non è nullo significa che ci sono almeno 2 nodi
        succ = new nodo<T>(f->_next->_info,prec,nullptr);
        prec->_next=succ;
        f=f->_next;
        prec=prec->_next;
    }
    l=succ; //l'_end viene aggiornato con il succ
    return start;
}

template<class T>
lista<T>::lista():_first(nullptr), _end(nullptr) {}

template<class T>
lista<T>::lista(const lista &l):_first(copia(l._first,_end)) {}

template<class T>
lista<T>::~lista() { delete _first; }

template<class T>
lista<T>& lista<T>::operator=(const lista &d) {
    if(this != &d) {
        delete _first;
        _first=copia(d._first,_end);
    }
    return *this;
}

template<class T>
bool lista<T>::isEmpty() const
{
    return (_first==nullptr);
}

template<class T>
void lista<T>::insertFront(const T &t)
{
    nodo<T> *first=new nodo<T>(t);
    if(this->isEmpty()) //lista vuota
        _first=_end=first;
    else //lista non vuota
    {
        first->_next=_first;
        _first->_prev=first;
        _first=first;
    }
}

template<class T>
void lista<T>::insertBack(const T &t)
{
    nodo<T> *last=new nodo<T>(t);
    if(this->isEmpty()) //lista vuota
        _first=_end=last;
    else
    {
        last->_prev=_end;
        _end->_next=last;
        _end=last;
    }
}

template<class T>
typename lista<T>::constiterator lista<T>::begin() const {
    return _first;
}

template<class T>
typename lista<T>::constiterator lista<T>::end() const {
    if(_end==nullptr) return nullptr;
    return constiterator(_end+1,true); //ritorna il _pte sse lista non vuota
}

template<class T>
T lista<T>::front() const {
    return _first->getInfo();
}

template<class T>
T lista<T>::back() const {
    return _end->getInfo();
}

template<class T>
lista<T>::constiterator::constiterator(nodo<T> *p, bool pte): _ptr(p), _pastTheEnd(pte) {}

template<class T>
const T& lista<T>::constiterator::operator*() const {
    return _ptr->_info;
}

template<class T>
const T* lista<T>::constiterator::operator->() const {
    return &(_ptr->_info);
}

template<class T>
typename lista<T>::constiterator& lista<T>::constiterator::operator++() {//prefisso
    if(!_pastTheEnd)
    {
        if(_ptr->_next==nullptr) {++_ptr; _pastTheEnd=true;}
        else
            _ptr=_ptr->_next;
    }
    return *this;
}

template<class T>
typename lista<T>::constiterator lista<T>::constiterator::operator++(int) {//postfisso
    lista<T>::constiterator i = *this;
    if(!_pastTheEnd)
    {
        if(_ptr->_next==nullptr) {++_ptr; _pastTheEnd=true;}
        else
            _ptr=_ptr->_next;
    }
    return i;
}

template<class T>
typename lista<T>::constiterator& lista<T>::constiterator::operator--() {
    if(_ptr!=nullptr)
    {
        if(_pastTheEnd) {--_ptr; _pastTheEnd=false;}
        else _ptr=_ptr->_prev;
    }
    return *this;
}

template<class T>
typename lista<T>::constiterator lista<T>::constiterator::operator--(int) {
    lista<T>::constiterator i = *this;
    if(_ptr!=nullptr)
    {
        if(_pastTheEnd) {--_ptr; _pastTheEnd=false;}
        else _ptr=_ptr->_prev;
    }
    return i;
}

template<class T>
bool lista<T>::constiterator::operator==(const typename lista<T>::constiterator& x) const {
    return _ptr==x._ptr;
}

template<class T>
bool lista<T>::constiterator::operator!=(const typename lista<T>::constiterator &x) const {
    return !(_ptr==x._ptr);
}
template<class T>
bool lista<T>::contains(const T &t) const {
    for(lista<T>::constiterator i = begin(); i != end(); i++)
    {
        if(*i == t)
            return true;
    }
    return false;
}

template<class T>
typename lista<T>::constiterator lista<T>::indexOf(const T &t) const {
    for(constiterator i = begin(); i != end(); i++)
    {
        if(*i == t)
            return i;
    }
    return nullptr;
}

template<class T>
void lista<T>::remove(const constiterator &x) { //il remove non funziona nei cicli for perché da problemi con gli iteratori
    //converto constiterator in int?
    if(!this->isEmpty())
    {
        if(x==this->begin())
        {
            if(_first==_end)
                _first = _end = nullptr;
            else
            {
                nodo<T> *f=_first;
                _first=_first->_next;
                f->_next= nullptr;
                delete f;
            }
        }
        else if(x==this->end())
        {
            if(_first==_end)
                _first = _end = nullptr;
            else
            {
                nodo<T> *e=_end;
                _end=_end->_prev;
                _end->_next= nullptr;
                delete e;
            }
        }
        else
        {
            nodo<T>* p=x._ptr->_prev;
            nodo<T>* s=x._ptr->_next;
            p->_next=s;
            s->_prev=p;
            //da valutare se vanno messe o meno
            //x._ptr->_prev=x._ptr->_next=nullptr;  //senza queste funziona fuori i for e circa anche dentro
            //delete x._ptr;                        //con queste funziona fuori
        }
    }
}

template<class T>
void lista<T>::remove(const T &t) {
    lista<T>::remove(lista<T>::indexOf(t));
}
#endif //LISTA_H
