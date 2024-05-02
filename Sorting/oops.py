# dog.py

class Dog:
    species = "Canis familiaris"

    def __init__(self, name, age):
        self.name = name
        self.age = age

    # Instance method
    def __str__(self):
        return f"{self.name} is {self.age} years old"

    # Another instance method
    def speak(self, sound):
        return f"{self.name} says {sound}"
    
class Bulldog(Dog):
    def speak(self, sound = "Woof"):
        return f"{self.name} says {sound}"
    pass

class Dachshund(Dog):
    pass

class JackRusselTerrier(Dog):
    def speak(self, sound="Arf"):
        return super().speak(sound)
    
    
class GoldenRetriever(Dog):
    def speak(self, sound = "Bark"):
        return super().speak(sound)
    
Lola = GoldenRetriever("Lola", 3)
print(Lola.speak())

miles = Bulldog("Miles",4)

print(isinstance(miles, Dog))

print(issubclass(Bulldog, Dog))

Anyo = JackRusselTerrier("Anyo", 8)
print(Anyo.speak())

print(miles.speak())

miles.speak("Bow Wow")

print(miles)


# Create a Car class with two instance attributes:

# .color, which stores the name of the car’s color as a string
# .mileage, which stores the number of miles on the car as an integer
# Then create two Car objects—a blue car with twenty thousand miles and a red car with thirty thousand miles—and print out their colors and mileage. Your output should look like this:

# The blue car has 20,000 miles
# The red car has 30,000 miles
# There are multiple ways to solve this challenge. To effectively practice what you’ve learned so far, try to solve the task with the information about classes in Python that you’ve gathered in this section.

class Car:
    def __init__(self, name_color, mileage):
        self.name_color = name_color
        self.mileage = mileage
    
    def __str__(self):
        return f"The {self.name_color} car has {self.mileage} miles"

blue = Car('blue',20000)
red = Car('red', 30000)

print(blue)
print(red)