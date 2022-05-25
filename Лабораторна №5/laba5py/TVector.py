from abc import ABC, abstractmethod
from math import sqrt

class TVector(ABC):
    
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
        super().__init__(x);
        self.__y = y

    def display(self):
        super().display()
        print(f"{self.__y}; ", end = '')

    def is_parallel(self, vector):
        cross_product = self.x * vector.__y - self.__y * vector.x
        if cross_product == 0:
            return True
        return False

    def is_perpendicular(self, vector):
        dot_product = self.x * vector.x + self.__y * vector.__y
        if dot_product == 0:
            return True
        return False

    def calc_length(self):        
        return sqrt(self.x ** 2 + self.__y ** 2) 


class R3(TVector):
    def __init__(self, x, y, z):
        super().__init__(x);
        self.__y = y
        self.__z = z

    def display(self):
        super().display()
        print(f"{self.__y}; {self.__z}; ", end = '')

    def is_parallel(self, vector):
        cross_product = (self.__y * vector.__z - vector.__y * self.__z) - (self.x * vector.__z - vector.x * self.__z) + (self.x * vector.__y - vector.x * self.__y)
        if cross_product == 0:
            return True
        return False

    def is_perpendicular(self, vector):
        dot_product = self.x * vector.x + self.__y * vector.__y + self.__z * vector.__z
        if dot_product == 0:
            return True
        return False

    def calc_length(self):        
        return sqrt(self.x ** 2 + self.__y ** 2 + self.__z ** 2) 
      