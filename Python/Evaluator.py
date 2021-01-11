# This is a port of the expression evaluator I made in C.
# I thought it would be a fun experiment to move it over
# to Python and compare.

from Translate import *

expression = "1+2*(3-4)"

print(translate(expression))

