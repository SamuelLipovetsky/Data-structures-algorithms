def Biggest(lista):
    l=[0]*len(lista)
    for m in range(len(lista)):
        if m==0:
            l[0]=lista[0]
            
        else:

            l[m]=lista[m] -lista[m-1]
    
    x=m=0
    for z in l:
        x=x+z
       
        if(m<=x):
            m=x
           
            

    return m

Biggest([1,2,3,9,15,5,20])