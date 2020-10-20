#include<stdio.h>
const int maxsize = 20;
struct sparse {
	int n, m, z;
	int row[maxsize];
	int col[maxsize];
	int element[maxsize];
};
void input(struct sparse *mat) {
	printf("Enter the number of rows and column \n");
	scanf("%d %d", &mat->n, &mat->m);
	int fullmatrix[mat->n][mat->m];
	printf("Enter the elements of the original matrix\n");
	for (int i = 0; i < mat->n; i++) {
		for (int j = 0; j < mat->m; j++) {
			scanf("%d", &fullmatrix[i][j]);
		}
		printf("\n");
	}
	int k = 0;
	for (int i = 0; i < mat->n; i++) {
		for (int j = 0; j < mat->m; j++) {
			if (fullmatrix[i][j] != 0) {
				mat->row[k] = i + 1;
				mat->col[k] = j + 1;
				mat->element[k] = fullmatrix[i][j];
				k++;
			}
		}
	}
	mat->z = k;

}
void print_sparsematrix(struct sparse mat) {
	printf("Matrix in 3-Column representation: \n");
	printf(" _____________________\n");
	printf("|Row No|Col No|element|\n");
	for (int i = 0; i < mat.z; i++) {
		printf("|  %d   |  %d   |   %d   | \n", mat.row[i], mat.col[i], mat.element[i]);
	}
	printf("|______|______|_______|\n");
}

struct sparse add(struct sparse m1, struct  sparse m2) {
	struct sparse m3;
	int k = 0;
	int i = 0, j = 0;
	while (i < m1.z and j < m2.z) {
		if (m1.row[i] < m2.row[j]) {
			m3.row[k] = m1.row[i];
			m3.col[k] = m1.col[i];
			m3.element[k] = m1.element[i];
			i++, k++;
		} else if (m1.row[i] == m2.row[j] and m1.col[i] < m2.col[j]) {
			m3.row[k] = m1.row[i];
			m3.col[k] = m1.col[i];
			m3.element[k] = m1.element[i];
			i++, k++;
		} else if (m1.row[i] == m2.row[j] and m1.col[i] == m2.col[j]) {
			if (m1.element[i] + m2.element[j] != 0) {
				m3.row[k] = m1.row[i];
				m3.col[k] = m1.col[i];
				m3.element[k] = m1.element[i] + m2.element[j];
				i++, k++, j++;
			}
		}
		else {
			m3.row[k] = m2.row[j];
			m3.col[k] = m2.col[j];
			m3.element[k] = m2.element[j];
			k++, j++;

		}
	}
	while (i < m1.z) {
		m3.row[k] = m1.row[i];
		m3.col[k] = m1.col[i];
		m3.element[k] = m1.element[i];
		i++, k++;
	}
	while (j < m2.z) {
		m3.row[k] = m2.row[j];

		m3.col[k] = m2.col[j];
		m3.element[k] = m2.element[j];
		j++, k++;
	}
	m3.z = k;
	return m3;
}
int main() {
	sparse m1, m2, m3;
	printf("\n---------MATRIX A----------\n");
	input(&m1);
	print_sparsematrix(m1);
	printf("\n---------MATRIX B----------\n");
	input(&m2);
	print_sparsematrix(m2);
	m3 = add(m1, m2);
	printf("\n\n********** Matrix after Addition ***********\n\n");
	print_sparsematrix(m3);
	return 0;

}

