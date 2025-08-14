import requests

def fetch_data():
    url="https://api.freeapi.app/api/v1/public/randomusers/user/random"
    response=requests.get(url)
    try:
        object=response.json()
    except ValueError:  #JSONDecodeError(excatly this error happen here but it is sub class of ValueError)
        raise Exception("Invalid link..")
    
    if object["success"] and "data" in object:
        user_data=object["data"];
        user_name=user_data["login"]["username"]
        user_coordinates=user_data["location"]["coordinates"]
        return user_name,user_coordinates
    else:
        raise Exception("Falied to fetch user data..")


def main():
    try:
        user_name,user_coordinate=fetch_data()
        print(f"Username: {user_name}\nLocation:\nLatitude: {user_coordinate["latitude"]}\nLongitude: {user_coordinate["longitude"]}")

    except Exception as e:
        print(str(e))


if __name__=="__main__":
    main()



    