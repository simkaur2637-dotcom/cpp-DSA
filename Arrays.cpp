#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

/*
    DSA - ARRAYS IN C++

    Topics Covered:
    1. Array declaration and initialization
    2. Traversing an array
    3. Taking input
    4. Finding sum
    5. Finding maximum and minimum
    6. Linear search
    7. Counting occurrences
    8. Reversing an array
    9. Checking if array is sorted
    10. Finding second largest element
    11. STL functions
    12. Prefix sum
*/

int main() {

    // =========================================================
    // 1. ARRAY DECLARATION AND INITIALIZATION
    // =========================================================

    int arr[] = {10, 20, 30, 40, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";


    // =========================================================
    // 2. ACCESSING AN ELEMENT
    // =========================================================

    cout << "First Element: " << arr[0] << "\n";
    cout << "Third Element: " << arr[2] << "\n";


    // =========================================================
    // 3. FINDING SUM OF ARRAY
    // =========================================================

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << "\n";


    // =========================================================
    // 4. FINDING MAXIMUM ELEMENT
    // =========================================================

    int maximum = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    cout << "Maximum Element: " << maximum << "\n";


    // =========================================================
    // 5. FINDING MINIMUM ELEMENT
    // =========================================================

    int minimum = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    cout << "Minimum Element: " << minimum << "\n";


    // =========================================================
    // 6. LINEAR SEARCH
    // =========================================================

    int target = 30;
    bool found = false;

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {
            found = true;

            cout << "Element " << target
                 << " found at index " << i << "\n";

            break;
        }
    }

    if (!found) {
        cout << "Element " << target << " not found\n";
    }


    // =========================================================
    // 7. COUNT OCCURRENCES
    // =========================================================

    int numbers[] = {5, 2, 5, 7, 5, 9};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    int searchValue = 5;
    int count = 0;

    for (int i = 0; i < size; i++) {

        if (numbers[i] == searchValue) {
            count++;
        }
    }

    cout << searchValue
         << " occurs " << count << " times\n";


    // =========================================================
    // 8. REVERSE AN ARRAY USING TWO POINTERS
    // =========================================================

    int reverseArr[] = {1, 2, 3, 4, 5};

    int reverseSize =
        sizeof(reverseArr) / sizeof(reverseArr[0]);

    int left = 0;
    int right = reverseSize - 1;

    while (left < right) {

        swap(reverseArr[left], reverseArr[right]);

        left++;
        right--;
    }

    cout << "Reversed Array: ";

    for (int i = 0; i < reverseSize; i++) {
        cout << reverseArr[i] << " ";
    }

    cout << "\n";


    // =========================================================
    // 9. CHECK IF ARRAY IS SORTED
    // =========================================================

    int sortedArr[] = {1, 2, 3, 4, 5};

    int sortedSize =
        sizeof(sortedArr) / sizeof(sortedArr[0]);

    bool isSorted = true;

    for (int i = 1; i < sortedSize; i++) {

        if (sortedArr[i] < sortedArr[i - 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "Array is sorted\n";
    }
    else {
        cout << "Array is not sorted\n";
    }


    // =========================================================
    // 10. FIND SECOND LARGEST ELEMENT
    // =========================================================

    int secondArr[] = {10, 20, 5, 30, 25};

    int secondSize =
        sizeof(secondArr) / sizeof(secondArr[0]);

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < secondSize; i++) {

        if (secondArr[i] > largest) {

            secondLargest = largest;
            largest = secondArr[i];
        }
        else if (secondArr[i] > secondLargest &&
                 secondArr[i] != largest) {

            secondLargest = secondArr[i];
        }
    }

    cout << "Largest Element: "
         << largest << "\n";

    cout << "Second Largest Element: "
         << secondLargest << "\n";


    // =========================================================
    // 11. VECTOR - DYNAMIC ARRAY
    // =========================================================

    vector<int> v = {10, 20, 30, 40, 50};

    cout << "Vector: ";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\n";


    // Adding an element
    v.push_back(60);

    cout << "After push_back(60): ";

    for (int x : v) {
        cout << x << " ";
    }

    cout << "\n";


    // Removing the last element
    v.pop_back();

    cout << "After pop_back(): ";

    for (int x : v) {
        cout << x << " ";
    }

    cout << "\n";


    // =========================================================
    // 12. STL FUNCTIONS
    // =========================================================

    cout << "Maximum using STL: "
         << *max_element(v.begin(), v.end())
         << "\n";

    cout << "Minimum using STL: "
         << *min_element(v.begin(), v.end())
         << "\n";

    cout << "Sum using STL: "
         << accumulate(v.begin(), v.end(), 0)
         << "\n";


    // =========================================================
    // 13. SORTING USING STL
    // =========================================================

    vector<int> unsorted = {50, 10, 40, 20, 30};

    sort(unsorted.begin(), unsorted.end());

    cout << "Sorted Vector: ";

    for (int x : unsorted) {
        cout << x << " ";
    }

    cout << "\n";


    // =========================================================
    // 14. PREFIX SUM
    // =========================================================

    vector<int> original = {2, 4, 1, 5, 3};

    vector<int> prefix(original.size());

    prefix[0] = original[0];

    for (int i = 1; i < original.size(); i++) {
        prefix[i] = prefix[i - 1] + original[i];
    }

    cout << "Prefix Sum: ";

    for (int x : prefix) {
        cout << x << " ";
    }

    cout << "\n";


    // =========================================================
    // PROGRAM END
    // =========================================================

    return 0;
}
