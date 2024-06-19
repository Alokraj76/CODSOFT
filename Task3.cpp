#include<iostream>
using namespace std;

const int n=3; // n is the size of the board
char board[n][n];
char currentPlayer;

//initialize the board with empty spaces and set the starting player
void initializeBoard()
{
    currentPlayer = 'X';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        board[i][j] = ' ';
    }
}

void printBoard() //print the current stats of the board
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j];
            if(j<n-1)
            cout<<" |";
        }
        cout<<endl;
        if(1<n-1)
        cout<<"---------"<<endl;
    }
}
bool makeMove(int row,int col) // make a move in the board if the cell is empty and within the bounds
{
    if(row>=0 and row < n and col>=0 and col<n and board[row][col]==' ')
    {
        board[row][col]=currentPlayer;
        return true;
    }
    return false;
}
bool checkWin() // check if the current player is won the game
{
    for(int i=0;i<n;i++)
    {
        if(board[i][0]==currentPlayer and board[i][1]==currentPlayer and board[i][2]==currentPlayer)
        return true;
        if(board[0][i]==currentPlayer and board[1][i] == currentPlayer and board[2][i]==currentPlayer)
        return true;
    }
    if(board[0][0]==currentPlayer and board[1][1]==currentPlayer and board[2][2]==currentPlayer)
    return true;
    if(board[0][2]==currentPlayer and board[1][1]==currentPlayer and board[2][0]==currentPlayer)
    return true;
    return false;
}

//check the board full
bool isBoardFull()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(board[i][j]==' ')
        return false;
    }
    return true;
}

//switch the current player
void switchPlayer()
{
    currentPlayer = (currentPlayer=='X')?'O':'X';
}
int main()
{
    initializeBoard();
    int row , col;
    bool gameWon=false;
    
    //main game loop
    while(!gameWon and !isBoardFull())
    {
        printBoard();
        cout<<"Player "<<currentPlayer<<" enter your move (row and column): ";
        cin>>row>>col;
        if(makeMove(row-1,col-1)) //adjust for zero based index
        {
            gameWon = checkWin();
            if(!gameWon)
            switchPlayer();
        }
        else
        {
            cout<<"Invalid move. Try again"<<endl;
        }
    }
    printBoard();
    if(gameWon)
    {
        cout<<"Player "<<currentPlayer<<" wins!"<<endl;
    }
    else
    {
        cout<<"It's a draw! "<<endl;
    }
    return 0;
}