def main(x):
    if x[3] == "LSL":
        return LSLRoute(x)
    elif x[3] == "PAN":
        return PANRoute(x)
    elif x[3] == "DART":
        return DARTRoute(x)


def LSLRoute(x):
    if x[2] == 'RDOC':
        return 6
    elif x[2] == 'TEA':
        return 7


def PANRoute(x):
    if x[2] == 'RDOC':
        return 8
    elif x[2] == 'TEA':
        return 9


def DARTRoute(x):
    if x[0] == "HAXE":
        if x[4] == 'XC':
            return 2
        elif x[4] == 'GLYPH':
            if x[1] == 'APL':
                return 0
            if x[1] == 'MAX':
                return 1
    elif x[0] == "BLADE":
        return 3
    elif x[0] == "ELM":
        if x[2] == 'RDOC':
            return 4
        elif x[2] == 'TEA':
            return 5


print(main(['ELM', 'APL', 'RDOC', 'DART', 'XC'])) # 4
print(main(['BLADE', 'APL', 'TEA', 'DART', 'GLYPH'])) # 3
print(main(['ELM', 'APL', 'TEA', 'PAN', 'GLYPH'])) # 9
print(main(['HAXE', 'MAX', 'TEA', 'LSL', 'GLYPH'])) # 7
print(main(['BLADE', 'MAX', 'RDOC', 'PAN', 'XC'])) # 8