# XML stands for eXtensible Markup Language and it is a standard format used to store and 
# exchange data. In Python, we can parse XML files using the built-in `xml` module.

# To start parsing an XML file in Python, we first need to import the 
# `ElementTree` class from the `xml.etree.ElementTree` module. 
# This class represents the XML document as a tree structure, where each node is an XML element.

import xml.etree.ElementTree as ET

# Next, we can use the `parse()` function of the `ElementTree` class to parse an XML file and get the root element of the XML tree:
tree = ET.parse('1.4-KB-XML-File.xml')
root = tree.getroot()

# We can then access the elements and attributes of the XML file using various methods provided by the `ElementTree` class. 
# For example, we can iterate over all child elements of the root element using a for loop:

for child in root:
    print(child.tag, child.attrib)

#find all 'name' elements with price > 35
Software_engineers = root.findall("./name[position = Software Engineer]")
for engineers in Software_engineers:
    print(engineers.attrib['name'])