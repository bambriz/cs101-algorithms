//Bryan AMbriz :) 
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj{
   Node head;
   Node tail;
   Node curr;
   int length;
} ListObj;
typedef ListObj* List;

// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->head = L->tail=L->curr = NULL;
   L->length = 0;
   return(L);
}


// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.S
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL) { 
      while( length(*pL)>0 ) { 
         deleteBack(*pL); 
      }
      free(*pL);
      *pL = NULL;
   }
}

   


// Access functions -----------------------------------------------------------
int length(List L){
     L->length=0;
    for(Node tampon = L->head; tampon != NULL; tampon=tampon->next){
        L->length++;
    }
    return L->length;
}
int getIndex(List L){
    if(L->curr == NULL) return -1;
    Node temp = L->head;
        int ind = 0;
        while( temp != NULL ){
             if( temp->data == L->curr->data) return ind;
             ind++;
             temp= temp->next;
        }
       return -1;
    
}
int front(List L){
    if( length(L) > 0) return L->head->data;
        return -1;
}
int back(List L){
    if ( length(L) > 0) return L->tail->data;
        return -1;
}
int getElement(List L){
    if(length(L) > 0 && getIndex(L) >= 0) return L->curr->data;
        return -1;
}
int equals(List A, List B){
    if( length(A) != length(B)) return 0;
        Node temp = A->head;
        Node tempL = B->head;
        
        while( temp != NULL){
             if( temp->data != tempL->data) return 0;
             temp = temp->next;
             tempL = tempL->next;
        }
        return 1;
}

// Manipulation procedures ----------------------------------------------------
void clear(List L){
L->curr = NULL;
     while(length(L)>0){
        deleteFront(L);
     }
    L->length = 0;
    
   // freeList(&L);
}
//move curosr to index
void moveTo(List L, int i){
    if ( i >= 0 && i <= length(L) -1) {
              L->curr = L->head;
              if(i == 0) return;
              for( int j = 0; j<i; j++){
               //   cur = cur.next;
               moveNext(L);
              }
        }else {
              L->curr = NULL;
        }
}
//iterate cursor to the left
void movePrev(List L){
    if(getIndex(L) == -1) return;
           if(getIndex(L) == 0) L->curr = NULL;
           if ( getIndex(L) >= 0 && getIndex(L) <= length(L) -1) L->curr = L->curr->prev;
}
//iterate the cursor to the right
void moveNext(List L){
    if(getIndex(L) == -1) return;
           if(getIndex(L) == length(L)-1) L->curr = NULL;
           if ( getIndex(L) >= 0 && getIndex(L) <= length(L) -1) L->curr = L->curr->next;
}//add a node to before the front
void prepend(List L, int data){
    Node temp = newNode(data);
           if(length(L) == 0){
             L->head = L->tail = temp;   
              return;
            }           
           temp->next = L->head;
           L->head->prev = temp;
           L->head = L->head->prev;
}

// append to the back a node
void append(List L, int data){
    Node temp = newNode(data);
           if(length(L) == 0){
             L->head = L->tail = temp;   
              return;
            }  
            temp->prev = L->tail;
            L->tail->next = temp;
            L->tail = L->tail->next;
}//insert before cursor
void insertBefore(List L, int data){
    if( length(L) > 0 && getIndex(L) >= 0){
            if(getIndex(L) == 0){
            prepend(L,data); 
            return;
            }
            Node temp = newNode(data);
            temp->next = L->curr;
            L->curr->prev->next = temp;
            L->curr->prev = temp;
        }
}
//insers after cursor
void insertAfter(List L, int data){
    if( length(L) > 0 && getIndex(L) >= 0){
            if(getIndex(L) == length(L)-1){
            append(L,data); 
            return;
            }
            Node temp = newNode(data);
            temp->next = L->curr->next;
            temp->prev = L->curr;
            L->curr->next->prev = temp;
            L->curr->next = temp;
        }
}
//deltes and frees first node
void deleteFront(List L){
    if( length(L) < 0) return;
         if( length(L) == 1){
         //clear(L);
         Node del = L->head;
         L->head = NULL;
         L->tail= NULL;
         freeNode(&del);
         return;
         }
         Node del = L->head;
         L->head = L->head->next;
         L->head->prev = NULL;
         freeNode(&del);
}

//deltes and frees last node
void deleteBack(List L){
    if( length(L) < 0) return;
         if( length(L) == 1){
         //clear(L);
         Node del = L->tail;
         L->head = NULL;
         L->tail= NULL;
         freeNode(&del);
         //del = NULL;
         return;
         }
         Node del = L->tail;
         L->tail = L->tail->prev;
         L->tail->next = NULL;
         freeNode(&del);
         //del = NULL;
}

// deletes the node and frees it at the cursor
void delete(List L){
    if( length(L) > 0 && getIndex(L) >= 0){
            if( length(L) == 1){
              //clear(L);
              Node del = L->head;
              L->head = NULL;
              L->tail= NULL;
              L->curr= NULL;
              freeNode(&del);
              return;
             }
             if(L->head == L->curr){
                deleteFront(L);
                L->curr = NULL;
                return;
             }
             if(L->tail == L->curr){
                deleteBack(L);
                L->curr = NULL;
                return;
             }
            if(L->curr->prev != NULL) {
                Node del = L->curr;
                L->curr->prev->next = L->curr->next;
                L->curr->next->prev = L->curr->prev;
                freeNode(&del);
            }else{
                Node del = L->curr;
                L->curr->next->prev = L->curr->prev;
                L->curr->prev->next = L->curr->next;
                freeNode(&del);
            }
        }
}
// Other operations -----------------------------------------------------------
void printList(FILE* out, List L){
   // char[] returnString = malloc(sizeOf(;
        Node transverser = L->head;
        while( transverser != NULL){
            fprintf(out,"%d ", transverser->data);
            /*returnString += transverser->data;
            returnString += " ";*/
            transverser = transverser->next;
        }
        //return returnString; 
   }

List copyList(List L){
 List C = newList();
 for(Node T = L->head; T != NULL; T=T->next){
    append(C,T->data);
 }
 return C;
}