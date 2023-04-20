def count_change(money, coins):
    combinations = [0]*(money +1)
    coins.sort()
    combinations[0] = 1
    print(combinations)
    
    for coin in coins:
        idx = 0
        while(idx + coin <= money):
            combinations[coin + idx] += combinations[idx]
            idx += 1
 
    return combinations[-1]
