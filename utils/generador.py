'''
    We use this file to generate the tests for part 4 (convex hull)
    This script generate a list of random coordinates
'''

import random

for i in range(1000):
    print("(",random.randint(-500,500),", ",random.randint(-500,500),")",sep='')