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
                head = new Node((head->c).xcor , (head->c).ycor , NULL,NULL,NULL,NULL,add->data);
            }else{
                Node* temp = head;
                while(temp->next!= NULL){
                    temp=temp->next;
                }
                temp->next = new Node((head->c).xcor , (head->c).ycor,NULL,temp,NULL,NULL,add->data);
            }
        }

        void removefromLast(){
            if(isEmpty() == true){
                return;
            }else{
                Node* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                Node* temp2 = temp;
                temp->next = NULL;
                delete temp;
            }
        }

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

    Node2pointers(int x =0 , int y=0 , Node2pointers* n = NULL , Node2pointers* p = NULL , List l = NULL  ){
        c.xcor = x;
        c.ycor = y;
        next = n;
        prev = p;
        list = l;
    }
};

class List2pointers{
    public:
    Node2pointers* head;

        List2pointers(Node2pointers* h = NULL){
            head = h;
        }

        void append(Node2pointers* add){
            if(isEmpty() == true){
                head = new Node2pointers((head->c).xcor , (head->c).ycor);
            }else{
                Node2pointers* temp = head;
                while(temp->next!= NULL){
                    temp=temp->next;
                }
                temp->next = new Node2pointers((head->c).xcor , (head->c).ycor);
            }
        }

        void removefromLast(){
            if(isEmpty() == true){
                return;
            }else{
                Node2pointers* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                Node2pointers* temp2 = temp;
                temp->next = NULL;
                delete temp;
            }
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        Node2pointers* getHead(){
            return head;
        }

        

};

List2pointers createListzeros(int size){
    List l;
    l.head = new Node(0,0);
    for (int i=1 ; i<size ; i++){
        Node* temp = new Node(0,0);
        l.append(temp);
    }
    List2pointers l1;
    l1.head = new Node2pointers(0,0,NULL,NULL,l);
    for (int i=1 ; i<size; i++){
        Node2pointers* temp = new Node2pointers(0,0,NULL,NULL,l);
        l1.append(temp);
    }

    Node2pointers*temp= l1.head; 
    Node* prevtrack ;
    Node* forwtrack ;
    for (int i=0 ; i<size ; i++){
        Node* temp2 = (temp->list).head;
        if(i>0 && i<size-1){
            prevtrack = ((temp->prev)->list).head;
            forwtrack = ((temp->next)->list).head;
        }else if(i==0){
            forwtrack = ((temp->next)->list).head;
        }else if(i== size-1){
            prevtrack = ((temp->prev)->list).head;
        }
        for(int j=0 ; j<size; j++){
            if(i==0){
                temp2->left = NULL;
                temp2->right = forwtrack;
                forwtrack = forwtrack->next;
            }else if(i<size-1){
                temp2->left = prevtrack;
                temp2->right = forwtrack;
                prevtrack = prevtrack->next;
                forwtrack = forwtrack->next;
            }else if (i == size-1){
                temp2->right = NULL;
                temp2->prev = prevtrack;
                prevtrack = prevtrack->next;
            }
            temp2->data = '.';
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    return l1;
}

class Grid{
    List2pointers grid;
    int size;

    public:

        Grid(int s){
            size = s;
        }

        void DisplayGrid(){
            grid = createListzeros(size);

            
            //grid to be created
        }    


};



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

            displayGrid(20);

            getch();
            endwin();
        }

        void displayGrid(int size){
            List2pointers grid = createListzeros(size);
            Node2pointers* temp = grid.head;
            for(int i=0 ; i<size ; i++){
                Node* temp2 = (temp->list).head; 
                for(int j=0 ; j<size ; j++){
                    mvprintw((temp2->c).xcor , (temp2->c).ycor , &(temp2->data) );
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

