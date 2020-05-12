#include<stdio.h>
typedef struct node {
	int start;
	int end;
	int time;
}node;
int main()
{
	int n;
	node Arr[130];
	printf("请输入活动数:\n");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("请输入开始时间和结束时间:%d\n", i + 1);
		scanf_s("%d %d", &Arr[i].start, &Arr[i].end);

		Arr[i].time = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			if (Arr[i].end > Arr[j].end)
			{
				int etmp = Arr[i].end;
				int stmp = Arr[i].start;
				Arr[i].end = Arr[j].end;
				Arr[i].start = Arr[j].start;
				Arr[j].end = etmp;
				Arr[j].start = stmp;
			}

		}

	int sep = 0;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i].start >= sep)
		{
			Arr[i].time = 1;
			sep = Arr[i].end;
		}

	}
	int index = 1;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i].time == 1)
		{
			printf("最多能安排的活动数量是%d\n", index);
			index++;
		}
	}

}