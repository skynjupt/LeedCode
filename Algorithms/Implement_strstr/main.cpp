/*
	https://leetcode.com/problems/implement-strstr/
	{
		Implement strStr().

		Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

		Update (2014-11-02):
		The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.	
	}
*/


#include <iostream>
#include <string.h>

using namespace std;

/*return the index of the first occurrentce of needle in haystack, 
  or -1 if needle is not part of haystack.*/
#if 0
int strStr(char *haystack, char *needle) {
	if(haystack == NULL || needle == NULL) {
		cout << "haha" << endl;
		return -1;
	}

	int len1 = strlen(haystack);
	int len2 = strlen(needle);

	if(len2 == 0) {
		return 0;
	}

	if(len1 < len2) {
		cout << "ee" << endl;
		return -1;
	}

	cout << "len1:" << len1 << endl;
	cout << "len2:" << len2 << endl;

	for(int i = 0; i < len1; i++) {
		int t = i;
		int j = 0;
		while(j < len2 && t < len1) {
			if(haystack[t++] != needle[j]) {
				break;
			} else {
				j++;
			}
		}

		if(j == len2) {
			return i;
		}
	}

	cout << "tt" << endl;
	return -1;	
}
#else

void fail(char *p, int *f) {
	if(p == NULL || f == NULL) {
		return;
	}

	int n = strlen(p);
	f[0] = -1;
	for( int i = 0, j = -1; i < n-1; ) {
		if(j == -1 || p[i] == p[j]) {
			i++;
			j++;
			if(p[i] == p[j]) {
				f[i] = f[j];
			} else { 
				f[i] = j;
			}
//			cout << i << endl;
		} else {
			j = f[j];
		}
	}
}

int strStr(char *haystack, char *needle) {
	if(haystack == NULL || needle == NULL) {
		return -1;
	}	
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
//	if(len2 == 0)
//		return 0;
	int *F = new int[len2];
//	int F[len2];
	fail(needle, F);
	int i = 0, j = 0;
//	while( i <= len1-len2 ) {
	while( i < len1 && j < len2) {
		if(j == -1 || haystack[i] == needle[j]) {
			i++;
			j++;
		} else {
			j = F[j];
		}
	}
	delete[] F;

	return j == len2 ? i-len2 : -1;

}
#endif

int main(int argc, char *argv[])
{
	char *t1 = "hellofdsf";	
	char *t2 = "fds";
	cout << strStr(t1, t2) << endl;

	// Output: -1, Expected: 0
	char *t3 = "";	
	char *t4 = "";
	cout << strStr(t3, t4) << endl;

	// Output: 0, Expected: -1 
	char *t5 = "mississippi";	
	char *t6 = "a";
	cout << strStr(t5, t6) << endl;

	return 0;
}
