from abs import ABC, abstractmethod

class Sensor(ABC):

    @abstractmethod
    def getValue(self): pass

    @abstractmethod
    def close(self): pass
