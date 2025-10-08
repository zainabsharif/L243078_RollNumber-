#include <iostream>
#include <fstream>
#include <cstring>
#include<string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
//.............................................................
//declaration of functions
void select_category(int &cat) //incase of error in choosing
{
    cout << "Choose the category you wish to play ( Enter the number ) : " << endl;
    cout << "1. Animals " <<endl;
    cout << "2. Plants " << endl;
    cout << "3. Countries " << endl;
    cout << "4. Languages " << endl;
    cout << "5. Food " << endl;
    cout << "6. Games " << endl;
    cout << "7. Sports " << endl;
    cout << "8. Subjects " << endl;
    cout << "9. Tools " << endl;
    cout << "10. Movies " << endl;
    cout << "11. Cities " << endl;
    cout << "12. Body Parts " << endl;
    cout << "13. Animes " << endl;
    cin>> cat;
}
void start_display(int &cat)
{
    cout << "............HANGMAN............" << endl;
    cout << "Choose the category you wish to play (Enter a number from 1 to 13) : " << endl;
    cout << "1. Animals " <<endl;
    cout << "2. Plants " << endl;
    cout << "3. Countries " << endl;
    cout << "4. Languages " << endl;
    cout << "5. Food " << endl;
    cout << "6. Games " << endl;
    cout << "7. Sports " << endl;
    cout << "8. Subjects " << endl;
    cout << "9. Tools " << endl;
    cout << "10. Movies " << endl;
    cout << "11. Cities " << endl;
    cout << "12. Body Parts " << endl;
    cout << "13. Animes " << endl;
    cin>> cat;
}

string choosefile(int c)
{
    string a;
    int error=0;
    switch (c)
    {
    case 1:
        a= "animals.txt";
        break;
    case 2:
        a= "plants.txt";
        break;
    case 3:
        a= "countries.txt";
        break;
    case 4:
        a= "languages.txt";
        break;
    case 5:
        a= "food.txt";
        break;
    case 6:
        a= "games.txt";
        break;
    case 7:
        a= "sports.txt";
        break;
    case 8:
        a= "Subjects.txt";
        break;
    case 9:
        a= "tools.txt";
        break;
    case 10:
        a= "movies.txt";
        break;
    case 11:
        a= "cities.txt";
        break;
    case 12:
        a= "body_parts.txt";
        break;
    case 13:
        a= "animes.txt";
        break;
    default:
      

            cout << "Enter a number between 1 and 13 " << endl;
select_category(error);
        return choosefile(error); 
    }

    return a;
}
//this function will basically read file and store category words
string store_word(string file_name)
{
    char ch='0';
    ifstream file(file_name);
    if(!file.is_open())
    {
        cout << "Couldnt open file ";
        exit(1);
    }
    string allwords ;
    while (file.get(ch))
    {
        allwords+=ch;
    }
    file.close();
    return allwords;
}
int count_word(string allwords)
{
    int count=0 ;
    int in=0;
    while(allwords[in]!='.')
    {
        if(allwords[in] == ',')
        {
            count++;
        }
        in++;
    }
    return count ;
}
//this function stores the words in array
string * storewordinarray( int count, string &allwords  )
{
    int j=0;
    int i=0;
    string word = "null";
string * arr = new string [count];
    while(allwords[j] != '.')
    {
        if(allwords[j] != ','  )
        {
            
            word += allwords[j]; 
            j++;
           
        }

        else
        {
            arr[i] = word;
            i++;
           
            word="";
            j++;
        }

    }

    if (!word.empty() && i < count)
    {
        arr[i] = word;
    }
    return arr;
}
// this uses randomizer to choose a random word
string chooseword(string * arr , string allwords , int count ,int &index )
{

    string selected_word;
    srand(time(0));
    index = rand() % count ;
    for(int i=0 ; i < count ; i++)
    {
        if(index == i)
        {
            selected_word = arr[i];
            index=i;
        }
    }
    return selected_word;
}
// this will be the logic behind the game itself
void game(string sel_word , int count , string * arr , int index )
{
    //string filled_word= "any";
    string incorrect="";
    bool repcheck=true;
    int i=0;
    int j=0;
    string word= "";
    char letter ;
    char prev_letter='0';
    int attempt=9;
    int length =0;
    bool match = false;
    bool check=false;
    bool repeat_check= false;
    string repeat = "";
    length = strlen(sel_word.c_str()); 

    //..................delete this array here ..........................................................
    char * fill = new char [length+1];
    for ( i=0 ; i < length; i++)
    {
        fill[i] = '_';
    }
    cout << "The word to be guessed is : " << endl;
    for ( i=0 ; i < length; i++)
    {
        cout << fill[i] << " ";
    }
    cout << endl;
//........................LOGIC................................
    while( attempt >0 and match != true)
    {
        cout << "............................................." << endl ;
        cout << "Enter your guess (for space add hyphen it wont deduct attempts): " ;
        cin >> letter ;
        if (letter == '-') {
         letter = ' ';  // treat hyphen as space
}

        letter = tolower(letter);
        repeat_check = false;
        check = false;

        for (int k = 0; k < repeat.length(); k++)
        {
            if (letter == repeat[k])
            {
                repeat_check = true;
                break;
            }
        }

        if (repeat_check)
        {
            cout << "Select another letter this has already been tried" << endl;
            attempt--;
            //cout << endl;
            for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
               cout << endl << endl;
               cout << endl << "The wrong guesses are : ";


            if(incorrect != "")
            {
                cout << incorrect <<  " " << letter ;
            incorrect = incorrect +  " " +  letter ;
            }

            else if(incorrect == ""){
                incorrect = letter ;
            cout << incorrect ;
            }
            cout << endl;
            cout  << "No of attempts left " << attempt << endl;
            continue;
        }

        for (j = 0; j < length; j++)
        {
            if (letter == sel_word[j])
            {
                fill[j] = letter;
                check = true;
            }
        }

        repeat += letter;
        //.....................................................................................................
        if(check)
        {

            cout << "NICE ! Correct guess " << endl;
            for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
            cout << endl << endl;
            repcheck=true;
            cout << "The wrong guesses are : " << incorrect << endl;
        }
        else
        {
            if(letter == ' '){
                cout << "Wrong letter . Try another one :( "  << endl ;
            for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
            cout << endl ;
            }
            else {
            cout << "Wrong letter . Try another one :( " << endl  ;
            for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
            cout << endl;


            attempt --;
        }
        repcheck=false;
        cout << endl << "The wrong guesses are : ";
        if(repcheck==false){
            if(incorrect != "")
            {
                cout << incorrect <<  " " << letter ;
            incorrect = incorrect +  " " +  letter ;
            }

            else if(incorrect == ""){
                incorrect = letter ;
            cout << incorrect ;
            }
            cout << endl;
        }

        }
         cout << endl << "No of attempts left " << attempt << endl;
         for(int k=0 ; k < length  ; k++)
    {
        if( fill[k] == sel_word[k])
        {
            match = true;
        }
        else
        {
            match = false ;
            break;
        }

    }
    }

    if(match)
    {
        cout << "......................................................................" << endl;
        cout << "|                      | HURRAY ! YOU WON !!! :)|                    |" << endl;
        cout << " ................CONGRATULATIONS <3 YOU ARE A GENIUS................. " << endl;
        for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
            cout << endl;
        for ( i=0 ; i < length; i++)
        {
           cout <<"_ ";
        }
        cout << endl;

    }
    else
    {
        cout << "AW YOU LOST TRY AGAIN :(( " << endl << "ITS FINE LOSING IS PART OF LIFE " << endl;
        for ( i=0 ; i < length; i++)
            {
                if(fill[i] == ' '){
                    cout << '-' << " ";
                }
                cout << fill[i] << " ";
            }
            cout << endl;

        cout << endl << "THE CORRECT WORD WAS : " << endl;
        cout << " * " ;
        for ( i=0 ; i < length; i++)
        {
            cout << sel_word[i] << " ";
        }
        cout << " * " << endl;
    }
    delete [] fill;
    fill = nullptr;
    }

int main()
{
    int index=0;
    //............................ERROR.....................................
    //int count_word=0;
    int no_words=0;
    string filename="null" , selected_word ="null", input_word="null" , allwords="null" ;
    int attempts=0 , count=0 , category ;
    start_display(category);
    filename =  choosefile(category);
    allwords =store_word(filename);
    no_words = count_word(allwords);
    string * arr = storewordinarray(no_words , allwords);
   selected_word = chooseword( arr , allwords , no_words, index);
    game(selected_word , no_words , arr , index);
    cout << "DO you wish to try again? YES(1) OR NO (0) " << endl;
    bool flag;
    cin >> flag;
    while(flag){
        start_display(category);
        filename =  choosefile(category);
         allwords =store_word(filename);
        no_words = count_word(allwords);
       string * arr = storewordinarray(no_words , allwords);
       selected_word = chooseword( arr , allwords , no_words, index);
    game(selected_word , no_words , arr , index);
    cout << "DO you wish to try again? YES(1) OR NO (0) " ;
    bool flag;
    cin >> flag;
    }
    if(flag==0){
        cout << "AWWWW GOING AWAY SO SOON ? TIRED OF LOSING :( " << endl;
        cout << "Thank you for playing . Have a nice day BUDDY (gonna cry in a corner from losing hangman )" << endl;
    }
    return 0;
}
