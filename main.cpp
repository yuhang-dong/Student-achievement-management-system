#include<stdio.h>
#include<stdlib.h>
#define size sizeof(struct stu)
struct stu
{
	int num;
	char name[20];
	char sex;
	int age;
	float score[3];
	float and;
}stu[300];



void dayin(int k)
{
	int i;
	printf("学号    姓名     性别     年龄    英语     高数     物理");
	printf("\n-------------------------------------------------------------------\n");
	for (i = 0; i < k; i++)
		printf("%6d%6s%6c  %6d  %6.2f  %6.2f  %6.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].age, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	printf("\n-------------------------------------------------------------------\n");
}


void adddate1(int j)
{
	int i = 0;
	for (; i < j; i++)
	{
		printf("请输入学生学号：");  scanf("%d", &stu[i].num);
		printf("请输入学生姓名：");  scanf("%s", &stu[i].name);
		getchar();
		printf("请输入性别(男F 女M)：");  scanf("%c", &stu[i].sex);
		printf("请输入年龄"); scanf("%d", &stu[i].age);
		printf("请输入英语成绩：");  scanf("%f", &stu[i].score[0]);
		printf("请输入高数成绩：");  scanf("%f", &stu[i].score[1]);
		printf("请输入计算机成绩："); scanf("%f", &stu[i].score[2]);
	}
}

void zengjia(int j)
{
	printf("请输入学生学号：");  scanf("%d", &stu[j].num);
	printf("请输入学生姓名：");  scanf("%s", &stu[j].name);
	getchar();
	printf("请输入性别(男F 女M)：");  scanf("%c", &stu[j].sex);		printf("请输入年龄"); scanf("%d", &stu[j].age);

	printf("请输入英语成绩：");  scanf("%f", &stu[j].score[0]);
	printf("请输入高数成绩：");  scanf("%f", &stu[j].score[1]);
	printf("请输入计算机成绩："); scanf("%f", &stu[j].score[2]);
}
void editdata(int j)
{
	int i, k;
	int no;
	printf("请输入要修改学生的学号:");
	scanf("%d",&no);
	k = -1;
	for (i = 0; i<j; i++)
	{
		if (no==stu[i].num)
		{
			k = i;
			break;
		}
	}
	if (k == -1)
	{
		printf("\n\n没有找到该学生(学号d)!", no);
	}
	else
	{
		printf("请输入学生学号：");  scanf("%d", &stu[k].num);
		printf("请输入学生姓名：");  scanf("%s", &stu[k].name); getchar();
		printf("请输入性别(男F 女M)：");  scanf("%c", &stu[k].sex);		printf("请输入年龄"); scanf("%d", &stu[k].age);

		printf("请输入英语成绩：");  scanf("%f", &stu[k].score[0]);
		printf("请输入高数成绩：");  scanf("%f", &stu[k].score[1]);
		printf("请输入计算机成绩："); scanf("%f", &stu[k].score[2]);
		printf("\n修改数据成功\n");
	}
}
void shanchu(int j)
{
	int i, k;
	int n;
	printf("请输入要删除学生的学号:");
	scanf("%d",&n);
	k = -1;
	for (i = 0; i < j; i++)
	{
		if (n == stu[i].num)
		{
			k = i;
			break;
		}
	}
	if (k == -1)
	{
		printf("\n\n没有找到该学生(学号%d)!", n);
	}
	else
	{
		for (i = k; i < j - 1; i++)	//将后面的数据前移一位
			stu[i] = stu[i + 1];
	}
}
void querydatano(int j)
{
	int i, k, l;

	printf("选择排序方式（1.学号 \n2.年龄 \n3.总成绩）");
	scanf("%d", &i);
	switch (i)
	{
	case 1: for (k = 0; k < j - 1; k++)
		for (l = 0; l < j - 1 - l; l++)
			if (stu[l].num > stu[l + 1].num)
			{
				stu[300] = stu[l];
				stu[l] = stu[l + 1];
				stu[l + 1] = stu[300];

			}break;
	case 2: for (k = 0; k < j - 1; k++)
		for (l = 0; l < j - 1 - l; l++)
			if (stu[l].age > stu[l + 1].age)
			{
				stu[300] = stu[l];
				stu[l] = stu[l + 1];
				stu[l + 1] = stu[300];

			}break;
	case 3: for (k = 0; k < j - 1; k++)
		for (l = 0; l < j - 1 - l; l++)
			if (stu[l].and > stu[l + 1].and)
			{
				stu[300] = stu[l];
				stu[l] = stu[l + 1];
				stu[l + 1] = stu[300];

			}break;
	}
	dayin(j);
}
void find(int j)
{
	int max, min, i, k, l, m=0;
	printf("最高分：");
	scanf("%d", &max);
	printf("最低分：");
	scanf("%d", &min);
	printf("满足条件的学生为：\n");
	for (i = 0; i < j; i++)
		if (stu[i].and >= min&&stu[i].and <= max)
		{
			printf("%d%s\n", stu[i].num, stu[i].name);
			m++;
		}
	printf("总人数为%d", m);
}
void sortdatano(j)
{
	int i, k, l, m, n, o;
	printf("要在哪个学号前添加数据？");
	scanf("%d",&i);
	for (k = 0; k < j; k++)
		if (i = stu[k].num)
			break;
	//k以后数据全向后挪一位
	for (o = j - 1; o >= k; o--)
		stu[o] = stu[o + 1];
	zengjia(k);
}

void main()
{
	int fun, i = 1, j, k = 0;
	FILE *fp;
	printf("文件中是否有原始数据（1-yes，0-no）");
	scanf("%d", &fun);
	if (fun == 0)
	{
		printf("需要添加的总共人数:");
		scanf("%d", &j);
		adddate1(j);
	}
	else
	{

		if ((fp = fopen("D:\\data.dat", "r")) == NULL) // 如果文件不存在
		{
			printf("ERROR!");

		}
		while(!feof(fp))
		{
			fread(&stu[k], sizeof(struct stu), 1, fp);
			k++;
		}
		j = k-1;//总人数
		fclose(fp);
	}
	for (int m = 0; m < j; m++)
		stu[i].and = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];

	while (i)
	{
		printf("请输入功能号[0-7]:\n");
		printf("1 查看所有学生信息\n2 输入学生记录(将会添加在最后)\n3 删除学生记录\n4 修改学生记录\n5 排序输出）\n6 查找分数段\n7 插入学生记录\n8 退出\n");
		scanf("%d", &fun);
		switch (fun)
		{
		case 1: dayin(j); break;        // 查看所有学生信息
		case 2: zengjia(j); j++; break;       // 输入学生记录 (添加在最后)
		case 3: shanchu(j); j--;  break;      // 删除学生记录
		case 4: editdata(j); break;    // 修改学生记录
		case 5: querydatano(j); break;   // 排序输出
		case 6: find(j); break;   //  查找分数段
		case 7:{ sortdatano(j); j++;} break;   //  插入学生记录
		case 8: i = i - 1; break;                   // 退出
		}
	}
	if ((fp = fopen("D:\\data.dat", "w")) == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	for (i = 0; i < j; i++)
		fwrite(&stu[i], sizeof(struct stu), 1, fp);
	fclose(fp);
}
