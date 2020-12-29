/*
316. ȥ���ظ���ĸ
����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���

ʾ�� 1��
���룺s = "bcabc"
�����"abc"

ʾ�� 2��
���룺s = "cbacdcbc"
�����"acdb"

��ʾ��
1 <= s.length <= 104
s ��СдӢ����ĸ���

�������̣�
1. һ��ʼ�����⣬�о����򵥵ġ����͹�ϣ�����¶����
2. ���û��ô�򵥣�������˵����ȫû�������������͵�
3. �������󣬻�Ȼ����ԭ�������ѣ���ʵ���Ǽ򵥵�˫��ѭ��+ջ
*/

char * removeDuplicateLetters(char * s)
{
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
