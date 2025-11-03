unsigned partition(int *arr, unsigned low, unsigned high) {
    unsigned left = low, right = high;
    int pivot = arr[left], swap;
    while (left < right) {
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] > pivot) right--;
        if (left < right) {
            swap = arr[left];
            arr[left] = arr[right];
            arr[right] = swap;
            left++;
            right--;
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}
