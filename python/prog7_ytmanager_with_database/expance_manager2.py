import sqlite3
import time

# --- DB setup ---
conn = sqlite3.connect('expense_management.db')   # ✅ DB filename (corrected spelling)
cursor = conn.cursor()

cursor.execute('''
    CREATE TABLE IF NOT EXISTS expenses(
        id INTEGER PRIMARY KEY AUTOINCREMENT,   -- ✅ autoincrement id
        category TEXT NOT NULL,                 -- ✅ fixed spelling
        expense REAL NOT NULL,                  -- ✅ use REAL for decimals
        day INTEGER NOT NULL,
        month INTEGER NOT NULL,
        year INTEGER NOT NULL
    )
''')

# --- helper / UI ---
def animation():
    print("Session Terminating")
    for i in range(6):
        print("." * i, end="\r")
        time.sleep(0.3)
    print("Done!!!")

# ✅ NEW: function to check whether an expense id exists
def expense_exists(expense_id):
    cursor.execute("SELECT 1 FROM expenses WHERE id = ?", (expense_id,))
    return cursor.fetchone() is not None
    # ✅ (Added this whole function to validate IDs before update/delete)

def list_expenses():
    cursor.execute("SELECT * FROM expenses ORDER BY year, month, day")
    rows = cursor.fetchall()
    if not rows:
        print("No expenses found.")
        return
    print("ID\tDate\t\tCategory\tAmount")
    print("-" * 50)
    for row in rows:
        # row -> (id, category, expense, day, month, year)
        print(f"{row[0]}\t{row[3]:02d}-{row[4]:02d}-{row[5]}\t{row[1]}\t\t{row[2]}")

def add_expenses(amount, category, day, month, year):
    cursor.execute(
        "INSERT INTO expenses (category, expense, day, month, year) VALUES (?,?,?,?,?)",
        (category, amount, day, month, year)
    )
    conn.commit()

def update_expenses(expense_id):
    # ✅ ID validation inside the function (so callers don't need to repeat it)
    if not expense_exists(expense_id):
        print("Invalid ID — no expense found with that ID.")
        return

    category = input("Enter the category: ")
    try:
        amount = float(input("Enter the amount: "))
    except ValueError:
        print("Invalid amount. Update cancelled.")
        return

    cursor.execute(
        "UPDATE expenses SET category = ?, expense = ? WHERE id = ?",
        (category, amount, expense_id)
    )
    conn.commit()
    print("Expense updated.")

def delete_expenses(expense_id):
    # ✅ ID validation before deleting
    if not expense_exists(expense_id):
        print("Invalid ID — no expense found with that ID.")
        return

    # optional: ask for confirmation
    confirm = input(f"Are you sure you want to delete expense ID {expense_id}? (y/N): ").strip().lower()
    if confirm != 'y':
        print("Delete cancelled.")
        return

    cursor.execute("DELETE FROM expenses WHERE id = ?", (expense_id,))
    conn.commit()
    print("Expense deleted.")

def expenses_of_month(month, year):
    cursor.execute("SELECT * FROM expenses WHERE month = ? AND year = ? ORDER BY day", (month, year))
    rows = cursor.fetchall()
    if not rows:
        print(f"No expenses found for {month:02d}-{year}.")
        return

    total = 0.0
    print("ID\tDate\t\tCategory\tAmount")
    print("-" * 50)
    for row in rows:
        print(f"{row[0]}\t{row[3]:02d}-{row[4]:02d}-{row[5]}\t{row[1]}\t\t{row[2]}")
        total += row[2]
    print("-" * 50)
    print(f"Total expenses of this month is {total}")

# --- main loop ---
def main():
    while True:
        print("\n Expense Manager ")
        print("1. List all expenses")
        print("2. Add an expense")
        print("3. Update an expense")
        print("4. Delete an expense")
        print("5. Show total spending of a month")
        print("6. Exit")
        choice = input("Enter your choice: ").strip()

        match choice:
            case '1':
                list_expenses()
            case '2':
                try:
                    amount = float(input("Enter amount: "))
                except ValueError:
                    print("Invalid amount. Operation cancelled.")
                    continue
                category = input("Enter the category: ")
                date_input = input("Enter date (DD-MM-YYYY): ")
                try:
                    day, month, year = map(int, date_input.split('-'))
                except Exception:
                    print("Invalid date format. Use DD-MM-YYYY.")
                    continue
                add_expenses(amount, category, day, month, year)
                print("Expense added.")
            case '3':
                try:
                    expense_id = int(input("Enter the ID of the expense to update: "))
                except ValueError:
                    print("Invalid ID.")
                    continue
                # ✅ we can rely on update_expenses to validate the id internally
                update_expenses(expense_id)
            case '4':
                try:
                    expense_id = int(input("Enter the ID of the expense to delete: "))
                except ValueError:
                    print("Invalid ID.")
                    continue
                # ✅ delete_expenses validates ID and asks confirmation
                delete_expenses(expense_id)
            case '5':
                date_input = input("Enter date (MM-YYYY): ")
                try:
                    month, year = map(int, date_input.split('-'))
                except Exception:
                    print("Invalid date format. Use MM-YYYY.")
                    continue
                expenses_of_month(month, year)
            case '6':
                animation()
                break
            case _:
                print("Invalid choice! Please try again.")

    conn.close()

if __name__ == "__main__":
    main()
