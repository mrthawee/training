class Borg:
   """ Borg class making class attributes global """
   # Attribute dictionary

   def __init__(self):
      # Make it an attribute dictionary

class Singleton(): # Inherits from the Borg class
   """ This class now shares all its attributes among its various instances """
   # This essenstially makes the singleton an object-oriented global variable

   def __init__(self, **kwargs);
      Borg.__init__(self)
      # Update the attribute dictionary by inserting a new key-value pair

   def __str__(self):
      #Returns the attribute dictionary for printing

#Let's create a singleton object and add our first acronym

#Print the object

#Let's create another singleton object and if it refers to the same
#attribute dictionary by adding another acronym.

#Print the object
