/*
  stats_test.cpp

  Description:
    School project. C++
    Simple program that receives a set of integers and calculates the
    mean, median and mode.
*/

#include "iostream.h"

/* Maximum number of elements to process. */
#define MAX_N 100

void main()
{
  int i, j, k;
  int mode, max_count;
  float mean, median, count = 0;
  /* Total number of elements in the data set. */
  int n;
  /* Data set. */
  int data_set[MAX_N];

  /* Get the user input. */
  cout<<"Total number of elements (max is "<<MAX_N<<"): ";
	cin>>n;
  n = (n <= MAX_N) ? n : MAX_N;
  
	cout<<"\nEnter the elements one by one:"<<endl;
	for (i = 0; i < n; i++)
	{
		cin>>data_set[i];
	}
  
  /* Calculate the mean (usual average). */
	for (i = 0; i < n; i++)
	{
		count += data_set[i];
	}
	mean = count / n;

  /* Bubble sort the array of integers. */
	for (i = 0; i < (n - 1); i++)
	{
		for (j = (i + 1); j < n; j++)
		{
			if (data_set[j] < data_set[i])
			{
				k = data_set[j];
				data_set[j] = data_set[i];
				data_set [i] = k;
			}
		}
	}
  /* Print the sorted array. */
	for (i = 0; i < n; i++)
		cout<<data_set[i]<<"-";

  /* Calculate the median (middle number) using the sorted array. If there
   * is an even number of numbers, the median is the average between the two
   * middle numbers. */
	k = n / 2;
	if ((n % 2) == 0)
		median = (data_set[k] + data_set[k - 1]) / 2;
	else
		median = data_set[k];

  /* Find the mode (element that repeats the most) in the sorted array. */
	max_count = 1;
	for (i = 1; i < n; i++)
	{
    k = data_set[i];
    count = 0;

    /* Count how many times k appears in the data set. */
		while (k == data_set[i])
		{
			count++;
			i++;
		}
    /* Keep the maximum number of times an integer repeats in the data set. */
		if (count > max_count)
		{
			max_count = count;
			mode = data_set[i - 1];
		}
	}
  /* If all integers appear just once in the data set, there is no mode. */
	if (max_count == 1)
		mode = 0;

  /* Print the results to the standard output. */
	cout<<"Mean = "<<mean<<", Median = "<<median<<", Mode = "<<mode<<endl;
}
