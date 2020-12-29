/*
387. �ַ����еĵ�һ��Ψһ�ַ�
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��

ʾ����
s = "leetcode"
���� 0

s = "loveleetcode"
���� 2
 
��ʾ������Լٶ����ַ���ֻ����Сд��ĸ��

�������̣�
1. ��ϣ���¼��ĸ�����Լ�����ĸ���ֵĵ�һ��λ��
2. �ڶ������Ǳ���������Ϊ1����λ����С����ĸ
3. ��������Ŀǰ��ĸ��λ��
*/

int firstUniqChar(char * s)
{
	int num[26], addr[26];
	int slen = strlen (s);
	int i, ret = slen;
	
	memset (num, 0, sizeof(int)*26);
	
	for (i = 0; i < slen; i++)
	{
		num[s[i]-'a']++;
		addr[s[i]-'a'] = i;
	}
	
	for (i = 0; i < 26; i++)
		if (num[i] == 1 && ret > addr[i])
			ret = addr[i];
	
	return ret == slen ? -1:ret;
}
