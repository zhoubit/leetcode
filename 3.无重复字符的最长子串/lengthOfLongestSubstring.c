/*����һ���ַ����������ҳ����в������ظ��ַ���?��Ӵ�?�ĳ��ȡ�

ʾ��?1:
����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ���?"wke"�������䳤��Ϊ 3��
   ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke"?��һ�������У������Ӵ���
*/

/*
����˼·��
 ���ҵ�һ��ͷ�ַ������ƶ�β�ַ���ÿ���ж�β�ַ��Ƿ���ͷ�ַ�֮��β�ַ�֮ǰ���ַ����
1.������ȣ����¼��β�ַ���ȵ����꣬ʹ��һ��ͷ�ַ���ʼ��Ϊ���ַ�����һ���ַ�
2.������ַ�����ʹβ�ַ���һ
3.��ִ�й����У���Ĳ������ַ������ȱ�ʣ����ַ������ȳ�����ֱ���˳�����ѭ�������ص�ǰMaxLen
*/
#include <string.h>

int lengthOfLongestSubstring(char * s)
{
	int MaxLen = 1;
	int searchLen = 1;
	int sLen = (int)strlen(s);
	int i, j, l;
	char head, tail, test;
	
	i = 0;
	if (sLen == 0)
		return sLen;

        for (j = i + 1; j < sLen; j++)
        {
        	head = s[i];
        	tail = s[j];
        	
        	//����β�� 
		for (l = i; l < j; l++)
		{
		        test = s[l];
		        if (tail == test)
		        {
		        	i = l+1;
		        	j = i; //������j = i + 1; ��Ϊ���滹Ҫ����һ��j++ 
		        	break;
		        }
		        searchLen++;
		}

	        if (searchLen > MaxLen)
	        	MaxLen = searchLen;
	        
	        if (MaxLen >= sLen - i)
	        	break;
		
		searchLen = 1; //��ʼ�� 
        }

	return MaxLen;
}
