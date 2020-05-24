#ifndef LISTA_H
#define LISTA_H

/*template<class T>
ostream& operator<< (ostream&, const lista<T>&);
/*template <class T>
class nodo{
private:
    T _info;
    nodo *_next;
public:
    nodo(const T& info=T(), nodo *next=nullptr);
     ~nodo(){ delete _next; }

};*/

template <class T>
class lista
{
    //friend  ostream& operator<< <T>(ostream&, const lista<T>&);
private:
    //classe nodo interna alla lista
    class nodo{
    public:
        T _info;
        nodo* _next;
        //costruttore di nodo
        nodo(const T& info=T(), nodo* next=nullptr):_info(info), _next(next) {}
        //distruttore di nodo
        ~nodo(){ delete _next; }
    };
    nodo *_first, *_end; //nodo<T> *_first, *_end
    //_end punta all'ultimo nodo, non alla "cella" successiva
    static nodo* copia(nodo* f, nodo*& l){ //static nodo<T>* copia(nodo<T>* f, nodo<T>*& l){
       if(f==nullptr) return l=nullptr; //this._end == nullptr => lista vuota
       //la lista che sto copiando non è vuota
       nodo* prec=new nodo(f->info,nullptr); //primo nodo
       nodo* succ=prec;
       nodo* start=prec; //nodo da cui si parte
       while(f->next!=nullptr) { //se il next non è nullo significa che ci sono almeno 2 nodi
         succ = new nodo(f->next->info,nullptr);
         prec->next=succ;
         f=f->next;
         prec=prec->next;
       }
       l=succ; //l'_end viene aggiornato con il succ
       return start;
     }

    static bool less(nodo* t1, nodo* t2) {
        if(t2==nullptr) return false;
        if(t1==nullptr) return true;
        return t1->_info < t2->_info || (t1->_info==t2->_info && less(t1->_next,t2->_next));
      }

public:
    //costruttore lista
    //lasciare il default? altrimenti lista():_first(nullptr), _end(nullptr) {}
    //lista(unsigend int n, const T& t){for(unsigned int i=0; i<n; i++) insertFront(t); } inserire n elementi tutti uguali
    //costruttore di copia di lista
    lista(const lista& l):_first(copia(l._first,_end)) {}
    //distruttore di lista
    ~lista() { delete _first; }
    //operatore di assegnazione
    lista& operator=(const lista& d) {
        if(this != &d) {
          delete _first;
          _first=copia(d._first,_end);
        }
        return *this;
      }
    //lista vuota
    bool isEmpty() const
    {
        return (_first==nullptr);
    }
    //inserimento in testa
    void insertFront(const T& t)
    {
        nodo *first=new nodo(t,_first);
        if(this->isEmpty()) //lista vuota
            _end=first;
        else //lista non vuota
            first->_next=_first;
    }
    //inserimento in coda
    void insertBack(const T& t)
    {
        nodo *last=new nodo(t,nullptr);
        if(this->isEmpty()) //lista vuota
            _first=_end=last;
        else
            _end->_next=last;
    }
    //iteratore
    class iterator {
        friend class lista<T>;
      private:
        nodo* _ptr;
        bool _pastTheEnd; // true iff iterator è "past-the-end"
        iterator(nodo* p, bool pte=false): _ptr(p), _pastTheEnd(pte) {}
      public:
        iterator(): _ptr(nullptr), _pastTheEnd(false) {}

        T& operator*() const{
          return _ptr->info;
        }

        T* operator->() const{
          return &(_ptr->info);
        }

        iterator& operator++() {//prefisso
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

        iterator operator ++(int) // postfissi
        {
            if(_ptr!=nullptr)
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
        /*iterator& operator--() {
          if(ptr!=nullptr)
          {
            if(pastTheEnd) {--ptr; pastTheEnd=false;}
            //else come tornare indietro?
          }
          return *this;
        }*/

        bool operator==(const iterator& x) const {
          return _ptr==x._ptr;
        }

        bool operator!=(const iterator& x) const {
          return _ptr!=x._ptr;
        }
      };
    iterator begin() const {
        return _first;
    }

    iterator end() const {
        if(_end==nullptr) return nullptr;
        return iterator(_end+1,true);
      }
    /*
    static void concat(const lista<T>& l1, const lista<T>& l2)
    {
        if(!l1.isEmpty() && !l2.isEmpty())
        {
            l1._end->_next=l2._first;
        }
        else
        //da sistemare
            concat(l1._first->_next,l2);
    }*/

    T& front() const {
        return _first;
    }

    T& back() const {
        return _end;
    }

    T& find(const T& t) const {
        //usare l'iteratore
        /*nodo *curr=_first;
        iterator i=this->begin();
        while(i<this->end() && i.ptr->_info!=t)
        {
            if(i.ptr==t)
            i++;
        }*/
        // restituire la posizione, il valore, true o false, parametri?
    }
    //numero elementi, erase, remove, sort, find, print
    //altre versioni?
    void remove(const T& t){
        if(!isEmpty()){
            if(_first->_info == t){
                nodo* curr = _first;
                _first = _first->next;
                delete curr;
            }
            else { //dal secondo elemento in poi
            nodo* prev = _first;
            nodo* curr = _first->_next;
            bool r=false;
            while(curr != nullptr && !r) { //il puntatore è valido
                if(curr->_info == t) {
                    r=true;
                }
                else {
                    prev = curr;
                    curr = curr->_next;
                }
            }
            if(!r)
                _first; //va tolto, messo perché da errore
                //"nodo non rimosso\n";
            else{
                prev->_next = curr->_next;
                delete curr;
                }
            }
        }
    }

    nodo* search(const T& t) {
        bool s=false;
        nodo* curr = _first;
        while(curr != nullptr && !s){
            if(curr->_info == t)
                s=true;
            else
                curr = curr->_next;
        }
        return curr;
    }

    /*void print(){
        if(_first!=nullptr)
        {
            nodo* curr = _first;
            while(curr){
                //cout<<curr->_info << endl;
                curr = curr->_next;
            }
        }
    }*/

    void sort(){

    }
};

/*template<class T>
ostream& operator<<(ostream& os, const lista<T>& l){
    os<<"(";
    nodo<T> *f=l._first;
    for(; f!= nullptr; f=f->_next)
        os<<*f<<" ";
    os<<")"<<endl;
    return os;
}*/

#endif // LISTA_H
