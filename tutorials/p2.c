#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long ans = 0;
    for (int i = 0; i < 32; i++ )
        ans += pow(2,i);
    printf("%lld\n", ans);
    return 0;
}