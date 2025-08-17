#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char *items;
    int top;
};

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->items = (char*)malloc(sizeof(char) * size);
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1)
        return '\0'; // Stack underflow
    return stack->items[stack->top--];
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool isValid(char *s) {
    int length = strlen(s);
    struct Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(stack, c);
        } else {
            if (isEmpty(stack)) {
                return false;
            }
            char topChar = pop(stack);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    bool result = isEmpty(stack);
    free(stack->items);
    free(stack);
    return result;
}

int main() {
    char s[] = "{[()]}";
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}
