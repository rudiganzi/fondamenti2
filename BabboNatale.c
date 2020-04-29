#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void BabboNatale(int p, const int* pacchi, int n, unsigned i, bool* vcurr, bool* vbest, unsigned* max, unsigned cnt, int sum) {

	if (i == n) {

		if (cnt > (*max)) {

			(*max) = cnt;

			memcpy(vbest, vcurr,n* sizeof(bool));
		}

		return;
	}


	vcurr[i] = 0;

	BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);

	sum = sum + pacchi[i];

	if (sum  <= p) {

		
		vcurr[i] = 1;

		BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt + 1, sum );
	}



}









int main() {

	int n = 5;
	int ii = 0;
	int peso = 20;

	int pacchi[5] = { 10,11,1,3, 3 };

	bool* vcurr;
	bool* vbest;

	vcurr = malloc(sizeof(bool) * n);

	vbest = calloc(n, sizeof(bool));

	unsigned max = 0;

	unsigned cnt = 0;

	int summ = 0;

	BabboNatale(peso, pacchi, n, ii, vcurr, vbest, &max, cnt, summ);

	for (int i = 0; i < n; ++i) {

		printf("%1d", vbest[i]);

	}
	printf("\n\n");

	free(vcurr);

	free(vbest);

	return EXIT_SUCCESS;
}