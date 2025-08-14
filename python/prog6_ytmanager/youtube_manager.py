import json
import time
def animation():
    print("Season Expiring")
    for i in range(6):
        print("."*i,end="\r")
        time.sleep(0.4)
    print("Done!!!")

def load_data():
    try:
        with open ("youtube.txt",'r') as file:
            return json.load(file)
    except FileNotFoundError:
        return []
    finally:
        pass

def save_data(videos):
    with open ("youtube.txt",'w') as file:
        json.dump(videos,file)

def list_all_videos(videos):
    for index,video in  enumerate(videos,start=1):
        print(f"{index}.")

def add_video(videos):
    name=input("Enter video name: ")
    time=input("Enter video time: ")
    videos.append({'name':name,'time':time})
    save_data(videos)

def update_video(videos):
    list_all_videos(videos)
    index=int(input("Enter the index of the video to update:"))
    if 1<=index<=len(videos):
        name=input("Enter the name of video:")
        time=input("enter the duration of this video:")
        videos[index-1]={'name':name,'time':time}
        save_data(videos)
    else:
        print("Invalid index entered..")   
def delete_video(videos):
    list_all_videos(videos)
    index=int(input("Enter the index of the video:"))
    if 1<=index<=len(videos):
        del videos[index-1]#To delete the value by index
        save_data(videos)
    else:
        print("Invalid index entered..")
def main():
    
    videos=load_data()

    while True:
        print("\n Youtube Manager ")
        print("1. List all youtube videos")
        print("2. Add a youtube video")
        print("3. Update a youtube video details")
        print("4. Delete a youtube video")
        print("5. Exit the app")
        choice=input("Enter your choice: ")

        print(videos)

        match choice:
            case '1':
                list_all_videos(videos)
            case '2':
                add_video(videos)
            case '3':
                update_video()
            case '4':
                delete_video(videos)
            case '5':
                animation()
            case _:
                print("Invalid choice")

if __name__=="__main__":
    main()
