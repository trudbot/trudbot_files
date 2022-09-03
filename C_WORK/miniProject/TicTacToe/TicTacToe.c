#include <stdio.h>
#include <windows.h>
int map[4][4];

int getWeight(int r, int c) {
	int w = 0, t, i;
	for(i=1, t = 0; i<=3; i++) {
		t += map[i][c];
	}
	w += (t == 2);
	if(t == -2) {
		w += 1000;
	}
	for(i = 1, t = 0; i<=3; i++) {
		t += map[r][i];
	}
	w += (t == 2);
	if(t == -2) {
		w += 1000;
	}
	
	if(r == c) {
		w++;
		for(i = 1, t = 0; i<=3; i++) {
			t += map[i][i];
		}
		w += (t == 2);
		if(t == -2) {
			w += 1000;
		}
	}
	
	if(r + c == 4) {
		w++;
		for(i = 3, t = 0; i<=3; i++) {
			t += map[i][4-i];
		}
		w += (t == 2);
		if(t == -2) {
			w += 1000;
		}
	}
	return w;
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
		if(i != 1) {
			puts("-----------");
		} 
		for(int j=1; j<=3; j++) {
			if(j != 1) {
				printf("|");
			}
			if(map[i][j] == 0) {
				printf("   ");
			} else if(map[i][j] == 1) {
				printf(" O ");
			} else {
				printf(" X ");
			}
		}
		puts("");
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
}


int main() {
	for(int i=1; i<=5; i++) {
		Input();
		if(fail(1)) {
			system("cls");
			print();
			puts("你赢了， 冠军");
			system("pause");
			return 0;
		}
		defense();
		system("cls");
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

