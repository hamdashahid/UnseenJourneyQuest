

// struct Node4pointers{
//     coordinates c;
//     Node4pointers* next;
//     Node4pointers* prev;
//     Node4pointers* up;
//     Node4pointers* down;

//     Node4pointers(int x = 0 , int y =0 , Node4pointers* n = NULL , Node4pointers* p = NULL , Node4pointers* u = NULL , Node4pointers* d = NULL ){
//         c.xcor = x;
//         c.ycor = y;
//         next = n;
//         prev = p;
//         up = u;
//         down = d;
//     }
// };



// class List4pointers{

//         Node4pointers* head;
//     public:

//         List4pointers(Node4pointers* h = NULL){
//             head = h;
//         }

//         void append(Node4pointers* add){
//             if(isEmpty() == true){
//                 head = new Node4pointers((head->c).xcor , (head->c).ycor);
//             }else{
//                 Node4pointers* temp = head;
//                 while(temp->next!= NULL){
//                     temp=temp->next;
//                 }
//                 temp->next = new Node4pointers((head->c).xcor , (head->c).ycor);
//             }
//         }

//         void removefromLast(){
//             if(isEmpty() == true){
//                 return;
//             }else{
//                 Node4pointers* temp = head;
//                 while(temp->next!=NULL){
//                     temp = temp->next;
//                 }
//                 Node4pointers* temp2 = temp;
//                 temp->next = NULL;
//                 delete temp;
//             }
//         }

//         bool isEmpty(){
//             if(head == NULL){
//                 return true;
//             }
//             return false;
//         }

//         Node4pointers* getHead(){
//             return head;
//         }

// };