#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef enum {
	false, true
}bool;

int terry[17][31];
int num[17][31];
int st[17][31];//0: 未打开， 1: 已打开, 2: 插旗, 3 : 已确定是地雷 
int dir[] = {1, 0, -1};
int markNum = 0;

bool IsVaild(int r, int c) {
	return r >= 1 && r <= 16 && c >= 1 && c <= 30;
}

void InitMap(int x, int y) {
	srand((int)time(0));
	int cnt = 99;
	while(cnt) {
		int r = rand() % 16 + 1, c = rand() % 30 + 1;
		if(terry[r][c] || (abs(r - x) < 2 && abs(c - y) < 2)) {
			continue;
		} else {
			terry[r][c] = 1;
			cnt--;
		}
	}
}

void mark(int r, int c) {
	if(st[r][c] == 0) {
		st[r][c] = 2;
	} else if(st[r][c] == 2) {
		st[r][c] = 0;
	}
}

void getNum(int r, int c) {
	num[r][c] = 0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(terry[r + dir[i]][c + dir[j]]) {
				num[r][c]++;
			}
		}
	}
}


bool click(int r, int c) {
	if(st[r][c] == 0) {
		if(terry[r][c]) {
			return false;
		}
		st[r][c] = 1;
		getNum(r, c);
		if(num[r][c] == 0) {
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					if(st[r + dir[i]][c + dir[j]] == 0) {
						click(r + dir[i], c + dir[j]);
					}
				}
			}
		}
	} else if(st[r][c] == 1) {
		int cnt = 0;
		//检查插旗数 
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				if(st[r + dir[i]][c + dir[j]] >= 2) {
					cnt ++;
				}
			}
		}
		if(cnt == num[r][c]) {//插旗数量正确时
			
			//检查是否插错 
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					int x = r + dir[i], y = c + dir[j];
					if(st[x][y] == 2 && !terry[x][y]) {
						return false;
					}
				}
			}
			//全部插对， 则把区域内未打开的网格全部打开 
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					int x = r + dir[i], y = c + dir[j];
					if(st[x][y] == 0) {
						click(x, y);
					} else if(st[x][y] == 2) {
						markNum++;
						st[x][y] = 3;
					}
				}
			}
		}
	}
	return true; 
}

void print() {
	//column num
	printf("   ");
	for(int i=1; i<=30; i++) {
		printf("%2d ", i);
	}
	puts("");
	for(int i=1; i<=16; i++) {
		printf("%2d ", i);
		for(int j=1; j<=30; j++) {
			if(st[i][j] == 0) {
				printf(" . ");
			} else if(st[i][j] == 1) {
				printf("%2d ", num[i][j]);
			} else if(st[i][j] == 2){
				printf(" ? ");
			} else {
				printf(" * ");
			}
		}
		puts("");
	}
}

void over() {
	printf("   ");
	for(int i=1; i<=30; i++) {
		printf("%2d ", i);
	}
	puts("");
	for(int i=1; i<=16; i++) {
		printf("%2d ", i);
		for(int j=1; j<=30; j++) {
			printf(" %c ", terry[i][j] ? '*' : '.');
		}
		puts("");
	}
}

void run(bool first) {
	puts("输入\"1 R C\" : 点开<R, C>");
	puts("输入\"2 R C\" : 点标记 / 取消标记 <R, C>为地雷"); 
	printf("请输入指令:");
	int o, r, c;
	scanf("%d%d%d", &o, &r, &c);
	if(!IsVaild(r, c)) {
		return;
	}
	if(first) {
		InitMap(r, c);
	}
	if(o == 2) {
		mark(r, c);
	} else if(o == 1){
		if(!click(r, c)) {
			over();
			puts("游戏失败");
			exit(0);
		}
	}
}

int main() {
	print();
	run(true);
	while(markNum < 99) {
		system("cls");
		print();
		run(false);
	}
	system("cls");
	over();
	puts("游戏胜利");
	return 0;
}



