#include <iostream>
#include <vector>
#include <mpi.h>
#include <math.h>
#include <fstream>
#include <random>
using namespace std;

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
			arr.push_back(rand() % 101);
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
		BubbleSort(final_arr, arr_size);

		PrintArray(final_arr, arr_size, rank);

		end = MPI_Wtime();

		double time_taken = end - start;

		cout << "Time Taken: " << time_taken << endl;

		delete (send_arr);
		delete (recv_arr);
		delete (final_arr);
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