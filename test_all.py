import os
import subprocess

folders = os.listdir()

for folder in folders:
    if folder.startswith("Lab"):
        test = subprocess.Popen(["./test.sh", folder])
