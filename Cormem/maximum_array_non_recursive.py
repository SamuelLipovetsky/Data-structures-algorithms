def kadane(array):
    local_max = 0
    inicio = 0
    fim = 0
    global_max = float('-inf')
    for i in range(len(array)):
        if array[i] > array[i]+local_max:
            local_max = array[i]
            inicio = i
        else:
            local_max += array[i]
            fim = i+1
        if local_max > global_max:
            global_max = local_max
        print(array[inicio:fim], global_max, local_max)
        print(array)

    print(global_max)
    return global_max


kadane([2, 5, -2, 2, -2, 2, -2, 30])

# fonte:
# https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
