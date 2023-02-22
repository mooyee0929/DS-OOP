#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class matrix
{
public:
	vector<vector<int> > M;


	matrix()
	{
		//TO_DO: Initialize a matrix of size 3 * 3
		M.resize(3);
		for (int i = 0; i < 3; ++i) {
			M[i].resize(3);
		}
	}

	matrix(vector<vector<int> >& m)
	{
		M = m;
	}

	// TO_DO: Implement a function to multiply two matrices.
	void multiply( matrix m) {
		matrix n;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int temp = 0;
				for (int k = 0; k < 3; k++) {
					temp += M[i][k] * m.M[k][j];
				}
				n.M[i][j] = temp;
			}
		}
		*this = n;
	}

	// TO_DO: Implement a function to calculate the classic adjoint matrix.
	matrix adj_matrix() {
		matrix adj;
		int det[4], count;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				count = 0;
				for (int k = 0; k < 3; k++) {
					for (int L = 0; L < 3; L++) {
						if (k != j && L != i) det[count++] = M[k][L];
					}
				}
				adj.M[i][j] = det[0] * det[3] - det[1] * det[2];
				if ((i + j) % 2 == 1) adj.M[i][j] *= -1;
			}
		}
		return adj;
	}
	// TO_DO: Implement a function to calculate the determinant.
	int determinant() {
		matrix A = *this;
		A.multiply(this->adj_matrix());
		
		return A.M[0][0];
	}

	// A.printMatrix();
	void printMatrix() {
		cout << M[0][0] << "\t" << M[0][1] << "\t" << M[0][2] << endl;
		cout << M[1][0] << "\t" << M[1][1] << "\t" << M[1][2] << endl;
		cout << M[2][0] << "\t" << M[2][1] << "\t" << M[2][2] << endl;
	}
};


int main()
{
	fstream fin;

	fin.open("testcase.txt", ios::in);
	if (!fin) {
		cout << "not open" << endl;
		exit(0);
	}

	int n;
	fin >> n;
	matrix matrix;

	for (int i = 0; i < n; i++) {
		////////////////////////
		// TO_DO: read the input and call the functions you've implemented to generate the output
		for (int j = 0; j < 3; j++) {
			fin >> matrix.M[j][0] >> matrix.M[j][1] >> matrix.M[j][2];
		}
		////////////////////////
		cout << "The determinant of the matrix M: " << matrix.determinant() << endl;
	}
	
	return 0;
}
