#include <stdio.h>

int main()
{

    int N = 0, low = 0, high = 0;
    int count = 0,i = 0;
    char pwm[1000] = {'0'};
    float result;

    scanf("%d",&N);

    count = N;

    while(count--)
    {
        low = 0;high = 0;i=0;
        // getchar();
        scanf("%s", pwm);
        while(pwm[i] != '\0')
        {
            if(pwm[i] == '1')
            {
                high ++;
            }
            else if(pwm[i] == '0')
            {
                low ++;
            }
            i++;
        }

        result = high/(float)(low+high)*100;
        
        printf("%.2f%%\n",result);
    }

    return 0;
}
