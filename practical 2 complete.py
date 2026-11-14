class Div_Conq:
    def __init__(self):
        self.cust=[]

    def get_cust_id(self):
        n=int(input("How Many Customers Id To Register::"))
        for i in range(n):
            cust_id=int(input("enter customer id::"))
            self.cust.append(cust_id)

    def display(self):
        for i in self.cust:
            print(i)

    def Lin_Search(self,key):
        for i in range(len(self.cust)):
            if key==self.cust[i]:
                print("Key Found At...",i)
                return
        print("Key Not Found...")

    def Bin_Search(self,key):
        if key > self.cust[-1]:
            print("Key Out Of Records...")
        else:
            low=0
            high=len(self.cust)-1
            while low <= high :

                mid=(low+high)//2

                if key == self.cust[mid]:
                    print("Key Found At...",mid)
                    return
                elif key < self.cust[mid]:
                    high=mid-1
                else:
                    low=mid+1
            print("Key Not Found...")

n1=Div_Conq()
'''n1.get_cust_id()
n1.display()

m=int(input("which key to find::"))

n1.Lin_Search(m)
n1.Bin_Search(m)'''

choice='Y'
while (choice=='Y'):
    print("to store user data(1)\nto display user data(2)\nto perform linear search(3)\nto perform binary search(4)\nexit(5)")
    ch=int(input("enter your choice::"))

    if ch==1:
        n1.get_cust_id()

    elif ch==2:
        n1.display()

    elif ch==3:
        m=int(input("which cust to find::"))
        n1.Lin_Search(m)

    elif ch==4:
        m=int(input("which cust to find::"))
        n1.Bin_Search(m)

    else:
        print("Visit Again...")
        break

    choice=input("Do u want to continue(Y/N)::").upper()































                



















            
