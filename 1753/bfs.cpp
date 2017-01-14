/* 
���ݽṹ�����С� 
˼·��bfs ����Ҫ�ݹ�
�ѵ㣺bfs 
���Ӷȣ�ʱ�临�ӶȺ�����O(2^n)����Ϊ������ÿһ��״̬��Ҫ���������ռ临�Ӷ�ȡ���ڶ�����Ԫ�����������O(1)? 
��ʵ�Ҳ���֪������n�̶���������Ӷ���ô�� 
*/ 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct Node{
	int state;
	int step;
};

int visit[65536] = {0};                                                   //visit==true��ʾ���ʹ��ˣ������������ 

int change[16] = {                                                        //ʹ��������flip, 1 ^ 1 = 0, 0 ^ 1 = 1�� 
	51200,58368,29184,12544,  
    35968,20032,10016,4880,  
    2248,1252,626,305,  
    140,78,39,19
	};

int bfs(int state){
	queue<Node>q;                                                         //ʹ��queue����bfs 
	Node cur, next;
	cur.state = state;
	cur.step = 0;
	q.push(cur);
	visit[cur.state] = true;
	
	if(cur.state == 0 || cur.state == 0xffff)                             //0xffff==65535��ȫb  
		return cur.step;
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i = 0; i < 16; i++){	
			next.state = cur.state ^ change[i];                           //flip 
			next.step = cur.step + 1;                                     //���ں�����ʹ��ľͲ�push�����step����ֱ��+1 
			if(visit[next.state])
				continue;
			if(next.state == 0 || next.state == 0xffff)                   
				return next.step;
			visit[next.state] = true;
			q.push(next);
		}
	}
	
	return -1;                                                             //ȫ��״̬������� 
} 

int main(){
	char a[5][5];
	int state;
	int ans;
	
	for(int i = 0; i < 4; i++)
		scanf("%s", a[i]);
	
	state = 0;
	for(int i = 0; i < 4; i++){                                            //��wb��ת��Ϊ01��ʾ��int 
		for(int j = 0; j < 4; j++){
			state <<= 1;
			if(a[i][j] == 'b') state++;
		}
	}
	
	ans = bfs(state);
	if(ans == -1) printf("Impossible");
	else printf("%d", ans);
	
	return 0;
}
