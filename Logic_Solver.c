#include <stdio.h>//-------------------FINAL-----------------------
#include <stdlib.h>
#include <math.h>
struct node
{
    int data[257],binary[26],noofones,isimplicant,minarr[1000];
    char term[26];
    struct node* right;
};

struct node *start;
int noofvariable,noofminterm,limit;
void assending_order();         //for arranging minterm in assending order;
void exchange(struct node*,struct node*); //for selection  sort exchange of value
char ex[200];
char exd[200];

int main()
{
    int i,j,k,x;
    struct node* tmp;
    int a=0,c=0,d=1,dd=1;
    char b='A';
    printf("NOTE-FOR NEGATION USE '!' IN PLACE OF ' \n");
    printf("NOTE-max number of variable allowed id 11\n");
    printf("NOTE-if a term in expression does not contain all variable then add all value contain in group\nEXAMPLE-in 3 variable expression if a term is AC! then it is combination of ABC! and AB!C! then we have to add remain term,program take value of a term of in which missing variable present in negation\n");
    printf("Please enter expression in SOP and check that all term are a midterm in expression\n");
    scanf("%s",ex);
    while(ex[a]!='\0')
    {
        if(ex[a]=='+')
        {
            d=d+1;
            a=a+1;
        }
        if(ex[a]=='!')
        a=a+1;
        else
        {
            if(b<ex[a])
            {
                b=ex[a];
            }
            a++;
        }
    }
    c=b-64;//c= number of variable;
    noofminterm=d;
    noofvariable=c;
    int a1=0,a2=1,e,z,z1;
    int terms[40];
    int term[40][12];
    for(z=0;z<=40;z++)
    {
    	terms[z]=0;
    	for(z1=0;z1<=20;z1++)
    	{
    		term[z][z1]=0;
		}
	}
    while(ex[a1]!='\0')
    {
        if(ex[a1]=='+')
        {
            a2=a2+1;
        }
        else if(ex[a1]=='!')
    	;
        else if(ex[a1]=='A')
        {
            if(ex[a1+1]=='!')
            term[a2][1]=0;
            else
            term[a2][1]=1;
        }
        else if(ex[a1]=='B')
        {
            if(ex[a1+1]=='!')
            term[a2][2]=0;
            else
            term[a2][2]=1;
        }
        else if(ex[a1]=='C')
        {
            if(ex[a1+1]=='!')
            term[a2][3]=0;
            else
            term[a2][3]=1;
        }
        else if(ex[a1]=='D')
        {
            if(ex[a1+1]=='!')
            term[a2][4]=0;
            else
            term[a2][4]=1;
        }
        else if(ex[a1]=='E')
        {
            if(ex[a1+1]=='!')
            term[a2][5]=0;
            else
            term[a2][5]=1;
        }
        else if(ex[a1]=='F')
        {
            if(ex[a1+1]=='!')
            term[a2][6]=0;
            else
            term[a2][6]=1;
        }
        else if(ex[a1]=='G')
        {
            if(ex[a1+1]=='!')
            term[a2][7]=0;
            else
            term[a2][7]=1;
        }
        else if(ex[a1]=='H')
        {
            if(ex[a1+1]=='!')
            term[a2][8]=0;
            else
            term[a2][8]=1;
        }
        else if(ex[a1]=='I')
        {
            if(ex[a1+1]=='!')
            term[a2][9]=0;
            else
            term[a2][9]=1;
        }
        else if(ex[a1]=='J')
        {
            if(ex[a1+1]=='!')
            term[a2][10]=0;
            else
            term[a2][10]=1;
        }
        else if(ex[a1]=='K')
        {
            if(ex[a1+1]=='!')
            term[a2][11]=0;
            else
            term[a2][11]=1;
        }
        a1=a1+1;
    }
    for(a2=1;a2<=d;a2++)
    {
        for(a1=1;a1<=c;a1++)
        {
            e=pow(2.0,(a1-1));
            terms[a2]=terms[a2]+term[a2][a1]*e;
        }
    }
    a1=0;
    a2=1;
    printf("\nNo. Of term\tminterm value\n");
    for(a1=1;a1<=d;a1++)
    {
        printf("%d                  value =%d\n",a1,terms[a1]);
    }
    printf("");
    char a3;
    int a4;
    getchar();
    printf("if you want add term (add in min term value form) type 'Y' else 'N'\n");
    scanf("%c",&a3);
    fflush(stdin);
    if(a3=='Y')
    {
        int a5;
        printf("\nENTER TOTAL number of terms you want to add\n");
        scanf("%d",&a4);
        noofminterm=d+a4;
        fflush(stdin);
        for(a5=1;a5<=a4;a5++)
        {
            printf("enter value of %d min term\n",a5);
            scanf("%d",&terms[d+a5]);
            fflush(stdin);
        }
    }
    i=noofminterm-1;
    int p=1;
    start=tmp=(struct node*)malloc(sizeof(struct node));//insertion of term 1 
    tmp->data[0]=terms[p];
    p=p+1;                    
    j=tmp->data[0];
    tmp->noofones=0;
    x=noofvariable;
    k=0;
    while(x--)      /*convertion of minterm to binary notation*/
    {
        if(j%2==1)
        {
            tmp->binary[k]=1;
            tmp->noofones++;
        }
        else
        {
            tmp->binary[k]=0;
        }
        j=j/2;
        k++;
    }
    while(i--)      /*insertion of rest term*/
    {
        tmp=tmp->right=(struct node*)malloc(sizeof(struct node));
        tmp->data[0]=terms[p];
        p=p+1;
        j=tmp->data[0];
        tmp->noofones=0;
        x=noofvariable;
        k=0;
        while(x--)
        {
            if(j%2==1)          
            {
                tmp->binary[k]=1;
                tmp->noofones++;      
            }
            else
            {
                tmp->binary[k]=0;
            }
            j=j/2;
            k++;
        }
    }
    tmp->right=NULL;
    assending_order();
}
void assending_order()        
{
    struct node *tmp1,*tmp2;
    tmp1=tmp2=start;
    while(tmp1!=NULL)             /*selection sort*/
    {
        tmp2=start;//--------------------------------
        while(tmp2!=NULL)
        {
            if(tmp1->data[0]<tmp2->data[0])       
            {
                //exchange(tmp1,tmp2);
            }
            tmp2=tmp2->right;
        }
        if(tmp1->right==NULL)
        {
            limit=tmp1->data[0];
        }
        tmp1=tmp1->right;
    }
}
