A = B = 0
command = input()
while (command != "7"):
    command = command.split()
    if command[0] == "1":
        if command[1] == "A":
            A = int(command[2])
        else:
            B = int(command[2])
    elif command[0] == "2":
        if command[1] == "A":
            print(A)
        else:
            print(B)
    elif command[0] == "3":
        if command[1] == "A":
            if command[2] == "B":
                A = A+B
            else:
                A = A+A
        else:
            if command[2] == "A":
                B = A+B
            else:
                B = B+B
    elif command[0] == "4":
        if command[1] == "A":
            if command[2] == "A":
                A = A*A
            else:
                A = A*B
        else:
            if command[2] == "A":
                B = B*A
            else:
                B = B*B
    elif command[0] == "5":
            if command[1] == "A":
                if command[2] == "B":
                    A = A-B
                else:
                    A = A-A
            else:
                if command[2] == "A":
                    B = B-A
                else:
                    B = B-B
    elif command[0] == "6":
        if command[1] == "A":
            if command[2] == "A":
                A = int(A/A)
            else:
                A = int(A/B)
        else:
            if command[2] == "A":
                B = int(B/A)
            else:
                B = int(B/B)
    command = input()