int clear(int b[100][100]) {
	int i, j = 0;
	int m = 40;
	for (j = 0; j < m; j++) {
		for (i = 0; i < m; i++) {
			b[i][j] = 0;
		}
	}
	return b[100][100];
}
