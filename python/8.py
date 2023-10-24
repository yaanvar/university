import re


def main(s):
    keys = re.findall(r'\((.*?)\)', s)
    values = re.findall(r'#+([-0-9]+)', s)

    return dict(map(lambda i, j: (i, int(j)), keys, values))

# {'erari_368': 9262, 'anceon': 7011}
print(main('<: <block>option #9262 => q(erari_368) </block>. <block>\noption#7011=> q(anceon) </block>. :>'))
# {'erausve_536': 8354, 'beatbe': 7690, 'rixein': 2505}
print(main('<:<block> option#8354=> q(erausve_536) </block>. <block> option #7690\n=> q(beatbe) </block>.<block>option #2505 => q(rixein)</block>. :>'))
# {'leed_195': 9293, 'atleor_196': -5295}
print(main('<: <block> option #9293 => q(leed_195) </block>. <block> option\n#-5295 => q(atleor_196)</block>. :>'))