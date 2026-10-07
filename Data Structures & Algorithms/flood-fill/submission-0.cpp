class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image,int initial, int color) {

        int n = image.size();
        int m = image[0].size();

        // boundary or different color
        if (i < 0 || i >= n || j < 0 || j >= m ||
            image[i][j] != initial)
            return;

        // change color
        image[i][j] = color;

        // 4 directions
        dfs(i + 1, j, image, initial, color);
        dfs(i - 1, j, image, initial, color);
        dfs(i, j + 1, image, initial, color);
        dfs(i, j - 1, image, initial, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {

        int initial = image[sr][sc];

        if (initial == color)
            return image;

        dfs(sr, sc, image, initial, color);

        return image;
    }
};