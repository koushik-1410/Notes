"""
import time
wait_time=1
max_tries=5
for i in range(max_tries):
    print(f"Attempt no:{i+1},Wait time-{wait_time},Tries left:{5-i-1}")
    time.sleep(wait_time)
    wait_time*=2
"""
import time
target="KoUsHiK"
wait_time=0
max_attempt=5
attempt=1
while attempt<=max_attempt:
    time.sleep(wait_time)
    wait_time=2**wait_time
    print(f"Attempt no:{attempt},Tries left:{max_attempt-attempt}")
    if input("Enter Password:")==target:
        print("Well Done!!!!")
        break
    else:
        print(f"Wrong password....Retries in {wait_time}sec")
    attempt+=1    
    