#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data[257],binary[26],noofones,isimplicant,minarr[1000];
    char term[26];
    struct node* right;
};
struct node *start,*head,*improot,*save,*fin;
int noofvariable,noofminterm,limit;
int columns=2,check=1,imptable[100][100],counter=0,essential[1000],t=0,no=0,minterms[1000];
void assending_order();         
void exchange(struct node*,struct node*);
void store_minterms();
void grouping();          //the minterms are grouped according to the number of ones
void end_loop(struct node*); 
void pairing_minterm();          
void implicants(struct node*);          //initializes each term as an implicant
void remove_duplicate();               
void bin_to_variable();        
void essential_implicants();        //for determine essential implicants                
void other_implicants();        //the prime implicants other than the essential ones are collected
void final_minimized_terms();     //the final terms in the minimized function are noted
void display_minimized_function();
char ex[200];
char exd[200];
char a_var[26],b_var_com[26];       //character

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
        printf("%d          \tvalue =%d\n",a1,terms[a1]);
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
            printf("enter value of min term\n");
            scanf("%d",&terms[d+a5]);
            fflush(stdin);
        }
    }
    i=noofminterm-1;
    int p=1;
    start=tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data[0]=terms[p];
    p=p+1;                     //first minterm is stored
    j=tmp->data[0];
    tmp->noofones=0;
    x=noofvariable;
    k=0;
    while(x--)      // minterm to binary notation
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
    while(i--)      //rest of the minterms are stored
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
            if(j%2==1)          // minterms to binary notation
            {
                tmp->binary[k]=1;
                tmp->noofones++;       //the number of ones in binary notation OF minterm
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
    for(i=0;i<26;i++)
    {
        a_var[i]=65+i;      //variables
        b_var_com[i]=97+i;      //its compliments
    }
    assending_order();     
    store_minterms();
    grouping();
    //number++;
    end_loop(start);
    head=(struct node*)malloc(sizeof(struct node));
    while(check>0)
    {
        pairing_minterm();
    }
    save->right=NULL;           //storing null value in link field of list storing prime implicants
    end_loop(improot);
    remove_duplicate();
    counter++;
    essential_implicants();
    other_implicants();
    final_minimized_terms();
    end_loop(fin);
    bin_to_variable();
    display_minimized_function();
    return 0;
}

void assending_order()          //arranging the minterms in increasing order of magnitude
{
    struct node *tmp1,*tmp2;
    tmp1=tmp2=start;
    while(tmp1!=NULL)
    {
        tmp2=start;
        while(tmp2!=NULL)
        {
            if(tmp1->data[0]<tmp2->data[0])       //if not in order their values are exchanged  
            {
                exchange(tmp1,tmp2);
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

void store_minterms()       //array to store all the minterms
{
    int i=0;
    struct node* tmp;
    tmp=start;
    while(tmp!=NULL)
    {
        minterms[i]=tmp->data[0];
        i++;
        tmp=tmp->right;
    }
}

void exchange(struct node* tmp1,struct node* tmp2)        //swapping all the data of two nodes
{
    int x,y,i=0;
    i=noofvariable;
    for(i=0;i<noofvariable;i++)      //binary notation is exchanged
    {
        y=tmp1->binary[i];
        tmp1->binary[i]=tmp2->binary[i];
        tmp2->binary[i]=y;
    }
    y=tmp1->noofones;          //no. of ones is exchanged
    tmp1->noofones=tmp2->noofones;
    tmp2->noofones=y;
    x=tmp1->data[0];           //data(minterm) is exchanged
    tmp1->data[0]=tmp2->data[0];
    tmp2->data[0]=x;
}

void grouping()       // minterms are arranged according to the number of ones in their binary notation
{
    int i,count=0,j,k=0;
    struct node *tmp,*next;
    tmp=save=start;
    start=next=(struct node*)malloc(sizeof(struct node));
    for(i=0;i<=noofvariable;i++)
    {
        tmp=save;
        while(tmp!=NULL)
        {
            if(tmp->noofones==i)       //minterms are arranged according to no. of ones (asscending order)
            {
                next->data[0]=tmp->data[0];
                k++;
                for(j=0;j<noofvariable;j++)
                {
                    next->binary[j]=tmp->binary[j];
                }
                next->noofones=tmp->noofones;
                next=next->right=(struct node*)malloc(sizeof(struct node));
            }
            tmp=tmp->right;
        }
    }
    minterms[k]=-1;
    next->right=NULL;
}



void end_loop(struct node* ptr)
{
    struct node* tmp;
    tmp=ptr;
    while(tmp->right->right!=NULL)
    {
        tmp=tmp->right;
    }
    tmp->right=NULL;
}

void pairing_minterm()    //pairing on the basis of differece in number of ones in binary notation
{
    int i,count,k,j,x;
    struct node *tmp,*next,*p,*imp;
    check=0;
    if(columns==2)      
    {
        imp=improot=(struct node*)malloc(sizeof(struct node));
        p=head;
    }
    else        
    {
        imp=save;
        start=head;
        p=head=(struct node*)malloc(sizeof(struct node));
    }
    tmp=start;
    implicants(start);
    while(tmp!=NULL)
    {
        next=tmp->right;
        while(next!=NULL)
        {
            count=0;
            if(next->noofones-tmp->noofones==1)        
            {
                for(i=0;i<noofvariable;i++)
                {
                    if(tmp->binary[i]!=next->binary[i])
                    {
                        k=i;            //the place in which they differ is noted
                        count++;
                    }
                }
            }
            if(count==1)        //checks if the two terms differ by one place in binary notation
            {
                tmp->isimplicant=0;        //if they do then they are not a prime implicant
                next->isimplicant=0;
                check++;
                for(i=0;i<noofvariable;i++)
                {
                    p->binary[i]=tmp->binary[i];     
                }
                p->binary[k]=-1;
                x=0;
                for(j=0;j<columns/2;j++)            //data from first term is stored
                {
                    p->data[x]=tmp->data[j];
                    x++;
                }
                for(j=0;j<columns/2;j++)            //data from second term is stored
                {
                    p->data[x]=next->data[j];
                    x++;
                }
                p->noofones=tmp->noofones;
                p=p->right=(struct node*)malloc(sizeof(struct node));        // one extra node that is to be deleted
            }
            next=next->right;
        }
        tmp=tmp->right;
    }
    p->right=NULL;
    if(check!=0)
    {
        end_loop(head);     //extra node is deleted
    }
    tmp=start;
    while(tmp!=NULL)           //for selecting the prime implicants
    {
        if(tmp->isimplicant==1)        // if term is a prime implicant it is stored separately in list with head pointer improot
        {
            i=0;
            for(i=0;i<columns/2;i++)
            {
                imp->data[i]=tmp->data[i];
            }
            imp->data[i]=-1;
            for(i=0;i<noofvariable;i++)
            {
                imp->binary[i]=tmp->binary[i];
            }
            imp=imp->right=(struct node*)malloc(sizeof(struct node));
        }
        tmp=tmp->right;
    }
    save=imp;
    columns=columns*2;
    //number++;
}
void implicants(struct node* ptr)       //initializing each term as a prime implicant
{
    struct node* tmp;
    tmp=ptr;
    while(tmp!=NULL)
    {
        tmp->isimplicant=1;
        tmp=tmp->right;
    }
}

void remove_duplicate()          //removal of duplicate terms
{
    int common=0,i;
    struct node *tmp1,*tmp2,*temp3;
    tmp1=tmp2=improot;
    while(tmp1!=NULL)
    {
        tmp2=tmp1->right;
        while(tmp2!=NULL)
        {
            common=0;
            for(i=0;i<noofvariable;i++)     
            {
                if(tmp2->binary[i]==tmp1->binary[i])
                {
                    common++;
                }
            }
            if(common==noofvariable)
            {
                temp3=improot;
                while(temp3->right!=tmp2)      //removal of repeated term
                {
                    temp3=temp3->right;
                }
                temp3->right=tmp2->right;
                tmp2=temp3;
            }
            tmp2=tmp2->right;
        }
        tmp1=tmp1->right;
    }
}
void bin_to_variable()          //convertion of binary notation of  terms to variables.
{
    int i,j;
    struct node* tmp;
    tmp=fin;
    while(tmp!=NULL)
    {
        j=0;
        for(i=0;i<noofvariable;i++)
        {
            if(tmp->binary[i]==0)
            {
                tmp->term[j]=b_var_com[i];
                j++;
            }
            if(tmp->binary[i]==1)
            {
                tmp->term[j]=a_var[i];
                j++;
            }
        }
        tmp=tmp->right;
    }
}
void essential_implicants()         //function for  selecting essential prime implicants
{
    struct node* tmp;
    int i,j,k,m,n,x,y,count=0,count2=0,a=0;
    for(i=0;i<counter;i++)
    {
        for(j=0;j<=limit;j++)
        {
            imptable[i][j]=0;        
        }
    }
    i=0;
    j=0;
    k=0;
    tmp=improot;
    while(tmp!=NULL)
    {
        k=0;
        while(tmp->data[k]!=-1)
        {
            imptable[i][tmp->data[k]]=1;  // 1 or X is placed for the column with same index 
            k++;
        }
        i++;
        tmp=tmp->right;
    }
    for(i=0;i<counter;i++)      //for finding essential prime implicants
    {
        for(j=0;j<=limit;j++)
        {
            count=0;
            if(imptable[i][j]==1)
            {
                y=j;
                x=i;
                for(k=0;k<counter;k++)
                {
                    if(imptable[k][j]==1)       //checks if there is only one X in a column
                    {
                        count++;
                    }
                }
                if(count==1)  //places - in place of X in every column of the table whose one row contains only one X in a column
                {
                    essential[t]=x;
                    t++;
                    for(n=0;n<=limit;n++)
                    {
                        if(imptable[i][n]==1)
                        {
                            for(m=0;m<counter;m++)
                            {
                                imptable[m][n]=0;
                            }
                        }
                    }
                }
            }
        }
    }
    essential[t]=-1;
    i=0;
}

void other_implicants()     
{
    no=0;           
    int count1=0,count2=0;
    int i,j;
    for(i=0;i<counter;i++)
    {
        count1=0;
        for(j=0;j<=limit;j++)
        {
            if(imptable[i][j]==1)       //no. of X's or 1's are calculated
            {
                no++;
                count1++;
            }
        }
        if(count1>count2)       //to find the term with maximum X's in a row
        {
            essential[t]=i;
            count2=count1;
        }
    }
    for(j=0;j<=limit;j++)           //removing the X's in the row as well a those X's which are in same column
    {
        if(imptable[essential[t]][j]==1)
        {
            for(i=0;i<counter;i++)
            {
                imptable[i][j]=0;
            }
        }
    }
    t++;
    essential[t]=-1;
    if(no>0)            //if one or more terms is found the function is called again otherwise not
    {
        other_implicants();
    }
}

void final_minimized_terms()         
{
    int i=0,j,c=0,x;
    struct node *tmp,*ptr;
    fin=tmp=(struct node*)malloc(sizeof(struct node));
    while(essential[i]!=-1)
    {
        ptr=improot;
        x=essential[i];
        for(j=0;j<x;j++)
        {        
            ptr=ptr->right;
        }
        j=0;
        while(ptr->data[j]!=-1)        
        {
            tmp->data[j]=ptr->data[j];
            j++;
        }
        tmp->data[j]=-1;
        for(j=0;j<noofvariable;j++)          
        {
            tmp->binary[j]=ptr->binary[j];
        }
        tmp=tmp->right=(struct node*)malloc(sizeof(struct node));
        i++;
        c++;
    }
    tmp->right=NULL;
}
void display_minimized_function()         //displays the minimized function in SOP form
{
    struct node* tmp;
    tmp=fin;
    printf("\nThe minimized function is :- ");
    while(tmp!=NULL)
    {
        printf("%s",tmp->term);
        if(tmp->right!=NULL)
        {
            printf(" + ");
        }
        tmp=tmp->right;
    }
    
}
