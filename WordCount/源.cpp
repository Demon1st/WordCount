
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void charcount(const char *f)//�ַ���ͳ��
{
	FILE *file;
	int char_num = 0;
	char ch;
	if ((file = fopen(f, "r")) == NULL)
	{
		printf("�ļ���ȡʧ��");
	}
	ch = fgetc(file);
	while (ch != EOF) {
		char_num++;
		ch = ch = fgetc(file);
	}
	printf( "�ַ���%d" ,char_num);
	fclose(file);
}
void wordcount(const char *f)//���ʵ�ͳ��
{
	FILE *file;
	int word_num = 0;
	bool flag;
	char ch;
	if ((file = fopen(f, "r")) == NULL)
	{
		printf("�ļ���ȡʧ��");
	}
	ch = fgetc(file);
	while (ch != EOF)
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			flag = 0;
		else if (flag == 0 && (ch == ' ' || ch == ',' || ch == ';' || ch == '.'))
		{
			word_num++;
			flag = 1;
		}
		ch = ch = fgetc(file);
	}
	printf("��������%d", word_num);
	fclose(file);
}
int main(int argc, char **argv)
{
	const char *p = argv[1];
	const char *file_name = argv[2];
	if (strcmp(p,"-c") == 0 )
	{
		charcount(file_name);
	}
	if (strcmp(p,"-w")== 0)
	{
		wordcount(file_name);
	}
	return 0;
}