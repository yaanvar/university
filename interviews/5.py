# Даны две отсортированных по неубыванию последовательности целых чисел.
# Необходимо вызвать block() с каждым элементом из первой последовательности, которых нет во второй.

# filterSortedList([1, 2, 3], [3, 4], { print($0) })
# Output: 1 2

# [-1, 2, 13, 42, 57] [-1, 4, 5, 42]

def filterSortedList(inp, filt, block):
    l = 0
    for i in inp:
        while l < len(filt) and filt[l] < i :
            l += 1
        if filt[l] == i:
            continue
        block(i)