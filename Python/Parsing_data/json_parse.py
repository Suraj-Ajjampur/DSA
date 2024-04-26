# In this example, we used the `open()` function to open the `data.json` file in read mode (`’r’`) 
# and assigned its contents to a variable called `data`. Then, we used the `json.loads()` function to
# parse the JSON data stored in the `data` variable into a Python object called `parsed_data`.

# We can then access individual values in the parsed data using dictionary-like syntax. 
# For example, if our JSON data contains information about a person, we can access their name like this:

import json 

with open('sample1.json','r') as f:
    data = f.read()

#parse the data
parsed_data = json.loads(data)
print(parsed_data)

#The `json` module also provides a `dump()` function that allows us to convert a Python object into a JSON-formatted string. Here’s an example:
person = {'name' :'John', 'age':30, 'city': 'New York'}
json_string = json.dumps(person)

print(json_string)




