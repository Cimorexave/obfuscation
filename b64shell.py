import base64
import os

# Replace the file_name variable with the name of the shell script you want to obfuscate
file_name = "script.sh"

# Read the script
with open(file_name, "r") as f:
    script = f.read()

# Encode the script
encoded_script = base64.b64encode(script.encode()).decode()

# Write the encoded script to a new file
with open(file_name, "w") as f:
    f.write(f"#!/bin/bash\necho '{encoded_script}' | base64 -d | bash")

# Make the new file executable
os.chmod(file_name, 0o755)

# Delete the script
os.remove(__file__)
