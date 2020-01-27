
# bubble sort 
def sort(lista):
        l=len(lista)
        for i in range(l-1):
            for m in range(l-i-1):
                if lista[m] > lista[m+1]:
                    temp=lista[m]
                    lista[m]=lista[m+1]
                    lista[m+1]=temp
                    print (lista) 

# compare two  subsequent values and swap them if the one with a bigger index is greater in value than 
# the the other one, in doing so, the biggest value will bubble to the end of the list, and the smallest will bubble to the start of the list


sort([5,4,3,2,1])