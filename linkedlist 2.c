#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void display()
{
	if(head==NULL)
	{
		printf("NO nodes to Display\n");
		return;
	}
    printf("elements are\n");
    NODE *temp=head;
    while(temp!=NULL)
    {
    	printf("%d ",temp->data);
    	temp=temp->next;
	}
	printf("\n");
}
void insert_at_head(NODE *nn)
{
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head=nn;
	}
}
void insert_at_end(NODE *nn)
{
	NODE *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nn;//inserting new node
}
void delete_at_head()
{
	if(head==NULL)
	{
		printf("NO NORDS\n");
		return;
	}
	printf("Deleted element is %d: \n",head->data);
	NODE *dn=head; //storing to be deleted nord in dn variable  to free
	head=head->next;
	free(dn); //deallocating memory...
}
void delete_at_end()
{
if(head==NULL)
	{
		printf("NO NORDS\n");
	}
	else if(head->next==NULL) //list is containing single node
	{
		printf("Deleted element is %d\n",head->data);
		head=NULL;
	}
	else  //if list is containing more than 1 nord
	{
		NODE *temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		printf("Deleted element is %d\n",temp->next->data);
		NODE *dn=temp->next;
		temp->next=NULL;
		free(dn);
	}	
}
void insert_at_pos(NODE *nn,int pos)
{
	if(pos==1)
	{
		insert_at_head(nn);
	}
	else
	{
		NODE *temp=head;
		int c=1;
		while(c<pos-1)
		{
			c++;
			temp=temp->next;
		}
		printf("printing current position %d\n",c);
	}
}
int main()
{
	while(1)
	{
		int choice;
		printf("Enter\n1.Insert at head\n2.insert at end\n3.Delete at head\n4.Delete at end\n5.Insert at pos\n6.Delete at pos\n7.Display\nand anything else to exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			//insert at head
			int val;
			printf("Enter value to be inserted: ");           
			scanf("%d",&val);
			NODE *nn=(NODE *)malloc(sizeof(NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_head(nn);
		}
		else if(choice==2)
		{
			//insert at end
			int val;
			printf("Enter value to be inserted: ");
			scanf("%d",&val);
			NODE *nn=(NODE*)malloc(sizeof(NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_end(nn);
		}
		else if(choice==3)
		{
			//Delete at head
			delete_at_head();
			
		}
		else if(choice==4)
		{
			//Delete at end
			delete_at_end();
		}
		else if(choice==5)
		{
			//insert at pos
			NODE *nn=(NODE *)malloc(sizeof(NODE));
			int val;
			printf("Enter a value to be inserted: ");
			scanf("%d",&val);
			nn->next=NULL;
			int pos;
			printf("Enter the position to inssert the node: ");
			scanf("%d",&pos);
			insert_at_pos(nn,pos);
		}
		else if(choice==6)
		{
			//Delete at pos
		}
		else if(choice==7)
		{
			display();
		}
		else
		{
			printf("Thank you");
			break;
		}
	}
}
