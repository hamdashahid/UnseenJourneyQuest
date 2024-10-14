#include<iostream>
#include<ctime>
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
    // entity coins;

    // Node2pointers(List l ){
    //     list = l;
    //     c.xcor = 0;
    //     c.ycor = 0;
    //     next = NULL;
    //     prev = NULL;
    // }

    Node2pointers(int x = 0, int y = 0, Node2pointers* n = nullptr, Node2pointers* p = nullptr){
        c.xcor = x;
        c.ycor = y;
        next = n;
        prev = p;
        list = List();
        // coins = entity();
    }
        // : c{x, y}, next(n), prev(p), list() {} // Initialize list to empty

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

struct stNode{
    stNode* next;
    int move;

    stNode(int m = 0 , stNode* n = NULL){
        move = m;
        next = n;
    }
};

class Stack{
    public:

        stNode* top;

        Stack(stNode* t = NULL){
            top = t;
        }

        void push(stNode* add){
            if(isEmpty()){
                top = add;
            }else{
                add->next = top;
                top = add;
            }
        }

        int pop(){
            stNode* temp = top;
            top = top->next;
            int m = temp->move;
            delete temp;
            return m;
        }

        bool isEmpty(){
            return top==NULL;
        }

};


class GAME{ 
    public:
        int size;
        int moves;
        int Totalmoves;
        int undo;
        int Totalundo;
        int score;
        int distance;
        int disDoor;
        bool keystatus;
        bool doorstatus;
        bool loss ;
        bool win ;
        int MODE;
        entity player;
        entity Initialplayer;
        entity key;
        entity bomb;
        entity door;
        entity coins1;
        // entity Initialcoins1;
        // entity Initialcoins2;
        entity coins2;
        // entity Initialcoins3;
        entity coins3;
        List2pointers grid;
        List2pointers CoinCollection;
        Stack Rec_moves;

        GAME(int s = 0 , int u=0 ,int m = 0){
            size = s;
            undo = u;
            score =0;
            keystatus = false;
            win = false;
            loss = false;
            disDoor = 0;
            player = entity(1000,1000,'P');
            key = entity(1000,1000,'K');
            bomb = entity(1200,1200,'B');
            door = entity(1300,1300,'D');
            coins1 = entity(1400,1400,'C');
            coins2 = entity(1500,1500,'C');
            coins3 = entity(1600,1600,'C');
            grid = List2pointers();
            distance = calculateDistance('k');
            moves =calcMoves()+m;
            Rec_moves = Stack();
            doorstatus = false;
            Totalmoves = moves;
            Totalundo = undo;
        }

        void Display(){

            initscr();
            MenuScreen();
            
            refresh();
            // GAME SCREEN

            GameOverScreen();
            getch();
            endwin();
        }

        void MenuScreen(){
            
            keypad(stdscr, TRUE);
            cbreak();
            noecho();
            // nodelay(stdscr, TRUE);  
            mvprintw(3,5,"<====================================== UNSEEN  JOURNEY  QUEST =====================================>");
            mvprintw(5,35,"<================== MENU ======================>");
            mvprintw(10,50,"1. EASY");
            mvprintw(12,50,"2. MEDIUM");
            mvprintw(14,50,"3. DIFFICULT");

            while (true){
                int ch = getch();

                if(ch == 49){
                    size = 10;
                    undo = 6;
                    MODE = 1;
                    GameScreen(1);
                    break;
                }else if(ch == 50){
                    size = 15;
                    undo = 4;
                    MODE = 2;
                    GameScreen(2);
                    break;
                }else if(ch == 51){
                    size = 20;
                    undo = 1;
                    MODE = 3;
                    GameScreen(3);
                    break;
                }else if(ch == 27){
                    return;
                }

            }

        }

        void GameScreen(int mode = 0){
            // mvprintw(5,50,"                ");
            clear();
            refresh();
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
            // mvprintw(3,10,"Next drop in line:  ");
            mvprintw(3,80,"Press {U or u} to UNDO the move ");
            mvprintw(4,80,"Press {esc} to EXIT the game ");
            displayGrid();
            placements();
            Coins();
            Initialplayer = player;
            // Initialcoins1 = entity(coins1.xcor,coins1.ycor,coins1.value);
            // Initialcoins2 = entity(coins2.xcor,coins2.ycor,coins2.value);
            // Initialcoins3 = entity(coins3.xcor,coins3.ycor,coins3.value);
            switch(mode){
                case 1:
                    movement(1);

                    break;
                case 2:
                    movement(2);

                    break;
                case 3:
                    movement(3);

                    break;        

            }
            // GameOverScreen();

        }

        void GameOverScreen(){ 
            clear();
            refresh();
            mvprintw(1,5,"<====================================== UNSEEN  JOURNEY  QUEST =====================================>");
            displayGrid();
            if(win == true){
                mvprintw(2,30,"<=========== :) YOU WON THE GAME !!!!! :)==============>");
            }else {
                mvprintw(2,30,"<=========== :( YOU LOST THE GAME !!!!! :( ==============>");
            }
            // mvprintw(5,45,"GAME OVER");
            mvprintw(3,50,"Mode :  ");
            switch(MODE){
                case 1:
                    mvprintw(3,55,"EASY");
                    break;
                case 2:
                    mvprintw(3,55,"MEDIUM");
                    break;
                case 3:
                    mvprintw(3,55,"DIFFICULT");
                    break;        
            }
            mvprintw(3,5,"Score :  ");
            mvprintw(3,15,"%d",score);
            mvprintw(6,85,"COINS COLLECTED AT : ");
            Node2pointers* temp = CoinCollection.head;
            int x = 85;
            int y = 7;
            while(temp!=NULL){
                
                mvprintw(y,x-1 ,"(" );
                mvprintw(y,x ,"%d" , (temp->c).xcor );
                mvprintw(y,x+2 ,"," );
                x+=3;
                mvprintw(y,x ,"%d" , (temp->c).ycor );
                mvprintw(y,x+2 , ")" );
                y++;
                x=85;
                mvprintw((temp->c).ycor,(temp->c).xcor,"  ");
                mvprintw((temp->c).ycor,(temp->c).xcor,"C");
                temp = temp->next;
            }
            y++;
            mvprintw(y,85,"Initial Key Position : ");
            mvprintw(y,109,"(");
            mvprintw(y,110,"%d",key.xcor);
            mvprintw(y,112,",");
            mvprintw(y,113,"%d",key.ycor);
            mvprintw(y,115,")");

            mvprintw(y+2,85,"Initial Door Position : ");
            mvprintw(y+2,109,"(");
            mvprintw(y+2,110,"%d",door.xcor);
            mvprintw(y+2,112,",");
            mvprintw(y+2,113,"%d",door.ycor);
            mvprintw(y+2,115,")");


            mvprintw(y+4,85,"LEFT OVER MOVES : ");
            mvprintw(y+4,105,"%d",moves);

            mvprintw(y+6,85,"LEFT OVER UNDOS : ");
            mvprintw(y+6,105,"%d",undo);

            mvprintw(4 , 30 , "THIS WAS THE INITIAL STATE OF GRID : ");
            
            mvprintw(Initialplayer.ycor,Initialplayer.xcor,"%c",(Initialplayer.value));
            mvprintw(key.ycor,key.xcor,"%c",(key.value));
            mvprintw(bomb.ycor,bomb.xcor,"%c",(bomb.value));
            mvprintw(door.ycor,door.xcor,"%c",(door.value));
            // mvprintw(Initialcoins1.ycor,Initialcoins1.xcor,"%c",(Initialcoins1.value));
            // mvprintw(Initialcoins2.ycor,Initialcoins2.xcor,"%c",(Initialcoins2.value));
            // mvprintw(Initialcoins3.ycor,Initialcoins3.xcor,"%c",(Initialcoins3.value));

            while(true){
                int ch = getch();
                if(ch == 27){
                    return;
                }
            }

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
                    // cout<<" x : "<<(temp2->c).xcor <<" y : "<<(temp2->c).ycor;
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
                    y+=1;
                }
                temp = temp->next;
                x+=3;
                // cout<<endl;
            }
            return li;
        }

        void placements(){
            player.xcor = 28 + ((rand() % (size-2)) * 3);
            player.ycor = 6 + (rand() % (size-2));
            while(true){
                key.xcor = 28 + ((rand() % size-3)*3) ;
                key.ycor = 6 + (rand() % size-2);
                if(key.xcor != player.xcor && key.ycor != player.ycor)  {
                   break;
                }
            }
            while(true){
                bomb.xcor = 28 + ((rand() % (size-2)) * 3);
                bomb.ycor = 6 + (rand() % (size-2));
                if((bomb.xcor != player.xcor && bomb.ycor != player.ycor) &&
                    (bomb.xcor != key.xcor && bomb.ycor != key.ycor))  {
                   break;
                }
            }
            while(true){
                door.xcor = 28 + ((rand() % (size-2)) * 3);
                door.ycor = 6 + (rand() % (size-2));
                if((door.xcor != player.xcor && door.ycor != player.ycor) &&
                    (door.xcor != key.xcor && door.ycor != key.ycor)&&
                    (door.xcor != bomb.xcor && door.ycor != bomb.ycor))  {
                   break;
                }
            }
            mvprintw(player.ycor,player.xcor,"%c",(player.value));
            // mvprintw(key.ycor,key.xcor,"%c",(key.value));
            // mvprintw(bomb.ycor,bomb.xcor,"%c",(bomb.value));
            // mvprintw(door.ycor,door.xcor,"%c",(door.value));
            // mvprintw(coins1.ycor,coins1.xcor,"%c",(coins1.value));
        }

        void movement(int mode = 0) {
            keypad(stdscr, TRUE);
            cbreak();
            noecho();
            nodelay(stdscr, TRUE);  

            bool keyfound = false;
            int doordistance=0;
            int ch=0;
            int d=distance;
            int prev=0;

            // Initialcoins1.xcor = ;
            // Initialcoins1.ycor = coins1.ycor;
            // Initialcoins1.value = coins1.value;
            // Initialcoins2.xcor = coins2.xcor;
            // Initialcoins2.ycor = coins2.ycor;
            // Initialcoins2.value = coins2.value;
            // Initialcoins3.xcor = coins3.xcor;
            // Initialcoins3.ycor = coins3.ycor;
            // Initialcoins3.value = coins3.value;
            switch(mode){
                case 1:
                    moves =calcMoves()+6;
                    mvprintw(0,55,"               ");
                    mvprintw(0,55,"Mode : EASY");
                    break;
                case 2:
                    mvprintw(0,55,"               ");
                    mvprintw(0,55,"Mode : MEDIUM");                
                    moves =calcMoves()+2;
                    break;
                case 3:
                    mvprintw(0,55,"               ");
                    mvprintw(0,55,"Mode : DIFFICULT");
                    moves =calcMoves()+6;
                    break;        
            }
            for (int i=0;true;i++) {
                ch = getch();
                
                mvprintw(player.ycor,player.xcor,".");
                switch (ch) {
                    case KEY_UP:
                        if (player.ycor>6 ) {
                            if((i>0 && prev!= KEY_DOWN)||i==0){   
                                player.ycor-=1;  
                                prev = KEY_UP;
                                stNode* n = new stNode(KEY_UP);
                                Rec_moves.push(n);
                                moves--;
                                distance = d;
                                disDoor = doordistance;
                            }
                        }

                        break;

                    case KEY_DOWN:
                        if (player.ycor < size+3 ) {
                            if((i>0 && prev!= KEY_UP)||i==0){
                                player.ycor+=1; 
                                prev = KEY_DOWN;  
                                stNode* n = new stNode(KEY_DOWN);
                                Rec_moves.push(n);
                                moves--;
                                distance = d;
                                disDoor = doordistance;
                            }
                        }
                        break;

                    case KEY_LEFT:
                        if (player.xcor > 28) {
                            if((i>0 && prev!= KEY_RIGHT)||i==0){
                               player.xcor-=3; 
                               prev = KEY_LEFT; 
                               stNode* n = new stNode(KEY_LEFT);
                                Rec_moves.push(n);
                                moves--;
                                distance = d;
                                disDoor = doordistance;
                            }
                        }
                        
                        
                        break;

                    case KEY_RIGHT:
                        if (player.xcor < (size*3)+19) {
                            if((i>0 && prev!= KEY_LEFT)||i==0){
                                player.xcor+=3;  
                                prev = KEY_RIGHT;
                                stNode* n = new stNode(KEY_RIGHT);
                                Rec_moves.push(n);
                                moves--;
                                distance = d;
                                disDoor = doordistance;
                            }
                        }
                        break;

                    case 'U':
                    case 'u':
                        UndoMove();
                        distance = d;
                        break;    
                    case 27: 
                        mvprintw(0, 0, "Exiting");
                        return;
                }
                
                if(player.xcor == key.xcor && player.ycor == key.ycor){
                    keystatus =true;
                    mvprintw(2,45,"True ");
                    keyfound = true;
                    disDoor = calculateDistance('d');
                    doordistance = disDoor;
                }
                mvprintw(player.ycor, player.xcor, "%c", player.value);
                mvprintw(1,28,"    ");
                mvprintw(1,28,"%d",moves);
                if(keystatus == false){
                    d = calculateDistance('k');
                    if(distance > d){
                        mvprintw(1,90,"                 ");
                        mvprintw(1,90,"GETTING CLOSER");
                    }else{
                        mvprintw(1,90,"                  ");
                        mvprintw(1,90,"FURTHER AWAY");
                    }
                }else{
                    doordistance = calculateDistance('d');
                     if(disDoor > doordistance){
                        mvprintw(1,90,"                 ");
                        mvprintw(1,90,"GETTING CLOSER");
                    }else{
                        mvprintw(1,90,"                  ");
                        mvprintw(1,90,"FURTHER AWAY");
                    }
                }
                if(i%5000000 == 0){
                    Coins();
                }
                if(player.xcor == door.xcor && player.ycor == door.ycor && keystatus == true){
                    doorstatus = true;
                    // ReachedDoor();
                }
                CoinFound();
                if(GameOver() == true){
                    return;
                }

                refresh();
            }

        }

        bool UndoMove(){
            if(Rec_moves.isEmpty() ){
                return false;
            }
            switch(Rec_moves.pop()){
                case KEY_UP:
                    if (player.ycor < size+3 ) {
                        player.ycor+=1; 
                    }
                    break;
                case KEY_DOWN:
                    if (player.ycor>6 ) {
                        player.ycor-=1;  
                    }
                    break;
                case KEY_LEFT:
                    if (player.xcor < (size*3)+19) {
                        player.xcor+=3;  
                    }
                    break;
                case KEY_RIGHT:
                    if (player.xcor > 28) {
                        player.xcor-=3; 
                    }
                    break;            
            }
            undo--;
            mvprintw(1,58,"       ");
            mvprintw(1,58,"%d",undo);
            refresh();
            return true;
        }

        int calculateDistance(char k){
            int x1 = 0  , y1=0;
            if(k == 'k'){
                x1 = player.xcor - key.xcor;
                y1 = player.ycor - key.ycor;
            
                x1 = x1<0? -1*x1 : x1;
                y1 = y1<0? -1*y1 : y1;
            }else if(k == 'd'){
                x1 = player.xcor - door.xcor;
                y1 = player.ycor - door.ycor;
            
                x1 = x1<0? -1*x1 : x1;
                y1 = y1<0? -1*y1 : y1;
            }

            return x1+y1;
        }

        int calcMoves(){
            int x1 = player.xcor - key.xcor;
            int y1 = player.ycor - key.ycor;
            int x2 = player.xcor - door.xcor;
            int y2 = player.ycor - door.ycor;
            int x3 = key.xcor - door.xcor;
            int y3 = key.ycor - key.ycor;

            x1 = x1<0? -1*x1 : x1;
            x2 = x2<0? -1*x2 : x2;
            x3 = x3<0? -1*x3 : x3;
            y1 = y1<0? -1*y1 : y1;
            y2 = y2<0? -1*y2 : y2;
            y3 = y3<0? -1*y3 : y3;

            return x1+x2+x3+y1+y2+y3;
        }

        void Coins(){
            mvprintw(coins1.ycor,coins1.xcor,".");
            mvprintw(coins2.ycor,coins2.xcor,".");
            mvprintw(coins3.ycor,coins3.xcor,".");
            coins1.value = 'C';
            coins2.value = 'C';
            coins3.value = 'C';
            while(true){
                coins1.xcor = 28 + ((rand() % (size-2)) * 3);
                coins1.ycor = 6 + (rand() % (size-2));
                if((coins1.xcor != player.xcor && coins1.ycor != player.ycor)&&
                    (coins1.xcor != bomb.xcor && coins1.ycor != bomb.ycor)&&
                    (coins1.xcor != key.xcor && coins1.ycor != key.ycor) && 
                    (coins1.xcor != door.xcor && coins1.ycor != door.ycor)){
                        break;
                    }

            }
             while(true){
                coins2.xcor = 28 + ((rand() % (size-2)) * 3);
                coins2.ycor =6 + (rand() % (size-2));
                if((coins2.xcor != player.xcor && coins2.ycor != player.ycor)&&
                    (coins2.xcor != bomb.xcor && coins2.ycor != bomb.ycor)&&
                    (coins2.xcor != key.xcor && coins2.ycor != key.ycor) && 
                    (coins2.xcor != door.xcor && coins2.ycor != door.ycor)&&
                    (coins2.xcor != coins1.xcor && coins2.ycor != coins1.ycor)){
                        break;
                    }

            }

            while(true){
                coins3.xcor = 28 + ((rand() % (size-2)) * 3);
                coins3.ycor = 6 + (rand() % (size-2));
                if((coins3.xcor != player.xcor && coins3.ycor != player.ycor)&&
                    (coins3.xcor != bomb.xcor && coins3.ycor != bomb.ycor)&&
                    (coins3.xcor != key.xcor && coins3.ycor != key.ycor) && 
                    (coins3.xcor != door.xcor && coins3.ycor != door.ycor)&&
                    (coins3.xcor != coins1.xcor && coins3.ycor != coins1.ycor)&&
                    (coins3.xcor != coins2.xcor && coins3.ycor != coins2.ycor)){
                        break;
                    }

            }
            mvprintw(coins1.ycor,coins1.xcor,"C");
            mvprintw(coins2.ycor,coins2.xcor,"C");
            mvprintw(coins3.ycor,coins3.xcor,"C");
        }

        void CoinFound(){
            if(player.xcor == coins1.xcor && player.ycor == coins1.ycor){
                mvprintw(coins1.ycor,coins1.xcor,".");
                score+=2;
                undo++;
                Node2pointers* n = new Node2pointers(player.xcor , player.ycor);
                CoinCollection.append(n);
                coins1.xcor =1000;
                coins1.ycor = 1000;
            }
            if(player.xcor == coins2.xcor && player.ycor == coins2.ycor){
                mvprintw(coins2.ycor,coins2.xcor,".");
                score+=2;
                undo++;
                Node2pointers* n = new Node2pointers(player.xcor , player.ycor);
                CoinCollection.append(n);
                coins2.xcor =1000;
                coins2.ycor = 1000;
            }
            if(player.xcor == coins3.xcor && player.ycor == coins3.ycor){
                mvprintw(coins3.ycor,coins3.xcor,".");
                score+=2;
                undo++;
                Node2pointers* n = new Node2pointers(player.xcor , player.ycor);
                CoinCollection.append(n);
                coins3.xcor =1000;
                coins3.ycor = 1000;
            }
            mvprintw(2,18,"     ");
            mvprintw(2,18,"%d" , score);
            mvprintw(1,58,"       ");
            mvprintw(1,58,"%d",undo);                                      

        }

        bool GameOver(){
           
            if (player.xcor == bomb.xcor && player.ycor == bomb.ycor){
                loss = true;
            }
            if(moves == 0 && doorstatus == false){
                loss = true;
            }
            if(moves>0 && doorstatus == true){
                win = true;
            }
            if (win == false && loss == false){
                return false;
            }

            if(win == true){
                score+=moves;
            }
            
            return true;
            
        }

};

int main(){
    GAME e;

    e.Display();

    return 0;
}