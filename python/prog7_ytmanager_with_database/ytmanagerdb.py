import sqlite3
import time
conn=sqlite3.connect('youtube_videos.db')

cursor=conn.cursor()

cursor.execute('''
    CREATE TABLE IF NOT EXISTS videos(
               id INTEGER PRIMARY KEY,
               name TEXT NOT NULL,
               time TEXT NOT NULL
               )
''')
def animation():
    print("Season Terminating")
    for i in range(6):
        print("."*i,end="\r")
        time.sleep(0.3)
    print("Done!!!")


def list_videos():
    cursor.execute("SELECT * FROM videos")
    for row in cursor.fetchall():
        print(row)

def add_video(name,time):
    cursor.execute("INSERT INTO videos (name,time) VALUES (?,?)",(name,time))
    conn.commit()

def update_video(videoid,new_name,new_time):
    cursor.execute("UPDATE videos SET name = ?,time = ? WHERE id = ?",(new_name,new_time,videoid))
    conn.commit()

def delete_video(videoid):
    cursor.execute("DELETE FROM videos where id = ?",(videoid,))
    conn.commit()

def main():
    while True:
        print("\n Youtube Manager ")
        print("1. List all youtube videos")
        print("2. Add a youtube video")
        print("3. Update a youtube video details")
        print("4. Delete a youtube video")
        print("5. Exit the app")
        choice=input("Enter your choice: ")
        match choice:
            case '1':
                list_videos()
            case '2':
                name=input("ENter the name of the video: ")
                time=input("ENter the duration of the video: ")
                add_video(name,time)
            case '3':
                videoid=int(input("Enter video id to update: "))
                name=input("ENter the name of the video: ")
                time=input("ENter the duration of the video: ")
                update_video(videoid,name,time)
            case '4':
                videoid=int(input("Enter video id to delete"))
                delete_video(videoid)
            case '5':
                animation()
                break
            case _:
                print("Invalid Choice")

    conn.close()
if __name__=="__main__":
    main()

