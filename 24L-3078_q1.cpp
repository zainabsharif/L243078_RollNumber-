#include <iostream>
 #include <string>
using namespace std;

void inputwords(string * array , int elements ){
    cout << "Enter the words for palindrome check : ";
    for(int i=0 ; i < elements ; i++){
       cin >> array[i];
       
    }
    
}
void checkpalindrome(string * array , int elements){
    bool flag=0;
    
    string checkword;
    int z=0;
    cout << "...............PALINDROME OR NOT..................\n";
    for(int i=0 ; i < elements ; i++){
        checkword = array[i];
        z=checkword.size() -1;
        for(int j=0 ; j< checkword.size()/2 ; j++ ){
            
            if(checkword[j] == checkword[z--] ){
                flag = true;
            }
            else {
                flag=false;
                break;
            }
        }
        cout << endl;
        if(flag){
            cout << "The word **  " << checkword << " ** is a palindrome :) \n ";
        }
        else {
            cout << "The word ** " << checkword << " ** is NOT a palindrome :( \n ";
        }
    }
}


int main(){
    int input =0 ; 
    int elements =0 ; 
    cout << "Enter the option you want to select : \n 1)Check the palindrome \n 2)Exit the program \n";
    cin >> input;
while(input != 2 ){

cout << "Enter the number of words you want to check as palindrome : ";
cin >> elements ;
string * array = new string [elements];
inputwords(array , elements);
checkpalindrome(array , elements);
cout << endl << "................................................." << endl;

 cout << "Enter the option you want to select : \n 1)Check the palindrome \n 2)Exit the program \n";
 cin >> input;
}
cout  << ".........................................................." << endl;
cout << " Thank you for using the palindrome checker . GOOD BYE !!! ";
return 0 ; 

}