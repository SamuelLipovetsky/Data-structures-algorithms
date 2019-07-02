from ar import Array
import ctypes
class MultiArray:
    def __init__(self,*dimensions):
        assert len(dimensions )>1,'crie uma array com mais de 1 dimensao'
        self._dims=dimensions

        size=1
        for d in dimensions:
            assert d>0,'insira dimensoes maior que 0'
            size *=d
        self._size=size
        self._elements=Array(size)
        self._factors=Array(len(dimensions))

        self._computeFactors()
        
        
    def numDims(self):
        return len(self._dims)

    def length(self,dim):
        assert dim>0 and dim<len(self._dims),'dimension out of range'
        return self._dims[dim-1]

    def clear(self,value):
        self._elements.clear(value)

    def __getitem__(self,ndxTuple):
        
        assert  len(ndxTuple) == (len(self._factors)),'invalidd array of subscription '
        index =self._computeIndex(ndxTuple)
        assert index is not None,'Array subscription out of range'
        return self._elements[index]

    def __setitem__(self,ndxTuple,value):
        
        assert  len(ndxTuple) == (len(self._factors)),'invalidd array of subscription '
        index =self._computeIndex(ndxTuple)
        assert index is not None,'Array subscription out of range'
        self._elements[index]=value

    def _computeIndex(self,idx):
        offset=0    
        for j in range (len(idx)):

            if idx[j] <0 or idx[j] >= self._dims[j]:
                return None
            else:
                offset +=idx[j] *self._factors[j]
                print(offset)
        return offset

    def _computeFactors(self):
        d=self._size
        for i in range(len(self._factors)-1):
            
            
            d/=self._dims[i]
         
            self._factors[i]=int(d)
        self._factors[i+1]=1
            

a=MultiArray(3,4,5)

