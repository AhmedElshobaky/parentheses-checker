#include "Stack.h"
// prototype of the function used to check for balanced parentheses
uint8_t* balancedParentheses(uint8_t* expression);
int main(){
    // initialize the program
    printf("\t\tWelcome\n");
    printf("Press 's' to start and any other key to exit\n");
    char input= ' ';
    scanf(" %c", &input);
    // if the user wants to start the program he will press 's'
    if(input == 's') {
        //changing the input from 's' -> start to 'r' -> reload to be able to reload the program
        input = 'r';
        while (input == 'r') {
            // taking the string from the user that will be checked
            uint8_t str[25] = " ";
            printf("Please, enter a string with a maximum of 24 characters\n");
            scanf(" %[^\n]%*c", str);
            //passing the string to the function and taking the returned value, store it in a pointer to string "result"
            uint8_t *result = balancedParentheses(str);
            // showing the result to the user
            printf("Test result is: %s\n", result);
            // checking whether the user wants to make other tests or not
            printf("Press 'r' to reload or any other key to exit\n");
            scanf(" %c", &input);
            // clearing the stack in case if there were values stored in it from the past test
            emptyStack();
        }
    }
}

uint8_t *balancedParentheses(uint8_t *expression) {
    // test results that will be returned
    static uint8_t condition1[9] = "Balanced";
    static uint8_t condition2[13] = "Not Balanced";
    // check each character in the string
    for(int i = 0; i< strlen(expression); i++){
        //if the character is a left parentheses, it will be pushed to the stack
        if( (expression[i] == '{') ||
            (expression[i] == '[') ||
            (expression[i] == '(')) {
            push(expression[i]);
        }
        /* if the character is a right parentheses:
                1-pull from the stack a value
                2- if the stack is empty it will test result will be "not balanced"
                3-else: compare the pulled value with value from the string to check matching
                3- if the two values matched the loop will continue until the stack is empty or they are not matching.
        */
        if(expression[i] == '}' ||
           expression[i] == ']' ||
           expression[i] == ')' ){
            switch(pull()) {
                case '\0':
                    return condition2;
                case '{':
                    if(expression[i] != '}') return condition2;
                    continue;
                case '(':
                    if(expression[i] != ')') return condition2;
                    continue;
                case '[':
                    if(expression[i] != ']') return condition2;
                    continue
                    ;
                }
            }
        }
    /* after the loop finishes there are only two cases:
            1- stack is empty     --> test result will be balanced as all matching
                                      parentheses have been pulled from the stack.
            2- stack is not empty --> test result will be not balanced. ex: " {{{2+3}} "
    */
    if(pull() == '\0')
        return condition1;
    return condition2;
}
