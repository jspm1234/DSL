class Mylib :
    def __init__(self):
        self.users={}
        self.books={}
        self.borrowlog=[]

    def regi_users(self,uid,uname):
        if uid in self.users:
            print("USER ALREADY EXISTS...")
        else:
            self.users[uid]=uname
            print(f"{uid} successfully created")

    def display(self):
        if not self.users:
            print("NO USER FOUND...")
        else:
            print("UID UNAME")
            for i in self.users:
                print(f"{i}   {self.users[i]}")

    def regi_books(self,bid,bname):
        if bid in self.books:
            print("BOOK AVAILABLE...")
        else:
            self.books[bid]={'booknm':bname,'borrowcount':0}

    def show(self):
        if not self.books:
            print("BOOK NOT AVAILABLE")
        else:
            print("BID   BNAME           BORROWCOUNT")
            for j in self.books:
                print(f"{j} {self.books[j]}")

    def borrow_books(self,uid,bid):
        if uid not in self.users:
            print("USER NOT REGISTERED...")
            return
        if bid not in self.books:
            print("BOOK NOT IN LIBRARY...")
            return
        self.books[bid]['borrowcount']+=1
        self.borrowlog.append((uid,bid))
        print(f"{self.users[uid]} borrowed {self.books[bid]['booknm']}")

    def book_record(self):
        if not self.borrowlog:
            print("No Borrow Record")
            return
        else:
            print("USER ID  BOOK ID")
            for k in self.borrowlog:
                print(k)

    def most_borrowed(self):
        if not self.books:
            print("No Book Available...")
            return
        max_borrow = max(self.books.values(),key=lambda b:b['borrowcount'])['borrowcount']
        most_borrowed = [b['booknm'] for b in self.books.values() if b['borrowcount']==max_borrow]
        print("Most Borrowed Book::",most_borrowed,"-",max_borrow,"times")

    def least_borrowed(self):
        if not self.books:
            print("No Book Available...")
            return
        min_borrow = min(self.books.values(),key=lambda b:b['borrowcount'])['borrowcount']
        least_borrowed = [b['booknm'] for b in self.books.values() if b['borrowcount']==min_borrow]
        print("Least Borrowed Book::",least_borrowed,"-",min_borrow,"times")

    def total_books_borrowed(self):
        sum=0
        for i in self.books:
            sum=sum+self.books[i]['borrowcount']
        print("Total books borrow::",sum)

    def members_not_borrowed_book(self):
        borrowed_user_ids = set()
        for record in self.borrowlog:
            u_id = record[0]
            borrowed_user_ids.add(u_id)
        print("User Who Borrowed Books::",borrowed_user_ids)

        users_without_books = [u_id for u_id in self.users if u_id not in borrowed_user_ids]
        print("User With No Books Issued::")
        for uid in users_without_books:
            print(f"{uid}: {self.users[uid]}")

    def avg_borrowed_books(self):
        sum = 0
        for i in self.books:
            sum=sum+self.books[i]['borrowcount']
        lib_mem = len(self.users)
        print("Total Registered Users::",lib_mem)
        avg = (sum/lib_mem)
        print("Average Num Of Books Borrowed::",avg)
        
n1 = Mylib()

n = int(input("How Many Users U Want::"))
for i in range(n):
    uid = int(input("USER ID::"))
    uname = input("USER NAME::")
    n1.regi_users(uid,uname)
n1.display()

m = int(input("How Many Books To Register::"))
for j in range (m):
    bid = int(input("BOOOK ID::"))
    bname = input("BOOK NAME::")
    n1.regi_books(bid,bname)
n1.show()

o = int(input("How Many Books To Borrow::"))
for k in range(o):
    uid = int(input("USER ID::"))
    bid = int(input("BOOK ID::"))
    n1.borrow_books(uid,bid)
n1.book_record()

n1.most_borrowed()
n1.least_borrowed()

n1.total_books_borrowed()
n1.members_not_borrowed_book()

n1.avg_borrowed_books()





















