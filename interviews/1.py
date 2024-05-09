# Дан массив чисел a_1, a_2, ..., a_n .
# Необходимо найти монотонный подотрезок (то есть строго убывающий или строго возрастающий)
# максимальной длины и вернуть пару индексов его начала и конца.
# Примеры:
# [2, 7, 5, 4, 4, 3] -> {1, 3}
#     l     c  r
# [1, 1] -> {1, 1} // or {0, 0}

def findSub(seq):
    sub = [0, 0]
    if len(seq) < 2:
        return sub
    if len(seq) < 3 and seq[0] != seq[1]:
        return [0, 1]
    
    l = 0
    r = 1
    curr = l
    while r < len(seq):
        if seq[r] < seq[curr]:
            while r < len(seq) and seq[r] < seq[curr]:
                r += 1
                curr += 1
            if sub[1] - sub[0] < r - l:
                sub = [l, r - 1]
            l = curr
        elif seq[r] > seq[curr]:
            while r < len(seq) and seq[r] > seq[curr]:
                r += 1
                curr += 1
            if sub[1] - sub[0] < r - l:
                sub = [l, r - 1]
            l = curr
        else:
            curr += 1
            l = curr
            r += 1

    return sub
            
test = [2, 7, 5, 4, 4, 3]
test2 = [1, 1]
test3 = [1, 0]

print(findSub(test))
print(findSub(test2))
print(findSub(test3))