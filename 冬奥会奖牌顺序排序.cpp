#include<stdio.h>
#define N 3//������ų���Ϊ��Ϣ��
typedef struct student 
{
	char country[20];
	float num;
}std;//����ṹ��������Ϊstd

void sr(std *,int );//�������뺯��
void xie(std *,int );
void du(std *,int );
void sc(std *,int );//�����������

int main()
{
	std sx[N],sxt[N];
	sr(sx,N);//�������ݲ�����
	xie(sx,N);//�����ݴ����ı�
	du(sxt,N);//���ı���ȡ���ݵ��ڴ�
	sc(sxt,N);//�������
	return 0;
}

void sr(std sx1[],int n)//�������ݵ��ڴ���
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		printf("�������%d����Ϣ��\n",i+1);
		printf("����  ��������\n");
		scanf("%s%f",&sx1[i].country,&sx1[i].num);
	}//�������ݵ��ڴ���

	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	if(sx1[j].num < sx1[j+1].num)
	{
		t=sx1[j].num;
		sx1[j].num=sx1[j+1].num;
		sx1[j+1].num=t;
	}
	//�����ݰ���������������
}

void xie(std sx2[],int n)//�������Զ�������ʽд���ı�
{
	FILE *fp;
	int i;
	if((fp=fopen("d:\\y\\lzy\\text.txt","wb"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�����\n");
		return ;
	}
	for(i=0;i<n;i++)
	{
		fwrite(&sx2[i],sizeof(std),1,fp);//д�������ļ�
	}
	rewind(fp);//���ļ�ָ��ָ���ļ�ͷ
	fclose(fp);//�رպ����ļ�
}

void du(std sx3[],int n)//���������ı����ݶ�ȡ���ڴ���
{
	FILE *fp;
	int i;
	if((fp=fopen("d:\\y\\lzy\\text.txt","rb"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�����\n");
		return ;
	}
	for(i=0;i<n;i++)
	{
		fread(&sx3[i],sizeof(std),1,fp);//���������ļ�
	}
	fclose(fp);//�رպ����ļ�
	return ;
}

void sc(std sx4[],int n)//����ڴ��е�����
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t%s\t%f\n",i+1,sx4[i].country,sx4[i].num);

}