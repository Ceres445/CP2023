import os
import subprocess

folders = os.listdir()

for folder in folders:
    if folder.startswith("Lab"):
        test = subprocess.Popen(["./test.sh", folder], stdout=subprocess.PIPE)
        output = test.communicate()[1]
        if test.returncode != 0:
            # print(output.decode("utf-8"))
            raise Exception("Test failed for " + folder)

        print("Testing " + folder)
