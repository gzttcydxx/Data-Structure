#include <stdlib.h>
#include "sorts.h"

// ≤Â»Î≈≈–Ú
Status INSERTSORT(ElemType* K, int n) {
	int j;
	ElemType tmp;
	for (int i = 1; i < n; i++) {
		tmp = K[i];
		j = i - 1;
		while (j >= 0 && K[j] > tmp) K[j + 1] = K[j--];
		K[j + 1] = tmp;
	}
	return OK;
}

// ’€∞Î≤Â»Î≈≈–Ú
Status BININSERTSORT(ElemType* K, int n) {
	int low, mid, high;
	ElemType tmp;
	for (int i = 1; i < n; i++) {
		tmp = K[i];
		low = 0;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (tmp < K[mid]) high = mid - 1;
			else low = mid + 1;
		}
		for (int j = i - 1; j >= low; j--) K[j + 1] = K[j];
		K[low] = tmp;
	}
	return OK;
}

// —°‘Ò≈≈–Ú
Status SELECTSORT(ElemType* K, int n) {
	int minid;
	ElemType tmp;
	for (int i = 0; i < n; i++) {
		minid = i;
		for (int j = i; j < n; j++) if (K[j] < K[minid]) minid = j;
		if (minid != i) {
			tmp = K[i];
			K[i] = K[minid];
			K[minid] = tmp;
		}
	}
	return OK;
}

// √∞≈›≈≈–Ú∑®
Status BUBBLESORT(ElemType* K, int n) {
	int flag;
	ElemType tmp;
	for (int i = 1; i < n; i++) {
		flag = 1;
		for (int j = 0; j < n - i; j++) if (K[j] > K[j + 1]) {
			tmp = K[j];
			K[j] = K[j + 1];
			K[j + 1] = tmp;
			flag = 0;
		}
		if (flag) return OK;
	}
	return OK;
}

// œ£∂˚≈≈–Ú
Status SHELLSORT(ElemType* K, int n) {
	int flag, gap = n;
	ElemType tmp;
	while (gap > 1) {
		gap /= 2;
		do {
			flag = 0;
			for (int i = 0; i < n - gap; i++) if (K[i] > K[i + gap]) {
				tmp = K[i];
				K[i] = K[i + gap];
				K[i + gap] = tmp;
				flag = 1;
			}
		} while (flag);
	}
	return OK;
}