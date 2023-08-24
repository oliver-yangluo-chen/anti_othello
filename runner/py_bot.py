#!/usr/bin/env python3

import sys
def debug_print(*args):
  print(*args, file=sys.stderr, flush=True)

debug_print('Write debug output like this!')

bw = input()
print('ok', flush=True)

line = '...'
while line and line != 'done':
  line = input()
  if line == 'get move':
    print('d4', flush=True)
  else:
    pass