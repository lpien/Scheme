/* main.c
 * contains the main method, which 
 * calls your other functions
 *
 * Your mission (which you have no choice but to accept):
 * Modify the functions below (marked with TODO) so that
 * your program correctly reads student loans from stdin 
 * (standard input source) and writes the correct amount 
 * to stdout (standard output source).
 *
 * There are four functions you must modify:
 *      main
 *      stdin_to_loan
 *      compute_balance
 *      print_loan
 *
 * Lauren Pien
 * CSC 173 Fall 2015 -- Loan Calculator project
 * Submitted 9/11/15
 */

// Instructions on running the executable:
// The makefile will produce an executable file called
// 'loans', which you can run to see if your code is
// correct.
// 'loans' takes its input from stdin (by default,
// your terminal) and prints its output to stdout
// (also your terminal by default). To run it this way,
// type './loans' at your command line (without the quotes),
// then type in each loan on a separate line.
// Each time you press enter, your program's
// result should appear right below.
// When you are sick and tired of typing in student loans,
// type 'SICK' (without the quotes) and press enter.
// Your program should terminate once this happens.
// However, this requires you to type in loans every
// time you want to run your program. There is a quicker way...
// To run your program against the given test cases, for example,
// redirect the test cases to stdin, and connect stdout to a file.
// To do this, type './loans < tests/in.txt > tests/out.txt'
// (without the quotes).

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <math.h>
#include <string.h>

int main() {
    // falsely assume that we are only given one loan to process
    // read in the loan from stdin

    
    //reads all input lines until reads 'SICK'
    while(1){
        loan_t loan = stdin_to_loan();                //saves stdin to loan struct
        double balance = compute_balance(loan);      //computes balance of loan
        print_balance(balance);                     //prints balance to stdout
    }
}

// reads in a loan from stdin and 
// stores it in a loan_t struct
loan_t stdin_to_loan() {
    loan_t *loan = malloc(sizeof(loan_t));

    char loanLine[30];

    fgets(loanLine, sizeof(loanLine), stdin);
    if(strcmp(loanLine, "SICK\n") == 0){
        exit(0);
    }
    else{
        sscanf(loanLine, "%lf %lf %d %d", &loan -> initial, &loan -> interest_rate, &loan -> years, &loan -> compounding_rate);
    }
    //printf("LOAN INFORMATION Initial: %lf, interest rate: %lf, years: %d, compounding rate: %d\n", &loan -> initial, &loan -> interest_rate, &loan -> years, &loan -> compounding_rate);
    return *loan;

    /* NOTE: Using the gets() function to read from stdin is insecure.
     * Instead, use fgets(). 
     * 
     * (We won't penalize you for using gets(),
     * but it's good C practice to avoid it like the plague. In fact,
     * the newest C standard, C11, completely removes it from the 
     * language.) For more info. see:
     * http://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-used
     */
}

// computes the amount (in dollars) of how much we would
// owe on the loan after the given number of years
double compute_balance(loan_t loan) {
    double amtTotal;    //amount owed after calculations
    int count1;
    int count2;
    amtTotal = loan.initial;

    for(count1 = 0; count1 < loan.years; count1++){
        for(count2 = 0; count2 < loan.compounding_rate; count2++){
            //amtTotal = loan.initial * pow((1 + (loan.interest_rate / loan.compounding_rate)), (loan.compounding_rate * loan.years));
            //new_amount = old_amount * (1 + rate/n)
            amtTotal = amtTotal * (1 + (loan.interest_rate / loan.compounding_rate));
            amtTotal = floor(amtTotal * 100) / 100;
        }
    }
    
    //count = 0;
    //amtTotal = loan.initial;

    //new_amount = old_amount * (1 + rate/n)
    
    
    return amtTotal;
}

// prints the balance of the loan to stdout.
void print_balance(double balance) {
    printf("%.2lf\n", balance);     //formatted to print to two decimal places
}






