#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxmemcell 30000
unsigned char mem_cell[maxmemcell]; 
int current_mem_index = 0;
struct bf_ll
{
    char val;
    int pos;
    struct bf_ll *next;
};
struct bf_ll *start = NULL;
struct bf_ll *createnewnode(char val, int pos)
{
    struct bf_ll *newnode = (struct bf_ll *)malloc(sizeof(struct bf_ll));
    newnode->val = val;

    newnode->next = NULL;
    newnode->pos = pos;
    return newnode;
}
void push(struct bf_ll **start, char val, int pos)
{
    if (*start == NULL)
    {

        *start = createnewnode(val, pos);

        return;
    }
    else
    {
        struct bf_ll *tempstart = *start;
        *start = createnewnode(val, pos);
        (*start)->next = tempstart;
    }
}
int pop()
{
    int val = start->pos;

    if (start->next != NULL)
    {
        start = start->next;
    }
    else
    {
        return -1;
    }
    return val;
}

void displaystack(struct bf_ll *start)
{
    if (start == NULL)
    {
        return;
    }
    printf("\n %s \n", &start->val);

    displaystack(start->next);
}
int main()
{
    memset(mem_cell, 0, sizeof(mem_cell));
    char *code = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.";
    for (int x = 0; x < strlen(code); x++)
    {

        switch (code[x])
        {
        case '>':
            if (current_mem_index < maxmemcell)
            {
                current_mem_index += 1;
            }
            else
            {
                current_mem_index = 0;
            }
            break;
        case '<':
            if (current_mem_index > 0)
            {
                current_mem_index -= 1;
            }
            else
            {
                current_mem_index = 0;
            }
            break;
        case '+':
            mem_cell[current_mem_index] += 1;
            break;
        case '-':
            mem_cell[current_mem_index] -= 1;
            break;
        case '.':
            printf("%c ", mem_cell[current_mem_index]);
            break;
        case '[':
            push(&start, '[', x);
            break;
        case ']':
            if (mem_cell[current_mem_index] == 0)
            {
                pop();
            }
            else
            {
                x = start->pos;
            }
        }
    }
}
