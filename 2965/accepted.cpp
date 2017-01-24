/*
-��ʾ�򿪣���0��+��ʾ���ϣ� ��1

ע�⵽����ÿһ��'+'�����Խ�����������ȫ����תһ�飬����'+'��ת�������Σ����������и��Ӷ�ֻ��ת��ż���Ρ���ע�⵽�����ӷ�תż����ʱ������ȥ���ɽ�

��bfs���˲��٣������ƺ���һ���ľ����ԣ�����Ŀ��ת��ʽ�����£���������������ż����������ν�����²��Լ��ɣ� 

�������Ŀ�ĳ����ƿ����Ƶķ�ת��ʽ���ƺ�ֻҪ���߽�����1�Ϳ���ͬ���ˣ�Ч����������Ϊÿ�η�ת��Ҫ���������̲����������ǿ��ܻ��Ǳ�bfsҪ��һ�� 
*/

#include<stdio.h>
#include<string.h>

char a[5][5];
int state = 0;                                                   //This 'state' is different from the 'state' of bfs. The 'bit x of state == 1' here means bit[x] need to be changed.
int change[16] = {
	63624, 62532, 61986, 61713,
	36744, 20292, 12066, 7953,
	35064, 17652, 8946, 4593,
	34959, 17487, 8751, 4383,
};

void solve(){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(a[i][j] == '+')
				state = state ^ change[15 - (i * 4 + j)];        //'state' is reversed here to be output in the right way.

	return;
}

void output(){                                                   //Each '1' in state means 1 flip on that bit.
	int s, step;
	s = state;
	step = 0;
	for(int i = 0; i < 16; i++){
		if(s == 0) break;
		if(s & 1 == 1) step++;
		s >>= 1;
	}
	printf("%d\n", step);
		
	s = state;
	for(int i = 0; i < 16; i++){
		if(s & 1 == 1) printf("%d %d\n", i / 4 + 1, i % 4 + 1);
		s >>= 1;
	}
	
	return;
}

int main(){
	for(int i = 0; i < 4; i++)
		scanf("%s", a[i]);		
	
	solve();
	output();
	
	return 0;	
}
