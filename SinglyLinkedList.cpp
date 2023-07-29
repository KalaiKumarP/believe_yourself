#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode;
class list
{
    int i=0;
    public:
    //create a new list
    create(int n)
    {
        head=nullptr;
        while(n>0)
        {
            newnode = new node;
            cout<<"\nEnter the data : ";
            cin>>newnode->data;
            newnode->next=nullptr;
            if(head==nullptr)
            {
                head=newnode;
                temp=newnode;
            }
            else{
                temp->next=newnode;
                temp = newnode;
            }n--;
        }
    }
    //insert at beginning
    void insertb(int val)
    {
        newnode = new node;
        newnode->data =val;
        newnode->next=head;
        head = newnode;
    }
    //display function
    void display()
    {
        temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp= temp->next;
        }
    }
    //insert at end
    void inserte(int val)
    {
        temp=head;
        newnode = new node;
        newnode->data=val;
        newnode->next=nullptr;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=newnode;
        newnode->next=nullptr;

    }
    //insert at position
    void insertp(int val,int p)
    {
        temp=head;
        newnode = new node;
        newnode->data = val;
        while(i<p-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    //delete at beginning
    void delb()
    {
        temp = head;
        head = temp->next;
        delete temp;
    }
    //delete at end
    void dele()
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=nullptr;
    }
    //delete at position
    void delp(int p)
    {
        temp =head;
        while(i<p-1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
};
int main()
{
    cout<<"\nImplementation of Linked list ";
    cout<<"\n1 : Insert at Beginning \n2 : Insert at End \n3 : Insert at Position"<<endl;
    cout<<"\n4 : Delete at Beginning \n5 : Delete at End \n6 : Delete at Position"<<endl;
    cout<<"\n7 : Display\n8 : Create a list"<<endl;
    int ch,val,p,n;
    list obj;
    do
    {
       cout<<"\nEnter the choise :";
       cin>>ch;
       switch(ch)
       {
       case 1:
            cout<<"Enter the data :"<<endl;
            cin>>val;
            obj.insertb(val);
            break;
       case 2:
            cout<<"Enter the data :"<<endl;
            cin>>val;
            obj.inserte(val);
            break;
       case 3:
            cout<<"Enter the data : "<<endl;
            cin>>val;
            cout<<"Enter the position (start with o) : ";
            cin>>p;
            obj.insertp(val,p);
            break;
       case 4:
            obj.delb();
            break;
       case 5:
            obj.dele();
            break;
       case 6:
            cout<<"Enter the position (start with 0) :";
            cin>>p;
            obj.delp(p);
            break;
       case 7:
            obj.display();
            break;
       case 8:
            cout<<"No of node you enter :";
            cin>>n;
            obj.create(n);
            break;
       }
    }while(ch<9);
    return 0;
}
