#include <iostream>
#include <cctype>
using namespace std ; 

void displayboard(char  (&box) [3][3]){
    cout << "-----------------------" << endl;
    for(int i=0 ; i < 3 ; i++){
        cout << "| " ;
        for(int j=0 ; j < 3 ; j++){
            if(box[i][j] == 'N'){
                cout << " _ " << " ";
            }
            else {
                cout <<" " << box[i][j] << "  " ;
            }
        }
        cout << " |" << endl; 
    }
    cout << "-----------------------";
    cout << endl;
}

void gametictactoe(char (&box)[3][3]){
    char playerone;
    int r=0 , c = 0 ; 
    char playertwo;
    bool flag=false;
     cout << "Choose if player one wants to be X OR O : ";
        cin >> playerone;
        playerone = toupper(playerone); // normalize input to uppercase

        if(playerone == 'X'){
            playertwo = 'O' ;
        }
        else if (playerone == 'O') {
            playertwo = 'X';
        }
        else {
           
            while (playerone != 'X' && playerone != 'O'){
                cout << "Enter a valid option either X or O \n ";
                cin >> playerone;
                playerone = toupper(playerone);
            }
            if(playerone == 'X'){
                playertwo = 'O' ;
            }
            else {
                playertwo = 'X';
            }
        }


    while (flag != true ){
       
        cout << "Player 1 enter the location row and column where you want your symbol ";
        cin >> r >> c;
        if((r >= 0 and r < 3 ) and ( c >= 0 and c < 3 )){
            if(box[r][c] == 'N'){
                box[r][c] = playerone;
            }
            else {
            
                while( (r < 0 or r > 2 or c < 0 or c > 2) or (box[r][c] != 'N') ){
                    cout << "The place is full or invalid. Enter a valid position: ";
                    cin >> r >> c;
                }
                box[r][c] = playerone;
            }
        }
        else {
          
            while( r < 0 or r > 2 or c < 0 or c > 2 ){
                cout << "Enter a valid range please (0..2 0..2): ";
                cin >> r >> c;
            }
            if(box[r][c] == 'N'){
                box[r][c] = playerone;
            }
            else {
                while( (r < 0 or r > 2 or c < 0 or c > 2) or (box[r][c] != 'N') ){
                    cout << "The place is full or invalid. Enter a valid position (0..2 0..2): ";
                    cin >> r >> c;
                }
                box[r][c] = playerone;
            }
        }
        displayboard(box);

      
        if(r==0 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])   // row 0
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c])   // col 0
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c+1] && box[r][c]==box[r+2][c+2]) ) { 
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r==1 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])   // row 1
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r+1][c]) ) { // col 0
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r==2 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])   // row 2
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c])   // col 0
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c+1] && box[r][c]==box[r-2][c+2]) ) { //anti diagonal
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 0 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])   // row 0
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c]) ) { // col 1
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 1 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])   // row 1
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r+1][c])   // col 1
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c-1] && box[r][c]==box[r+1][c+1])  // main diag 
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c+1] && box[r][c]==box[r+1][c-1]) ) { // anti-diag 
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 2 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])   // row 2
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c]) ) { // col 1
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 0 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])   // row 0
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c])   // col 2
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c-1] && box[r][c]==box[r+2][c-2]) ) { // main diag
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 1 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])   // row 1
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r-1][c]) ) { // col 2
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }
        else if(r== 2 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])   // row 2
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c])   // col 2
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c-1] && box[r][c]==box[r-2][c-2]) ) { // main diag 
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 1  *WON* \n ";
                break;
            }
        }

        cout << endl ;
        ///...............................PLAYER 2 ...............................................................

        cout << "Player 2  enter the location row and column where you want your symbol ";
        cin >> r >> c;
        if((r >= 0 and r < 3 ) and ( c >= 0 and c < 3 )){
            if(box[r][c] == 'N'){
                box[r][c] = playertwo;
            }
            else {
                while( (r < 0 or r > 2 or c < 0 or c > 2) or (box[r][c] != 'N') ){
                    cout << "The place is full or invalid. Enter a valid position (0..2 0..2): ";
                    cin >> r >> c;
                }
                box[r][c] = playertwo;
            }
        }
        else {
            while( r < 0 or r > 2 or c < 0 or c > 2 ){
                cout << "Enter a valid range please : ";
                cin >> r >> c;
            }
            if(box[r][c] == 'N'){
                box[r][c] = playertwo;
            }
            else {
                while( (r < 0 or r > 2 or c < 0 or c > 2) or (box[r][c] != 'N') ){
                    cout << "The place is full or invalid. Enter a valid position : ";
                    cin >> r >> c;
                }
                box[r][c] = playertwo;
            }
        }
        displayboard(box);

    
        if(r==0 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c+1] && box[r][c]==box[r+2][c+2]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r==1 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r+1][c]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r==2 and c==0){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c+1] && box[r][c]==box[r][c+2])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c+1] && box[r][c]==box[r-2][c+2]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 0 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 1 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r+1][c])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c-1] && box[r][c]==box[r+1][c+1])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c+1] && box[r][c]==box[r+1][c-1]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 2 and c==1 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c+1])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 0 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r+2][c])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c-1] && box[r][c]==box[r+2][c-2]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 1 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])
             || (box[r][c] != 'N' && box[r][c]==box[r+1][c] && box[r][c]==box[r-1][c]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
        else if(r== 2 and c== 2 ){
            if( (box[r][c] != 'N' && box[r][c]==box[r][c-1] && box[r][c]==box[r][c-2])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c] && box[r][c]==box[r-2][c])
             || (box[r][c] != 'N' && box[r][c]==box[r-1][c-1] && box[r][c]==box[r-2][c-2]) ){
                flag = true; 
                displayboard(box);
                cout << "Congratulations!  Player 2  *WON* \n ";
                break;
            }
        }
    }
}

int main(){
    int row=0 , col =0 ;
    char tictacbox[3][3] = {
        {'N','N','N'},
        {'N','N','N'},
        {'N','N','N'}
    }; 

    displayboard(tictacbox);
    gametictactoe(tictacbox);
    return 0;
}
