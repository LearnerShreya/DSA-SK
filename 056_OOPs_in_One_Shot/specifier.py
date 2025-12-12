class Teacher:
    def __init__(self):
        self.name = None          # public
        self.dept = None
        self.subject = None
        self.__salary = None      # private (name-mangled)

    # change department
    def change_dept(self, new_dept):
        self.dept = new_dept

    # setter (write salary safely)
    def set_salary(self, s):
        self.__salary = s

    # getter (read salary safely)
    def get_salary(self):
        return self.__salary


# object creation
t1 = Teacher()

# accessing public data directly
t1.name = "Shradha"
t1.subject = "C++"
t1.dept = "Computer Science"

# accessing private data using setter
t1.set_salary(25000)

# output
print(t1.name)
print(t1.get_salary())     # salary accessed using getter

# another object
t2 = Teacher()
