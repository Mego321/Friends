#include <cs50.h>
#include <stdio.h>

// Telling C that I am going to use call on these functions in the main line of code.
long counter(long cc);
long power(int x, int y);
long digit(int n, long cc);
int check_1(int c, long cc);
int check_2(int c, long cc);
string card_type(int sum, int c, long cc);

// Main line of code to be executed.
int main(void)
{
    // Ask for credit card number
    long cc = get_long("Number: ");

    // Determine the number of digits of the credit card
    int c = counter(cc);

    // Luhn's Algorithm Step 1
    int c1 = check_1(c, cc);

    // Luhn's Algorithm Step 2
    int c2 = check_2(c, cc);

    // Luhn's Algorithm Step 3
    int sum = c1 + c2;

    // Valdiity Check using output of Luhn's Algorithm
    string ct = card_type(sum, c, cc);

    // Prints type of card if valid, prints "INVALID" if the card is invalid.
    printf("%s\n", ct);
}

//Card type function to determine if a card is valid or not based on output of Step 3 of Luhn's algorithm
string card_type(int sum, int c, long cc)
{
    int val = digit(1, sum);
    string ct;

    // Val must be 0 according to Luhn's Algorithm for a creditcard to be valid
    if (val == 0)
    {
        if (c == 16)
        {
            // All visa begin with a 4 and are 16 digits long
            int first_two_digits = digit(c, cc) * 10 + digit(c - 1, cc);
            if (digit(c, cc) == 4)
            {
                ct = "VISA";
            }

            // All Mastercard begin with digits 51 - 55 and are 16 digits long
            else if (first_two_digits >= 51 && first_two_digits <= 55)
            {
                ct = "MASTERCARD";
            }
            else
            {
                ct = "INVALID";
            }
        }
        else if (c == 15)
        {
            // Amex can be 15 digits long and must being with a 34 or 37
            int first_two_digits = digit(c, cc) * 10 + digit(c - 1, cc);
            if (first_two_digits == 34 || first_two_digits == 37)
            {
                ct = "AMEX";
            }
            else
            {
                ct = "INVALID";
            }
        }
        else if (c == 13)
        {
            // Visa can be 13 digits and must begin with a 4
            if (digit(c, cc) == 4)
            {
                ct = "VISA";
            }
            else
            {
                ct = "INVALID";
            }
        }
        else
        {
            ct = "INVALID";
        }
    }
    else
    {
        ct = "INVALID";
    }
    // Returns string of card type if valid, or invalid if the card type was not valid.
    return ct;
}

// Luhn's Algorithm Step 1 function. Starting with digit 2, this sums all of the digits*2, and if the *2 ends up greater than 10, it then adds those two digits.
int check_1(int c, long cc)
{
    int n = 2;
    int l = 0;
    while (n <= c)
    {
        int m = digit(n, cc) * 2;
        if (m < 10)
        {
            l = m + l;
            n = n + 2;
        }
        if (m >= 10)
        {
            l = l + 1 + (m - 10);
            n = n + 2;
        }
    }
    return l;
}

// Luhn's Algorithm Step 2 function. This adds every other digit starting with the first digit.
int check_2(int c, long cc)
{
    int n = 1;
    int p = 0;
    while (n <= c)
    {
        int q = digit(n, cc);
        p = p + q;
        n = n + 2;
    }
    return p;
}

// Digit counting function to determine the number of digits in the credit card.
long counter(long cc)
{
    int c = 16;
    long i = power(10, c - 1);
    while (i > cc)
    {
        i = i / 10;
        c--;
    }
    return c;
}

/*Digit determiner to specifiy each digit of the credit card.
Digits start with the furthest right digit being n = 1.*/

long digit(int n, long cc)
{
    long power(int x, int y);
    long cc1 = cc;
    int di;
    int i = 16;
    while (i >= n)
    {
        double j = power(10, i - 1);
        double k = j;
        while (cc1 >= k)
        {
            k = k + j;
        }
        di = (k - j) / j;
        cc1 = cc1 - di * j;
        i--;
    }
    return di;
}

// Function to find the power of 10 for the digit determining loop. Used <math.h> library when intiially wriitng my code, then decided to write my own power funciton.
long power(int x, int y)
{
    long a = x;
    int i = 1;
    if (y >= 1)
    {
        while (i < y)
        {
            a = a * x;
            i++;
        }
    }
    if (y == 0)
    {
        a = 1;
    }
    return a;
}