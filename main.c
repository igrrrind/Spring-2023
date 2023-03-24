//TODO
//Check who wins
//Write replay function, via text
//Add player's to txt file
//Calculate win/loss percentage
//

#include <stdio.h>
#include <string.h>
#define MAXN 256

void printBoard(char *a,int size);
int checkWin(int size, char board[][size], int c1, int c2);
void saveLeaderboard();
void resetBoard(int size, char board[][size], int rows, int cols);
void menu(char *choice,char name1[],char name2[]);


//MAIN GAME


int main() {
    //initialize variable
    char choice;
    int c1,c2;
    int size;
    int player = 1;
    char name1[256],name2[256];
    
    //show menu
    menu:
    
    menu(&choice,name1,name2);
    
    //switch out of menu
    
    switch(choice){
        
//Player wants to play the game
        case '1':
            //print empty board, asks user for size
            printf("How many rows and collumns shall there be? ");
            scanf("%d", &size);
            //initialize board size
            char board [size][size];
            resetBoard(size,board,size,size);
                   
            c1 = 0;
            c2 = 0;
            //CHANGE TURNS ALGORITHM
            do {
                printBoard(&board[0][0],size);
                printf("\n\nPlayer %d's turn: ",player);
                //asks for user input
                do {
                    //checks if the square already has a mark
                    scanf("%d %d",&c1,&c2);
                    if (board[c1][c2] != ' '){
                        printf("This Square is already taken!\nReinput: ");
                    }
                }while (c1 < 0 || c1 > size-1 || c2 < 0 || c2 > size - 1 || board[c1][c2] != ' ');
    
                //change mark
                board[c1][c2] = (player == 1) ? 'X' :'O';
                //switch player before looping
                player = (player == 1) ? 2 : 1;
            } while (checkWin(size,board, c1, c2) != 1);
            //print board and winner
            printBoard(&board[0][0],size);
            printf("\n%s Wins!\n\n",(player == 1)?name2:name1);
            
            while (choice =='1'){
                printf("1. Back To Main Menu.\nOthers. Watch Instant Replay.\n>>");
                scanf(" %c",&choice);
                if (choice == '1'){
                    break;
                }
            }
            goto menu;
            
            
    }
}



//FUNCTION CODES


void printBoard(char *a,int size){
    printf("=> Player 1: X, Player 2: O:\n");
    printf("     ");
    //print first row of numbers
    for (int i = 0; i < size; i++){
        if (i >= 10){
            printf("%d   ",i);
        }
        else {
            printf("%d    ",i);
        }
    }
    printf("\n");
    //print each row, in batches of 2
    for (int i = 0; i < size; i++){
        printf("   ");
        for (int j = 0; j < size; j++){
            printf("|----");
        }
        printf("|\n");
        
        //digit Check
        if (i >= 10){
            printf("%d ",i);
        }
        else {
            printf("%d  ",i);
        }
        
        
        //print box
        for (int j = 0; j < size ;j++){
            printf("| %c  ", a[i * size + j]);
        }
        printf("|\n");
    }
    printf("   ");
    for (int j = 0; j < size; j++){
        printf("|----");
        }
    printf("|\n");
}


void resetBoard(int size, char board[][size], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ' ';
        }
    }
}


void menu(char *choice,char name1[],char name2[]){
    printf("\n-----Welcome to TIC TAC TOE 10x10-----\nChoose an Option\n1. Start Games\n2. Search For Player Info\n3. Game Replays\nOthers. Quit\n>> ");
    scanf(" %c", choice);
    switch (*choice){
            //Ask for player's names
        case '1':
            printf("Player 1: ");
            scanf("%s",name1);
            printf("Player 2: ");
            scanf("%s",name2);
            
            
            
            break;
            
        case '2':
            
            
            
            
        case '3':
            
            
        default:
            printf("Quitting Program");
    }
}

int checkWin(int size, char board[][size], int c1, int c2){
    int flag = 0,mark_count = 1;
    //horizontal check
    
    
    //rightcheck
    for (int j = c2 +1; j<size; j++){
        if (board[c1][j] == ' ') {
            break;
        }
        if (board[c1][j] != board[c1][c2]) {
            flag += 1;
            break;
        }
        //edge detection
        if (j+1 == size){
            flag = 1;
        }
        mark_count++;
    }
    //leftcheck
    for (int j= c2 - 1; j>-1; j--){
        if (board[c1][j] == ' ') {
            break;
        }
        if (board[c1][j] != board[c1][c2]) {
            flag = 1;
            break;
        }
        //edge detection
        if (j-1 == size){
            flag = 1;
        }
        mark_count++;
    }
    
    //win check
    if ( (mark_count == 4 && flag == 0) || mark_count > 4 ) {
        return 1;
    }
    //reinitialize
    flag = 0;
    mark_count = 1;
    
    

    //vertical check
    //down check
    for (int i = c1 + 1 ; i <size; i++){
        if (board[i][c2] == ' ') {
            break;
        }
        if (board[i][c2] != board[c1][c2]) {
            flag = 1;
            break;
        }
        //edge detection
        if (i+1 == size){
            flag = 1;
        }
        mark_count++;
    }
    //up check
    for (int i= c1 - 1; i>-1; i--){
        if (board[i][c2] == ' ') {
            break;
        }
        if (board[i][c2] != board[c1][c2]) {
            flag = 1;
            break;
        }
        //edge detection
        if (i-1 == -1){
            flag = 1;
        }
        mark_count++;
        
    }
        
    //win check
    if ( (mark_count == 4 && flag == 0) || mark_count >4 ) {
        return 1;
    }
    //reinitialize
    flag = 0;
    mark_count = 1;
    
    //diagonal check
    //up check
    int i = c1 + 1 , j = c2 + 1;
    for (; i<size && j<size; i++, j++){
        //checks for black space
        if (board[i][j] == ' ') {
            break;
        }
        //checks for other symbol,edge
        if (board[i][j] != board[c1][c2] ) {
            flag = 1;
            break;
        }
        //edge detection
        if (i+1 == size || j+1 == size){
            flag = 1;
        }
        mark_count++;
    }
    //down check
    i = c1 - 1;
    j = c2 - 1;
    for (; i>-1 && j>-1; i--, j--){
        if (board[i][j] == ' ') {
            break;
        }
        if (board[i][j] != board[c1][c2]) {
            flag = 1;
            break;
        }
        //edge detection
        if (i-1 == -1 || j - 1 == -1){
            flag = 1;
        }
        mark_count++;
    }

    //win check
    if ( (mark_count == 4 && flag == 0) || mark_count > 4 ) {
        return 1;
    }
    //none is true
    return 0;
}
