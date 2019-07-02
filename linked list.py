class Node:

    def __init__(self,data=None):
        self.data=data
        self.next=None


class linked_list:
    def __init__(self):
        self.head=Node()
    # insere node no final
    def append(self,data):
        new_node=Node(data)
        cur=self.head
        while cur.next!=None:
            cur=cur.next
        cur.next=new_node
    #retorna tamanho
    def size(self):
        cur=self.head
        total=0
        while cur.next!=None:
            total+=1
            cur=cur.next
        return total
    #print todos os elemntos
    def display(self):
        elems=[]
        cur=self.head
        while cur.next!=None:
            cur=cur.next

            elems.append(cur.data)
        print(elems)

    #insere no index desejado
    def insert(self,data,position):
        if position>=self.size():
            return 'index maior que o da linked list'
        else:

            count=1
            cur=self.head
            while count<=position:
                count+=1
                cur=cur.next
                if count==position:
                    nn=cur.next
                    cur.next=Node(data)
                    cur.next.next=nn
        nn=cur.next
        cur.next=Node(data)
        cur.next.next=nn

    # remove o nodo no index desejado
    def remove(self,position):
        if position>self.size()-1:
            print('index maior que o tamanho da linked list que é {}'.format(self.size()))
        else:
            cur =self.head
            temp=0
            while temp<position:
                temp+=1
                cur=cur.next
            cur.next=cur.next.next
            self.display()
    
a=linked_list()
for m in range(10):
    a.append(m)
a.display()
