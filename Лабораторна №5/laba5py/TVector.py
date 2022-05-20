from abc import ABC, abstractmethod
from math import sqrt

class TVector(ABC):
    #
    def __init__(self, x):
        self.x = x

    def display(self):
        print(f"{self.x}; ", end = '')

    @abstractmethod
    def is_parallel(self, vector):
        pass

    @abstractmethod
    def is_perpendicular(self, vector):
        pass

    @abstractmethod
    def calc_length(self):
        pass

class R2(TVector):
    def __init__(self, x, y):
        super(R2, self).__init__(x);
        self.__y = y

    def display(self):
        super().display()
        print(f"{self.__y}; ", end = '')

    def is_parallel(self, vector):
        if self.x/vector.x == self.__y/vector.y:
            return True
        return False

    def is_perpendicular(self, vector):
        dot_product = self.x * vector.x + self.y * vector.y
        if dot_product == 0:
            return True
        return False

    def calc_length(self):        
        return sqrt(self.x ** 2 + self.__y ** 2) 
      