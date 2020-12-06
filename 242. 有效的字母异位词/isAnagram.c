/*
242. ��Ч����ĸ��λ��
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true

ʾ�� 2:
����: s = "rat", t = "car"
���: false

˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����˼·��
1. �ַ���ֻ����Сд��ĸ�����ʮ�ּ��ˣ�����ʹ�ù�ϣ��
2. ����ռ��СΪ26
*/

#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t){
	int slen=strlen(s), tlen=strlen(t);
	
	if (slen != tlen)
		return false;
	
	int hash[26]; //��ʼ��Ϊ0
	int i, j;
	
	memset(hash, 0, 26); //��hash��ǰ26��Ԫ���滻��0
	//������ϣ��
	for (i = 0; i < slen; i++)
	{
		j = (int)(s[i]-'a');
		hash[j]++; //��������
	}
	
	//��������
	for (i = 0; i < tlen; i++)
	{
		j = (int)(t[i]-'a');
		
		if (hash[j] == 0)
			return false;
		hash[j]--;
	}
	return true;
}
