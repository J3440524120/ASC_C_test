#include <stdio.h>

int main()
{
	int T = 0, N = 0;
    int max_impression=0,temp_impression=0;
    int count =0,i;
    float V = 0.0,min_time = 0.0,temp_distance=0.0;
    int best = 0,near = 0;

    scanf("%d", &T);
    count = T;
    while (count--)
    {
        scanf("%d%f",&N,&V);

        max_impression = 0;
        min_time = 0.0;

        for(i=0;i<N;i++)
        {
            scanf("%f",&temp_distance);
            if(i==0 || temp_distance/V < min_time)
            {
                min_time = temp_distance/V;
                near = i+1;
            }
        }

        for(i=0;i<N;i++)
        {
            scanf("%d",&temp_impression);
            if(temp_impression>max_impression)
            {
                max_impression = temp_impression;
                best = i+1;
            }
        }

        printf("%d is the best. The nearest canteen is %d. It takes %.2fs.\n",best,near,min_time);
    }
}