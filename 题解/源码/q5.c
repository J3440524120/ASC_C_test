#include <stdio.h>

#define ROW 3
#define COL 3

typedef enum stage{
    Draw,
    O_win,
    X_win,
    Unfinished
}stage;

typedef enum role{
    player_none,
    player_O,
    player_X,
}role;

int is_full(char board[ROW][COL+1]);
role is_link(char board[ROW][COL+1]);
stage pd_win(char board[ROW][COL+1]);

int main()
{

    int T = 0;
    stage result = Draw;
    char board[ROW][COL+1] = {'\0'};
    int count = 0,i;

    scanf("%d",&T);
    count = T;

    while(count--)
    {
        for(i=0;i<ROW;i++)
        {
            scanf("%s",board[i]);
        }

        result = pd_win(board);

        switch (result)
        {
        case Draw:
            printf("Draw\n");
            break;
        case O_win:
            printf("O_win\n");
            break;
        case X_win:
            printf("X_win\n");
            break;
        case Unfinished:
            printf("Unfinished\n");
            break;
        default:
            break;
        }
    }

    return 0;
}

int is_full(char board[ROW][COL+1])
{
    int i=0,j=0;

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(board[i][j]=='*')
            {
                return 0;
            }
        }
    }

    return 1;
}

role is_link(char board[ROW][COL+1])
{
    int i=0;
    char temp = '*';

    for(i=0;i<ROW;i++)
    {
        if(board[i][0] == board[i][1] && board[i][2] == board[i][1])
        {
            temp = board[i][0];
        }
    }
    for(i=0;i<COL;i++)
    {
        if(board[0][i] == board[1][i] && board[2][i] == board[1][i])
        {
            temp = board[0][i];
        }
    }
    if(board[0][0] == board[1][1] && board[2][2] == board[1][1])
    {
        temp = board[0][0];
    }
    if(board[0][2] == board[1][1] && board[2][0] == board[1][1])
    {
        temp = board[1][1];
    }
    
    switch (temp)
    {
    case '*':
        return player_none;
    case 'O':
        return player_O;
    case 'X':
        return player_X;
    }

return player_none;
}

stage pd_win(char board[ROW][COL+1])
{
    int full = 0;
    role win = player_none;

    full = is_full(board);
    win = is_link(board);

    switch (win)
    {
    case player_none:
    {
        if(full)
        {
            return Draw;
        }
        else
        {
            return Unfinished;
        }
    }break;
    case player_O:
    {
        return O_win;
    }break;
    case player_X:
    {
        return X_win;
    }break;
    default:
        break;
    }
    return Draw;
}
