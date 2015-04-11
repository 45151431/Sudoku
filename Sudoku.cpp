#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cstring>
#include"Sudoku.h"
using namespace std;

int ques_init[12][12]={0, 2, 6, 0, 7, 3, 0, 5, 1, -1, -1, -1,
                       0, 0, 3, 9, 5, 0, 6, 0, 4, -1, -1, -1,
                       9, 0, 1, 6, 0, 4, 8, 0, 0, -1, -1, -1,
                       -1, -1, -1, 1, 3, 2, 0, 8, 7, 0, 5, 6,
                       -1, -1, -1, 0, 8, 0, 1, 9, 0, 4, 0, 0,
                       -1, -1, -1, 4, 0, 6, 2, 3, 0, 8, 7, 1,
                       1, 0, 0, 0, 4, 0, -1, -1, -1, 6, 0, 5,
                       0, 0, 4, 0, 6, 0, -1, -1, -1, 1, 3, 7,
                       6, 9, 0, 0, 1, 7, -1, -1, -1, 0, 8, 4,
                       3, 1, 2, -1, -1, -1, 7, 0, 0, 5, 0, 9,
                       7, 4, 8, -1, -1, -1, 0, 6, 9, 3, 0, 0,
                       0, 0, 0, -1, -1, -1, 3, 1, 0, 7, 0, 8};

Sudoku::Sudoku(){}
void Sudoku::GiveQuestion()
{
    srand(time(NULL));
    ran=rand();
    rotate();
    ran=rand();
    column_change();
    ran=rand();
    row_change();
    ran=rand();
    num_change();
    for(int j=0; j<12; j++)
    {
        printf("%d", ques[0][j]);
        for(int i=1; i<12; i++)
            printf(" %d", ques[i][j]);
        puts("");
    }
    return;
}
void Sudoku::rotate()
{
    int tmp=ran%4;
    if(tmp==0)
        for(int i=0; i<12; i++)
            for(int j=0; j<12; j++)
                ques[i][j]=ques_init[i][j];
    else if(tmp==1)
        for(int i=0; i<12; i++)
            for(int j=0; j<12; j++)
                ques[i][j]=ques_init[11-j][i];
    else if(tmp==2)
        for(int i=0; i<12; i++)
            for(int j=0; j<12; j++)
                ques[i][j]=ques_init[11-i][11-j];
    else if(tmp==3)
        for(int i=0; i<12; i++)
            for(int j=0; j<12; j++)
                ques[i][j]=ques_init[j][11-i];
    return;
}
void Sudoku::change(int i1, int j1, int i2, int j2)
{
    int tmp=ques[i1][j1];
    ques[i1][j1]=ques[i2][j2];
    ques[i2][j2]=tmp;
    return;
}
void Sudoku::column_change()
{
     int tmp=ran%6;
     if(tmp==0)
         for(int j=0; j<12; j++)
         {
             change(0, j, 6, j);
             change(1, j, 7, j);
             change(2, j, 8, j);
         }
     else if(tmp==1)
         for(int j=0; j<12; j++)
         {
             change(3, j, 9, j);
             change(4, j, 10, j);
             change(5, j, 11, j);
         }
     else if(tmp==2)
         for(int j=0; j<12; j++)
         {
             change(0, j, 9, j);
             change(1, j, 10, j);
             change(2, j, 11, j);
         }
     else if(tmp==3)
         for(int j=0; j<12; j++)
         {
             change(0, j, 3, j);
             change(1, j, 4, j);
             change(2, j, 5, j);
         }
     else if(tmp==4)
         for(int j=0; j<12; j++)
         {
             change(3, j, 6, j);
             change(4, j, 7, j);
             change(5, j, 8, j);
         }
     else if(tmp==5)
         for(int j=0; j<12; j++)
         {
             change(6, j, 9, j);
             change(7, j, 10, j);
             change(8, j, 11, j);
         }
     return;
}
void Sudoku::row_change()
{
     int tmp=ran%3;
     if(tmp==0)
         for(int i=0; i<12; i++)
         {
             change(i, 0, i, 6);
             change(i, 1, i, 7);
             change(i, 2, i, 8);
         }
     else if(tmp==1)
         for(int i=0; i<12; i++)
         {
             change(i, 3, i, 9);
             change(i, 4, i, 10);
             change(i, 5, i, 11);
         }
     else if(tmp==2)
         for(int i=0; i<12; i++)
         {
             change(i, 0, i, 9);
             change(i, 1, i, 10);
             change(i, 2, i, 11);
         }
     else if(tmp==3)
         for(int i=0; i<12; i++)
         {
             change(i, 0, i, 3);
             change(i, 1, i, 4);
             change(i, 2, i, 5);
         }
     else if(tmp==4)
         for(int i=0; i<12; i++)
         {
             change(i, 3, i, 6);
             change(i, 4, i, 7);
             change(i, 5, i, 8);
         }
     else if(tmp==5)
         for(int i=0; i<12; i++)
         {
             change(i, 6, i, 9);
             change(i, 7, i, 10);
             change(i, 8, i, 11);
         }
     return;
}
void Sudoku::num_change()
{
    int tmp=ran, x, y;
    x=ran%9+1;
    ran/=9;
    y=ran%9+1;
    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++)
        {
            if(ques[i][j]==x)
                ques[i][j]=y;
            else if(ques[i][j]==y)
                ques[i][j]=x;
        }
    return;
}
void Sudoku::ReadIn()
{
    space=0;
    check=0;
    for(int j=0; j<12; j++)
        for(int i=0; i<12; i++)
        {
            scanf("%d", &Sudo[i][j]);
            if(Sudo[i][j]==0)
            {
                spa_c[space]=i;
                spa_r[space++]=j;
            }
            else if(Sudo[i][j]==-1)
                check++;
        }
}
int Sudoku::column_check(int c)
{
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<12; i++)
    {
        if(Sudo[c][i]==-1||Sudo[c][i]==0)
            continue;
        if(flag[Sudo[c][i]]==true)
            return -1;
        flag[Sudo[c][i]]=true;
    }
    return 0;
}
int Sudoku::row_check(int r)
{
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<12; i++)
    {
        if(Sudo[i][r]==-1||Sudo[i][r]==0)
            continue;
        if(flag[Sudo[i][r]]==true)
            return -1;
        flag[Sudo[i][r]]=true;
    }
    return 0;
}
int Sudoku::block_check(int c, int r)
{
    memset(flag, 0, sizeof(flag));
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(Sudo[c-i][r-j]==0)
                continue;
            if(flag[Sudo[c-i][r-j]]==true)
                return -1;
            flag[Sudo[c-i][r-j]]=true;
        }
    return 0;
}
void Sudoku::space_solve(int N)
{
    if(N==space)
    {
        for(int i=0; i<12; i++)
        {
            check=column_check(i);
            if(check==-1)
                break;
            check=row_check(i);
            if(check==-1)
                break;
        }
        if(check!=-1)
            for(int i=2; i<12; i+=3)
                for(int j=2; j<12; j+=3)
                {
                    if(Sudo[i][j]==-1)
                        continue;
                    check=block_check(i, j);
                    if(check==-1)
                        break;
               }
        if(check!=-1)
        {
            ans_n++;
            if(ans_n==1)
                for(int i=0; i<12; i++)
                    for(int j=0; j<12; j++)
                        ans[i][j]=Sudo[i][j];
        } 
        return;
    }
    for(int i=1; i<10; i++)
    {
        if(pos[N][i])
            continue;
        Sudo[spa_c[N]][spa_r[N]]=i;
        space_solve(N+1);
        if(ans_n>1)
            break;
    }
    return;
}
void Sudoku::Solve()
{
    if(check!=36)//檢查-1的數目
    {
        cout<<"0\n";
        return;
    }
    check=0;
    memset(flag1, 0, sizeof(flag1));
    memset(flag2, 0, sizeof(flag2));
    for(int i=2; i<12; i=i+3)
        for(int j=2; j<12; j=j+3)
            if(Sudo[i][j]==-1&&flag1[i]==0&&flag2[j]==0)
            {
                check++;
                flag1[i]=1;
                flag2[j]=1;
                for(int k=0; k<3; k++)
                    for(int l=0; l<3; l++)
                        if(Sudo[i-k][j-l]!=-1)//-1的位置不正確
                        {
                            cout<<"0\n";
                            return;
                        }
            }
    if(check!=4)//-1的block數不正確
    {
        cout<<"0\n";
        return;
    }
    for(int i=0; i<12; i++)//判斷行列中不能有重複數字
    {
        check=column_check(i);
        if(check==-1)
        {
            cout<<"0\n";
            return;
        }
        check=row_check(i);
        if(check==-1)
        {
            cout<<"0\n";
            return;
        }
    }
    for(int i=2; i<12; i+=3)//判斷九宮格內不能有重複數字
        for(int j=2; j<12; j+=3)
        {
            if(Sudo[i][j]==-1)
                continue;
            check=block_check(i, j);
            if(check==-1)
            {
                cout<<"0\n";
                return;
            }
        }
    if(space>64)//判斷空格大於64時不可能只有一解
    {
        cout<<"2\n";
        return;
    }
    memset(pos, 0, sizeof(pos));
    for(int i=0; i<space; i++)
    {
        int c=spa_c[i], r=spa_r[i];
        for(int j=0; j<12; j++)
        {
            if(Sudo[c][j]!=-1)
                pos[i][Sudo[c][j]]=true;
            if(Sudo[j][r]!=-1)
                pos[i][Sudo[j][r]]=true;
        }
        c=c+2-(c%3);
        r=r+2-(r%3);
        for(int k=0; k<3; k++)
            for(int l=0; l<3; l++)
                pos[i][Sudo[c-k][r-l]]=true;
        check=0;
        for(int j=1; j<10; j++)
            if(pos[i][j]==false)
                check++;
        if(!check)//如果空格無法填入任何1~9的數即代表無解
        {
            cout<<"0\n";
            return;
        }
    }
    ans_n=0;
    space_solve(0);
    if(ans_n==0)
        cout<<"0\n";
    else if(ans_n>1)
        cout<<"2\n";
    else if(ans_n==1)
    {
        printf("1\n");
        for(int j=0; j<12; j++)
        {
            printf("%d", ans[0][j]);
            for(int i=1; i<12; i++)
                printf(" %d", ans[i][j]);
            puts("");
        }
    }
    return;
}
