class Solution:
	def accountBalancing (self, moviments : List[int]) -> int:
		count = 0
		debts = defaultdict(dict) #es una matriu dispersa
		for x,y,z in moviments:
			debts[y][x] = debts[y].get(x, 0) + z

		for u in debts.keys():
			for v,z1 in debts[u].items():
				z2 = debts[v].get(u, 0)
				if z2 > 0:
					if z1 < z2:
						debts[u].pop(v)
						debts[v][u] -= z1
					elif z1 > z2:
						debts[v].pop(u)
						debts[u][v] -= z2
					else:
						debts[v].pop(u)
						debts[u].pop(v)
				if len(debts[v].keys()) == 0:
					debts.pop(v)
			if len(debts[u].keys()) == 0:
				debts.pop(u)

		for u in debts.keys():
			for v, deute in debts[u].keys():
				for w, deute2 in debts[v].keys():
				 