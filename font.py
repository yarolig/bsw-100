import sys, os

def read_one_line():
    line = ';'
    while not line or line.startswith(';'):
        line=fi.readline()
        if not line:
            break
        line = line.strip()
    return line

lines_per_char = 5
def read_lines_for_char():
    result = []
    for i in xrange(5):
        result.append(read_one_line())
    return result


def add_line(line, char):
    if line in line_dict:
        line_dict[line] += 1
        return
    if 'XXX' not in line and '___' not in line:
        print '; bad line', line, 'for char', char
    if len(line) != len('.......'):
        print '; bad line len ', line, 'for char', char
    line_dict[line] = 1



fi=open(sys.argv[1])

line_dict = {}

blank_lines = '!!!'
chars = {}
for i in xrange(128):
    lines = read_lines_for_char()
    chars[i] = lines
    for line in lines:
        add_line(line, i)
    if i == 0:
        blank_lines = lines
    print '; ', i, chr(i) if i > 31 else '?'
    print '\n'.join(lines if i > 31 else blank_lines)
    print

ii = line_dict.keys()
ii.sort()
n = 0
for i in ii:
    print ';', n,i, line_dict[i]
    n += 1



#00000000 <disassemble_it>:
#0:   88 bd           out     0x28, r24       ; 40
#2:   98 bd           out     0x28, r25       ; 40
#4:   ed 91           ld      r30, X+
#6:   00 00           nop
#8:   88 bd           out     0x28, r24       ; 40
#a:   09 94           ijmp


def can_ld(line, pos, already, prev):
    if already:
        return False
    if prev != line[pos]:
        return False
    if pos + 1 >= len(line):
        return False
    if line[pos] == line[pos+1]:
        return True


def line_index_to_offset(li):
    return 4+li * 7


fo = open(sys.argv[2], 'w')
fo.write("""
// This file is generated automatically from font.txt by font.py

#include <avr/io.h>
#include <avr/pgmspace.h>
__attribute__ ((aligned (512))) PROGMEM const char font_char_scanlines[]  = {
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
""")


n = 0
line_index = {}
for i in ii:
    line_index[i] = n
    fo.write('// ' +str(n)+ ' ' +str(i) + ' addr:' + hex(0x600+line_index_to_offset(n)) + '\n')
    already = False
    prev = '?'
    skip = False
    for pos in xrange(len(i)):
        if skip:
            skip = False
        elif can_ld(i, pos, already, prev):
            already = True
            skip = True
            fo.write("0xed, 0x91,   // ld r30, X+\n")
        #elif prev == i[pos]:
        #    fo.write("0x00, 0x00,   // nop\n")
        elif i[pos] in '._':
            fo.write("0x88, 0xb9,   // out 0x08, r24\n")
        elif 'X' == i[pos]:
            fo.write("0x98, 0xb9,   // out 0x08, r25\n")
        else:
            print '; bad symbol'
        prev = i[pos]
    if not already:
        print '; bad place for LD'
    fo.write("0x09, 0x94,  // ijmp\n")
    n += 1

fo.write("""
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
0x08, 0x95,   // ret
};
""")
fo.write("""
__attribute__ ((aligned (256))) char font_chars[]  = {
""")

n=0

for j in xrange(5):
    fo.write('//--------------------------------------\n')
    for i in xrange(128):
        char = chars[i]
        fo.write('    // char #' + str(i) +
                " " + (chr(i) if i > 31 else '?') +
                ' col ' + str(j) +
                '\n')
        y = char[j]
        fo.write('    '+str(line_index_to_offset(line_index[y])) + " ," + "// " + y + "\n")
#    for i in xrange(128):
#        fo.write('    0,\n')
fo.write("""
};
""")

fo.close()

