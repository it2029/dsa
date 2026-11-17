#include<iostream> 
#include<cstring> 
#include<math.h> 
using namespace std; 
class stack 
{ 
private :  
           typedef struct stack1 
           { 
           int data; 
           struct stack1 *next; 
           }node; 
           node *top; 
public:     
stack(); 
           ~stack(); 
           void push(char,node **); 
           int pop(node **); 
           int stackempty(node *); 
void postfix(); 
           }; 
 
int main() 
{ 
int ch; 
stack st; 
do 
{ 
cout<<"\n1.Infix to postfix \n2. Exit"; 
cout<<"\n Enter your choice"; 
cin>>ch; 
switch(ch) 
{ 
case 1: st.postfix(); 
         break; 
case 2: break; 
} 
}while(ch!=2); 
} 
 
stack::stack() 
{ 
top=NULL; 
} 
 
stack :: ~stack() 
{ 
node *temp; 
temp=top; 
if(temp==NULL) 
delete temp; 
else 
{ 
while(temp!=NULL) 
{ 
temp=temp->next; 
top=NULL; 
top=temp; 
} 
delete temp; 
} 
} 
 
void stack :: push(char x,node **top) 
{ 
node *newnode; 
newnode=new node; 
newnode->next=NULL; 
newnode->data=x; 
newnode->next=*top; 
*top=newnode; 
} 
 
int stack::pop(node **top) 
{ 
int x; 
node *temp; 
x=(*top)->data; 
temp=*top; 
*top=(*top)->next; 
delete temp; 
return x; 
} 
 
int stack :: stackempty(node *temp) 
{ 
if(temp==NULL) 
return 1; 
else 
return 0; 
} 
 
void stack::postfix() 
{ 
char exp[40]; 
int length,j,l; 
char ch; 
char post[40]; 
j=0; 
cout<<"\n enter exp"; 
cin>>exp; 
length=strlen(exp); 
cout<<"\n\n The postfix is:"; 
for(int i=0;i<=length-1;i++) 
{ 
ch=exp[i]; 
if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/') 
push(ch,&top); 
else if(ch!=')') 
{ 
post[j]=ch; 
j++; 
cout<<ch; 
} 
else 
{ 
do 
{ 
ch=pop(&top); 
if(ch!='(') 
{ 
post[j]=ch; 
j++; 
cout<<ch; 
} 
}while(ch!='('); 
} 
} 
post[j]='$'; 
}
