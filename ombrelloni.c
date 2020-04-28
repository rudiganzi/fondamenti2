#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void Ombrelloni (int n, int i, int k, bool vcurr[], int cnt,unsigned* nsol){

	if (cnt == k){

		

		
		(*nsol)++;

		for (int j = 0; j < n; ++j) {

			printf("%2d", vcurr[j]);
		}

		printf("\n\n");
		return;
	}







	vcurr[i] = 0;

	Ombrelloni(n, i + 1, k, vcurr, cnt, nsol);

	if (i == 0 && (vcurr[i - 1] != 1)) {

		vcurr[i] = 1;

		Ombrelloni(n, i + 1, k, vcurr, cnt + 1, nsol);
	}

}







int main() {

	int kk = 2;

	int n = 4;

	bool* vcurr;

	vcurr = malloc(sizeof(bool) * n);
	unsigned nsol = 0;
	int cnt = 0;

	Ombrelloni(n, 0, kk, vcurr, cnt, &nsol);

	return EXIT_SUCCESS;
}