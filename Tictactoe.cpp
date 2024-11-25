/*
 Coded by Parth Pandya
 Problem statement:- 
 I have coded a terminal based tic tac toe game 
 */

#include <iostream> //header files
#include <stdbool.h>
#include <cstdlib>
#include <string>
using namespace std;

bool isValidindex(int index) //function to check if the index is valid
{
    if (index >= 1 && index <= 9)
    {
        return true;
    }
    return false;
}

bool isUsed(string A[3][3], int index) //function to check if the index is already used
{
    int i = (index - 1)/3; 
    int j = (index - 1)%3;
    
    if (A[i][j] == "X" || A[i][j] == "O")
    {
        return true;
    }
    return false;
}

bool playerwin(string A[3][3], string data) //function to check if any player has won the game
{
    if (A[0][0] == data && A[0][1] == data && A[0][2] == data) 
    {
        return true;
    }
    
    else if (A[1][0] == data && A[1][1] == data && A[1][2] == data)
    {
        return true;
    }
    
    else if (A[2][0] == data && A[2][1] == data && A[2][2] == data)
    {
        return true;
    }
    
    else if (A[0][0] == data && A[1][0] == data && A[2][0] == data)
    {
        return true;
    }
    else if (A[0][1] == data && A[1][1] == data && A[2][1] == data)
    {
        return true;
    }
    else if (A[0][2] == data && A[1][2] == data && A[2][2] == data)
    {
        return true;
    }
    else if (A[0][0] == data && A[1][1] == data && A[2][2] == data)
    {
        return true;
    }
    else if (A[0][2] == data && A[1][1] == data && A[2][0] == data)
    {
        return true;
    }
    return false;
}

void addtopos(string A[3][3],int index,string data) //funtion to add the value at index choosen by user
{
    int i = (index - 1)/3;
    int j = (index - 1)%3;
    
    A[i][j] = data;
}

void display(string A[3][3]) //function to display the tictactoe board
{
    system("cls"); //used to clear terminal on windows during run time , i used this for easier understanong of user
    for (int i = 0;i<3;i++)
    {
        for (int j = 0;j<3;j++)
        {
            cout<<"| "<<A[i][j]<<" ";
        }
        cout<<"|";
        cout<<"\n|---|---|---|"<<endl;
    }
}

int main()
{
    int check = 0,index,c=0,d=0; //the basics for inputs and checking 
    static int count = 0;
    string A[3][3] = {
        { "1", "2", "3" },
        { "4", "5", "6" },
        { "7", "8", "9" }
    };
    
    string name1,name2;
    string data1 = "X",data2 = "O";
    
    cout<<"Hello user this is a terminal based tic tac toe game"<<endl;
    cout<<"\nEnter the name of 1st Player (he/she will play as (X))"<<endl;
    getline(cin,name1);
    
    cout<<"Enter the name of 2nd Player (he/she will play as (O))"<<endl;
    getline(cin,name2);
    
    string turn = data1;
    cout<<"\n\n"<<name1<<" will play as "<<data1<<endl;
    cout<<name2<<" will play as "<<data2<<"\n\n"<<endl;
    
    cout<<"\nFor the users to enter (X and O),the board has 9 boxes which has indexes from 1 to 9, just select the index at which you want insert when its your turn\n"<<endl;
    
    do
    {
        if(playerwin(A,data1)) //will execute if player 1 win
        {
            cout<<endl;
            display(A);
            cout<<"\nCongratulations "<<name1<<" you have won the game!!!"<<endl;
            break;
        }
        else if(playerwin(A,data2)) //will execute if player2 win
        {
            cout<<endl;
            display(A);
            cout<<"\nCongratulations "<<name2<<" you have won the game!!!"<<endl;
            
            break;
        }
        else //if no one has won this will execute
        {
            if (turn == data1) //will execute if 1st players turn
            {
                cout<<endl;
                display(A);
                cout<<"\n"<<name1<<" enter the index at which you want to place "<<data1<<endl;
                cin>>index;
                while (c != 1)
                {
                    if(isValidindex(index))
                    {
                        if(isUsed(A,index))
                        {
                            cout<<"\nThis index has already been used you can only place at non-used index"<<endl;
                            cin>>index;
                            c = 0;
                        }
                        else
                        {
                            addtopos(A,index,data1);
                            count++;
                            turn = data2;
                            c = 1;
                        }
                    }
                    else
                    {
                        cout<<"\nPlease enter a valid index between 1 to 9"<<endl;
                        cin>>index;
                        c = 0;
                    }
                }
                c = 0;
                continue;
            }
            else // will execute if second players turn
            {
                cout<<endl;
                display(A);
                cout<<"\n"<<name2<<" enter the index at which you want to place "<<data2<<endl;
                cin>>index;
                while (d != 1)
                {
                    if(isValidindex(index))
                    {
                        if(isUsed(A,index))
                        {
                            cout<<"\nThis index has already been used you can only place at non-used index"<<endl;
                            cin>>index;
                            d = 0;
                        }
                        else
                        {
                            addtopos(A,index,data2);
                            count++;
                            turn = data1;
                            d = 1;
                        }
                    }
                    else
                    {
                        cout<<"\nPlease enter a valid index between 1 to 9"<<endl;
                        cin>>index;
                        d = 0;
                    }
                }
                d = 0;
                continue;
            }
        }
    }while (count != 9); 
    
    if(count == 9) //if a draw has occured
    {
        cout<<endl;
        display(A);
        cout<<"\nThe game is a draw..."<<endl;
    }
    
    return 0;
}// Thank You my Friend
