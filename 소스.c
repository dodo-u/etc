#include <stdio.h>
#define True 1
#define False 0

int plusone(int a);
int equal(int a, int b);
int greater_than(int a, int b);		/*a가 크면 retrun true, b가 크면 return false    */
int not(int a);
int abs(int a);
int mul(int a, int b);

int plus(int a, int b);
int minus(int a, int b);
int multiple(int a, int b);
int mok(int a, int b);
int namege(int a, int b);





int main() {

	while (1) {
		char ope;
		int a, b;
		printf("숫자 2개 입력 : ");
		scanf_s("%d %d", &a, &b);
		getchar();
		printf("연산 입력[+,-,*,/] : ");
		scanf_s("%c", &ope);	

		

		if (equal(ope, (int)43)) {
			if (equal(a, 0)) {
				if (equal(b, 0)) printf("answer : %d\n\n", 0);
				else printf("answer : %d\n\n", b);
			}
			else if (equal(b, 0)) {
				printf("answer : %d\n\n", a);
			}
			else if (greater_than(a, 0)) {
				if (greater_than(b, 0)) printf("answer : %d\n\n", plus(a, b));
				else {
					if (greater_than(a,abs(b))) printf("answer : %d\n\n", minus(a, abs(b)));
					else printf("answer : m%d\n\n", minus(a, abs(b)));
				}
			}
			else {
				if (greater_than(0, b)) printf("answer : m%d\n\n", plus(abs(a), abs(b)));
				else {
					if (greater_than(b, abs(a))) printf("answer : %d\n\n", minus(b, abs(a)));
					else printf("answer : m%d\n\n", minus(b, abs(a)));
				}
			}
			
		}
		else if (equal(ope, (int)45)) {
			if (equal(a, b)) printf("answer : %d\n\n", 0);
			else if (greater_than(a, b)) printf("answer : %d\n\n", minus(a, b));
			else printf("answer : m%d\n\n", minus(a, b));
		}
		else if (equal(ope, (int)42)) {
			if (equal(a,0)) printf("answer : %d\n\n", 0);
			else if (equal(b,0)) printf("answer : %d\n\n", 0);
			else if (mul(a,b)) printf("answer : %d\n\n", multiple(abs(a), abs(b)));
			else printf("answer : m%d\n\n", multiple(abs(a), abs(b)));
		}
		else if (equal(ope, (int)47)) {
			printf("answer : 몫은 %d  나머지는 %d\n\n", mok(a, b), namege(a,b));
		}
		else {
			printf("잘못된 연산자 입니다\n\n");
		}
	}



	return 0;
}


int plusone(int a) {
	return ++a;
}

int equal(int a, int b) {
	if (a == b) return True;
	else return False;
}

int greater_than(int a, int b) {
	int aa = a;
	int bb = b;

	while (1) {
		aa = plusone(aa);
		bb = plusone(bb);
		if (equal(aa, b)) {
			return False;
		}
		else if(equal(bb, a)) {
			return True;
		}
	}
}

int not(int a) {
	if (equal(a, True)) return False;
	else return True;
}

int plus(int a, int b) {
	int ans = 0;
	int temp = 0;
	if (equal(a, 0)) {
		if (equal(b, 0)) return 0;
		else return b;
	}
	else if (equal(b, 0)) return a;

	if (greater_than(a, 0)) {
		if (greater_than(b, 0)) {
			while (not(equal(ans, a))) {
				ans = plusone(ans);
			}
			while (not(equal(temp, b))) {
				ans = plusone(ans);
				temp = plusone(temp);
			}
		}
	}
	else {
		if (greater_than(0, b)) {
			while (not(equal(0, a))) {
				a = plusone(a);
				ans = plusone(ans);
			}
			while (not(equal(0, b))) {
				b = plusone(b);
				ans = plusone(ans);
			}
		}

	}
	

	return ans;
}

int minus(int a, int b) {
	int ans = 0;

	if (equal(a, b)) return 0;
	else if (greater_than(a, b)) {
		while (not(equal(a, b))) {
			ans = plusone(ans);
			b = plusone(b);
		}
	}
	else {
		while (not(equal(a, b))) {
			ans = plusone(ans);
			a = plusone(a);
		}
	}

	return ans;
}


int abs(int a) {
	if (greater_than(a, 0)) return a;
	else {
		int num = 0;

		while (not(equal(a, 0))) {
			a = plusone(a);
			num = plusone(num);
		}

		return num;
	}
}

int mul(int a, int b) {

	if (greater_than(a, 0)) {
		if (greater_than(b, 0)) {
			return True;
		}
		else return False;
	}
	else {
		if (greater_than(b, 0)) {
			return False;
		}
		else return True;
	}
}

int multiple(int a, int b) {
	int ans = 0;
	int bb = 0;

	if (equal(a, 0)) return 0;
	else if (equal(b, 0)) return 0;
	
	while (not(equal(bb, b))) {
		ans = plus(ans, a);
		bb = plusone(bb);
	}

	return ans;
}

int mok(int a, int b) {

	int ans = 0;
	int aa = 0;
	int bb = 0;

	while (not(equal(a, aa))) {
		aa = plusone(aa);
		bb = plusone(bb);
		if (equal(bb, b)) {
			ans = plusone(ans);
			bb = 0;
		}
	}
	return ans;
}

int namege(int a, int b) {
	return minus(a, multiple(b, mok(a, b)));
}