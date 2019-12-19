/*
回溯法之子集树问题
这道题的backtrack需要修改为有两个形参
（本来还想用优先队列，但感觉小题大做了，只要满足：
当前村民没选过、当前村民与选了的村民不是敌人即要走他的左子树） 

AC了的 
*/



#include <iostream>
using namespace std;

const int maxn = 1051;
bool revenge[maxn][maxn];	//敌对关系矩阵 
int n;	//村民数目 
int m;	//敌对关系数目 
int maxSum = 0;	//记录最多村民情况下的村民数目
int solution[maxn];	//记录最优解情况下选取村民的情况
int x[maxn];	//子集树向量 
 
 
void backtrack(int t, int sum)		//sum表示已选取的村民数目 
{
	
	if (t > n)
	{
		if (sum > maxSum)
		{
			maxSum = sum;
			
			for (int i = 1; i <= n; i++)
			{
				solution[i] = x[i];		//将选取的村民情况复制到最优解情况下 
			}
		}
		return;
	}
	
	bool flag = true;	//当目前遍历的村民与选取的村民不为敌人时，为true 
	
	for (int i = 1; i <= n; i++)	//这个循环的作用是，判断该不该选当前遍历的村民，只要符合没选过且不和之前选的是敌人即可 
	{
		if (i == t)	continue;
		if (x[i] == 1 && revenge[i][t])
		{
			flag = false;
			break;
		}
	 } 

	if (flag)		//满足条件就让sum加1，同时开始遍历下一个村民 
	{
		x[t] = 1;	//满足条件，走左子树 
		backtrack(t + 1, sum + 1);
		x[t] = 0;
	}
	
	backtrack(t + 1, sum);	//不满足条件直接走右子树且sum不变 
}



 
int main()
{
	cin >> n >> m; 
	
	for (int i = 0; i < m; i++)
	{
		int j, k;
		cin >> j >> k;
		revenge[j][k] = true;
		revenge[k][j] = true;
	}
	
	backtrack(1, 0);
	
	cout << maxSum << endl;
	
	for (int i = 1; i <= n; i++)
	{
		cout << solution[i] << " ";
	}
	
	return 0;
}