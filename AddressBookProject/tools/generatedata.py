import random

# Lists of first names and last names
first_names = ["John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Linda", "Robert", "Patricia"]
last_names = ["Doe", "Smith", "Johnson", "Brown", "Williams", "Jones", "Garcia", "Martinez", "Miller", "Davis"]
def generate_phone():
    return f"{random.randint(100, 999)}-{random.randint(100, 999)}-{random.randint(1000, 9999)}"

# Generate 5000 entries
entries = []
for _ in range(5000):
    first_name = random.choice(first_names)
    last_name = random.choice(last_names)
    phone = generate_phone() if random.choice([True, False]) else ""
    entries.append(f"{first_name} {last_name} {phone}")

# Save to a file
with open("data.txt", "w") as file:
    file.write("\n".join(entries))

print("File 'data.txt' generated!")