/*
205. 同构字符串

给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:
输入: s = "egg", t = "add"
输出: true

示例 2:
输入: s = "foo", t = "bar"
输出: false

示例 3:
输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

解题思路：
1. 乍一看，简单的题怎么使我毫无思路。。。
2. 我实在是想不到很聪明的办法
3. 对两个字符串进行遍历，依次对字符进行修改，用哈希表记录字母的替换情况
4. 本来以为又是长篇大论，结果边写边改就只有那么几行，所以啊，不是所有都那么复杂的，只要我好好思考过
5. 我服了，竟然还有数字！！！所以就依然是哈希表，但是不限制26了！ 
*/

bool isIsomorphic(char * s, char * t)
{
	int len = strlen(s);
	if (len == 0)
		return true;
	
	int shash[256] = {0}, thash[256] = {0};
	int i;
	int snew = 2, tnew = 2;
	
	shash[s[0]] = 1;
	thash[t[0]] = 1;
	
	for (i = 1; i < len; i++)
	{
		if (shash[s[i]] == 0)
			shash[s[i]] = snew++;
		
		if (thash[t[i]] == 0)
			thash[t[i]] = tnew++;
        
		if (shash[s[i]] != thash[t[i]])
			return false;
	}
	
	return true;
}
