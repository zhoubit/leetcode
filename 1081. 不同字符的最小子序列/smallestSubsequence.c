/*
1081. ��ͬ�ַ�����С������
�����ַ��� text �а��ֵ���������С�������У��������а��� text �����в�ͬ�ַ�һ�Ρ�

ʾ�� 1��
���룺"cdadabcc"
�����"adbc"

ʾ�� 2��
���룺"abcd"
�����"abcd"

ʾ�� 3��
���룺"ecbacba"
�����"eacb"

ʾ�� 4��
���룺"leetcode"
�����"letcod"

��ʾ��
1 <= text.length <= 1000
text ��СдӢ����ĸ���
*/

char * smallestSubsequence(char * s){
	int hash[26], vis[26];
	int i, slen = strlen(s), top, n;
	
	memset (hash, 0, sizeof(int)*26); //��Ÿ���
	memset (vis, 0, sizeof(int)*26); //�Ƿ���ջ
	
	for (i = 0; i < slen; i++)
		hash[s[i]-'a']++;
	
	char *stack;
	stack = (char*)malloc(sizeof(char)*27); //ջ
	top = 0;
	
	for (i = 0; i < slen; i++)
	{
		n = s[i]-'a';
		if (vis[n] == 0)
		{
			while (top > 0 && stack[top-1] > s[i] && hash[stack[top-1]-'a'] > 0)
				vis[stack[--top]-'a'] = 0;
			
			stack[top++] = s[i];
			vis[n] = 1;
		}
		hash[n]--;
	}
	stack[top] = '\0';
	
	return stack;
}
