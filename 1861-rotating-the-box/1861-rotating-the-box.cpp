class Solution {
public:
void rotate90(vector<vector<char>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<char>> res(m, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][n - i - 1] = mat[i][j];
        }
    }

    mat = res;
}

vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    rotate90(box);
    int n = box.size();
    int m = box[0].size();
    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (box[i][j] == '.') {
                int currow = i - 1;
                while (currow >= 0 && box[currow][j] == '.')
                    currow--;
                if (currow>=0 && box[currow][j] == '#') {
                    box[i][j] = '#';
                    box[currow][j] = '.';
                }
            }

        }
    }
    return box;
}
};