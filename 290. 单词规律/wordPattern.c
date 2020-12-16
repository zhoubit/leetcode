/*
290. ���ʹ���
����һ�ֹ��� pattern ��һ���ַ��� str ���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�
����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�

ʾ��1:
����: pattern = "abba", str = "dog cat cat dog"
���: true

ʾ�� 2:
����:pattern = "abba", str = "dog cat cat fish"
���: false

ʾ�� 3:
����: pattern = "aaaa", str = "dog cat cat dog"
���: false

ʾ�� 4:
����: pattern = "abba", str = "dog dog dog dog"
���: false

˵��:
����Լ��� pattern ֻ����Сд��ĸ�� str �������ɵ����ո�ָ���Сд��ĸ��

�������̣�
1. ��һ��Ӧ�ǹ�ϣ��ϸ����Ŀ�󣬾������ⲻӦ�÷��ڼ򵥣���Ϊ�Ҿ������Ⲣ����
2. ��һ����Ҫ���鼯����Ϊ����������й�
3. �����ڵ�˼·�ǣ��ȶ�pattern���в�����Ȼ���ù�ϣ���¼��str��ÿ�����ʵ���ĸ��������Ƚ��˷ѿռ䣨��Լ�ռ�Ļ������Լ�¼��������ĸλ�ã�
4. ��ѡ���˷ѿռ�ģ���Ϊ��¼����ĸ�Ļ��ͱȽ��鷳
5. ��ʵ���и����⣬���������ַ����ĸ������ܲ�һ�£���ʵ��ܼ����жϣ�str�еĿո���һ����pattern_len-1��ͬʱ�ո�����һ������ĸ��
   �ҿ�����������ϣ���ʱ��ͼ����Ƿ��Ƕ�Ӧ�� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASHLEN 26

bool isSame (int *hash1, int *hash2)
{
	int i;
	for (i = 0; i < HASHLEN; i++)
		if (hash1[i] != hash2[i])
			return false;
	return true;
}

bool wordPattern(char * pattern, char * s)
{
	int patternlen = strlen (pattern), slen = strlen (s);
	int *set, **hash;
	int i, j;
	
	set = (int*)malloc(sizeof(int)*patternlen);
	hash = (int**)malloc(sizeof(int*)*patternlen);
	
	memset (set, -1, sizeof(int)*patternlen);
	
	for (i = 0; i < patternlen; i++)
	{
		for (j = 0; j < i; j++) //ȷ������
		{
			if (pattern[i] == pattern[j])
			{
				set[j]--;
				set[i] = j;
				break;
			}
		}
		
		hash[i] = (int*)malloc(sizeof(int)*HASHLEN);
		memset (hash[i], 0, sizeof(int)*HASHLEN);
	}
	
	j = 0;
	for (i = 0; i < slen; i++) //��¼hash
	{
		if (s[i] == ' ')
		{
			if (i == 0 || i == slen-1 || s[i-1] == ' ' || s[i+1] == ' ')
				return false;
			
			if (++j >= patternlen) //�����������࣬�ڴ˷�ֹ����Խ�����
				return false;
		}
		else
			hash[j][s[i]-'a']++;
	}
	if (j < patternlen-1) //������������
		return false;
	
	for (i = 0; i < patternlen; i++)
	{
		for (j = i+1; set[i] < 0 && j < patternlen; j++)
		{
			if (set[j] == i && isSame (hash[i], hash[j]) == false) //ͬһ�����ϵ���Ԫ�ز���� 
				return false; 
			else if (set[j] < 0 && set[i] < 0 && isSame (hash[i], hash[j]) == true) //��ͬ���ϵ�Ԫ�����
				return false;
			//���迼����Ԫ��֮���Ƿ����
		}
	}
	
	return true;
}

int main (void)
{
	char pattern[] = "abba", s[] = "dog dog dog dog";
	if (wordPattern(pattern, s))
		printf ("\n%d\n", 1);
	
	return 0;
}
