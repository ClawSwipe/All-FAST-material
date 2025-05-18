#include <iostream>
#include <vector>
#include <mpi.h>
#include <math.h>
#include <fstream>
#include <random>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temporary arrays
	int L[n1], R[n2];

	// Copy data to temporary arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temporary arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{

	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for large l and r
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Merge the sorted halves
		merge(arr, l, m, r);
	}
}

// SWAP INTEGERS
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// BUBBLE SORT
void BubbleSort(int arr[], int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (i % 1000000 == 0)
		{
			printf("\n%d", i);
		}

		for (int j = 0; j < size - i - 1; j++)
		{
			// cout<<"Checking "<<arr[j]<<" and "<<arr[j+1]<<endl;
			if (arr[j] > arr[j + 1])
			{
				// cout<<"Swapping "<<arr[j]<<" and "<<arr[j+1]<<endl;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// PRINT ARRAY
void PrintArray(int arr[], int size, int rank)
{

	cout << "Process " << rank << " recieved array of size " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
}

int main()
{

	// MPI REGION
	MPI_Init(NULL, NULL);

	int rank, size;
	int *local_arr;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{

		vector<int> arr;

		int S;
		cin >> S;

		for (int i = 0; i < S; i++)
		{
			arr.push_back(rand() % S);
		}

		int arr_size = arr.size();

		int chunk = floor(float(arr_size) / size);

		cout << "Chunk: " << chunk << endl;

		int to_send = 1;
		int send_counter = 0;

		int *send_arr = new int[chunk];

		double start, end;

		start = MPI_Wtime();
		// Send input chunk values to process
		for (int i = 0; i < size - 1; i++)
		{

			if (send_counter >= arr_size - 1)
			{
				break;
			}

			for (int j = 0; j < chunk; j++)
			{
				send_arr[j] = arr[send_counter];
				send_counter++;
			}

			MPI_Send(&chunk, 1, MPI_INT, to_send, 100, MPI_COMM_WORLD);
			MPI_Send(send_arr, chunk, MPI_INT, to_send, 101, MPI_COMM_WORLD);
			to_send++;
		}

		// Deactive other unused slaves if any

		int remaining_elements = arr_size - send_counter;

		local_arr = new int[remaining_elements];

		// Master chunk of work
		for (int j = 0; j < remaining_elements; j++)
		{
			local_arr[j] = arr[send_counter++];
		}

		BubbleSort(local_arr, remaining_elements);

		// Compile all sub sorted arrays

		int *final_arr = new int[arr_size];
		int recv_counter = 0;
		int *recv_arr = new int[chunk];

		// From slaves
		for (int i = 1; i < to_send; i++)
		{

			MPI_Recv(recv_arr, chunk, MPI_INT, i, 200, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			for (int j = 0; j < chunk; j++)
			{
				final_arr[recv_counter++] = recv_arr[j];
			}
		}

		// complie from master
		for (int j = 0; j < remaining_elements; j++)
		{
			final_arr[recv_counter++] = local_arr[j];
		}

		// Final Master Sort
		double start2 = MPI_Wtime();
		mergeSort(final_arr, 0, arr_size);
		// PrintArray(final_arr, arr_size, rank);
		double end2 = MPI_Wtime();

		end = MPI_Wtime();

		double time_taken = (end - start) - (end2 - start2);

		cout << "Time Taken: " << time_taken << endl;
		int flag = 0;
		for (int i = 0; i < arr_size - 1; i++)
		{
			if (final_arr[i] > final_arr[i + 1])
			{
				cout << "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO";
				flag = 1;
			}
		}

		cout << flag << endl;
		delete (send_arr);
		delete (recv_arr);
		delete (final_arr);
		FILE *file = NULL;
		file = fopen("result", "w");
		int i;
		for (i = 0; i < arr_size; i++)
		{
			fprintf(file, "%d\n", final_arr[i]);
		}
		fclose(file);
	}
	else
	{

		int local_size;
		MPI_Recv(&local_size, 1, MPI_INT, 0, 100, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		local_arr = new int[local_size];
		MPI_Recv(local_arr, local_size, MPI_INT, 0, 101, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		BubbleSort(local_arr, local_size);

		MPI_Send(local_arr, local_size, MPI_INT, 0, 200, MPI_COMM_WORLD);
	}

	// delete(local_arr);

	MPI_Finalize();
}