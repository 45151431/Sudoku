#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
class Sudoku
{
    public:
		Sudoku();
		void GiveQuestion();
        void rotate();
        void change(int i1, int j1, int i2, int j2);
        void column_change();
        void row_change();
        void num_change();
		void ReadIn();
		int column_check(int c);
		int row_check(int r);
		int block_check(int c, int r);
		void space_solve(int N);
		void Solve();
    private:
        int ran;
        int ques[12][12], Sudo[12][12], ans[12][12];
        int spa_c[144], spa_r[144], spa_b[144];//處理空格的行列和block組別
        int space;
        int check;
        int ans_n;
        bool flag1[12], flag2[12], flag[10];
        int pos[144][10], pos_fill[144][10];
};
#endif
