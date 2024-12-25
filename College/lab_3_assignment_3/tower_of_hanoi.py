def tower_of_hanoi(num,source,destination,temporary):
    for i in range(1,num+1):
        if i==num:
            print(f"Move disc from {source} to {destination}")
        
        