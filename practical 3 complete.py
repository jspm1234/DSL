class Employee:
    def __init__(self):
        self.salary=[]

    def get_data(self):
        n=int(input("Enter How Many Employee Salaries To Store::"))
        for i in range(n):
            sal=int(input("Enter Salary::"))
            self.salary.append(sal)

    def show(self):
        for i in self.salary:
            print(i)

    def bubble_sort(self):
        n=len(self.salary)-1
        for i in range(n):
            for j in range(n-i):
                if self.salary[j]>self.salary[j+1]:
                    temp=self.salary[j]
                    self.salary[j]=self.salary[j+1]
                    self.salary[j+1]=temp
                else:
                    continue
    def selection_sort(self):
        n=len(self.salary)
        for i in range(n-1):
            min_index=i
            for j in range(i+1,n):
                if self.salary[j]<self.salary[min_index]:
                    min_index=j

            temp=self.salary[min_index]
            self.salary[min_index]=self.salary[i]
            self.salary[i]=temp

    def highest_salaries(self):
        self.bubble_sort()

        for i in range(-1,-6,-1):
            print(self.salary[i])

n1=Employee()

choice='y'

while choice.lower()=='y':

    print("TO STORE SALARIES(1)\nTO DISPLAY SALARIES(2)\nTO PERFORM BUBBLE SORT(3)\nTO PERFORM SELECTION SORT(4)\nTO VIEW HIGHEST SALARIES(5)\nEXIT(6)")

    ch=int(input("What Do U Want To Do::"))

    if ch==1:
        n1.get_data()

    elif ch==2:
        n1.show()

    elif ch==3:
        n1.bubble_sort()
        n1.show()

    elif ch==4:
        n1.selection_sort()
        n1.show()

    elif ch==5:
        n1.highest_salaries()

    else:
        print("Visit Again...")
        break

    choice=input("Do U Want To Continue(Y/N)::")
    

        










                
