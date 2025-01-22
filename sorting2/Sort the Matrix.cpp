#include <iostream>
using namespace std;

int main() {
    int heap[100], no, i, j, c, root, temp, d = 0;

    cin >> no;

    for (i = 0; i < no * no; i++) {
        cin >> heap[i];
    }

    // Building the max heap
    for (i = 1; i < no * no; i++) {
        c = i;
        do {
            root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    // Sorting the heap
    for (j = no * no - 1; j >= 0; j--) {
        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;

        root = 0;
        do {
            c = 2 * root + 1;

            if ((heap[c] < heap[c + 1]) && c < j - 1)
                c++;

            if (heap[root] < heap[c] && c < j) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;

        } while (c < j);
    }

    // Printing the sorted elements in a grid format
    for (i = 0; i < no * no; i++) {
        d++;
        cout << heap[i] << " ";
        if (d % no == 0)
            cout << endl;
    }

    return 0;
}
