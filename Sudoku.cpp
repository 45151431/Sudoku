#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cstring>
#include"Sudoku.h"
using namespace std;
/*******GiveQuestion*******/
int ques_init[12][12]={
	0,0,0,0,2,0,-1,-1,-1,0,8,6,
	1,0,0,8,0,7,-1,-1,-1,5,0,4,
	5,0,0,0,0,0,-1,-1,-1,0,0,0,
	0,0,7,0,0,0,6,3,0,-1,-1,-1,
	0,5,4,0,0,3,0,0,7,-1,-1,-1,
	0,6,0,0,8,0,0,2,0,-1,-1,-1,
	-1,-1,-1,0,4,0,0,0,0,0,0,0,
	-1,-1,-1,9,0,0,1,0,0,0,5,0,
	-1,-1,-1,0,0,0,0,0,0,0,3,0,
	0,0,0,-1,-1,-1,0,6,0,0,7,8,
	0,0,0,-1,-1,-1,0,8,0,3,6,2,
	0,0,0,-1,-1,-1,0,0,0,0,0,0};//初始的Sudoku
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
	ran=rand();
	num_change();
	ran=rand();
	num_change();
    for(int j=0; j<12; j++)//output question
    {
        printf("%d", ques[0][j]);
        for(int i=1; i<12; i++)
            printf(" %d", ques[i][j]);
        puts("");
    }
    return;
}
void Sudoku::rotate()//根據random值做轉0度,90度,180度,270度
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
void Sudoku::change(int i1, int j1, int i2, int j2)//設置一個函數方便我做交換
{
    int tmp=ques[i1][j1];
    ques[i1][j1]=ques[i2][j2];
    ques[i2][j2]=tmp;
    return;
}
void Sudoku::column_change()//根據random值做大column間的交換
{
    int tmp=ran%6;
    if(tmp==0)
        for(int j=0; j<12; j++)
        	for(int i=0; i<3; i++)
            	change(i, j, i+6, j);
    else if(tmp==1)
        for(int j=0; j<12; j++)
        	for(int i=3; i<6; i++)
            	change(i, j, i+6, j);
    else if(tmp==2)
        for(int j=0; j<12; j++)
        	for(int i=0; i<3; i++)
            	change(i, j, i+9, j);
    else if(tmp==3)
        for(int j=0; j<12; j++)
        	for(int i=0; i<3; i++)
        	    change(i, j, i+3, j);
    else if(tmp==4)
        for(int j=0; j<12; j++)
        	for(int i=3; i<6; i++)
    	        change(i, j, i+3, j);
    else if(tmp==5)
        for(int j=0; j<12; j++)
        	for(int i=6; i<9; i++)
	            change(i, j, i+3, j);
    return;
}
void Sudoku::row_change()//根據random值做大row間的交換
{
	int tmp=ran%3;
    if(tmp==0)
		for(int i=0; i<12; i++)
			for(int j=0; j<3; j++)
            	change(i, j, i, j+6);
    else if(tmp==1)
        for(int i=0; i<12; i++)
            for(int j=3; j<6; j++)
    	        change(i, j, i, j+6);
    else if(tmp==2)
        for(int i=0; i<12; i++)
        	for(int j=0; j<3; j++)
    	        change(i, j, i, j+9);
    else if(tmp==3)
        for(int i=0; i<12; i++)
	        for(int j=0; j<3; j++)
	            change(i, j, i, j+3);
    else if(tmp==4)
        for(int i=0; i<12; i++)
    		for(int j=3; j<6; j++)
				change(i, j, i, j+3);
    else if(tmp==5)
        for(int i=0; i<12; i++)
            for(int j=6; j<9; j++)
            	change(i, j, i, j+3);
    return;
}
void Sudoku::num_change()//根據random值做number間的交換
{
    int tmp=ran, x, y;
    x=tmp%9+1;
    tmp/=9;
    y=tmp%9+1;
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
/*******ReadIn part*******/
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
                spa_r[space]=j;
				spa_b[space++]=i+2-(i%3)+12*(j+2-(j%3));//Read in時順便將空格所屬的的column,row,block存起來
            }
            else if(Sudo[i][j]==-1)//紀錄-1的總數
                check++;
        }
}
/*******Solve part*******/
int Sudoku::column_check(int c)//檢查column有沒有重複的數字
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
int Sudoku::row_check(int r)//檢查row有沒有重複的數字
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
int Sudoku::block_check(int c, int r)//檢查block有沒有重複的數字
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
void Sudoku::space_solve(int N)//recursive解題function
{
    if(N==space)//填寫完成後,做重複的檢查
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
            if(ans_n==1)//檢查後發現沒有重複的數字即為解,如果是第一個解,將它存下來
                for(int i=0; i<12; i++)
                    for(int j=0; j<12; j++)
                        ans[i][j]=Sudo[i][j];
        }
        return;
    }
    for(int i=1; i<10; i++)
    {
        if(pos[N][i]||pos_fill[N][i])//本來就不能填的數字和前面填了導致不能填的數字都要continue
            continue;
		for(int j=N+1; j<space; j++)//前面的數字填寫後,影響後面數字的填寫
			if(spa_c[N]==spa_c[j]||spa_r[N]==spa_r[j]||spa_b[N]==spa_b[j])//同column,row,block的會受影響
			{
				pos_fill[j][Sudo[spa_c[N]][spa_r[N]]]++;
				pos_fill[j][i]--;
			}
        Sudo[spa_c[N]][spa_r[N]]=i;//將數字填入
        space_solve(N+1);//recursive
        if(ans_n>1)//ans_n>1代表發現重複解,將function終止
            return;
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
    for(int i=0; i<12; i++)//判斷column,row中不能有重複數字
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
    for(int i=2; i<12; i+=3)//判斷block內不能有重複數字
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
    if(space>96)//判斷空格大於96時不可能只有一解
    {
        cout<<"2\n";
        return;
    }
    memset(pos, 0, sizeof(pos));
    for(int i=0; i<space; i++)//判斷在原始題目下,空格能填的數字
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
    ans_n=0;//將ans數歸0
	memset(pos_fill, 0, sizeof(pos_fill));
    space_solve(0);//呼叫解題的function
    if(ans_n==0)//無解
        cout<<"0\n";
    else if(ans_n>1)//非唯一解
        cout<<"2\n";
    else if(ans_n==1)//唯一解
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
