def main(x):
    x = int(x)
    x = (x >> 6) << 6
    l4 = (x >> 11) << 11
    l3 = (x & 1024) >> 10
    l2 = ((x << 8) & 262143) >> 13
    l23 = l2 | l3
    l423 = l4 | l23
    return l423


print(main('135096')) # 133149
print(main('92775')) # 92178
print(main('193114')) # 192530
print(main('1148')) # 3