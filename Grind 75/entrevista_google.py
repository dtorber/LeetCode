def best_apartment (apartaments : List[dict], serveis : List[str]) -> float:
	MAX_VALUE = float('inf')
	#initialise the dp matrix with all the minimum distances to infinity
	dp = list()
	for i in range(len(apartaments)):
		dp.append([MAX_VALUE] * len(serveis))

	for j,servei in enumerate(serveis):
		if apartaments[0][servei]:
			dp[0][j] = 0

	for i, apartament in enumerate(apartaments[1:]):
		for j, servei in enumerate(serveis):
			if apartament[servei]:
				dp[i][j] = 0
			else:
				dp[i][j] = 1 + dp[i - 1][j]

	#initialise the dp matrix with all the minimum distances to infinity, with the right-to-left iteration
	#-> NO!!! We do not have to create another matrix we have to iterate over the same matrix
	for i in range(len(apartaments) - 2, -1, -1):
		apartament = apartaments[i]
		for j, servei in enumerate(serveis):
			dp[i][j] = min(dp[i][j], 1 + dp2[i + 1][j])

	max_distances = list()

	for i in range(len(apartaments)):
		max_distances.append(max(dp[i]))

	return min(max_distances)