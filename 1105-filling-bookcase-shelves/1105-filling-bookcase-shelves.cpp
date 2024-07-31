class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int remainingShelfWidth, int maxHeight, vector<vector<int>> &books, int &shelfWidth) {
    if (i == books.size() - 1) {
        if (remainingShelfWidth >= books[i][0]) return max(maxHeight, books[i][1]);
        return maxHeight + books[i][1];
    }

    if (mem[i][remainingShelfWidth] != -1)
        return mem[i][remainingShelfWidth];
    int ans = maxHeight + dp(i + 1, shelfWidth - books[i][0], books[i][1], books, shelfWidth);
    if (remainingShelfWidth >= books[i][0]) {
        ans = min(ans, dp(i + 1, remainingShelfWidth - books[i][0], max(maxHeight, books[i][1]), books, shelfWidth));
    }
    return mem[i][remainingShelfWidth]=ans;
}

int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    mem.assign(books.size(), vector<int>(shelfWidth + 1, -1));
    return dp(0,shelfWidth,0,books,shelfWidth);
}
};