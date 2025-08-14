import sqlite3
import time


conn=sqlite3.connect('expence_management.db')


cursor=conn.cursor()


cursor.execute('''
    CREATE TABLE IF NOT EXISTS expances(
               id INTEGER PRIMARY KEY,
               catagory TEXT NOT NULL,
               expance FLOAT NOT NULL,
               day INTEGER NOT NULL,
               month INTEGER NOT NULL,
               year INTEGER NOT NULL
               )
''')

def animation():
    print("Exiting the season")
    for i in range(6):
        print("."*i,end="\r")
        time.sleep(0.3)
    print("Done!!!")


def list_expances():
    cursor.execute("SELECT * FROM expances")
    print("ID\tDate \tCatagory\tAmount")
    for row in cursor.fetchall():
        print(f"{row[0]}\t{row[3]:02d}-{row[4]:02d}-{row[5]}{row[1]}{row[2]}")
def add_expances(amount,catagory,day,month,year):
    cursor.execute("INSERT INTO expances (catagory,expance,day,month,year) VALUES (?,?,?,?,?)",(catagory,amount,day,month,year))
    conn.commit()
def update_expances(id):

    catagory=input("Enter the catagory: ")
    amount=float(input("Enter the amount: "))
    cursor.execute("UPDATE expances SET catagory = ?,expance = ? WHERE id = ?",(catagory,amount,id))
    conn.commit()
def delete_expances(id):
    cursor.execute("DELETE FROM expances where id = ?",(id,))
    conn.commit()
def expances_of_month(month, year):
    cursor.execute("SELECT * FROM expances WHERE month = ? AND year = ?",(month,year))
    total=0
    for row in cursor.fetchall():
        print(f"{row[0]}\t{row[3]:02d}-{row[4]:02d}-{row[5]}{row[1]}{row[2]}")
        total=total+row[2]
    print(f"Total expances of this month is {total}")




def main():
    while True:
        print("\n Youtube Manager ")
        print("1. List all expences")
        print("2. Add an expences")
        print("3. Update an expences")
        print("4. Delete an expences")
        print("5. Show total spending of a month")
        print("6. Exit")
        choice=input("Enter your choice: ")
        match choice:
            case '1':
                list_expances()
            case '2':
                amount=float(input("Enter amount: "))
                catagory=input("Enter the catagory: ")
                date_input = input("Enter date (DD-MM-YYYY): ")
                day, month, year = map(int, date_input.split('-'))
                add_expances(amount,catagory,day,month,year)
            case '3':
                id=int(input("Enter the id of yhe expances: "))
                cursor.execute("SELECT * FROM expances")
                if(1<=id<=len(cursor.fetchall())):
                    update_expances(id)
                else:
                    print("Invaild id")
            case '4':
                id=int(input("ENter the id of expances:"))
                cursor.execute("SELECT * FROM expances")
                if(1<=id<=len(cursor.fetchall())):
                    delete_expances(id)
                else:
                    print("Invaild id")
            case '5':
                date_input = input("Enter date (MM-YYYY): ")
                month, year = map(int, date_input.split('-'))
                expances_of_month(month, year)
            case '6':
                animation()
                break

if __name__=="__main__":
    main()