def tower_of_hanoi(num, source, destination, temporary):
    if num == 1:
        print(f"Move Disc {num} from {source} to {destination}")
        return
    tower_of_hanoi(num - 1, source, temporary, destination)
    print(f"Move Disc {num} from {source} to {destination}\n")
    tower_of_hanoi(num - 1, temporary, destination, source)


num = int(input("Enter the number of discs : "))
tower_of_hanoi(num, "A", "C", "B ")
