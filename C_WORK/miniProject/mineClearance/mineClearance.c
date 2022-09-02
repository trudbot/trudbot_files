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
int st[17][31];//0: δ�򿪣� 1: �Ѵ�, 2: ����, 3 : ��ȷ���ǵ��� 
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
		//�������� 
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				if(st[r + dir[i]][c + dir[j]] >= 2) {
					cnt ++;
				}
			}
		}
		if(cnt == num[r][c]) {//����������ȷʱ
			
			//����Ƿ��� 
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					int x = r + dir[i], y = c + dir[j];
					if(st[x][y] == 2 && !terry[x][y]) {
						return false;
					}
				}
			}
			//ȫ����ԣ� ���������δ�򿪵�����ȫ���� 
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
	puts("����\"1 R C\" : �㿪<R, C>");
	puts("����\"2 R C\" : ���� / ȡ����� <R, C>Ϊ����"); 
	printf("������ָ��:");
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
			puts("��Ϸʧ��");
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
	puts("��Ϸʤ��");
	return 0;
}



