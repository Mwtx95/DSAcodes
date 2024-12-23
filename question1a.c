#include <stdio.h>
#define size 100

struct stack 
{
    int top;
    int s[size];
} st;

void push(int item)
{
    if (st.top >= size - 1) {
        printf("stack overflow\n");
    } else {
        st.s[++st.top] = item;
    }
}

int pop()
{
    if (st.top == -1) {
        printf("stack underflow\n");
        return -1;
    }
    int item = st.s[st.top];
    st.top--;
    return item;
}

void display()
{
    for (int i = 0; i <= st.top; i++) {
        printf("%d ", st.s[i]);
    }
}

int main()
{
    st.top = -1;
    int n, item;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        push(item);
    }

    printf("Stack before reversing: \n");
    display();

    struct stack temp;
    temp.top = -1;

    while (st.top != -1) {
        push(pop(&temp));
    }

    printf("Stack after reversing: \n");
    display();

    return 0;
}
