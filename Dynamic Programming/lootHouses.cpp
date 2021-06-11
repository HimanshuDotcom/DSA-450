

int lootHouses(int *houses, int n) {
	int *maxMoney = new int[n]; // 0 index as 1st house and n-1 as nth
	maxMoney[0] = houses[0];   
	
	if(n > 1)
		maxMoney[1] = max(houses[1], maxMoney[0]);
		
	for(int i = 2; i < n; i++) {
		maxMoney[i] = max(maxMoney[i-1], maxMoney[i-2] + houses[i]);
	}
	
	int result = maxMoney[n-1];
	delete[] maxMoney;  //  free memory
	return result;
	
}
