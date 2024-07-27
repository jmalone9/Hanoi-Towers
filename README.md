# Hanoi-Towers
a simple hanoi towers solver with visualization to help a friend learn programming

to use this just compile the c++ code then use the args as follows:

for default values (3 disks going from rod 1 to rod 3):

    hanoiTowers.exe

the first arg is always number of disks:

    hanoiTowers.exe 6

if you only give it number of disks you can use the verbose flag to get the individual moves printed:

    hanoiTowers.exe 6 -v

you can also tell it where to start and end:

    hanoiTowers.exe 6 1 3

start and end with verbose:

    hanoiTowers.exe 6 1 3 -v


TODO list: 

recognize the verbose flag in any of the args instead of just in cases where we have the number of disks and no other args or all args

error check the args

make ascii art for the visualization instead of just numbers

