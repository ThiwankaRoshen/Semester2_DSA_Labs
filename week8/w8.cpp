
#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{  //initialize ro variable as largest
   int ro = root;   

   //calculate indices
   int l = 2 * root + 1;
   int r = 2 * root + 2;

   //compare with left and right childs , update the ro accordingly
   if (r< n && arr[r] > arr[ro])
      ro = r;
   if (l < n && arr[l] > arr[ro])
      ro = l;
   if (ro != root)
   {
      //swap arr[root] and arr[largest]
      int temp = arr[root];
      arr[root] = arr[ro];
      arr[ro] = temp;

      heapify(arr, n, ro);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{  //Build a max heap from the arr
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

   for (int j = n - 1; j >= 0; j--)
   {
      //swap arr[0] and arr[i]
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;

      heapify(arr, j, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << endl;
}

// main program
int main()
{
   int n;

   //prompt user for number of items in the list
   cout << "Enter the number of elements: ";
   cin >> n;

   //store them 
   int heap_arr[n];
   cout << "Enter the elements: ";
   for (int i = 0; i < n; i++)
      cin >> heap_arr[i];
   
   //output the input array
   cout << "Input array" << endl;
   displayArray(heap_arr, n);

   //sorts the array 
   heapSort(heap_arr, n);
   
   //output sorted array
   cout << "Sorted array" << endl;
   displayArray(heap_arr, n);

   return 0;
}
