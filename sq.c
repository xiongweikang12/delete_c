#include <stdio.h>
struct Splist
{
	int length;
	int* p;

};
void squeeze(int  s[], int t[],int lens,int lent);
int len(int  s[]);
void squeeze_new(struct Splist* s, struct Splist* t);
void print(int s[]);

int main()
{	
	int  ss[100] = {1,5,8,4};
	int  tt[100] = {7,2,5,6,10,5,8,8,9,10};
	struct Splist s;
	struct Splist t;
	s.p = &ss;
	t.p = &tt;
	t.length = len(tt);
	s.length = len(ss);
	print(ss);
	print(tt);
	printf("处理后的顺序表\n");
	squeeze(ss, tt, s.length,t.length);
	squeeze_new(&s, &t);

	return 0;
}

int len(int s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return i;
}

void squeeze(int  s[], int t[],int lens, int lent)
{
	int a;
	int b ;
	int j = 0;
	int k;
	
	
	for (a = 0; t[a] != '\0'; a++)
	{	
		b = 0;
		while ((s[b] != t[a])&&(s[b]!='\0'))
		{
			b++;
		}
		if (b ==( lens))
		{
			continue;
		}
		else
		{
			for (j = a; j < lent; j++)
			{
				t[j] = t[j + 1];
			}
		}
		a--;
	}
	for (k = 0; t[k] != '\0'; k++) {
		printf("%d,", t[k]);
	}
	printf("\n");
}

void squeeze_new(struct Splist* s, struct Splist* t)
{	
	int a;
	int b;
	int j=0;
	int k;

	for (a = 0; s->p[a] != '\0'; a++)//遍历待删除的字符串
	{
		b = 0;
		while ((s->p[b] != t->p[a]) && (s->p[b] != '\0'))//遍历待删除字符串，与待比较字符串
		{
			b++;
		}
		if (b == s->length)//判断是否遍历完全
		{
			continue;
		}
		else
		{
			for (j = a; j < t->length; j++)//a为待删除的元素位置，通过顺序表删除的思想
			{
				t->p[j] = t->p[j + 1];
			}
		}
		a--;//删除后位置返回到删除元素的前一个，继续遍历

	}
	for (k = 0; t->p[k] != '\0'; k++)
	{
		printf("%d,", t->p[k]);
	}
	printf("\n");
}

void print(int s[])
{
	int i = 0;
	while (s[i]!='\0')
	{ 
		printf("%d,", s[i]);
		i++;
	}
	printf("\n");
}
