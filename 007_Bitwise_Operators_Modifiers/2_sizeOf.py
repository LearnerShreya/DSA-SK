import sys

# Examples and real-world use cases
age = 25                        # Small value — like short in C++
population = 1_000_000          # Large value — like long
stars = 9223372036854775807     # Very large — like long long
temperature = -15               # Signed integer
student_count = 150             # Unsigned-like positive count
price = 19.99                   # Float
distance = 1.797e+308           # Double-like
flag = True                     # Boolean

# Displaying values and sizes
print("Age (int):", age, "| Size:", sys.getsizeof(age), "bytes")
print("Population (int):", population, "| Size:", sys.getsizeof(population), "bytes")
print("Stars (int):", stars, "| Size:", sys.getsizeof(stars), "bytes")
print("Temperature (int):", temperature, "| Size:", sys.getsizeof(temperature), "bytes")
print("Student Count (int):", student_count, "| Size:", sys.getsizeof(student_count), "bytes")

print("Price (float):", price, "| Size:", sys.getsizeof(price), "bytes")
print("Distance (float - large):", distance, "| Size:", sys.getsizeof(distance), "bytes")

print("Flag (bool):", flag, "| Size:", sys.getsizeof(flag), "bytes")



# Age (int): 25 | Size: 28 bytes
# Population (int): 1000000 | Size: 28 bytes
# Stars (int): 9223372036854775807 | Size: 32 bytes
# Temperature (int): -15 | Size: 28 bytes
# Student Count (int): 150 | Size: 28 bytes
# Price (float): 19.99 | Size: 24 bytes
# Distance (float - large): 1.797e+308 | Size: 24 bytes
# Flag (bool): True | Size: 28 bytes