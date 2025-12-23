#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int f;
	int lens;
} PrimeAndLens;
typedef struct {
	int f;
	int lens;
	int num;
	int temp;
} NewNum;
NewNum n[30];
PrimeAndLens get_len(int n) {
	PrimeAndLens p;
	int len = 0, temp = n;
	while (n) {
		n /= 10;
		len++;
	}
	p.lens = len;
	len--;
	while (len--) {
		temp /= 10;
	}
	p.f = temp;
	return p;
}
int cmp(const void* p1, const void* p2) {
	NewNum* q1 = ((NewNum*)p1);
	NewNum* q2 = ((NewNum*)p2);
	if (q1->f != q2->f) return q2->f - q1->f;
	else if (q1->lens != q2->lens) {
		NewNum** max = q1->lens < q2->lens ? &q2 : &q1;
		NewNum** min = q1->lens < q2->lens ? &q1 : &q2;
		int temp = (*min)->num % 10;
		int minnum = (*min)->num;
		while (((*max)->lens - (*min)->lens)) {
			minnum = minnum * 10 + temp;
		}
		(*min)->temp = minnum;
		(*max)->temp = (*max)->num;
		return q2->temp - q1->temp;
	}
	else return q2->num - q1->num;
}
int main() {
	int t;
	PrimeAndLens p;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int temp;
		scanf("%d", &temp);
		p = get_len(temp);
		n[i].num = temp;
		n[i].lens = p.lens;
		n[i].f = p.f;
	}
	qsort(n, t, sizeof(n[0]), cmp);
	for (int i = 0; i < t; i++) {
		printf("%d", n[i].num);
	}
}