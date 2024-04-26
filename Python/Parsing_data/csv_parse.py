import csv

file_path = "/home/suraj/DSA/Python/customers-100.csv"
with open (file_path, "r") as file:
	# code to parse the file
	csv_reader = csv.reader(file)
	headers = next(csv_reader)
	for row in csv_reader:
		row[0] = float(row[0])
		print(row)



