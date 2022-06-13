class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
	for(int level = size(triangle) - 2; level >= 0; level--) // start from bottom-1 level
		for(int i = 0; i <= level; i++)
			 // for every cell: we could have moved here from same index or index+1 of next level
			triangle[level][i] += min(triangle[level + 1][i], triangle[level + 1][i + 1]);
	return triangle[0][0]; // lastly t[0][0] will contain accumulated sum of minimum path
}
};