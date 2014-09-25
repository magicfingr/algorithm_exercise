class Solution {
public:
	void quickSort(int *a, int start, int end){
		if (start < end){
			int p = partition(a, start, end);
			quickSort(a, start, p - 1);
			quickSort(a, p + 1, end);
		}
	}

	int partition(int *a, int start, int end){
		int left = start;
		int right = end;
		int pivot = a[left];
		while (left < right){
			while (left < right && a[right] >= pivot) right--;
			a[left] = a[right];
			while (left < right && a[left] <= pivot) left++;
			a[right] = a[left];
		}
		a[left] = pivot;
		return left;
	}
};