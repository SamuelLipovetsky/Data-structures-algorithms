def binarySearch(lista,target):
    low=0
    high=len(lista)
    count=0
    while low<=high:
        mid=(high+low)//2
        if mid<0 or mid >len(lista)-1:
             return False,count
        if lista[mid]==target:
            return True ,mid,count
        else:
            if lista[mid]>target:
                high=mid-1
            else:
                low=mid+1
        count+=1
b=[]
