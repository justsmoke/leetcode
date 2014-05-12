class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) {
        	return findMid(B, 0, n - 1, A, 0, m - 1);
        } else {
        	return findMid(A, 0, m - 1, B, 0, n - 1);
        }
    }
    double findMid(int A[], int la, int ra, int B[], int lb, int rb) {
    	while (la < ra) {
    		int ma = (la + ra) / 2;
    		int mb = (lb + rb) / 2;
    		if (A[ma] <= B[mb]) {
    			la = ma + 1;
    			rb -= ma + 1 - la;
    		} else {
    			ra = ma - 1;
    			lb += ra - ma + 1;
    		}
    	}
    	int n = rb - lb + 1;
		int mid = (lb + rb) / 2;
    	if (la > ra) {
    		if (n & 1 == 1) {
    			return B[mid];
    		} else {
    			return (B[mid] + B[mid + 1]) / 2.0;
    		}
    	} else {
	    	if (n & 1 == 1) {
	    		if (A[la] < B[mid - 1]) {
	    			return (B[mid] + B[mid - 1]) / 2.0;
	    		} else if (A[la] > B[mid + 1]) {
	    			return (B[mid] + B[mid + 1]) / 2.0;
	    		} else {
	    			return (B[mid] + A[la]) / 2.0;
	    		}
	    	} else {
	    		if (A[la] < B[mid]) {
	    			return B[mid];
	    		} else if (A[la] > B[mid + 1]) {
	    			return B[mid + 1];
	    		} else {
	    			return A[la];
	    		}
	    	}
    	}
    }
};