#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int* Monete(int* t, int size, int b) {

	int i = 0;

	int spesa = 0;

	int* out = malloc(sizeof(int) * size);

	for (int l = 0; l < size; ++l) {

		out[l] = 0;
	}

	while ((b < spesa) || (i < size)) {

		if (spesa + t[i] <= b) {

			out[i]++;

			spesa = spesa + t[i];
		}

		else {

			++i;
		}
}

	return out;
}



int main() {

	int t[] = { 50,20,10,5,2,1 };

	int ssize = 6;

	int budget = 126;

	int* c = Monete(t, ssize, budget);

	for (int k = 0; k < ssize; ++k) {

		printf("%d\n", c[k]);
	}

	free(c);
	return 0;
}