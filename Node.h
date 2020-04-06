#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
struct Node {
    //typedef T value_type;
    Node() : next_ptr(this), prev_ptr(this) {}
    Node(const T& val)
            : Node_data(val), next_ptr(this), prev_ptr(this) {

    }

    T& data(){return Node_data;}
    void setNodeData(const T& new_data){Node_data = new_data;}
    void setNext(Node<T>* new_next){next_ptr = new_next;}
    void setPrev(Node<T>* new_prev){prev_ptr = new_prev;}

    T        Node_data;
    Node<T>* next_ptr; // pointer to successor element.
    Node<T>* prev_ptr; // pointer to predecessor element.
};

//------------------------------------------------------------------------------------DONE----------- list_head_insert

/*insert first node.   */
template<class T>
void list_head_insert(Node<T>*& head_ptr, const T& entry){
    if(head_ptr == NULL){
        head_ptr = new Node<T>(entry);
    }

}

//------------------------------------------------------------------------------------------------ list_insert

template<class T>
void list_insert(Node<T>* previous_ptr, const T& entry){
    Node<T> *insert_ptr;

    insert_ptr = new Node<T>(entry, previous_ptr->next_ptr);
    previous_ptr->setNext(insert_ptr);
}

#endif // NODE_H




// template<class T>
//   struct Node {
//       typedef T value_type;
//     Node() : next_ptr(this), prev_ptr(this) {}
//     Node(const T& val, Node<T>* n=0, Node<T>* p=0)
//           : Node_data(val), next_ptr(n), prev_ptr(p) {}
//
//     T& data(){return Node_data;}
//     void setNodeData(const T& new_data){Node_data = new_data;}
//     void setNext(Node<T>* new_next){next_ptr = new_next;}
//     void setPrev(Node<T>* new_prev){prev_ptr = new_prev;}
//
//     T        Node_data;
//     Node<T>* next_ptr; // pointer to successor element.
//     Node<T>* prev_ptr; // pointer to predecessor element.
//   };
//
////------------------------------------------------------------------------------------DONE----------- list_head_insert
//
///*insert first node.   */
//   template<class T>
//   void list_head_insert(Node<T>*& head_ptr, const T& entry){
//       if(head_ptr == 0){
//        head_ptr = new Node<T>(entry,head_ptr,head_ptr);
//       }
//
//   }
//
////------------------------------------------------------------------------------------------------ list_insert
//
//    template<class T>
//    void list_insert(Node<T>* previous_ptr, const T& entry){
//       Node<T> *insert_ptr;
//
//       insert_ptr = new Node<T>(entry, previous_ptr->next_ptr);
//       previous_ptr->setNext(insert_ptr);
//   }
//
////--------------------------------------------------------------------------------------------------- list_remove
//
//   template<class T>
//   void list_remove(Node<T>* previous_ptr){
//       Node<T> *remove_ptr;
//
//       remove_ptr = previous_ptr->next_ptr;
//       previous_ptr->setNext(remove_ptr->next_ptr);
//       delete remove_ptr;
//   }
//
////------------------------------------------------------------------------------------------------------------- list_clear
//
//    template<class T>
//    void list_clear(Node<T>*& head_ptr){
//
//        while(head_ptr != NULL){
//            list_head_remove(head_ptr);
//        }
//    }
//
//    //--------------------------------------------------------------------------------------------------- list_head_remove
//
//   template<class T>
//   void list_head_remove(Node<T>*& head_ptr){
//       Node<T> *remove_ptr;
//
//        remove_ptr = head_ptr;
//        head_ptr = head_ptr->next_ptr;
//        delete remove_ptr;
//   }
//
//
////
//////functions to manipulate a linked-list
/////* */
//
//////--------------------------------------------------------------------------------------------------- list_copy
////
////   template<class T>/* implemented for single linklist non circular */
////   void list_copy(const Node<T>* source_ptr, Node<T>*& head_ptr, Node<T>*& tail_ptr){
////       head_ptr = NULL;
////       tail_ptr = NULL;
////
////       //handle the case of the empty list
////
////       if(source_ptr == NULL)
////        return;
////
////       //Make head node for the newly created list and put data in it
////
////       list_head_insert(head_ptr,source_ptr->data());
////       tail_ptr = head_ptr;
////
////       //copy the rest of the nodes one at a time, adding at the tail of the new list
////       source_ptr = source_ptr->next_ptr;
////       while(source_ptr != NULL){
////        list_insert(tail_ptr,source_ptr->data());
////        tail_ptr = tail_ptr->next_ptr;
////        source_ptr = source_ptr->next_ptr;
////       }
////   }
////
//
//////--------------------------------------------------------------------------------------------------- list_length
////
////   template<class T>
////   long list_length(const Node<T>* head_ptr){
////       const Node<T> *cursor;
////       long answer;
////
////       answer = 0;
////       for(cursor = head_ptr; cursor!=NULL; cursor=cursor->next_ptr)
////        ++answer;
////
////       return answer;
////   }
////
//////--------------------------------------------------------------------------------------------------- list_locate
////
////   template<class NodePtr, class SizeType> /*Not completely sure if this even works...  */
////   NodePtr list_locate(NodePtr head_ptr, SizeType position){
////
////       NodePtr cursor;
////       long i;
////
////       assert(0 < position);
////       cursor = head_ptr;
////       for(i = 1; (i<position) && (cursor != NULL); ++i)
////        cursor = cursor->next_ptr; /*getNextLink didn't automatically show up */
////       return cursor;
////   }
////
//////--------------------------------------------------------------------------------------------------- list_search
////
////   template<class NodePtr, class T>
////   NodePtr list_search(NodePtr head_ptr, const T& target){
////       NodePtr cursor;
////
////       for(cursor = head_ptr; cursor!= NULL; cursor->next_ptr)
////        if(target==cursor->data())
////            return cursor;
////       return NULL;
////   }
//
//#endif // NODE_H
//

