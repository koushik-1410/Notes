"""
size=int(input("enter the size of the list"))
my_list=[None]*size
dublicate=0
for i in range(size):
    my_list[i]=input(f"Enter the element {i+1}:")
print("My_list is ",my_list)   
for item in my_list:
    if my_list.count(item)>1:
        dublicate=1
if dublicate==1:
    print(item,"is the dublicate element in list")        
"""
items=["apple","banana","orange","tomato","apple"]
unique_item=set()
for item in items:
    if item in unique_item:
        print("THe dublicate element is:",item)
        break
    unique_item.add(item)    