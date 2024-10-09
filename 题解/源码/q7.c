#include <stdio.h>

void Menu_Show(void);

int stage=0,cursor=0;

int main()
{
    int operate;
    scanf("%d",&operate);
    Menu_Show();
    while(operate!=0)
    {
        
        switch (operate)
        {
        case 1:
        {
            switch (stage)
            {
            case 0:
                cursor = (cursor+1)%2;
                break;
            case 1:
                cursor = (cursor+2)%3;
                break;
            }
        }break;
        case 2:
        {
            switch (stage)
            {
            case 0:
                cursor = (cursor+1)%2;
                break;
            case 1:
                cursor = (cursor+1)%3;
                break;
            }
        }break;
        case 3:
        {
            switch (stage)
            {
            case 0:
            {
                switch (cursor)
                {
                case 0:
                {
                    cursor = 0;
                    stage = 1;
                }break;
                case 1:
                {
                    stage = 2;
                    cursor = 0;
                }break;
                }
            }break;
        }break;
        case 4:
        {
            switch (stage)
            {
            case 1:
            case 2:
            {
                stage = 0;
                cursor = 0;
            }break;
            }
        }break;
        default:
            break;
        }
    }
        Menu_Show();
        scanf("%d",&operate);
    }
    return 0;
}

void Menu_Show()
{
    switch (stage)
    {
    case 0:
    {
        printf("Main\n");
        if(cursor == 0)
        {
            printf("->  data\n    image\n");
        }
        else if(cursor == 1)
        {
            printf("    data\n->  image\n");
        }
    }break;
    case 1:
    {
        printf("data\n");
        switch (cursor)
        {
        case 0:
            printf("->  data1 101\n    data2 20.1\n    data3 1.23\n");
            break;
        case 1:
            printf("    data1 101\n->  data2 20.1\n    data3 1.23\n");
            break;
        case 2:
            printf("    data1 101\n    data2 20.1\n->  data3 1.23\n");
            break;
        default:
            break;
        }
    }break;
    case 2:
    {
        printf("image\n    ASC\n");
    }break;
    
    default:
        break;
    }
}
