import requests

def fetch_data():
    url="https://api.freeapi.app/api/v1/public/randomusers/13"
    response=requests.get(url)
    try:
        object=response.json()
    except ValueError:
        raise Exception("Invalid Link..")
    
    if object["success"] and "data" in object:
        user_data=object["data"]
        name=user_data["name"]
        phone_no=user_data["phone"]
        country=user_data["location"]["country"]
        return name,phone_no,country
    else:
        raise Exception("Data missing..")
    




def main():
    try:
        name,phone_no,country=fetch_data()
        print(f"Name: {name['title']}.{name['first']} {name['last']}\nPhoneNO:{phone_no}\nCountry: {country}")
    except Exception as e:
        print(str(e))


if __name__=="__main__":
    main()




    