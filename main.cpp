#include <iostream>
#include <string>

using namespace std;

//-PROTOTYPES----------------
// (1) add the function prototypes here to match their definitions (below)
string getUserPassword();
bool acceptedLength(string password);
bool acceptedPhrase(string password);
void displayPassword(string password);
int numberOfDigits (string password);




//---------------------------

//-MAIN PROGRAM--------------
int main()
{
    string entry; // keeps track of what the user entered
    bool isGoodLength = false; // whether it is an acceptable length
    bool isGoodWord = false; // whether it is an acceptable word
    int digits = 0;
    do
    {
       entry = getUserPassword();  
       isGoodLength = acceptedLength(entry); 
       isGoodWord = acceptedPhrase(entry);
       digits = numberOfDigits(entry);
        
       
        
    }while( !isGoodLength || !isGoodWord || digits < 2 );

    cout<<"Password ";
    displayPassword(entry);
    // (5) call the displayPassword function w/ the entry argument
    
    cout<<" has been set\n";

    return 0;
}
//----------------------------

//-FUNCTION-DEFINITIONS-------

//asks the user for their password and returns what they entered
string getUserPassword()
{
    string entered;
    cout<<"Please enter your password, between 8-20 characters: ";
    getline(cin, entered);
    return entered;
}

// receives a password and verifies whether or not it is between
// 8 and 20 characters long
bool acceptedLength(string password)
{
    int characters = password.length();

    if( characters >=8 && characters <= 20 )
    {
        return true;
    }
    else
    {  
        return false;
    } 
}

// receives a password as a string and returns whether or not it is an
// accepted word (e.g. "password" is not a valid password
bool acceptedPhrase(string password)
{
    bool acceptable;
    if( password == "password" || password == "12345678"
        || password =="123456789" || password == "qwertyuiop")
    {
        acceptable = false;
    }
    else
    {
        acceptable = true;
    } 
    return acceptable;
}

// receives a password and displays it with *'s replacing each character
void displayPassword(string password)
{
    for(int i=0; i<password.length(); i++)
    {
        cout<<"*";
    }
}

int numberOfDigits (string password)
{ 
        int numberCounter = 0;
        for(int i =0; i<password.length(); i++)
        {
                if(password[i] >='0' && password[i] <='9')
                {
                        numberCounter++;
                }
        }
        return numberCounter;
}
