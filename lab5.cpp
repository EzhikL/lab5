
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

#include <stdlib.h>
#include <string.h>
#include <string>

#include <memory>
#include <cassert>

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;



void Distance(int** matrix, int startDot, int N) {
	int* distance = new int[N];
	int index, m = startDot + 1;
	bool* visited = new bool[N];

	for (int i = 0; i < N; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[startDot] = 0;

	for (int i = 0; i < N - 1; i++) {
		int min = INT_MAX;

		for (int j = 0; j < N; j++)
			if (!visited[j] && distance[j] <= min) {
			min = distance[j];
			index = j;
			}

		visited[index] = true;
		for (int j = 0; j < N; j++)
			if (!visited[j] && matrix[index][j] && (distance[index] != INT_MAX) &&
				((distance[index] + matrix[index][j]) < distance[j]))
				distance[j] = distance[index] + matrix[index][j];
	}

	cout << "Result: \n";

	for (int i = 0; i < N; i++)
		if (distance[i] != INT_MAX)
			cout << m << " -> " << i + 1 << " = " << distance[i] << endl;
		else
			cout << m << " -> " << i + 1 << " = " << "Doesn't exists." << endl;

	delete[] distance;
	delete[] visited;
}

void main(int argc, char** argv) {
	int n = 0;
	int dot = 0;
	cout << "Write N: ";
	cin >> n;
	cout << "Initialize: \nExample: 1 -> 1 = 0\nif 1 -> 2";
	cout << " = 0 -> distance doesn't exists.  \n";
	int ** array = new int*[n];

	for (int i = 0; i < n; i++) {
		array[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> array[i][j];
	}
	cout << "Write start dot: ";
	cin >> dot;
	Distance(array, dot - 1, n);

	for (int i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;

	system("pause");
