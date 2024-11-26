// Qais Hweidi

#include <iostream>
#include <vector>

using namespace std;

// insertion sort
int *insertionSort(int* array, int size) {
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0 && array[j] < array[j - 1]; --j) {
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
		}
	}
	return array;
}

// merge sort
int* mergeSort(const int* array, int end, int start = 0) {
    if (end - start <= 1) {
        return new int[1] {array[start]};
    }

    const int mid = (end + start) / 2;
    const int leftSize = mid - start;
    const int rightSize = end - mid;

    int* leftArray = mergeSort(array, mid, start);
    int* rightArray = mergeSort(array, end, mid);

    int i = 0, j = 0;
    int* temp = new int[end - start];

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            temp[i + j] = leftArray[i];
            i++;
        }
        else {
            temp[i + j] = rightArray[j];
            j++;
        }
    }

    while (i < leftSize) {
        temp[i + j] = leftArray[i];
        i++;
    }

    while (j < rightSize) {
        temp[i + j] = rightArray[j];
        j++;
    }

    delete[] leftArray;
    delete[] rightArray;

    return temp;
}


// quick sort
int partition(int* array, int start, int end) {
    swap(array[start], array[(rand() % (end - start)) + start]);
    int i = start;
    for (int j = start + 1; j < end; ++j) {
        if (array[j] < array[start]) {
            swap(array[j], array[++i]);
        }
    }

    swap(array[i], array[start]);

    return i;
}

int* sort(int* array, int end, int start = 0) {
    if (end - start <= 1) {
        return array;
    }

    int pivot = partition(array, start, end);
    sort(array, pivot, start);
    sort(array, end, pivot);

    return array;
}


// bucket sort (ineger numbers)
int* bucketSort(int arr[], int n){

    vector<vector<int>> b(n);

    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int bi = (arr[i] * n) / (maxValue + 1);
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!b[i].empty()) {
            int* bucketArray = &b[i][0];
            insertionSort(bucketArray, b[i].size());
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];

    return arr;
}

int main()
{
    int size = 0;
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    array = bucketSort(array, size);

    cout << '[' << array[0];
    for (int i = 1; i < size; i++)
    {
        cout << ',' << array[i];
    }
    cout << ']';

    delete[] array;

    return 0;
}


/* My own trial to solve the insertion sort algorithm
for (i = 0; i < size; i++){
	key = array[i];
	for (j = i; j > 0; j--) {
		if (key < array[j-1]) {
			array[j] = array[j - 1];
			array[j - 1] = key;
		}
	}
}
*/