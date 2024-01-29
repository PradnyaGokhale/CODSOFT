#include <iostream>
using namespace std;
char matrix[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char player = 'X';
void Draw()
{
    system("cls");
    cout <<" \t\tTic Tac Toe " << endl<<endl;
    cout<<"Player 1) X\n";
    cout<<"Player 2) O";
    cout << "\n"<<"\t\t\t\tBelow is the 3x3 grid: \n";
    cout<<  "     |     |      "<< "\t\t     |     |      \n";
    cout << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << " "<< "\t\t  1  |  2  |  3   \n";
    cout << "_____|_____|_____ "<< "\t\t_____|_____|_____ \n";
    cout << "     |     |      "<< "\t\t     |     |      \n";
    cout << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << " "<< "\t\t  4  |  5  |  6   \n";
    cout << "_____|_____|_____ "<< "\t\t_____|_____|_____ \n";
    cout << "     |     |      "<<"\t\t     |     |      \n";
    cout << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << " "<< "\t\t  7  |  8  |  9   \n";
    cout << "     |     |      "<< "\t\t     |     |      \n";
    cout << "\n";
}
void Input()
{
    int a;
    cout << "Press the number of the field: ";
    cin >> a;
 
    if (a == 1)
        matrix[0][0] = player;
    else if (a == 2)
        matrix[0][1] = player;
    else if (a == 3)
        matrix[0][2] = player;
    else if (a == 4)
        matrix[1][0] = player;
    else if (a == 5)
        matrix[1][1] = player;
    else if (a == 6)
        matrix[1][2] = player;
    else if (a == 7)
        matrix[2][0] = player;
    else if (a == 8)
        matrix[2][1] = player;
    else if (a == 9)
        matrix[2][2] = player;
}
void TogglePlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}
char Win()
{
    //first player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
 
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
 
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
 
    //second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
 
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
 
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
 
    return '/';
}
bool filled_up()
{
	bool filled = true;
	
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
        {
            if(matrix[i][j]==' ')
            {
                filled = false;
            }
        }
	}
	
	return filled;
}
bool PlayAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void ResetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
    player = 'X';
}
int main()
{
    do {
        Draw();
        while (1)
        {
            Input();
            Draw();
            if (Win() == 'X')
            {
                cout << "X wins!" << endl;
                break;
            }
            else if (Win() == 'O')
            {
                cout << "O wins!" << endl;
                break;
            }
            else if(filled_up())
            {
                cout<<"There is a tie!"<<endl;
                break;
            }
            TogglePlayer();
        }
        ResetGame();
    }while(PlayAgain());
    system("pause");
    return 0;
}