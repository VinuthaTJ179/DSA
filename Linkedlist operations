#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node*link;
}NODE;
NODE *get_node();
NODE* insert_front(NODE*first,int ele)
{
    NODE *temp=get_node();
    temp->data=ele;
    temp->link=first;
    return temp;
}
NODE* insert_rear(NODE* first,int ele)
{
    NODE* tent;
    NODE* temp=get_node();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    tent=first;
    while(tent->link!=NULL)
    {
        tent=tent->link;
    }
    tent->link=temp;
    return first;
}
NODE* delete_front(NODE* first)
{
    NODE* temp;
    if(first==NULL)
    {
        return NULL;
    }
    temp=first;
    first=first->link;
    printf("Deleted node is %d\n",temp->data);
    free(temp);
    return first;
}
NODE* delete_rear(NODE* first)
{
    NODE *prev,*present;
    if(first==NULL)
    {
        return NULL;
    }
    if(first->link==NULL)
    {
        printf("Deleted node is %d",first->data);
        free(first);
        return NULL;
    }
    prev=NULL;
    present=first;
    while(present->link!=NULL)
    {
        prev=present;
        present=present->link;
    }
    printf("The deleted node is %d",present->data);
    free(present);
    prev->link=NULL;
    return first;
}
void display(NODE *first)
{
    if(first==NULL)
    {
        printf("No elements\n");
    }
    else
    {
    NODE *temp;
    printf("Display of elements:\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\t",temp->data);
    }
    }
    return;
}
NODE *get_node()
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("No memory\n");
        return NULL;
    }
    return temp;
}
int search_node(int key_node,NODE* first)
{
    NODE *temp=first;
    while(temp!=NULL)
    {
        if(temp->data==key_node)
        {
            return 1;
        }
        temp=temp->link;
    }
    return 0;
}
int main()
{
    NODE *first=NULL;
    int ch,ele,flag,key_node;
    for(;;)
    {
        printf("\n1.Insert front 2.Insert rear 3.Delete at the front\n4.Delete at the rear end 5.Display 6.Search for an element 7.Exit:\n");
        printf("Enter a choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter an element:\n");
            scanf("%d",&ele);
            first=insert_front(first,ele);
            break;
            case 2:
            printf("Enter an element:\n");
            scanf("%d",&ele);
            first=insert_rear(first,ele);
            break;
            case 3:
            first=delete_front(first);
            break;
            case 4:
            first=delete_rear(first);
            break;
            case 5:
            display(first);
            break;
            case 6:
            printf("Enter a key element to be searched:\n");
            scanf("%d",&key_node);
            flag=search_node(key_node,first);
            if(flag)
            {
                printf("Search successful\n");
                break;
            }
            else
            {
                printf("Search unsuccessful\n");
                break;
            }
            case 7:
            exit(0);
            default:
            printf("Enter a valid choice\n");
            break;
        }
    }
    return 0;
}



