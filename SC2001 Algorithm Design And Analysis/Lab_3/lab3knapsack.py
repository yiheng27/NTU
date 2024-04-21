def knapsack(C, w, p):
    n = len(w)
    profit = [[0] * (n + 1) for _ in range(C + 1)]

    for rC in range(1, C+1): #iterate through capacities
        for cP in range(1, n+1): #iterate through objects
            if w[cP-1] <= rC: #if current object can fit
                profit[rC][cP] = max(profit[rC][cP-1], profit[rC-w[cP-1]][cP]+p[cP-1]) #find max(don't include, include)
            else: #go next
                profit[rC][cP] = profit[rC][cP-1]
   
    #print the profit table
    for row in profit:
        print(row)

    return profit[C][n]

# Example usage
C = 14
w = [5, 6, 8]
p = [7, 6, 9]
max_profit = knapsack(C, w, p)
print("The maximum profit is:", max_profit)
