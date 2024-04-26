# open the file and return an object
file_obj = open("examplefile.txt", "r")

# Read the file data
file_data = file_obj.read()

# Split the data into a list of lines
lines = file_data.splitlines()
print(lines)
file_obj.close()

with open("examplefile.txt", "r") as file_data:
    for line in file_data:
        data = line.split()
        print(data)

