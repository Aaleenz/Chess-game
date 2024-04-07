#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
void movesdisplayr(int board_row, int board_col);
void movesdisplayb(int board_row, int board_col);
void movesdisplayk(int board_row, int board_col);
void movesdisplayq(int board_row, int board_col);
void movesdisplayn(int board_row, int board_col);
bool captureking(char board[8][8], int& i, int& j);
char board[8][8];
using namespace std;
void possibledisplayr(int board_row, int board_col, char board[8][8]) // displaying possible moves for rock
{
    cout << "Possible positions of Rock are \n";
    for (int initail_variable = board_row; initail_variable < board_row + 1; initail_variable++)
    {
        for (int initial_col = 1; initial_col <= 8; initial_col++)
        {
            cout << " [" << initail_variable << "," << initial_col << "]";
        }
    }

    for (int initail_variable = 1; initail_variable <= 8; initail_variable++)
    {
        for (int initial_col = board_col; initial_col < board_col + 1; initial_col++)
        {

            cout << " [" << initail_variable << "," << initial_col << "]";
        }
    }

    cout << endl;
}
void possibledisplayk(int board_row, int board_col) // displaying possible moves for king
{
    cout << "Possible positions of king are \n";
    for (int initail_variable = board_row - 1; initail_variable < board_row; initail_variable++)
    {

        for (int initial_col = board_col - 1; initial_col <= board_col + 1; initial_col++)
        {
            if ((initail_variable > 8 || initial_col > 8) || (initail_variable < 1 || initial_col < 1))
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }
    for (int initail_variable = board_row; initail_variable < board_row + 1; initail_variable++)
    {
        for (int initial_col = board_col - 1; initial_col <= board_col + 1; initial_col++)
        {
            if ((initail_variable > 8 || initail_variable < 1) || (initial_col > 8) || (initial_col < 1))
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }
    for (int initail_variable = board_row + 1; initail_variable < board_row + 2; initail_variable++)
    {

        for (int initial_col = board_col - 1; initial_col <= board_col + 1; initial_col++)
        {
            if ((initail_variable > 8 || initail_variable < 1) || (initial_col > 8) || (initial_col < 1))
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }

    cout << endl;
}
void possibledisplayb(int board_row, int board_col) // displaying possible mves for bishop
{

    // Check all four diagonal directions
    cout << "Possible moves for bishop at position (" << board_row << ", " << board_col << "):" << endl;
    int initail_variable = 1;
    while (initail_variable < 8)
    {
        int direction = 1;
        while (direction <= 4)
        {

            switch (direction)
            {
            case 1: // Top-right
                if ((board_row + initail_variable < 8) && (board_col + initail_variable < 8))
                {
                    cout << "(" << board_row + initail_variable << ", " << board_col + initail_variable << ")" << endl;
                }
                break;
            case 2: // Top-left
                if (board_row + initail_variable < 8 && board_col - initail_variable > 0)
                {
                    cout << "(" << board_row + initail_variable << ", " << board_col - initail_variable << ")" << endl;
                }
                break;
            case 3: // Bottom-right
                if (board_row - initail_variable > 0 && board_col + initail_variable < 8)
                {
                    cout << "(" << board_row - initail_variable << ", " << board_col + initail_variable << ")" << endl;
                }
                break;
            case 4: // Bottom-left
                if (board_row - initail_variable > 0 && board_col - initail_variable > 0)
                {
                    cout << "(" << board_row - initail_variable << ", " << board_col - initail_variable << ")" << endl;
                }
                break;
            }
            direction++;
        }
        initail_variable++;
    }
}
void possibledisplayq(int board_row, int board_col)
{
    cout << "Possible positions of Rock are \n";
    for (int initail_variable = board_row; initail_variable < board_row + 1; initail_variable++)
    {
        for (int initial_col = 1; initial_col <= 8; initial_col++)
        {

            cout << " [" << initail_variable << "," << initial_col << "]";
        }
    }
    for (int initail_variable = 1; initail_variable <= 8; initail_variable++)
    {
        for (int initial_col = board_col; initial_col < board_col + 1; initial_col++)
        {

            cout << " [" << initail_variable << "," << initial_col << "]";
        }
    }

    int initail_variable = 1;
    while (initail_variable < 8)
    {
        int direction = 1;
        while (direction <= 4)
        {

            switch (direction)
            {
            case 1: // Top-right
                if ((board_row + initail_variable < 8) && (board_col + initail_variable < 8))
                {
                    cout << "(" << board_row + initail_variable << ", " << board_col + initail_variable << ")" << endl;
                }
                break;
            case 2: // Top-left
                if (board_row + initail_variable < 8 && board_col - initail_variable > 0)
                {
                    cout << "(" << board_row + initail_variable << ", " << board_col - initail_variable << ")" << endl;
                }
                break;
            case 3: // Bottom-right
                if (board_row - initail_variable > 0 && board_col + initail_variable < 8)
                {
                    cout << "(" << board_row - initail_variable << ", " << board_col + initail_variable << ")" << endl;
                }
                break;
            case 4: // Bottom-left
                if (board_row - initail_variable > 0 && board_col - initail_variable > 0)
                {
                    cout << "(" << board_row - initail_variable << ", " << board_col - initail_variable << ")" << endl;
                }
                break;
            }
            direction++;
        }
        initail_variable++;
    }
}
void possibledisplayn(int board_row, int board_col)
{
    cout << "possible positions of knight are:\n";
    int initail_variable, initial_col;

    initail_variable = board_row - 2;
    while (initail_variable < board_row - 1)
    {
        initial_col = board_col - 1;
        while (initial_col < board_col)
        {
            if (initail_variable < 1 || initial_col < 1 || initail_variable > 8 || initial_col > 8)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            initial_col++;
        }
        initail_variable++;
    }

    initail_variable = board_row - 2;
    while (initail_variable < board_row - 1)
    {
        initial_col = board_col + 1;
        while (initial_col < board_col + 2)
        {
            if (initail_variable < 1 || initial_col < 1 || initail_variable > 8 || initial_col > 8)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            initial_col++;
        }
        initail_variable++;
    }

    initail_variable = board_row - 1;
    while (initail_variable < board_row)
    {
        initial_col = board_col - 2;
        while (initial_col < board_col - 1)
        {
            if (initail_variable < 1 || initial_col < 1 || initail_variable > 8 || initial_col > 8)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            initial_col++;
        }
        initail_variable++;
    }

    initail_variable = board_row - 1;
    while (initail_variable < board_row)
    {
        initial_col = board_col + 2;
        while (initial_col < board_col + 3)
        {
            if (initail_variable > 8 || initial_col > 8 || initail_variable < 1 || initial_col < 1)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            initial_col++;
        }
        initail_variable++;
    }

    initail_variable = board_row + 1;
    while (initail_variable < board_row + 2)
    {
        initial_col = board_col - 2;
        while (initial_col < board_col + 1)
        {
            if (initail_variable > 8 || initial_col > 8 || initial_col < 1 || initail_variable < 1)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            initial_col++;
        }
        initail_variable++;
    }
    for (int initail_variable = board_row + 1; initail_variable < board_row + 2; initail_variable++)
    {
        for (int initial_col = board_col + 2; initial_col < board_col + 3; initial_col++)
        {
            if (initail_variable > 8 || initial_col > 8 || initail_variable < 1 || initial_col < 1)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }
    for (int initail_variable = board_row + 2; initail_variable < board_row + 3; initail_variable++)
    {
        for (int initial_col = board_col - 1; initial_col < board_col; initial_col++)
        {
            if (initail_variable > 8 || initial_col > 8 || initail_variable < 1 || initial_col < 1)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }
    for (int initail_variable = board_row + 2; initail_variable < board_row + 3; initail_variable++)
    {
        for (int initial_col = board_col + 1; initial_col < board_col + 2; initial_col++)
        {
            if (initail_variable > 8 || initial_col > 8 || initail_variable < 1 || initial_col < 1)
            {
                break;
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
            else
            {
                cout << " [" << initail_variable << "," << initial_col << "]";
            }
        }
    }
    cout << endl;
}


void print_board(char board[][8], int size) // printing board through 2D array
{

    cout << "  ";
    for (int initail_variable = 0; initail_variable < size; initail_variable++)
        cout << " " << initail_variable + 1 << "  ";
    cout << endl;
    for (int row = 0; row < size; row++)
    {
        // Draw the top line
        cout << " +";
        for (int column = 0; column < size; column++)
            cout << "---+";
        cout << endl;
        // Draw the squares
        cout << row + 1 << "|";
        for (int column = 0; column < size; column++)
            cout << " " << board[row][column] << " |";
        cout << row + 1 << endl;
    }
    // Draw the bottom line

    cout << " +";
    for (int column = 0; column < size; column++)
        cout << "---+";
    cout << endl;
    cout << "  ";
    for (int initail_variable = 0; initail_variable < size; initail_variable++)
        cout << " " << initail_variable + 1 << "  ";
    cout << endl;

    // callling second fucntion to move pieces
}
int move_pieces(char board[][8], int size) // fucntion for moving peices
{
    if ('k' == 'K')
    {
        return 0;
    }
    
    else
    {
        int board_row, board_col, to_row, to_col;
        char piece;
        int choice;
        int i,
             j;
        cout << "if you want to conitune the game press 1\n";
        cout << "if you want to quit the game press 0 \n";
        cin >> choice;
        if (choice == 0)
        {
            cout << "you quit the game\n";
            return 0;
        }
        else if (choice == 1)
        {
            goto r;
        }
        
        r:
        cout << "YOUR TURN" << endl;
        cout << "enter which piece you want to move:\n";
        cout << "Rook=r" << endl;
        cout << "king=k" << endl;
        cout << "queen=q" << endl;
        cout << "knight=n" << endl;
        cout << "bishop=b" << endl;
        
        cin >> piece;
        if (piece >= 65 && piece <= 90)
        {
            cout << "invalid selection" << endl;
            goto r;
        }
        else 
        {

            cout << "Enter the row  of the piece to move : \n";
            cin >> board_row;
            cout << "Enter the column  of the piece to move : \n";
            cin >> board_col;
            if (piece == 'r')
            {
                movesdisplayr(board_row, board_col);
            }
            if (piece == 'k')
            {
                movesdisplayk(board_row, board_col);
            }
            if (piece == 'b')
            {
                movesdisplayb(board_row, board_col);
            }
            if (piece == 'q')
            {
                movesdisplayq(board_row, board_col);
            }
            if (piece == 'n')
            {
                movesdisplayn(board_row, board_col);
            }

        q:
            cout << "Enter the row  to move the piece to : \n";

            cin >> to_row;
            cout << "Enter the column to move the piece to : \n";
            cin >> to_col;

            if (board[to_row - 1][to_col - 1] == 32)
            {
                board[to_row - 1][to_col - 1] = board[board_row - 1][board_col - 1];

                board[board_row - 1][board_col - 1] = ' ';
                print_board(board, size);
            }
            else if ((board[to_row - 1][to_col - 1] >= 65) && (board[to_row - 1][to_col - 1] <= 'Z') && (board[to_row - 1][to_col - 1] != 'K'))
            {
                board[to_row - 1][to_col - 1] = board[board_row - 1][board_col - 1];

                board[board_row - 1][board_col - 1] = ' ';
                print_board(board, size);
            }
            else if ((board[to_row - 1][to_col - 1] == 'K'))
            {
                cout << "you are the winner\n";
                return 0;
            }
            else
            {
                cout << "invalid move\n";
                goto q;
            }
        }
    z:
        cout << "OPPONENTS TURN" << endl;
        cout << "enter which piece you want to move:\n";
        cout << "Rook=R" << endl;
        cout << "king=K" << endl;
        cout << "queen=Q" << endl;
        cout << "knight=N" << endl;
        cout << "bishop=B" << endl;

        cin >> piece;

        if (piece >= 97 && piece <= 122)
        {
            cout << "invalid selection" << endl;
            goto z;
        }
        else {
            cout << "Enter the row  of the piece to move : \n";
            cin >> board_row;
            cout << "Enter the column  of the piece to move : \n";
            cin >> board_col;
            if (piece == 'R')
            {
                movesdisplayr(board_row, board_col);
            }
            if (piece == 'K')
            {
                movesdisplayk(board_row, board_col);
            }
            if (piece == 'B')
            {
                movesdisplayb(board_row, board_col);
            }
            if (piece == 'Q')
            {
                movesdisplayq(board_row, board_col);
            }
            if (piece == 'N')
            {
                movesdisplayn(board_row, board_col);
            }
        a:
            cout << "Enter the row  to move the piece to : \n";
            cin >> to_row;
            cout << "Enter the column to move the piece to : \n";
            cin >> to_col;

            if (board[to_row - 1][to_col - 1] == 32)
            {
                board[to_row - 1][to_col - 1] = board[board_row - 1][board_col - 1];

                board[board_row - 1][board_col - 1] = ' ';
                print_board(board, size);
            }
            else if ((board[to_row - 1][to_col - 1] >= 97) && (board[to_row - 1][to_col - 1] <= 122) && board[to_row - 1][to_col - 1] != 'k')
            {

                board[to_row - 1][to_col - 1] = board[board_row - 1][board_col - 1];

                board[board_row - 1][board_col - 1] = ' ';
                print_board(board, size);
            }
            else if (board[to_row - 1][to_col - 1] == 'k')
            {

                cout << "Opponent is the winner\n";
                return 0;
            }
           
           


            else
            {
                cout << "invalid move\n";
                goto a;
            }
            move_pieces(board, size);
            
        }
    }
}
bool captureking(char board[8][8], int i, int j)
{
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            while (board[i][j] == 'k')
            {
                if (board[i - 1][j - 1] != 32 && board[i - 1][j - 1] >= 65 && board[i - 1][j - 1] <= 90 &&
                    board[i - 1][j] != 32 && board[i - 1][j] >= 65 && board[i - 1][j] <= 90 &&
                    board[i - 1][j + 1] != 32 && board[i - 1][j + 1] >= 65 && board[i - 1][j + 1] <= 90 &&
                    board[i][j - 1] != 32 && board[i][j - 1] >= 65 && board[i][j - 1] <= 90 &&
                    board[i][j + 1] != 32 && board[i][j + 1] >= 65 && board[i][j + 1] <= 90 &&
                    board[i + 1][j - 1] != 32 && board[i + 1][j - 1] >= 65 && board[i + 1][j - 1] <= 90 &&
                    board[i + 1][j] != 32 && board[i + 1][j] >= 65 && board[i + 1][j] <= 90 &&
                    board[i + 1][j + 1] != 32 && board[i + 1][j + 1] >= 65 && board[i + 1][j + 1] <= 90
                    ) {
                   
                    return 1;
                }
            }
        }
    }
}

void start()
{
    const int size = 8;
    char board[size][size] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'} };
    // printing board;
    print_board(board, size);
    move_pieces(board, size);
}
void movesdisplayr(int board_row, int board_col) // fucntion for displaying existing position and possible moves of rook
{
    cout << "existing position:"
        << " "
        << "[" << board_row << "," << board_col << "]" << endl;
    possibledisplayr(board_row, board_col, board);
}
void movesdisplayb(int board_row, int board_col) // fucntion for displaying existing position and possible moves of bishop
{
    cout << "existing position:"
        << " "
        << "[" << board_row << "," << board_col << "]" << endl;
    possibledisplayb(board_row, board_col);
}
void movesdisplayk(int board_row, int board_col) // fucntion for displaying existing position and possible moves of king
{
    cout << "existing position:"
        << " "
        << " [" << board_row << "," << board_col << "]" << endl;
    possibledisplayk(board_row, board_col);
}
void movesdisplayq(int board_row, int board_col) // fucntion for displaying existing position and possible moves of queen
{
    cout << "existing position:"
        << " "
        << "[" << board_row << "," << board_col << "]" << endl;
    possibledisplayq(board_row, board_col);
}
void movesdisplayn(int board_row, int board_col) // knight
{
    cout << "existing position:"
        << " "
        << "[" << board_row << "," << board_col << "]" << endl;
    possibledisplayn(board_row, board_col);
}
void main_start()
{

    cout << "Enter your name \n";
    string name = "";
    getline(cin, name);
    cout << "Press 1 to start \nPress 2 to exit\n";

    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        start();
    }
    else
        cout << "Your name is " << name << "\nYou have exited\n";
}
int main()
{

    main_start();
    return 0;
}