class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length;
        int n = mat[m - 1].length;
        if (m * n != r * c) {
            return mat;
        }

        int[][] reshape = new int[r][c];
        int mi = 0, mj = 0, ri = 0, rj = 0;
        int counter = 0;
        while (counter < r * c) {
            reshape[ri][rj] = mat[mi][mj];
            mj++;
            rj++;
            if (mj == n) {
                mi++;
                mj = 0;
            }
            if (rj == c) {
                ri++;
                rj = 0;
            }
            counter++;
        }
        return reshape;
    }
}