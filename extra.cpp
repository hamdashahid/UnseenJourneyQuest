

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


#include <iostream>
#include <ncurses.h>

using namespace std;

struct coordinates {
    int xcor;
    int ycor;
};

struct Node {
    coordinates c;
    Node* next;
    Node* prev;
    Node* left;
    Node* right;
    char data;

    Node(int x = 0, int y = 0, Node* n = nullptr, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr, char d = '\0')
        : c{x, y}, next(n), prev(p), left(l), right(r), data(d) {}
};

class List {
public:
    Node* head;

    List(Node* h = nullptr) : head(h) {}

    void append(Node* add) {
        if (isEmpty()) {
            head = new Node(add->c.xcor, add->c.ycor, nullptr, nullptr, nullptr, nullptr, add->data);
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(add->c.xcor, add->c.ycor, nullptr, temp, nullptr, nullptr, add->data);
        }
    }

    void removefromLast() {
        if (isEmpty()) {
            return;
        } else if (head->next == nullptr) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    Node* getHead() {
        return head;
    }
};

struct Node2pointers {
    coordinates c;
    Node2pointers* next;
    Node2pointers* prev;
    List list;

    Node2pointers(int x = 0, int y = 0, Node2pointers* n = nullptr, Node2pointers* p = nullptr)
        : c{x, y}, next(n), prev(p), list() {} // Initialize list to empty
};

class List2pointers {
public:
    Node2pointers* head;

    List2pointers(Node2pointers* h = nullptr) : head(h) {}

    void append(Node2pointers* add) {
        if (isEmpty()) {
            head = add;
        } else {
            Node2pointers* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = add;
            add->prev = temp; // Set the previous pointer
        }
    }

    void removefromLast() {
        if (isEmpty()) {
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node2pointers* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    Node2pointers* getHead() {
        return head;
    }

    void appendList(List l) {
        Node2pointers* newNode = new Node2pointers();
        newNode->list = l;
        append(newNode);
    }
};

List2pointers createListzeros(int size) {
    List l;
    l.append(new Node(0, 0)); // Initial node
    for (int i = 1; i < size; i++) {
        l.append(new Node(0, 0));
    }

    List2pointers l1;
    for (int i = 0; i < size; i++) {
        l1.appendList(l);
    }

    return l1;
}

class Easy {
public:
    void Display() {
        initscr();

        mvprintw(0, 55, "Mode : EASY");
        mvprintw(1, 10, "Remaining Moves: ");
        mvprintw(1, 40, "Remaining Undos: ");
        mvprintw(2, 10, "Score: ");
        mvprintw(2, 30, "Key Status: ");
        mvprintw(3, 10, "Next drop in line:  ");

        displayGrid(5);

        getch();
        endwin();
    }

    void displayGrid(int size) {
        List2pointers grid = createListzeros(size);
        Node2pointers* temp = grid.head;
        for (int i = 0; i < size && temp != nullptr; i++) {
            Node* temp2 = (temp->list).head;
            for (int j = 0; j < size && temp2 != nullptr; j++) {
                mvprintw(temp2->c.ycor, temp2->c.xcor, "%c", temp2->data);
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
};

int main() {
    Easy e;
    e.Display();
    return 0;
}
