#include "Stack.h"
// defining the max size of stack
# define max 25
// defining the stack as an array of unsigned characters (uint8_t)
uint8_t stack[max];
//initializing the top of the stack
int top =-1;
// push the given character to the stack
void push(uint8_t u8_data){
    // if the stack is full a message will indicate it
    if(top == (max)){
        printf("Stack overflow!\n");
    } else{
        /* raise the top of the stack and
           add the value given to the stack
           at the address of the top */
        top++;
        stack[top] = u8_data;

    }
}
// pull values from the stack
uint8_t pull(){
    // check if the stack is empty
    if(top == -1){
        // return null value
        return '\0';
    }
    else {
        // initialize temp variable and store the top of the stack in it
        int temp = stack[top];
        // decrease the top of the stack
        top--;
        // return the value of the temp
        return temp;
    }
}
// print all values in the stack
void printStack(){
    printf("__________________\n");
    printf("The stack is:\n");
    /* for loop to pass by all values stored in the stack such that
        the output is reversed in order of the array stack */
    for (int i = top; i > -1; i--) {
        printf("%c\n", stack[i]);
    }
    printf("__________________\n");
}
// function to empty the stack
void emptyStack(){
    while (pull() != '\0') pull();
}
