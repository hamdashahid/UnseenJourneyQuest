#include<iostream>
#include<ncurses.h>
using namespace std;

struct coordinates{
    int xcor;
    int ycor;
};

struct entity{
    int xcor;
    int ycor;
    char value;

    entity(int x =0, int y=0 , char v = '\0'){
        xcor = x;
        ycor = y;
        value = v;
    }
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

    List2pointers l1;
    for (int i = 0; i < size; i++) {
        List l;
        Node* n = new Node(0, 0);
        l.append(n);
        
        for (int j = 1; j < size; j++) {
            Node* temp = new Node(0, 0);
            l.append(temp);
        }

        l1.appendList(l);
    }

    Node2pointers* temp = l1.head;
    Node* prevtrack = nullptr;
    Node* forwtrack = nullptr;

    for (int i = 0; i < size && temp != nullptr; i++) {
        Node* temp2 = (temp->list).head;

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
                temp2->left = nullptr;
                temp2->right = forwtrack;
                if (forwtrack != nullptr) {
                    forwtrack = forwtrack->next;
                }
            } else if (i < size - 1) {
                temp2->left = prevtrack;
                temp2->right = forwtrack;
                if (prevtrack != nullptr) {
                    prevtrack = prevtrack->next;
                }
                if (forwtrack != nullptr) {
                    forwtrack = forwtrack->next;
                }
            } else if (i == size - 1) {
                temp2->right = nullptr;
                temp2->left = prevtrack;
                if (prevtrack != nullptr) {
                    prevtrack = prevtrack->next;
                }
            }
            temp2->data = '.';
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    return l1;
}

class Easy{ 
    public:
        int size;
        int moves;
        int undo;
        int score;
        int distance;
        entity player;
        entity key;
        entity bomb;
        entity door;
        entity coins;
        List2pointers grid;

        Easy(int s = 0 , int m =0 , int u=0 , int sc=0){
            size = s;
            undo = u;
            score =sc;
            player = entity(34,17,'P');
            key = entity(43,7,'K');
            bomb = entity(28,14,'B');
            door = entity(46,6,'D');
            coins = entity(64,18,'C');
            grid = List2pointers();
            distance = calculateDistance();
            moves =distance;
        }

        void Display(){

            initscr();
        
            mvprintw(0,55,"Mode : EASY");
            mvprintw(1,10,"Remaining Moves: ");
            mvprintw(1,28,"%d",moves);
            mvprintw(1,40,"Remaining Undos: ");
            mvprintw(1,58,"%d",undo);
            mvprintw(1,80,"HINT: ");
            mvprintw(2,10,"Score: ");
            mvprintw(2,18,"%d" , score);
            mvprintw(2,30,"Key Status: ");
            mvprintw(2,45,"False ");
            mvprintw(3,10,"Next drop in line:  ");
            displayGrid();
            placements();
            movement();

            getch();
            endwin();
        }

        void displayGrid(){
            grid = createListzeros(size);
            grid = assignCoordinates(grid);
            // cout<<"yes\n";
            Node2pointers* temp = grid.head;
            for(int i=0 ; i<size && temp != NULL ; i++){
                Node* temp2 = (temp->list).head; 
                for(int j=0 ; j<size ; j++){
                    mvprintw((temp2->c).ycor , (temp2->c).xcor ,"%c", (temp2->data) );
                    cout<<" x : "<<(temp2->c).xcor <<" y : "<<(temp2->c).ycor;
                    temp2 = temp2->next;
                }
                cout<<endl;
                temp = temp->next;
            }
        }

        List2pointers assignCoordinates(List2pointers li){
            int x = 25 ;
            int y = 5;
            Node2pointers* temp = li.head;
            for(int i=0 ; i<size && temp != NULL ; i++){
                Node* temp2 = (temp->list).head; 
                y = 5;
                for(int j=0 ; j<size ; j++){
                    (temp2->c).xcor = x;
                    (temp2->c).ycor = y;
                    if(i==size-1 || i== 0 || j==0 || j== size-1){
                        temp2->data = '#';
                    }
                    temp2 = temp2->next;
                    y+=1.75;
                }
                temp = temp->next;
                x+=3;
                cout<<endl;
            }
            return li;
        }

        void placements(){
            // player.value = 'P';
            mvprintw(player.ycor,player.xcor,"%c",(player.value));
            mvprintw(key.ycor,key.xcor,"%c",(key.value));
            mvprintw(bomb.ycor,bomb.xcor,"%c",(bomb.value));
            // mvprintw(door.ycor,door.xcor,"%c",(door.value));
            mvprintw(coins.ycor,coins.xcor,"%c",(coins.value));
        }

        void movement() {
            keypad(stdscr, TRUE);
            cbreak();
            noecho();
            nodelay(stdscr, TRUE);  

            int ch=0;
            int d=0;
            int prev=0;
            for (int i=0;true;i++) {
                ch = getch();
                mvprintw(player.ycor,player.xcor,".");
                switch (ch) {
                    case KEY_UP:
                        if (player.ycor>6 ) {
                            if((i>0 && prev!= KEY_DOWN)||i==0){   
                                player.ycor-=1;  
                                prev = KEY_UP;
                                moves--;
                            }
                        }

                        break;

                    case KEY_DOWN:
                        if (player.ycor < size+3 ) {
                            if((i>0 && prev!= KEY_UP)||i==0){
                                player.ycor+=1; 
                                prev = KEY_DOWN;  
                                moves--;

                            }
                        }
                        break;

                    case KEY_LEFT:
                        if (player.xcor > 28) {
                            if((i>0 && prev!= KEY_RIGHT)||i==0){
                               player.xcor-=3; 
                               prev = KEY_LEFT; 
                                moves--;
                            }
                        }
                        
                        
                        break;

                    case KEY_RIGHT:
                        if (player.xcor < (size*3)+19) {
                            if((i>0 && prev!= KEY_LEFT)||i==0){
                                player.xcor+=3;  
                                prev = KEY_RIGHT;
                                moves--;
                            }
                        }
                        break;

                    case 'q': 
                    case 'Q':
                        mvprintw(0, 0, "Exiting");
                        return;
                }
                d = calculateDistance();
                mvprintw(player.ycor, player.xcor, "%c", player.value);
                mvprintw(1,28,"    ");
                mvprintw(1,28,"%d",moves);

                if(distance > d){
                    mvprintw(1,90,"                 ");
                    mvprintw(1,90,"GETTING CLOSER");
                }else{
                    mvprintw(1,90,"                  ");
                    mvprintw(1,90,"FURTHER AWAY");
                }
                refresh();
            }

    }
   
        void clearprev(){
            
            Node2pointers* temp = grid.head;
            for(int i=0 ; i<size && temp != NULL ; i++){
                Node* temp2 = (temp->list).head; 
                for(int j=0 ; j<size ; j++){
                    if(((player.xcor == (temp2->c).xcor )&& (player.ycor == (temp2->c).ycor))){
                        
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
                cout<<endl;
            }
            // return li;
        }

        int calculateDistance(){
            int x = player.xcor - key.xcor;
            int y = player.ycor - key.ycor;

            if(x<0){
                x = -1*x;
            }

            if (y<0){
                y= -1*y;
            }

            return x+y;
        }

};

int main(){
    Easy e(20);

    e.Display();


    return 0;
}