#include <bits/stdc++.h>

using namespace std;
/*
UserId=Moinul
Password=Moinul909
*/

const string USER_ID = "Moinul";
const string PASSWORD = "Moinul909";

// Function to implement a login system
bool login() {
    string userId, password;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;

    if (userId == USER_ID && password == PASSWORD) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Login failed. Incorrect User ID or Password.\n";
        return false;
    }
}

// Function to visualize the array
void visualizeArray(const vector<int>& arr, int highlight1 = -1, int highlight2 = -1) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i == highlight1 || i == highlight2) {
            cout << "[" << arr[i] << "] ";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Sleep function to control speed
void sleep(int speed) {
    this_thread::sleep_for(chrono::milliseconds(speed));
}

// Bubble Sort Algorithm
void bubbleSort(vector<int>& arr, int speed) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            visualizeArray(arr, j, j + 1);
            sleep(speed);

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort Algorithm
int partition(vector<int>& arr, int low, int high, int speed) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        visualizeArray(arr, j, high);
        sleep(speed);

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int speed) {
    if (low < high) {
        int pi = partition(arr, low, high, speed);
        quickSort(arr, low, pi - 1, speed);
        quickSort(arr, pi + 1, high, speed);
    }
}

// Merge Sort Algorithm
void merge(vector<int>& arr, int left, int mid, int right, int speed) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        visualizeArray(arr, left + i, mid + 1 + j);
        sleep(speed);

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        visualizeArray(arr, left + i, -1);
        sleep(speed);
        arr[k++] = L[i++];
    }

    while (j < n2) {
        visualizeArray(arr, mid + 1 + j, -1);
        sleep(speed);
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right, int speed) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, speed);
        mergeSort(arr, mid + 1, right, speed);
        merge(arr, left, mid, right, speed);
    }
}

// Heap Sort Algorithm
void heapify(vector<int>& arr, int n, int i, int speed) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    visualizeArray(arr, i, left);
    sleep(speed);

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, speed);
    }
}

void heapSort(vector<int>& arr, int speed) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i, speed);

    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, speed);
    }
}

// Menu for sorting algorithms
void displayMenu() {
    cout << "Sorting Algorithm Visualizer\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Heap Sort\n";
    cout << "Enter your choice: ";
}

int main() {
    if (!login()) {
        cout << "Access denied!\n";
        return 0;
    }

    vector<int> arr;
    int n, choice, speed;
    char anotherSort;

    // Take array input from the user
    cout << "Enter the number of elements: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    do {
        displayMenu();
        cin >> choice;

        cout << "Enter the speed of visualization (in milliseconds): ";
        cin >> speed;

        switch (choice) {
            case 1:
                cout << "Visualizing Bubble Sort...\n";
                bubbleSort(arr, speed);
                break;
            case 2:
                cout << "Visualizing Quick Sort...\n";
                quickSort(arr, 0, arr.size() - 1, speed);
                break;
            case 3:
                cout << "Visualizing Merge Sort...\n";
                mergeSort(arr, 0, arr.size() - 1, speed);
                break;
            case 4:
                cout << "Visualizing Heap Sort...\n";
                heapSort(arr, speed);
                break;
            default:
                cout << "Invalid choice!\n";
                return 0;
        }

        cout << "Sorted array:\n";
        visualizeArray(arr);

        // Ask if the user wants to see another sorting algorithm
        cout << "Do you want to visualize another sort? (y/n): ";
        cin >> anotherSort;

        // Reset the array to the original unsorted state for the next sort
        if (anotherSort == 'y' || anotherSort == 'Y') {
            cout << "Re-enter the elements of the array to sort again:\n";
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
            }
        }

    } while (anotherSort == 'y' || anotherSort == 'Y');

    cout << "Exiting the program. Thank you for using the Sorting Algorithm Visualizer!\n";

    return 0;
}
