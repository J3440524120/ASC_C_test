#include <stdio.h>
#include <string.h>

typedef struct date
{
    int month;
    int day;
}date;

typedef struct student
{
    char name[21];
    int dormitory;
    date departure;
    date back;
}student, *Pstudent;

void sort_1(student stu[], int index[], int n);
void sort_2(student stu[], int index[], int n);
void sort_3(student stu[], int index[], int n);
int datecmp(date date1, date date2);

int main()
{
    int T = 0, n=0, index[51] = {0};
    student stu[51];
    int count = 0,i;

    scanf("%d",&T);

    while(count<T)
    {
        count ++;

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d.%d %d.%d", 
            stu[i].name, &stu[i].dormitory,
            &stu[i].departure.month, &stu[i].departure.day,
            &stu[i].back.month, &stu[i].back.day);
            index[i] = i;
        }

        sort_1(stu,index,n);
        printf("Dormitory %d:\n",count);
        for(i=0;i<n;i++)
        {
            printf("%s %d %d.%d %d.%d\n",
            stu[index[i]].name, stu[index[i]].dormitory,
            stu[index[i]].departure.month, stu[index[i]].departure.day,
            stu[index[i]].back.month, stu[index[i]].back.day);
        }

        sort_2(stu, index, n);
        printf("Departure %d:\n",count);
        for(i=0;i<n;i++)
        {
            printf("%s %d %d.%d %d.%d\n",
            stu[index[i]].name, stu[index[i]].dormitory,
            stu[index[i]].departure.month, stu[index[i]].departure.day,
            stu[index[i]].back.month, stu[index[i]].back.day);
        }
        sort_3(stu, index, n);
        printf("Back %d:\n",count);
        for(i=0;i<n;i++)
        {
            printf("%s %d %d.%d %d.%d\n",
            stu[index[i]].name, stu[index[i]].dormitory,
            stu[index[i]].departure.month, stu[index[i]].departure.day,
            stu[index[i]].back.month, stu[index[i]].back.day);
        }
    }

    return 0;
}

int datecmp(date date1, date date2)
{
    if(date1.month > date2.month)
    {
        return 1;
    }
    else if(date1.month < date2.month)
    {
        return -1;
    }
    else
    {
        if(date1.day == date2.day)
        {
            return 0;
        }
        else if(date1.day>date2.day)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

void sort_1(student stu[], int index[], int n)
{
    int i,j,count = 0;
    int temp;

    for(i=0;i<n-1;i++)
    {
        count = 0;
        for(j=0;j<n-1-i;j++)
        {
            if(stu[index[j]].dormitory>stu[index[j+1]].dormitory || 
            (strcmp(stu[index[j]].name,stu[index[j+1]].name)>0 && stu[index[j]].dormitory == stu[index[j+1]].dormitory))
            {
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
                count = 1;
            }
        }
        if(count == 0)
            break;
    }
}

void sort_2(student stu[], int index[], int n)
{
    int i,j,count = 0;
    int temp;

    for(i=0;i<n-1;i++)
    {
        count = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(datecmp(stu[index[j]].departure,stu[index[j+1]].departure)>0 || 
                (datecmp(stu[index[j]].departure,stu[index[j+1]].departure)==0 && strcmp(stu[index[j]].name,stu[index[j+1]].name)>0))
            {

                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
                count = 1;
            }
        }
        if(count == 0)
            break;
    }
}

void sort_3(student stu[], int index[], int n)
{
    int i,j,count = 0;
    int temp;

    for(i=0;i<n-1;i++)
    {
        count = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(datecmp(stu[index[j]].back,stu[index[j+1]].back)>0 || 
                (datecmp(stu[index[j]].back,stu[index[j+1]].back)==0 && strcmp(stu[index[j]].name,stu[index[j+1]].name)>0))
            {

                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
                count = 1;
            }
        }
        if(count == 0)
            break;
    }
}
