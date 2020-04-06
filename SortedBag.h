#ifndef SORTEDBAG_H
#define SORTEDBAG_H
#include <cassert>
#include "Node.h"
//#include "Student.h"

template<class T>
class SortedBag {
    typedef T value_type;
public:
    SortedBag() : m_data(0), m_size(0), m_asc(true), m_curr(0), m_tail(0) {}
    SortedBag(const SortedBag&);
    void operator =(const SortedBag&);
    ~SortedBag();

    bool erase_one(const T&);
    long erase(const T&);
    void insert(const T&);
    void operator +=(const SortedBag&);
    long size() const { return m_size; }
    long count(const T&) const;

    // SIMPLE ITERATOR
    void begin(const bool ascending=true);   //m_curr starting at head
    bool end() const{ if(m_end==true) return m_curr == m_data;}
    void operator++(){if(m_curr==m_data->prev_ptr)m_end = true; m_curr = m_curr->next_ptr;}
    void operator--(){m_curr = m_curr->prev_ptr;}
    T& get(){return m_curr->Node_data;}
private:
    Node<T>* m_data; /* pointer to ring structure.*/    /*Node* m_data; sort of like the m_data*/   //head_ptr
    long     m_size; // number of elements in the Bag.
    bool     m_asc;  // flag to indicate iteration in ascending order or not.
    Node<T>* m_curr; // iterator's current position.
    Node<T>* m_tail;
    bool     m_end;                                                                               //tail_ptr
};

//---------------------------------------------------------------------------------------------------------------------------insert



template<class T>
void SortedBag<T>::begin(const bool ascending){
    std::cout << " Start: "<< m_data->Node_data << std::endl;
    std::cout << " Next: "<< m_data->next_ptr->Node_data << std::endl;
    std::cout << " Before: "<< m_data->prev_ptr->Node_data << std::endl;

m_asc = ascending;
m_end = false;
m_curr = m_data;
}



template<class T>
void SortedBag<T>::insert(const T& entry){
    if(m_data==0){

        // insert if list is empty
        m_data = new Node<T>(entry);
        m_tail = m_data;
        m_size++;
    }

    else{

        // set temp to head pointer and create new node.
        Node<T>* temp = m_data;
        Node<T>* newNode = new Node<T>(entry);

        // if entry is smaller than first node insert as head node
        if(entry < m_data->Node_data){
            temp->prev_ptr = newNode;
            newNode->next_ptr = temp;
            m_data = newNode;
            m_data->prev_ptr = m_tail;
            m_tail->next_ptr = m_data;
            m_size++;
        }else
        // if entry is bigger than last node insert at the end
        if(entry > m_tail->Node_data){
            temp = m_tail;
            temp->next_ptr = newNode;
            newNode->prev_ptr = temp;
            m_tail = newNode;
            m_data->prev_ptr = m_tail;
            m_tail->next_ptr = m_data;
            m_size++;
        }
        else{
            //if not smaller than first node or bigger than last node find position and insert
            while(entry > temp->Node_data){
                temp = temp->next_ptr;
            }
            newNode->next_ptr = temp;
            temp->prev_ptr->next_ptr = newNode;
            newNode->prev_ptr = temp->prev_ptr;
            temp->prev_ptr = newNode;
            m_size++;
        }
    }

}

//------------------------------------------------------------------------------------------------------------------------operator+
template<class T>
SortedBag<T> operator+(const SortedBag<T>&, const SortedBag<T>&){

}

//------------------------------------------------------------------------------------------------------------------------operator=
template<class T>
void SortedBag<T>::operator=(const SortedBag& source){
    m_curr->Node_data = source.m_curr->Node_data;
}

//----------------------------------------------------------------------------------------------------------------------destructor
template<class T>
SortedBag<T>::~SortedBag(){

    for(int i=0; i<m_size; i++){
        Node<T> *curr = m_data;
        m_data = m_data->next_ptr;
        delete(curr);
    }
    m_size = 0;
    m_data = 0;
}

//---------------------------------------------------------------------------------------------------------------------erase_one
template<class T>
bool SortedBag<T>::erase_one(const T& target){
Node<T>* curr = m_data;
m_data = m_data->next_ptr;
delete(curr);
}

//------------------------------------------------------------------------------------------------------------------------erase
/* this function is for the single linked list, not double. fix */
template<class T>
long SortedBag<T>::erase(const T& target){
~SortedBag(target);
}

//------------------------------------------------------------------------------------------------------------------------operator+=
/* again, this regards the fact that the structure is double linked circular  */
template<class T>
void SortedBag<T>::operator +=(const SortedBag& addend){

}

//-------------------------------------------------------------------------------------------------------------------------count
/* this also is for single linked list non circular FIX  */
template<class T>
long SortedBag<T>::count(const T& target) const{

}

/* SIMPLE ITERATOR*/
//     void begin(const bool ascending=true);
//     bool end() const;
//     void operator++();
//     void operator--();
//     T& get();


#endif // SORTEDBAG_H
