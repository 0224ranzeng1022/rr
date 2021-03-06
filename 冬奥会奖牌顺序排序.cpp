#include<stdio.h>
#define N 3//定义符号常量为信息数
typedef struct student 
{
	char country[20];
	float num;
}std;//定义结构体类型名为std

void sr(std *,int );//定义输入函数
void xie(std *,int );
void du(std *,int );
void sc(std *,int );//定义输出函数

int main()
{
	std sx[N],sxt[N];
	sr(sx,N);//输入内容并排序
	xie(sx,N);//将内容存入文本
	du(sxt,N);//从文本读取内容到内存
	sc(sxt,N);//输出内容
	return 0;
}

void sr(std sx1[],int n)//输入内容到内存中
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		printf("请输入第%d行信息：\n",i+1);
		printf("国家  金牌数：\n");
		scanf("%s%f",&sx1[i].country,&sx1[i].num);
	}//输入内容到内存中

	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	if(sx1[j].num < sx1[j+1].num)
	{
		t=sx1[j].num;
		sx1[j].num=sx1[j+1].num;
		sx1[j+1].num=t;
	}
	//将内容按金牌数降序排序
}

void xie(std sx2[],int n)//将内容以二进制形式写入文本
{
	FILE *fp;
	int i;
	if((fp=fopen("d:\\y\\lzy\\text.txt","wb"))==NULL)
	{
		printf("文件打开失败！！！\n");
		return ;
	}
	for(i=0;i<n;i++)
	{
		fwrite(&sx2[i],sizeof(std),1,fp);//写二进制文件
	}
	rewind(fp);//将文件指针指到文件头
	fclose(fp);//关闭函数文件
}

void du(std sx3[],int n)//将二进制文本内容读取到内存中
{
	FILE *fp;
	int i;
	if((fp=fopen("d:\\y\\lzy\\text.txt","rb"))==NULL)
	{
		printf("文件打开失败！！！\n");
		return ;
	}
	for(i=0;i<n;i++)
	{
		fread(&sx3[i],sizeof(std),1,fp);//读二进制文件
	}
	fclose(fp);//关闭函数文件
	return ;
}

void sc(std sx4[],int n)//输出内存中的内容
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t%s\t%f\n",i+1,sx4[i].country,sx4[i].num);

}