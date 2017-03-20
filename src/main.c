#include <stdio.h>

const int depDelim = 100000;

float getPercentOfInc(int days, float deposit)
{
    float percent = 1;
    if(days <= 30) {
	percent -= 0.1;
    } else if(days <= 120) {
        percent += (deposit <= depDelim ? 0.02 : 0.03);
    } else if(days <= 240) {
        percent += (deposit <= depDelim ? 0.06 : 0.08);
    } else if(days <= 365) {
        percent += (deposit <= depDelim ? 0.12 : 0.15);
    }
    return percent;
}

int inputData(int *days, int *deposit)
{
    printf("Please input days: ");
    if (!scanf("%d", days)) {
        printf("Days is incorrect\n");
        return 0;
    } else if (*days < 0 || *days > 365) {
        printf("Out of range days\n");
        return 0;
    }

    printf("Please input deposit: ");
    if (!scanf("%d", deposit)) {
        printf("Deposit is incorrect\n");
        return 0;
    } else if (*deposit < 10000) {
        printf("Deposit is too small\n");
        return 0;
    }
    return 1;
}

int main()
{
    int days, deposit;
    if (!inputData(&days, &deposit)) {
        return 1;    
    }
    
    float income = deposit * getPercentOfInc(days, deposit);
    printf("Income: %.2f\n", income);  
   
    return 0;
}
