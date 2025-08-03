# Use int for small values like age (Python auto-handles size)
age = 25
print("Age (int):", age)

# Use int for larger numbers like population or file size
population = 1_000_000
print("Population (int):", population)

# Use int for very large numbers (Python handles big integers automatically)
stars_in_galaxy = 9223372036854775807
print("Stars in Galaxy (int):", stars_in_galaxy)

# Use int for signed values (positive/negative), e.g., temperature
temperature = -15
print("Temperature (int):", temperature, "°C")

# Use int for unsigned-like positive values, e.g., student count
student_count = 150
print("Student Count (int):", student_count)




# In Python, int automatically behaves like short, long, and long long — there's no need to specify size.

# There's no unsigned or signed keyword; Python int can represent both positive and negative numbers by default.

# Python automatically allocates memory as needed (unlike C++ fixed-size integers).