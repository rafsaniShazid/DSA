template<typename T>
// struct Node
// {
//     T data;
//     Node* next;
//     Node(const T& val): data(val),next(NULL){}
// };
// template<class T>
// class LinkedList{
//     Node<T>* head;
// public:
//     LinkedList(): head(NULL){}
//     ~LinkedList(){}
//     void insertFront(const T& val)
//     {
//         Node<T>* p= new Node<T>(val);
//         p->next=head;
//         head=p;
//     }
//     void insertEnd(const T& val){
//         Node<T>* ptr=new Node<T>(val);
//         Node<T>* p;
//         p=head;
//         while(p->next!=NULL)
//         {
//             p=p->next;
//         }
//         p->next=ptr;
//         ptr->next=NULL;    
//     }
//     void insertAtposition(int pos,const T& val){
//         Node<T>* newNode= new Node<T>(val);
//         Node<T>* p=head;
//         for(int i=0;i<pos-1;i++){
//             p=p->next;
//         }
//         newNode->next=p->next;
//         p->next=newNode;
//     }
//     bool search(const T& val)const{
//         Node<T>* p=head;
//         while(p!=NULL){
//             if(p->data==val) return true;
//             p=p->next;
//         }
//         return false;
//     }
//     void display( )const {
//         Node<T>* p=head;
//         while(p!=NULL){
//             cout<<p->data<<endl;
//             p=p->next;
//         }
//     }
//     int getLength()const{
//         Node<T>* p=head;
//         int count=0;
//         while(p!=NULL){
//             count++;
//             p=p->next;
//         }
//         return count;        
//     }
// };