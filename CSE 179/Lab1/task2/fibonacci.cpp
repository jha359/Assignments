#include <iostream>
#include <sys/time.h>
using namespace std;

struct timeval time_start;
struct timeval time_end;

int main() {
    int n, firstTerm = 1, secondTerm = 1, nextTerm;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: " << firstTerm << " + " << secondTerm << " + ";

    gettimeofday(&time_start, NULL);

    //measure the execution tv of the following loop
    for (int i = 1; i <= n-2; ++i) {
        nextTerm = firstTerm + secondTerm;
        cout << nextTerm << " + ";
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }

    gettimeofday(&time_end, NULL);

    cout << endl << time_end.tv_usec - time_start.tv_usec << " microsecond(s)" << endl;
    return 0;
}
