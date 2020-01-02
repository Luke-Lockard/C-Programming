/* User enters amount of taxable income and tax due is displayed */

#include <stdio.h>

int calc_tax_due(int income);

int main(void)
{
    float income, taxes;

    printf("Enter amount of taxable income: ");
    scanf("%f", &income);

    taxes = calc_tax_due(income);
    
    printf("Taxes: %.2f\n", taxes);

    return 0;
}

int calc_tax_due(int income)
{

    int taxes;

    if (income > 7000)
    {
        taxes = 230 + (income - 7000) * .06f;
    }
    else if (income > 5250)
    {
        taxes = 142.50f + (income - 5250) * .05f;
    }
    else if (income > 3750)
    {
        taxes = 82.50f + (income - 3750) * .04f;
    }
    else if (income > 2250)
    {
        taxes = 37.50f + (income - 2250) * .03f;
    }
    else if (income > 750)
    {
        taxes = 7.50f + (income - 750) * .02f;
    }
    else
    {
        taxes = income * .01f;
    }

    return taxes;
}
