int clear(int b[100][100]) {
	int i, j = 0;
	int size_of_matrix = 100;
	for (j = 0; j < size_of_matrix; j++) {
		for (i = 0; i < size_of_matrix; i++) {
			b[i][j] = 0;
		}
	}
	return b[100][100];
}
