#include <stdio.h>

int main()
{

    int T = 0, count_O = 0, count_X = 0;
    char board[3][4] = {'\0'};
    int count = 0,i,j;

    scanf("%d",&T);
    count = T;

    while(count--)
    {
        count_O = 0; count_X = 0;
        for(i=0;i<3;i++)
        {
            scanf("%s",board[i]);
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                switch (board[i][j])
                {
                case 'O':
                    count_O ++;
                    break;
                case 'X':
                    count_X ++;
                    break;
                default:
                    break;
                }
            }
        }

        printf("There are %d loops and %d crosses.\n", count_O, count_X);
    }

    return 0;
}
