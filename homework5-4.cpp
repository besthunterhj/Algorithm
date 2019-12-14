/*
回溯法之N叉树问题
*/


#include <iostream>
using namespace std;

const int maxn = 31;

struct item
{
	int value[maxn];
	int weight[maxn];
}items[maxn];

int n;	//定义多少个部件
int m;	//定义多少个供货商
int d;	//定义能花的总价格 
int currentSpace = 0;	//当前花费 
int currentWeight = 0;	//当前重量 
int leastWeight = 50382;		//最小重量方案中的最终重量 
int chosenSaleman[maxn];	//定义一个被选了的供货商情况
int solution[maxn];	//定义选择的供货商情况 

void backtrack(int t)	 
{
	if (t > n)	//达到叶子节点时 
	{
		if (currentWeight < leastWeight)	//更新最低重量 
		{
			leastWeight = currentWeight;
			
			for (int i = 1; i <= n; i++)
			{
				solution[i] = chosenSaleman[i];
			}
		}
		
		return;
	}
	else
	{
		for (int i = 1; i <= m; i++)	//n叉树的模板——遍历n个分支 
		{
			if (currentSpace + items[t].value[i] <= d)	//剪枝函数——超出预定金额范围的方案不选 
			{
				chosenSaleman[t] = i;
				
				currentSpace += items[t].value[i];
				currentWeight += items[t].weight[i];
				
				if (currentWeight < leastWeight)		//限界函数——当前重量超出了之前预选的最低重量就不考虑了 
				{
					backtrack(t + 1);
				}
				
				currentSpace -= items[t].value[i];
				currentWeight -= items[t].weight[i];
			}
		}
		
	}
}


int main()
{
	cin >> n >> m >> d;

	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> items[i].value[j];
		}
	}	 
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> items[i].weight[j];
		}
	}	 
	
	backtrack(1);
	
	cout << leastWeight << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << solution[i] << " "; 
	}
	
	return 0;
}
