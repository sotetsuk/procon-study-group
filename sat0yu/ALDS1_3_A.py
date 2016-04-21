#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

def calc(op, arg1, arg2):
    if op == '*':
        return arg1 * arg2
    elif op == '+':
        return arg1 + arg2
    elif op == '-':
        return arg1 - arg2
    else:
        raise Error("this case never occur in ALDS1_3")

def create_runner(symbols):
    idx_tail = len(symbols)

    def runner(idx, ls):
        if idx == idx_tail:
            return ls[0]
        else:
            sym = symbols[idx]
            if sym in {'*', '+', '-'}:
                # extract 2 elements(ls[1], ls[0]) from head of the given list(ls)
                # and calculate them according to the given operand.
                # finally, put the result on the head of the list
                return runner(idx + 1, [calc(sym, ls[1], ls[0])] + ls[2:])
            else:
                return runner(idx + 1, [int(sym)] + ls)
    return runner

line = raw_input()
symbols = line.split()
runner = create_runner(symbols)
result = runner(0, [])
print(result)
