////////////////////////////////////////////////////////////////
/// Author : wrench1815
/// Created On : Thu Mar 19 2020
/// File : Tic-Tac-Toe.cpp
///
///
/// Tic Tac Toe Game player vs player
///
/// One Player against another player
/// use of win32 API Cursor Controls for controlling Cursor Position
///
/////////////////////////////////////////////////////////////////////////////////////////////
#include <conio.h>    // for getchar()
#include <iostream>
#include <windows.h>    // to control the cursor position neede to include windows.h

using namespace std;

class TicTacToe {
  private:
    char Matrix[4][4];    // 4x4 used neglect 0s to make it easier to operate on Matrix

  public:
    TicTacToe();
    ~TicTacToe();
    // Method handling the Cursor Position
    // Co-ordinates taken in X and Y Axis format
    void CursorPos(short x, short y) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos       = { x, y };

        SetConsoleCursorPosition(hConsole, pos);
    }
    void DisplayMatrix();    // to display the Matrix
    void Player1Move();      // for Player 1 Move (should be in x y format starts from 1 not 0)
    void Player2Move();      // For Player 2 Move (should be in x y format starts from 1 not 0)
    int GameStatus();        // to check the winner
};

TicTacToe::TicTacToe() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            Matrix[i][j] = ' ';
        }
    }
}

TicTacToe::~TicTacToe() {}

// This will position the Matrix in a fancy way
void TicTacToe::DisplayMatrix() {
    CursorPos(41, 12);
    cout << "**Current Board**\n";

    {
        CursorPos(44, 13);
        cout << " ";
        CursorPos(45, 13);
        cout << Matrix[1][1];
        CursorPos(46, 13);
        cout << " ";
        CursorPos(47, 13);
        cout << "|";

        CursorPos(48, 13);
        cout << " ";
        CursorPos(49, 13);
        cout << Matrix[1][2];
        CursorPos(50, 13);
        cout << " ";
        CursorPos(51, 13);
        cout << "|";

        CursorPos(52, 13);
        cout << " ";
        CursorPos(53, 13);
        cout << Matrix[1][3];
        CursorPos(54, 13);
        cout << " ";
    }

    {
        CursorPos(44, 14);
        cout << "-";
        CursorPos(45, 14);
        cout << "-";
        CursorPos(46, 14);
        cout << "-";
        CursorPos(47, 14);
        cout << "|";

        CursorPos(48, 14);
        cout << "-";
        CursorPos(49, 14);
        cout << "-";
        CursorPos(50, 14);
        cout << "-";
        CursorPos(51, 14);
        cout << "|";

        CursorPos(52, 14);
        cout << "-";
        CursorPos(53, 14);
        cout << "-";
        CursorPos(54, 14);
        cout << "-";
    }

    {
        CursorPos(44, 15);
        cout << " ";
        CursorPos(45, 15);
        cout << Matrix[2][1];
        CursorPos(46, 15);
        cout << " ";
        CursorPos(47, 15);
        cout << "|";

        CursorPos(48, 15);
        cout << " ";
        CursorPos(49, 15);
        cout << Matrix[2][2];
        CursorPos(50, 15);
        cout << " ";
        CursorPos(51, 15);
        cout << "|";

        CursorPos(52, 15);
        cout << " ";
        CursorPos(53, 15);
        cout << Matrix[2][3];
        CursorPos(54, 15);
        cout << " ";
    }

    {
        CursorPos(44, 16);
        cout << "-";
        CursorPos(45, 16);
        cout << "-";
        CursorPos(46, 16);
        cout << "-";
        CursorPos(47, 16);
        cout << "|";

        CursorPos(48, 16);
        cout << "-";
        CursorPos(49, 16);
        cout << "-";
        CursorPos(50, 16);
        cout << "-";
        CursorPos(51, 16);
        cout << "|";

        CursorPos(52, 16);
        cout << "-";
        CursorPos(53, 16);
        cout << "-";
        CursorPos(54, 16);
        cout << "-";
    }

    {
        CursorPos(44, 17);
        cout << " ";
        CursorPos(45, 17);
        cout << Matrix[3][1];
        CursorPos(46, 17);
        cout << " ";
        CursorPos(47, 17);
        cout << "|";

        CursorPos(48, 17);
        cout << " ";
        CursorPos(49, 17);
        cout << Matrix[3][2];
        CursorPos(50, 17);
        cout << " ";
        CursorPos(51, 17);
        cout << "|";

        CursorPos(52, 17);
        cout << " ";
        CursorPos(53, 17);
        cout << Matrix[3][3];
        CursorPos(54, 17);
        cout << " ";
    }
}

// Player1 Logic
void TicTacToe::Player1Move() {
    int t1, t2;

P1Respawn:

    cout << "     ****Player 1****" << endl;
    cout << "Enter X Y Coordinate to Fill" << endl;
    cin >> t1 >> t2;

    if (Matrix[t1][t2] == ' ') {
        Matrix[t1][t2] = 'X';
    } else {
        cout << "Invalid Move!! Try Again\n";
        goto P1Respawn;
    }

    // Check for Draw
    int i, j;

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            if (Matrix[i][j] == ' ') {
                break;
            }
        }
        if (Matrix[i][j] == ' ') {
            break;
        }
    }

    if (i * j == 16) {    // because 0s are neglected got to check for 4x4
        CursorPos(45, 18);
        cout << "Game Draw!!\n";
        CursorPos(45, 20);
        getch();

        exit(EXIT_SUCCESS);
    }
}

// Player2 Moves, as above (Copy Paste)
void TicTacToe::Player2Move() {
    int t1, t2;

P2Respawn:

    cout << "     ****Player 2****" << endl;
    cout << "Enter X Y Coordinate to Fill" << endl;
    cin >> t1 >> t2;

    if (Matrix[t1][t2] == ' ') {
        Matrix[t1][t2] = 251;
    } else {
        cout << "Invalid Move!! Try Again\n";
        goto P2Respawn;
    }

    // Check for Draw
    int i, j;

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            if (Matrix[i][j] == ' ') {
                break;
            }
        }
        if (Matrix[i][j] == ' ') {
            break;
        }
    }

    if (i * j == 16) {    // because 0s are neglected got to check for 4x4
        CursorPos(45, 18);
        cout << "Game Draw!!\n";
        CursorPos(45, 20);
        getch();

        exit(EXIT_SUCCESS);
    }
}

// check the Game status who is winner????
int TicTacToe::GameStatus() {
    int i;

    for (i = 1; i <= 3; i++) {
        if (Matrix[i][1] == Matrix[i][2] && Matrix[i][1] == Matrix[i][3]) {
            return Matrix[i][1];
        }
    }
    for (i = 1; i <= 3; i++) {
        if (Matrix[1][i] == Matrix[2][i] && Matrix[1][i] == Matrix[3][i]) {
            return Matrix[1][i];
        }
    }

    if (Matrix[1][1] == Matrix[2][2] && Matrix[1][1] == Matrix[3][3]) {
        return Matrix[1][1];
    }

    if (Matrix[1][3] == Matrix[2][2] && Matrix[1][3] == Matrix[3][1]) {
        return Matrix[1][3];
    }

    return ' ';
}

// here starts the main()
int main() {
    TicTacToe Board;
    char Flag = ' ', Choice;    // Flag set to ' ' because it is easier to test the status this way as the default Matrix is filled with spaces
                                // so if there is another value returned by Method GameStatus(), then the winner has been found unless go on
    Board.CursorPos(30, 10);
    cout << "**This is a Game of Tic Tac Toe**" << endl;
    Board.CursorPos(27, 11);
    cout << "**Two Players will be Playing against each other**\n";
    Board.DisplayMatrix();
    Board.CursorPos(44, 18);
    cout << "Ready (y/n)";
    Board.CursorPos(49, 19);
    Choice = getchar();    // to make game a bit interactive

    // choice to play or not
    if (Choice == 'y') {

        // do while loop with required logic to run the game until winner is not found or game draws....
        do {
            system("cls");
            Board.DisplayMatrix();
            Board.CursorPos(0, 0);
            Board.Player1Move();
            Flag = Board.GameStatus();
            if (Flag != ' ') {    // if Flag gets the value other then space ' ' then the if is invoked and loop control goes o
                break;
            }
            system("cls");
            Board.DisplayMatrix();
            Board.CursorPos(0, 0);
            Board.Player2Move();
            system("cls");
            Board.DisplayMatrix();
            Flag = Board.GameStatus();

        } while (Flag == ' ');    // will run only and only if Flag has value ' '
        // if else to check the winner
        // if Flag has X then Player1 wins
        if (Flag == 'X') {
            Board.DisplayMatrix();
            Board.CursorPos(45, 18);
            cout << "Player 1 Win!!\n";
            Board.CursorPos(45, 20);
            getch();
        }
        // if Flag has 251(tick) Player2 wins
        else {
            Board.DisplayMatrix();
            Board.CursorPos(45, 18);
            cout << "Player 2 win!!\n";
            Board.CursorPos(45, 20);
            getch();
        }
    }

    else {
        exit(EXIT_SUCCESS);
    }

    return 0;
}