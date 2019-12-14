/*
���ݷ�֮N��������
*/


#include <iostream>
using namespace std;

const int maxn = 31;

struct item
{
	int value[maxn];
	int weight[maxn];
}items[maxn];

int n;	//������ٸ�����
int m;	//������ٸ�������
int d;	//�����ܻ����ܼ۸� 
int currentSpace = 0;	//��ǰ���� 
int currentWeight = 0;	//��ǰ���� 
int leastWeight = 50382;		//��С���������е��������� 
int chosenSaleman[maxn];	//����һ����ѡ�˵Ĺ��������
int solution[maxn];	//����ѡ��Ĺ�������� 

void backtrack(int t)	 
{
	if (t > n)	//�ﵽҶ�ӽڵ�ʱ 
	{
		if (currentWeight < leastWeight)	//����������� 
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
		for (int i = 1; i <= m; i++)	//n������ģ�塪������n����֧ 
		{
			if (currentSpace + items[t].value[i] <= d)	//��֦������������Ԥ����Χ�ķ�����ѡ 
			{
				chosenSaleman[t] = i;
				
				currentSpace += items[t].value[i];
				currentWeight += items[t].weight[i];
				
				if (currentWeight < leastWeight)		//�޽纯��������ǰ����������֮ǰԤѡ����������Ͳ������� 
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
