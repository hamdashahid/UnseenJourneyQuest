

// // // struct Node4pointers{
// // //     coordinates c;
// // //     Node4pointers* next;
// // //     Node4pointers* prev;
// // //     Node4pointers* up;
// // //     Node4pointers* down;

// // //     Node4pointers(int x = 0 , int y =0 , Node4pointers* n = NULL , Node4pointers* p = NULL , Node4pointers* u = NULL , Node4pointers* d = NULL ){
// // //         c.xcor = x;
// // //         c.ycor = y;
// // //         next = n;
// // //         prev = p;
// // //         up = u;
// // //         down = d;
// // //     }
// // // };



// // // class List4pointers{

// // //         Node4pointers* head;
// // //     public:

// // //         List4pointers(Node4pointers* h = NULL){
// // //             head = h;
// // //         }

// // //         void append(Node4pointers* add){
// // //             if(isEmpty() == true){
// // //                 head = new Node4pointers((head->c).xcor , (head->c).ycor);
// // //             }else{
// // //                 Node4pointers* temp = head;
// // //                 while(temp->next!= NULL){
// // //                     temp=temp->next;
// // //                 }
// // //                 temp->next = new Node4pointers((head->c).xcor , (head->c).ycor);
// // //             }
// // //         }

// // //         void removefromLast(){
// // //             if(isEmpty() == true){
// // //                 return;
// // //             }else{
// // //                 Node4pointers* temp = head;
// // //                 while(temp->next!=NULL){
// // //                     temp = temp->next;
// // //                 }
// // //                 Node4pointers* temp2 = temp;
// // //                 temp->next = NULL;
// // //                 delete temp;
// // //             }
// // //         }

// // //         bool isEmpty(){
// // //             if(head == NULL){
// // //                 return true;
// // //             }
// // //             return false;
// // //         }

// // //         Node4pointers* getHead(){
// // //             return head;
// // //         }

// // // };


// // #include <iostream>
// // #include <ncurses.h>

// // using namespace std;

// // struct coordinates {
// //     int xcor;
// //     int ycor;
// // };

// // struct Node {
// //     coordinates c;
// //     Node* next;
// //     Node* prev;
// //     Node* left;
// //     Node* right;
// //     char data;

// //     Node(int x = 0, int y = 0, Node* n = nullptr, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr, char d = '\0')
// //         : c{x, y}, next(n), prev(p), left(l), right(r), data(d) {}
// // };

// // class List {
// // public:
// //     Node* head;

// //     List(Node* h = nullptr) : head(h) {}

// //     void append(Node* add) {
// //         if (isEmpty()) {
// //             head = new Node(add->c.xcor, add->c.ycor, nullptr, nullptr, nullptr, nullptr, add->data);
// //         } else {
// //             Node* temp = head;
// //             while (temp->next != nullptr) {
// //                 temp = temp->next;
// //             }
// //             temp->next = new Node(add->c.xcor, add->c.ycor, nullptr, temp, nullptr, nullptr, add->data);
// //         }
// //     }

// //     void removefromLast() {
// //         if (isEmpty()) {
// //             return;
// //         } else if (head->next == nullptr) { // Only one node
// //             delete head;
// //             head = nullptr;
// //         } else {
// //             Node* temp = head;
// //             while (temp->next->next != nullptr) {
// //                 temp = temp->next;
// //             }
// //             delete temp->next;
// //             temp->next = nullptr;
// //         }
// //     }

// //     bool isEmpty() {
// //         return head == nullptr;
// //     }

// //     Node* getHead() {
// //         return head;
// //     }
// // };

// // struct Node2pointers {
// //     coordinates c;
// //     Node2pointers* next;
// //     Node2pointers* prev;
// //     List list;

// //     Node2pointers(int x = 0, int y = 0, Node2pointers* n = nullptr, Node2pointers* p = nullptr)
// //         : c{x, y}, next(n), prev(p), list() {} // Initialize list to empty
// // };

// // class List2pointers {
// // public:
// //     Node2pointers* head;

// //     List2pointers(Node2pointers* h = nullptr) : head(h) {}

// //     void append(Node2pointers* add) {
// //         if (isEmpty()) {
// //             head = add;
// //         } else {
// //             Node2pointers* temp = head;
// //             while (temp->next != nullptr) {
// //                 temp = temp->next;
// //             }
// //             temp->next = add;
// //             add->prev = temp; // Set the previous pointer
// //         }
// //     }

// //     void removefromLast() {
// //         if (isEmpty()) {
// //             return;
// //         } else if (head->next == nullptr) {
// //             delete head;
// //             head = nullptr;
// //         } else {
// //             Node2pointers* temp = head;
// //             while (temp->next->next != nullptr) {
// //                 temp = temp->next;
// //             }
// //             delete temp->next;
// //             temp->next = nullptr;
// //         }
// //     }

// //     bool isEmpty() {
// //         return head == nullptr;
// //     }

// //     Node2pointers* getHead() {
// //         return head;
// //     }

// //     void appendList(List l) {
// //         Node2pointers* newNode = new Node2pointers();
// //         newNode->list = l;
// //         append(newNode);
// //     }
// // };

// // List2pointers createListzeros(int size) {
// //     List l;
// //     l.append(new Node(0, 0)); // Initial node
// //     for (int i = 1; i < size; i++) {
// //         l.append(new Node(0, 0));
// //     }

// //     List2pointers l1;
// //     for (int i = 0; i < size; i++) {
// //         l1.appendList(l);
// //     }

// //     return l1;
// // }

// // class Easy {
// // public:
// //     void Display() {
// //         initscr();

// //         mvprintw(0, 55, "Mode : EASY");
// //         mvprintw(1, 10, "Remaining Moves: ");
// //         mvprintw(1, 40, "Remaining Undos: ");
// //         mvprintw(2, 10, "Score: ");
// //         mvprintw(2, 30, "Key Status: ");
// //         mvprintw(3, 10, "Next drop in line:  ");

// //         displayGrid(5);

// //         getch();
// //         endwin();
// //     }

// //     void displayGrid(int size) {
// //         List2pointers grid = createListzeros(size);
// //         Node2pointers* temp = grid.head;
// //         for (int i = 0; i < size && temp != nullptr; i++) {
// //             Node* temp2 = (temp->list).head;
// //             for (int j = 0; j < size && temp2 != nullptr; j++) {
// //                 mvprintw(temp2->c.ycor, temp2->c.xcor, "%c", temp2->data);
// //                 temp2 = temp2->next;
// //             }
// //             temp = temp->next;
// //         }
// //     }
// // };

// // int main() {
// //     Easy e;
// //     e.Display();
// //     return 0;
// // }



// //         // void clearprev(){
            
// //         //     Node2pointers* temp = grid.head;
// //         //     for(int i=0 ; i<size && temp != NULL ; i++){
// //         //         Node* temp2 = (temp->list).head; 
// //         //         for(int j=0 ; j<size ; j++){
// //         //             if(((player.xcor == (temp2->c).xcor )&& (player.ycor == (temp2->c).ycor))){
                        
// //         //             }
// //         //             temp2 = temp2->next;
// //         //         }
// //         //         temp = temp->next;
// //         //         cout<<endl;
// //         //     }
// //         //     // return li;
// //         // }


// #include <iostream>
// using namespace std;

// // Define the stNode structure
// struct stNode {
//     int data;
//     stNode* next;

//     stNode(int d) : data(d), next(NULL) {}
// };

// // Stack class exactly as provided
// class Stack {
// public:
//     stNode* top;

//     Stack(stNode* t = NULL) {
//         top = t;
//     }

//     void push(stNode* add) {
//         if (isEmpty()) {
//             top = add;
//         } else {
//             add->next = top;
//             top = add;
//         }
//     }

//     stNode* pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty, cannot pop!" << endl;
//             return NULL;
//         }
//         stNode* temp = top;
//         top = top->next;
//         return temp;
//     }

//     bool isEmpty() {
//         return top == NULL;
//     }
// };

// // Main function to demonstrate the stack usage
// int main() {
//     Stack s;

//     // Push elements onto the stack
//     s.push(new stNode(10));
//     s.push(new stNode(20));
//     s.push(new stNode(30));

//     cout << "Popping elements from the stack:" << endl;

//     // Pop and print elements from the stack
//     while (!s.isEmpty()) {
//         stNode* poppedNode = s.pop();
//         if (poppedNode) {
//             cout << "Popped: " << poppedNode->data << endl;
//             delete poppedNode; // Free the memory of the popped node
//         }
//     }

//     // Try to pop from an empty stack
//     s.pop();

//     return 0;
// }

#include <ncurses.h>

int main() {
    // Initialize the screen
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);  // Enable function keys

    // Create two custom windows (screens)
    WINDOW *screen1 = newwin(LINES, COLS, 0, 0);  // Full window 1
    WINDOW *screen2 = newwin(LINES, COLS, 0, 0);  // Full window 2

    // Add content to Screen 1
    mvwprintw(screen1, 50, 50, "This is Screen 1. Press '2' to switch to Screen 2.");
    
    // Add content to Screen 2
    mvwprintw(screen2, 1, 1, "This is Screen 2. Press '1' to switch to Screen 1.");
    
    // Show Screen 1 initially
    wrefresh(screen1);

    int ch;
    while ((ch = getch()) != 'q') {  // Press 'q' to quit
        switch (ch) {
            case '1':
                // Switch to Screen 1
                wclear(screen2);  // Optional: Clear Screen 2
                wrefresh(screen1);  // Refresh Screen 1
                break;
            case '2':
                // Switch to Screen 2
                wclear(screen1);  // Optional: Clear Screen 1
                wrefresh(screen2);  // Refresh Screen 2
                break;
            case 'm':
                // Switch to standard screen and use mvprintw
                clear();  // Clear standard screen
                mvprintw(1, 1, "This is the standard screen. Press '1' or '2' to switch.");
                refresh();  // Refresh standard screen
                break;
        }
    }

    // Clean up
    delwin(screen1);
    delwin(screen2);
    endwin();  // End ncurses mode
    return 0;
}
