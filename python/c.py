class myClass:
   var = 'blah'

   def dump(self):
      print "this is a msg from fn-dump() of myClass."
      print "var = %s" % self.var

obj = myClass()
obj.dump()
obj.var = "abacd"
obj.dump()
