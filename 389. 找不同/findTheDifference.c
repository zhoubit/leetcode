/*
389. �Ҳ�ͬ

���������ַ��� s �� t������ֻ����Сд��ĸ��
�ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ��
���ҳ��� t �б���ӵ���ĸ��

ʾ�� 1��
���룺s = "abcd", t = "abcde"
�����"e"
���ͣ�'e' ���Ǹ�����ӵ���ĸ��

ʾ�� 2��
���룺s = "", t = "y"
�����"y"

ʾ�� 3��
���룺s = "a", t = "aa"
�����"a"

ʾ�� 4��
���룺s = "ae", t = "aea"
�����"a"

��ʾ��
0 <= s.length <= 1000
t.length == s.length + 1
s �� t ֻ����Сд��ĸ

�������̣�
1. ����һ����̫���˰ɣ�ֱ��һ����ϣ��ͳ��s����ĸ���༰������Ȼ���ٱ���t��ͬ����������Ϊ-1������Ƕ��������ĸ
2. �ٿ�����ʾ����Ҫʲô��ϣ��ֱ�ӽ�s��ASCII���������ټ�t��ASCII���������������
*/

char findTheDifference(char * s, char * t)
{
	int ascii_sum = 0, i;
	int slen = strlen(s);
	
	for (i = 0; i < slen; i++)
		ascii_sum += t[i]-s[i];
	ascii_sum += t[slen];
	
	return ascii_sum;
}

//�������������ⷨ����һ�μ������ַ��������һ�£�������
char findTheDifference(char* s, char* t) {
	int n = strlen(s), m = strlen(t);
	int as = 0, at = 0;
	for (int i = 0; i < n; i++) {
		as += s[i];
	}
	for (int i = 0; i < m; i++) {
		at += t[i];
	}
	return at - as;
}
