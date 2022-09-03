#include <stdio.h>
#include <windows.h>
int map[4][4];

void judge(int cnt, int *victory, int *fail, int *w) {
	if(cnt == 2) {
		*fail = 1;
	} else if(cnt == -2) {
		*victory = 1;
	} else {
		*w += abs(cnt);
	}
} 

int getWeight(int r, int c) {
	int victory = 0, fail = 0, cnt = 0, w = 0;
	cnt = map[1][c] + map[2][c] + map[3][c];
	judge(cnt, &victory, &fail, &w);
	cnt = map[r][1] + map[r][2] + map[r][3];
	judge(cnt, &victory, &fail, &w);
	if(r == c) {
		cnt = map[1][1] + map[2][2] + map[3][3];
		judge(cnt, &victory, &fail, &w);
	} else if(r + c == 4) {
		cnt = map[1][3] + map[2][2] + map[3][1];
		judge(cnt, &victory, &fail, &w);
	}
	
	if(victory) {
		return 1000;
	} else if(fail) {
		return 100;
	} else {
		return w;
	}
}

void defense() {
	if(map[2][2] == 0) {
		map[2][2] = -1;
	} else {
		int r, c, weight = -1;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				if(map[i][j] == 0) {
					int w = getWeight(i, j);
					if(w > weight) {
						r = i, c = j, weight = w;
					}
				}
			}
		}
		map[r][c] = -1;
	}	
}

int fail(int x) {
	for(int i=1; i<=3; i++) {
		if(map[i][1] == x && map[i][2] == x && map[i][3] == x) {
			return 1;
		}
		if(map[1][i] == x && map[2][i] == x && map[3][i] == x) {
			return 1;
		}
	}
	int a = 1, b = 1;
	for(int i=1; i<=3; i++) {
		a &= (map[i][i] == x);
		b &= (map[i][4-i] == x);
	}
	return a || b;
}

void print() {
	for(int i=1; i<=3; i++) {
		if(i == 1) {
			puts("+ - + - + - +");
		} 
		for(int j=1; j<=3; j++) {
			if(j == 1) {
				printf("|");
			}
			if(map[i][j] == 0) {
				printf("   ");
			} else if(map[i][j] == 1) {
				printf(" O ");
			} else {
				printf(" X ");
			}
			printf("|");
		}
		puts("\n+ - + - + - +");
	}
}

int check(int r, int c) {
	return r >= 1 && r <= 3 && c >= 1 && c <= 3 && map[r][c] == 0;
}

void Input() {
	print();
	puts("请输入你要画圈的位置");
	int r, c; scanf("%d%d", &r, &c);
	if(!check(r, c)) {
		puts("你输入的位置无效, 请重新输入！");
		system("pause");
		system("cls");
		Input();
	} else {
		map[r][c] = 1;
	}
	system("cls"); 
}


int main() {
	for(int i=1; i<=5; i++) {
		Input();
		if(fail(1)) {
			print();
			puts("你赢了， 冠军");
			system("pause");
			return 0;
		}
		defense();
		if(fail(-1)) {
			print();
			puts("你输了, loser");
			system("pause");
			return 0;
		}
	}
	print();
	puts("平局！");
	system("pause");

	return 0;
}

