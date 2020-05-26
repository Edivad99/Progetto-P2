#include "lista.h"

template<class T>
nodo<T> *lista<T>::copia(nodo<T> *f, nodo<T> *&l)
{
    if(f==nullptr) return l=nullptr; //this._end == nullptr => lista vuota
    //la lista che sto copiando non è vuota
    nodo<T>* prec=new nodo(f->info,nullptr,nullptr); //primo nodo
    nodo<T>* succ=prec;
    nodo<T>* start=prec; //nodo da cui si parte
    while(f->next!=nullptr) { //se il next non è nullo significa che ci sono almeno 2 nodi
        succ = new nodo(f->next->info,prec,nullptr);
        prec->next=succ;
        f=f->next;
        prec=prec->next;
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
    nodo<T> *first=new nodo(t,nullptr, _first);
    if(this->isEmpty()) //lista vuota
        _end=first;
    else //lista non vuota
    {
        _first->_prec=first;
        _first=first;
    }
}

template<class T>
void lista<T>::insertBack(const T &t)
{
    nodo<T> *last=new nodo(t,_end,nullptr);
    if(this->isEmpty()) //lista vuota
        _first=last;
    else
    {
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
T& lista<T>::front() const {
    return _first;
}

template<class T>
T& lista<T>::back() const {
    return _end;
}

template<class T>
lista<T>::constiterator::constiterator(nodo<T> *p, bool pte): _ptr(p), _pastTheEnd(pte) {}

template<class T>
typename lista<T>::constiterator& lista<T>::constiterator::operator++() {//prefisso
    if(_ptr!= nullptr) //nodo puntato
    {
        if(!_pastTheEnd)
        {
            if(_ptr->next==nullptr) {++_ptr; _pastTheEnd=true;}
            else
                _ptr=_ptr->next;
        }
    }
    return *this;
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
bool lista<T>::constiterator::operator==(const typename lista<T>::constiterator& x) const {
    return _ptr==x._ptr;
}

template<class T>
bool lista<T>::constiterator::operator!=(const typename lista<T>::constiterator &x) const {
    return !(_ptr==x._ptr);
}#include "lista.h"

template<class T>
nodo<T> *lista<T>::copia(nodo<T> *f, nodo<T> *&l)
{
    if(f==nullptr) return l=nullptr; //this._end == nullptr => lista vuota
    //la lista che sto copiando non è vuota
    nodo<T>* prec=new nodo(f->info,nullptr,nullptr); //primo nodo
    nodo<T>* succ=prec;
    nodo<T>* start=prec; //nodo da cui si parte
    while(f->next!=nullptr) { //se il next non è nullo significa che ci sono almeno 2 nodi
        succ = new nodo(f->next->info,prec,nullptr);
        prec->next=succ;
        f=f->next;
        prec=prec->next;
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
    nodo<T> *first=new nodo(t,nullptr, _first);
    if(this->isEmpty()) //lista vuota
        _end=first;
    else //lista non vuota
    {
        _first->_prec=first;
        _first=first;
    }
}

template<class T>
void lista<T>::insertBack(const T &t)
{
    nodo<T> *last=new nodo(t,_end,nullptr);
    if(this->isEmpty()) //lista vuota
        _first=last;
    else
    {
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
T& lista<T>::front() const {
    return _first;
}

template<class T>
T& lista<T>::back() const {
    return _end;
}

template<class T>
lista<T>::constiterator::constiterator(nodo<T> *p, bool pte): _ptr(p), _pastTheEnd(pte) {}

template<class T>
typename lista<T>::constiterator& lista<T>::constiterator::operator++() {//prefisso
    if(_ptr!= nullptr) //nodo puntato
    {
        if(!_pastTheEnd)
        {
            if(_ptr->next==nullptr) {++_ptr; _pastTheEnd=true;}
            else
                _ptr=_ptr->next;
        }
    }
    return *this;
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
bool lista<T>::constiterator::operator==(const typename lista<T>::constiterator& x) const {
    return _ptr==x._ptr;
}

template<class T>
bool lista<T>::constiterator::operator!=(const typename lista<T>::constiterator &x) const {
    return !(_ptr==x._ptr);
}
