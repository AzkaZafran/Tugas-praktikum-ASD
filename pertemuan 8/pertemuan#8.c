#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *tail = NULL;

node *CreateNode(int val)
{
    node *new = malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void InsertLast(int val)
{
    node *new = CreateNode(val);
    if(tail->next == NULL)
    {
        tail->next = new;
        tail->prev = new;
        new->prev = tail;
        new->next = tail;
        tail = tail->next;
    }
    else
    {
        new->next = tail->next;
        tail->next->prev = new;
        tail->next = new;
        new->prev = tail;
        tail = tail->next;
    }
}

void SwitchNode(node *var1, node *var2)
{
    var1->next = var2->next;
    var2->next->prev = var1;
    var2->prev = var1;
    var2->prev = var2->prev->prev;
    var2->next = var1;
    var1->prev->next = var2;
    var1->prev = var2;
}

node *NodeDescendingSort(node *var)
{
    var = var->next;
    node *i = var;
    do
    {
        node *j = var;
        do
        {
            if((j->val) < (j->next->val))
            {
                printf("%d <=> %d\n", j->val, j->next->val);
                SwitchNode(j, j->next);
                if(j == var)
                {
                    var = j->prev;
                }
            }
            else
            {
                j = j->next;
            }
        }while(j->next != var);
        i = i->next;
    }while(i != var);
    return var->prev;
}

void NodePrint()
{
    node *temp = tail->next;
    do
    {
        printf("%d:%p --> ", temp->val, temp);
        temp = temp->next;
    }while(temp != tail->next);
    printf("\n");
}

int main()
{
    int num[7] = {5, 3, 6, 1, 7, 2, 9};
    tail = CreateNode(num[0]);
    for(int i = 1; i < 7; i++)
    {
        InsertLast(num[i]);
    }
    printf("List sebelum sort:\n");
    NodePrint();
    tail = NodeDescendingSort(tail);
    printf("List sesudah sort:\n");
    NodePrint();

    return 0;
}