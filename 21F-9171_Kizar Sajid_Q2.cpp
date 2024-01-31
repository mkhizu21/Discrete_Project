#include <iostream>
using namespace std;


void printMST(int** matrix, int* parent, int n)
{
	int minCost = 0;//getting minimum cost
	cout << "edges   cost" << endl;
	for (int i = 0; i < n; i++)
	{

		if (parent[i] != -1)
		{  //       vertex 1         vertex 2        cost between them
			cout << parent[i] + 1 << "--" << i + 1 << "    " << matrix[parent[i]][i] << endl;
			minCost += matrix[parent[i]][i];//adding minimum cost
		}

	}
	cout << "minimum cost: " << minCost << endl;
}
void createMST(int** matrix, int n, int* cost, int m)//function to create MST
{
	int* parent;
	int* parent1;
	parent1 = new int[n];
	parent = new int[n];//array for getting vertices
	bool* ok;
	ok = new bool[m];//checking if the weight is visited
	int edge_check = 0;//checking no of edges
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}

	for (int i = 0; i < m; i++)
	{
		ok[i] = false;
	}

	for (int i = 0; i < m; i++)//loop for checking weight
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (matrix[j][k] == cost[i] && ok[i] == false && edge_check < n - 1)//condition to get the weight
				{

					if (parent[j] != parent[k] || parent[k] == -1)
					{

						if (parent[k] == -1 && parent1[k] != parent[j])
						{
							ok[i] = true;
							parent[k] = j;//j is the parent of k vertex
							parent1[j] = k;
							edge_check++;//no of edge created
						}

					}

				}
			}
		}
	}
	cout << endl;
	printMST(matrix, parent, n);//function to print edges
}
int main()
{
	int** arr;
	int n, m, c;
	cout << "Input number of vertices: ";//getting number of vertices
	cin >> n;
	arr = new int* [n];//matrix of certain vertices
	for (int i = 0; i < n; i++)//making matrix
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)//initializing matrix with 0
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	cout << "Enter number of edges: ";//get number of edges
	cin >> m;
	int* costs;
	costs = new int[m];//array for saving costs of all edges
	int x, y;
	for (int k = 0; k < m; k++)
	{
		cout << "Enter 1st vertice: ";//1st vertice
		cin >> x;
		cout << "Enter 2nd vertice: ";//2nd vertice
		cin >> y;
		cout << "Enter cost: ";//cost between two vertices
		cin >> c;
		arr[x - 1][y - 1] = c;
		arr[y - 1][x - 1] = c;
		costs[k] = c;
	}
	cout << "Adjacency Matrix: " << endl;
	cout << "  ";
	for (int i = 0; i < n; i++)//adjacency matrix making
	{
		cout << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)//output adjacency matrix
	{
		cout << i + 1 << " ";
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)//sorting the weights in increasing order
		{
			if (costs[j] > costs[j + 1] && j + 1 < m)
			{
				int t = costs[j];
				costs[j] = costs[j + 1];
				costs[j + 1] = t;
			}
		}
	}
	cout << endl;
	createMST(arr, n, costs, m);//function to create MST
	system("pause");
	return 0;
}
