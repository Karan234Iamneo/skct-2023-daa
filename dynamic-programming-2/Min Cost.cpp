#include <bits/stdc++.h>
using namespace std;

int minCost(int cost[][100], int endrow, int endcol){
	for (int i = 1; i < endrow; i++)
		cost[i][0] += cost[i - 1][0];

	for (int j = 1; j < endcol; j++)
		cost[0][j] += cost[0][j - 1];

	for (int i = 1; i < endrow; i++)
		for (int j = 1; j < endcol; j++)
			cost[i][j]
				+= min(cost[i - 1][j], cost[i][j - 1]);

	return cost[endrow - 1][endcol - 1];
}

int main() {
	int cost[100][100];
	int endrow, endcol;
	cin >> endrow >> endcol;
    for(int i = 0; i < endrow; i ++){
        for(int j = 0; j < endcol; j ++){
            cin >> cost[i][j];
        }
    }
	cout << minCost(cost, endrow, endcol) << endl;
	return 0;
}
