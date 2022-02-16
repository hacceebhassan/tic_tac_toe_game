#include <iostream>
 
using namespace std;
 
 
char square[9] = { '1','2','3','4','5','6','7','8','9' };
 
 
 
void Introduction()
{
    cout << "\t\t\t\t\t" << "*********************************************" << endl;
    cout << "\t\t\t\t\t" << "*                                           *" << endl;
    cout << "\t\t\t\t\t" << "*      WELCOME TO TIC-TAC-TOE GAME !!       *" << endl;
    cout << "\t\t\t\t\t" << "*                                           *" << endl;
    cout << "\t\t\t\t\t" << "*********************************************" << endl;
    cout << endl;
    cout << "RULES: ";
    cout << "The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner." << endl;
    cout << endl << endl;
    cout << "Lets begin the game";
    cout << endl << endl;
}
 
int checkwin()
{
    if (square[0] == square[1] && square[1] == square[2])
    {
        if (square[0] == 'X')
            return 1;
        else
            return 2;
    }
    else
    {
        if (square[3] == square[4] && square[4] == square[5])
        {
            if (square[3] == 'X')
                return 1;
            else
                return 2;
        }
        else
        {
            if (square[6] == square[7] && square[7] == square[8])
            {
                if (square[6] == 'X')
                    return 1;
                else
                    return 2;
            }
            else
            {
                if (square[0] == square[3] && square[3] == square[6])
                {
                    if (square[0] == 'X')
                        return 1;
                    else
                        return 2;
                }
                else
                {
                    if (square[1] == square[4] && square[4] == square[7])
                    {
                        if (square[1] == 'X')
                            return 1;
                        else
                            return 2;
                    }
                    else
                    {
                        if (square[2] == square[5] && square[5] == square[8])
                        {
                            if (square[2] == 'X')
                                return 1;
                            else
                                return 2;
                        }
                        else
                        {
                            if (square[0] == square[4] && square[4] == square[8])
                            {
                                if (square[0] == 'X')
                                    return 1;
                                else
                                    return 2;
                            }
                            else
                            {
                                if (square[2] == square[4] && square[4] == square[6])
                                {
                                    if (square[2] == 'X')
                                        return 1;
                                    else
                                        return 2;
                                }
                                else
                                {
                                    if (square[0] == square[3] && square[3] == square[6])
                                    {
                                        if (square[0] == 'X')
                                            return 1;
                                        else
                                            return 2;
                                    }
                                    else
                                        return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
 
bool mark(int player, int box)
{
    bool IsSuccess = false;
    if (box >= 1)
    {
        box--;
    }
    if (square[box] == 'X' || square[box] == 'Y')
    {
        cout << "Please enter a different location" << endl;
        IsSuccess = false;
    }
    else
    {
        if (player == 1)
        {
            square[box] = 'X';
        }
        else
        {
            square[box] = 'Y';
        }
        IsSuccess = true;
    }
    return IsSuccess;
}
 
void display()
{
    cout << endl;
 
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
            cout << " " << "\t" << "|" << "\t" << "|" << endl; //Border
            cout << "    " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 1:
            cout << "   " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 2:
            cout << "   " << square[i];
            break;
        case 3:
            cout << endl;
            cout << " " << "_______" << "|" << "_______" << "|" << "_______" << endl; //Splitter
            cout << " " << "\t" << "|" << "\t" << "|" << endl; //Border
            cout << "    " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 4:
            cout << "   " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 5:
            cout << "   " << square[i];
            break;
        case 6:
            cout << endl;
            cout << " " << "_______" << "|" << "_______" << "|" << "_______" << endl; //Splitter
            cout << " " << "\t" << "|" << "\t" << "|" << endl; //Border
            cout << "    " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 7:
            cout << "   " << square[i];
            cout << " " << "\t" << "|";
            break;
        case 8:
            cout << "   " << square[i];
            cout << endl;
            cout << " " << "\t" << "|" << "\t" << "|" << endl; //Border
            break;
        }
    }
    cout << endl;
}
int main()
{
    int player1 = 1, player2 = 2;
 
    int box, result = 0, flag = 0;
 
    bool IsSuccess;
 
    Introduction();
 
    display();
    for (int i = 1; i < 5; i++)
    {
        cout << "PLAYER " << player1 << "(x) Enter location: ";
        cin >> box;
        IsSuccess = mark(player1, box);
        if (IsSuccess)
        {
            display();
        }
        else
        {
            do
            {
                display();
                cout << "PLAYER " << player1 << "(x) Enter location: ";
                cin >> box;
            } while (mark(player1, box) == false);
            display();
        }
        
        result = checkwin();
        if (result == 1)
        {
            cout << "Congratualtions! player " << player1 << " has Won ";
            flag = 1;
            break;
        }
        else
        {
            if (result == 2)
            {
                cout << "Congratualtions! player " << player2 << " has Won ";
                flag = 1;
                break;
            }
        }
        cout << "PLAYER " << player2 << "(y) Enter location: ";
        cin >> box;
        IsSuccess = mark(player2, box);
        if (IsSuccess)
        {
            display();
        }
        else
        {
            do
            {
                display();
                cout << "PLAYER " << player2 << "(y) Enter location: ";
                cin >> box;
            } while (mark(player2, box) == false);
            display();
        }
        result = checkwin();
        if (result == 1)
        {
            cout << "Congratualtions! player " << player1 << " has Won ";
            flag = 1;
            break;
        }
        else
        {
            if (result == 2)
            {
                cout << "\n Congratualtions! player " << player2 << " has Won ";
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Sorry, The game is a draw ";
    }
    return 0;
}