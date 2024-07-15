from collections import *
from itertools import *
from functools import *
from math import *
from heapq import *
from bisect import *
from typing import *
from random import randint
from string import ascii_lowercase

class Employee:
    def __init__(self):
        Employee.count += 1
        self.id = Employee.count
    
    def get_id(self) -> int:
        return self.id


if __name__ == "__main__":
    Employee.count = 0
    e1 = Employee()
    e2 = Employee()
    print(e1.get_id())
    print(e2.get_id())
    e3 = Employee()
    print(e3.get_id())
    