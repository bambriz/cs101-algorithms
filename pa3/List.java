//Bryan Ambriz
// bambriz
// Tantalo cs 101
/* This is a standard doubly-linked list ADT
*/

class List{

 
     // node constructor
       private class Node{
      
      object data;
      Node next;
      Node prev;
      Node( int data) { this.data = data; next = prev = null; }
      public String toString() { return String.valueOf(data); }
   }
   
   // fields for the list and constructor
   private Node head;// front node
   private Node tail; // back node
   private int size;
   private Node cur; // the cursor that points at any given node
   List(){head = tail = cur = null; size = 0;}
   
   //Access Functions
   int length() { 
      int d = 0;
      Node t = head;
      for(;t != null; t = t.next) d +=1;
      return d;
}
   int getIndex(){
         if (cur == null) return -1;
        Node temp = head;
        int ind = 0;
        while( temp != null ){
             if( temp.data == cur.data) return ind;
             ind += 1;
             temp= temp.next;
        }
       return -1;
   }
   object front() { 
        if( length() > 0) return head.data;
        return -1;
   }
   object back(){
        if ( length() > 0) return tail.data;
        return -1;
   }
   object getElement(){
        if(length() > 0 && getIndex() >= 0) return cur.data;
        return -1;
   }
   public boolean equals( List L){
        if( size != L.size) return false;
        Node temp = head;
        Node tempL = L.head;
        
        while( temp != null){
             if( temp.data != tempL.data) return false;
             temp = temp.next;
             tempL = tempL.next;
        }
        return true;
   }
   void clear (){
         head = null;
         tail = null;
         cur = null;
         size = 0;
   }
   void moveTo ( int i){
        if ( i >= 0 && i <= length() -1) {
              cur = head;
              if(i == 0) return;
              for( int j = 0; j<i; j++){
               //   cur = cur.next;
               moveNext();
              }
        }else {
              cur = null;
        }
   }
   void movePrev(){
           if(getIndex() == -1) return;
           if(getIndex() == 0) cur = null;
           if ( getIndex() >= 0 && getIndex() <= length() -1) cur = cur.prev;
           
   }
   void moveNext(){
          if(getIndex() == -1) return;
           if(getIndex() == length()-1) cur = null;
           if ( getIndex() >= 0 && getIndex() <= length() -1) cur = cur.next;
   }
   void prepend(object data){
            Node temp = new Node(data);
           if(length() == 0){
             head = tail = temp;   
              return;
            }           
           temp.next = head;
           head.prev = temp;
           head = head.prev;
           
   }
   void append( object data){
         Node temp = new Node(data);
           if(length() == 0){
             head = tail = temp;   
              return;
            }  
            temp.prev = tail;
            tail.next = temp;
            tail = tail.next;
   }
   void insertBefore(object data){
        if( length() > 0 && getIndex() >= 0){
            if(getIndex() == 0){
            prepend(data); 
            return;
            }
            Node temp = new Node(data);
            temp.next = cur;
            cur.prev.next = temp;
            cur.prev = temp;
        }
   }
   void insertAfter( object data){
         if( length() > 0 && getIndex() >= 0){
            if(getIndex() == length()-1){
            append(data); 
            return;
            }
            Node temp = new Node(data);
            temp.next = cur.next;
            temp.prev = cur;
            cur.next.prev = temp;
            cur.next = temp;
        }
   }
   void deleteFront(){
         if( length() < 0) return;
         if( length() == 1){
         clear();
         return;
         }
         head = head.next;
         head.prev = null;
         
   }
   void deleteBack(){
        if( length() < 0) return;
         if( length() == 1){
         clear();
         return;
         }
         tail = tail.prev;
         tail.next = null;
   }
   void delete(){
        if( length() > 0 && getIndex() >= 0){
            if( length() == 1){
              clear();
              return;
             }
             if(head == cur){
                deleteFront();
                cur = null;
                return;
             }
             if(tail == cur){
                deleteBack();
                cur = null;
                return;
             }
            if(cur.prev != null) {
                cur.prev.next = cur.next;
                cur.next.prev = cur.prev;
            }else{
                cur.next.prev = cur.prev;
                cur.prev.next = cur.next;
            }
        }
        
   }
   //other methods
   public String toString(){
        String returnString = "";
        Node transverser = head;
        while( transverser != null){
            returnString += transverser.data;
            returnString += " ";
            transverser = transverser.next;
        }
        return returnString;
   }
   List copy(){
        List L = new List();
        if( length() == 0) return L;
        Node transverser = head;
        while(transverser != null){
             L.append(transverser.data);
             transverser = transverser.next;
        }
        return L;
   }
   
   //concat
   
}
