#include<iostream>
#include<ncurses.h>
using namespace std;

struct coordinates{
    int xcor;
    int ycor;
};

struct Node{
    coordinates c;
    Node* next;
    Node* prev;
    Node* left;
    Node* right;
    char data;

    Node(int x =0 , int y =0 , Node* n = NULL , Node* p = NULL , Node* l= NULL , Node* r =NULL, char d = '\0'){
        c.xcor =x;
        c.ycor =y;
        next  = n;
        prev = p;
        left = l;
        right = r;
        data = d;
    }
    
};

class List{
    public:
    Node* head;

        List(Node* h = NULL){
            head = h;
        }

        void append(Node* add){
            if(isEmpty() == true){
                head = new Node((add->c).xcor , (add->c).ycor , NULL,NULL,NULL,NULL,add->data);
            }else{
                Node* temp = head;
                while(temp->next!= NULL){
                    temp=temp->next;
                }
                temp->next = new Node((add->c).xcor , (add->c).ycor,NULL,temp,NULL,NULL,add->data);
            }
        }

        // void removefromLast(){
        //     if(isEmpty() == true){
        //         return;
        //     }else{
        //         Node* temp = head;
        //         while(temp->next!=NULL){
        //             temp = temp->next;
        //         }
        //         Node* temp2 = temp;
        //         temp->next = NULL;
        //         delete temp;
        //     }
        // }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        Node* getHead(){
            return head;
        }

    
};

struct Node2pointers{
    coordinates c;
    Node2pointers* next;
    Node2pointers* prev;
    List list;

    // Node2pointers(List l ){
    //     list = l;
    //     c.xcor = 0;
    //     c.ycor = 0;
    //     next = NULL;
    //     prev = NULL;
    // }

    Node2pointers(int x = 0, int y = 0, Node2pointers* n = nullptr, Node2pointers* p = nullptr)
        : c{x, y}, next(n), prev(p), list() {} // Initialize list to empty

    // void setHead(List l){
    //     list = l;
    // }
};

class List2pointers{
    public:
    Node2pointers* head;

        List2pointers(Node2pointers* h = NULL){
            head = h;
        }

        void append(Node2pointers* add){
            if(isEmpty() == true){
                head = add;
            }else{
                Node2pointers* temp = head;
                while(temp->next!= NULL){
                    temp=temp->next;
                }
                temp->next = add;
                add->prev = temp;
            }
        }

        // void removefromLast(){
        //     if(isEmpty() == true){
        //         return;
        //     }else{
        //         Node2pointers* temp = head;
        //         while(temp->next!=NULL){
        //             temp = temp->next;
        //         }
        //         Node2pointers* temp2 = temp;
        //         temp->next = NULL;
        //         delete temp;
        //     }
        // }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        Node2pointers* getHead(){
            return head;
        }

        void setHead(List l){
            head->list = l;
        }

        void appendList(List l){
            if(isEmpty() == true){
                head = new Node2pointers();
                head->list = l;
            }else{
                Node2pointers* temp = head;
                while(temp->next!= NULL){
                    temp=temp->next;
                }
                temp->next = new Node2pointers();
                temp->next->list = l;
            }
        }

};

List2pointers createListzeros(int size) {
    // Step 1: Create a list with nodes initialized to (0, 0)
    List l;
    Node* n = new Node(0, 0);
    l.append(n);
    
    for (int i = 1; i < size; i++) {
        Node* temp = new Node(0, 0);
        l.append(temp);
    }

    // Step 2: Create a List2pointers and append the list to it
    List2pointers l1;
    for (int i = 0; i < size; i++) {
        l1.appendList(l);
    }

    // Step 3: Traverse and set the left and right pointers of the grid
    Node2pointers* temp = l1.head;
    Node* prevtrack = nullptr;
    Node* forwtrack = nullptr;

    std::cout << "helllooo\n\n";  // Debugging message

    for (int i = 0; i < size && temp != nullptr; i++) {
        Node* temp2 = (temp->list).head;

        // Set prevtrack and forwtrack based on the position in the grid
        if (i > 0 && i < size - 1) {
            prevtrack = (temp->prev != nullptr) ? (temp->prev->list).head : nullptr;
            forwtrack = (temp->next != nullptr) ? (temp->next->list).head : nullptr;
        } else if (i == 0) {
            forwtrack = (temp->next != nullptr) ? (temp->next->list).head : nullptr;
        } else if (i == size - 1) {
            prevtrack = (temp->prev != nullptr) ? (temp->prev->list).head : nullptr;
        }

        for (int j = 0; j < size && temp2 != nullptr; j++) {
            if (i == 0) {
                // First row: no left connections
                temp2->left = nullptr;
                temp2->right = forwtrack;
                if (forwtrack != nullptr) {
                    forwtrack = forwtrack->next;
                }
            } else if (i < size - 1) {
                // Middle rows: connect to previous and next rows
                temp2->left = prevtrack;
                temp2->right = forwtrack;
                if (prevtrack != nullptr) {
                    prevtrack = prevtrack->next;
                }
                if (forwtrack != nullptr) {
                    forwtrack = forwtrack->next;
                }
            } else if (i == size - 1) {
                // Last row: no right connections
                temp2->right = nullptr;
                temp2->left = prevtrack;
                if (prevtrack != nullptr) {
                    prevtrack = prevtrack->next;
                }
            }

            // Assign data and move to the next node in the row
            temp2->data = '.';
            temp2 = temp2->next;
        }

        // Move to the next row in the grid
        temp = temp->next;
    }

    return l1;
}

// class Grid{
//     List2pointers grid;
//     int size;

//     public:

//         Grid(int s){
//             size = s;
//         }

//         void DisplayGrid(){
//             grid = createListzeros(size);

            
//             //grid to be created
//         }    


// };

class Easy{ 
    public:

        void Display(){

            initscr();

            mvprintw(0,55,"Mode : EASY");
            mvprintw(1,10,"Remaining Moves: ");
            mvprintw(1,40,"Remaining Undos: ");
            mvprintw(2,10,"Score: ");
            mvprintw(2,30,"Key Status: ");
            mvprintw(3,10,"Next drop in line:  ");

            displayGrid(5);

            getch();
            endwin();
        }

        void displayGrid(int size){
            List2pointers grid = createListzeros(size);
            cout<<"yes\n";
            Node2pointers* temp = grid.head;
            for(int i=1 ; i<size && temp != NULL ; i++){
                Node* temp2 = (temp->list).head; 
                for(int j=1 ; j<size ; j++){
                    mvprintw((temp2->c).xcor , (temp2->c).ycor ,"%c", (temp2->data) );
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }


};

int main(){
    Easy e;

    e.Display();


    return 0;
}