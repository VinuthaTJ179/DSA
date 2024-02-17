#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE* get_node()
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(temp == NULL)
    {
        cout<<"No memory"<<endl;
        return NULL;
    }
    return temp;
}

NODE* addFirst(int data,NODE* first)
{
    NODE* temp = get_node();
    temp->data = data;
    if(first == NULL)
    {
        temp->link = NULL;
        return temp;
    }
    temp->link = first;
    return temp;
}

NODE* addLast(int data,NODE* first)
{
    NODE* temp = get_node();
    temp->data = data;
    temp->link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    NODE *ptr = first;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    return first;
}

NODE *deleteFirst(NODE *first)
{
    if(first == NULL)
    {
        cout<<"No elements to delete"<<endl;
        return NULL;
    }
    if(first->link == NULL)
    {
        cout<<"The deleted element is: "<<first->data<<endl;
        delete first;
        return NULL;
    }
    NODE *temp = first;
    cout<<"The deleted element is: "<<temp->data<<endl;
    first = first->link;
    delete temp;
    return first;
}

NODE* deleteLast(NODE *first)
{
    if(first == NULL)
    {
        cout<<"No elements to delete"<<endl;
        return NULL;
    }
    if(first->link == NULL)
    {
        cout<<"The deleted element is: "<<first->data<<endl;
        delete first;
        return NULL;
    }
    NODE *ptr1 = first;
    NODE *ptr2 = NULL;
    while(ptr1->link != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->link;
    }
    ptr2->link = ptr1->link;
    return first;
}

NODE* deleteAllValues(int val,NODE *first)
{
    NODE *temp = new NODE;
    temp->link = first;
    NODE *ptr = temp;
    while(ptr->link != NULL)
    {
        if(ptr->link->data == val)
        {
            ptr->link = ptr->link->link;
        }
        else
        {
            ptr = ptr->link;
        }
    }
    return temp->link;
}

NODE* deleteAllDuplicates(NODE* first)
{
    if(first == NULL)
    {
        cout<<"No elements to delete"<<endl;
        return NULL;
    }
    
    NODE *ptr1 = first;
    while(ptr1 != NULL && ptr1->link != NULL)
    {
        NODE *ptr2 = ptr1;
        while(ptr2->link != NULL)
        {
            if(ptr2->link->data == ptr1->data)
            {
                ptr2->link = ptr2->link->link;
            }
            else
            {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }
    return first;
}


void display(NODE *first)
{
    if(first == NULL)
    {
        cout<<"No elements to display"<<endl;
        return;
    }
    NODE *temp = first;
    while(temp != NULL)
    {
        if(temp->link != NULL)
        {
            cout<<temp->data<<"->";
        }
        else
        {
            cout<<temp->data<<endl;
        }
        temp = temp->link;
    }
}

int main()
{
    NODE *first = NULL;
    int choice = 0,data = 0;
    for(;;)
    {
        cout<<"1.Add nodes at the front\n2.Add nodes at the end\n3.Delete nodes at the front\n4.Delete nodes at the end\n5.Delete all particular values\n6.Delete all duplicates\n7.Display nodes\n8.Exit"<<endl;
        cout<<"Enter the choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the value: "<<endl;
            cin>>data;
            first = addFirst(data,first);
            break;
            
            case 2:
            cout<<"Enter the value: "<<endl;
            cin>>data;
            first = addLast(data,first);
            break;
            
            case 3:
            first = deleteFirst(first);
            break;
            
            case 4:
            first = deleteLast(first);
            break;
            
            case 5:
            int val;
            cout<<"Enter the values which is to be deleted: "<<endl;
            cin>>val;
            first = deleteAllValues(val,first);
            break;
            
            case 6:
            first = deleteAllDuplicates(first);
            break;
            
            case 7:
            display(first);
            break;
            
            case 8:
            exit(0);
            
            default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }
    return 0;
}

