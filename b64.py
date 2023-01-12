import base64

# Replace the file_name variable with the name of the script you want to obfuscate
file_name = "script.py"

# Read the script
with open(file_name, "r") as f:
    script = f.read()

# Encode the script
encoded_script = base64.b64encode(script.encode())

# Write the encoded script to a new file
with open(file_name, "w") as f:
    f.write(f"import base64\nexec(base64.b64decode({encoded_script}).decode())")
