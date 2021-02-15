file = open('./valgrind.txt', 'r')
vpnFile = open('./vpns.txt', 'w')

for line in file:
    if not line.startswith('='):
        vpnFile.write(str((int("0x" + line[3:11], 16) & 0xfffff000) >> 12) + "\n")

file.close()
vpnFile.close()
