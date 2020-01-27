import ctypes

class Array:

    def __init__(self,size):
        assert size >0,'Tamanho da array tem q ser maior que 0'
        self._size=size
        PyArrayTipe =ctypes.py_object *size
        self._elements=PyArrayTipe()
        self.clear(None)

    def __len__(self):
        return self._size

    def __getitem__(self,index):
        assert index>=0 and index<len(self),'index out of range'
        return self._elements[index]
    
    def __setitem__(self,index,value):
        assert index>=0 and index<len(self),'index out of range'
        self._elements[index]=value

    def clear(self,value):
        for i in range(len(self)):
            self._elements[i]=value

    def __iter__(self):

        return _ArrayIterator(self._elements)


class _ArrayIterator:

    def __init__(self,TheArray):
        self._TheArray=TheArray
        self._curNdx=-0

    def __iter__(self):
        return self

    def __next__(self):
        if self._curNdx<len(self._TheArray):
            Entry =self._TheArray[self._curNdx]
            self._curNdx+=1
            return Entry
        else:
            raise StopIteration






