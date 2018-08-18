#include <stdio.h>
#include <stdlib.h>
void display(char x[9][9])
{
    int i,j,k;

    for(i=0; i<=8; ++i)
    {
        if(i==0)
        {
            printf("\n\t\t\t---------------------------------------\n\t\t row %d  ",i+1);
        }
        else
        {
            printf("\n\t\t\t----|---|---||---|---|---||---|---|----\n\t\t row %d  ",i+1);
        }
        for(j=0; j<=8; ++j)
        {
            if(j==3)
            {
                printf("|");
            }
            if(j==6)
            {
                printf("|");
            }
            if(j==8)
            {
                printf("| %c |",x[i][j]);
            }
            else
            {
                printf("| %c ",x[i][j]);
            }
        }
        if(i==2)
        {
            printf("\n\t\t\t----|---|---||---|---|---||---|---|----");
        }
        if(i==5)
        {
            printf("\n\t\t\t----|---|---||---|---|---||---|---|----");
        }
        if(i==8)
        {
            printf("\n\t\t\t---------------------------------------");
            printf("\n\t\tcolumns   1   2   3    4   5   6    7   8   9  \n\n\n");
        }
    }

}
int compfill(char x[9][9])
{
    int l,m,c=0;
    for(m=0; m<=8; m++)
    {
        for(l=0; l<=8; l++)
        {
            if(x[m][l]!=' ')
            {
                c++;
            }
        }
    }
    if(c==81)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkc(char x[9][9],int d,int e,int choice)
{
    int i,g,h,m,n;
    if(choice==' ')
    {
        return 1;
    }
    if(choice>'9'||choice<'1')
    {
        printf("\n\t\t\t\twrong input : type number between 1 to 9 \n\t\t\t\t for erasing type 'spacebar' ");
        return 0;
    }
    if(d<=2 && d>=0)
    {
        g=0;
        h=2;
    }
    if(d<=5 && d>=3)
    {
        g=3;
        h=5;
    }
    if(d<=8 && d>=6)
    {
        g=6;
        h=8;
    }
    if(e<=2 && e>=0)
    {
        m=0;
        n=2;
    }
    if(e<=5 && e>=3)
    {
        m=3;
        n=5;
    }
    if(e<=8 && e>=6)
    {
        m=6;
        n=8;
    }
    for(g=g; g<=h; g++)
    {
        for(m=m; m<=n; m++)
        {
            if(x[g][m]==choice)
            {
                printf("\n\t\t\t\twrong input\n\t\t\t\tsame number already in box");
                return 0;
            }
        }
    }
    for(i=0; i<9; i++)
    {
        if(x[d][i]==choice)
        {
            printf("\n\t\t\t\twrong input\n\t\t\t\tsame number already in row");
            return 0;
        }
        else if(x[i][e]==choice)
        {
            printf("\n\t\t\t\twrong input\n\t\t\t\tsame number already in column");
            return 0;
        }
    }
    return 1;
}
int main()
{
    char x[9][9],choice;
    int d,e,com,check;
    for(d=0; d<=8; d++)
    {
        for(e=0; e<=8; e++)
        {
            x[d][e]=' ';
        }
    }
    display(x);
    do
    {
        printf("\nenter value at");
        scanf("%d",&d);
        scanf("%d",&e);
        --d;
        --e;
        printf("\nenter value");
        fflush(stdin);
        scanf("%c",&choice);
        check=checkc(x,d,e,choice);
        if(check!=0)
        {
            x[d][e]=choice;
        }
        display(x);
        com=compfill(x);
    }
    while(com==0);
    return 0;
}
