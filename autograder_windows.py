# Autograder for windows, modified by Druva, dm on Whatsapp for queries


import csv
import json
import os
import subprocess
import sys

# To call this script from the command line, run this:
# python3 autograder.py <path_of_c_code_file> <path_of_testcase_json_file> -flag
# use the -i flag to operate in instructor mode
# use the -t flag to operate in testcase generator mode

# To call this script in the batch processing mode, use:
# python3 autograder.py <path_of_testcase_json_file> -b


def autoeval(code_path, testcases_path, flag=None):
    score = 0
    testcase_num = 0

    # Batch processing mode
    # currently appends new entry to end of csv, and doesn't make a new csv if it already exists
    if flag == "-b":
        for root, dirs, files in os.walk(os.getcwd()):
            for file in files:
                if file.endswith(".c"):
                    code_path = os.path.join(root, file)
                    autoeval(code_path, sys.argv[1], "-i")
        print("scores.csv prepared")
        return 0

    # Loads testcases from the json file as a python dict

    with open(testcases_path, "r") as f:
        testcases = json.load(f)

    if flag == "-i":
        # Instructor mode
        # Make .csv file with user's code file name in the directory of the terminal.

        output_file_name = "scores.csv"

        # if scores.csv exists add new student records to existing file else make new
        if os.path.exists("scores.csv"):
            output_file = open(output_file_name, "a+")
            output_file_writer = csv.writer(output_file)
        else:
            output_file = open(output_file_name, "w")
            output_file_writer = csv.writer(output_file)
            # first row in the CSV (added only when new file created)
            first_row = ["Student ID"]

            for test in testcases["test_cases"]:
                first_row.append("Test Case " + str(test["id"]))

            first_row.append("Total Score")
            output_file_writer.writerow(first_row)

        # Row for writing in CSV (only used for instructor mode)
        # Storing Student ID as file name
        student_row = [os.path.splitext(os.path.basename(code_path))[0]]

    # Prints code file name
    elif flag == None:
        print(
            "Testing code for student with BITS ID: "
            + os.path.splitext(os.path.basename(code_path))[0]
        )

    # Compiles C code
    # Compilation errors need to be handled here
    if flag=="-i":
        compilation_process = subprocess.run(
            "gcc " + code_path+" -w",
            text=True,
            timeout=5,
            shell=True,
            capture_output=True,
        )
    else:
        compilation_process = subprocess.run(
            "gcc " + code_path,
            text=True,
            timeout=5,
            shell=True,
            capture_output=True,
        )

    compilation_error_occurred = False
    if not os.path.exists(os.path.join(os.getcwd(), "a.exe")):  # If compilation error occurs
        if flag == None or flag == "-t":  # Student mode and Test Case Generator mode
            compilation_error_occurred = True
            print("Compilation Error:\n")
            print(compilation_process.stderr)
            return  # Exit if compilation error in student mode
        elif flag == "-i":  # Instructor mode
            compilation_error_occurred = True

    if flag == "-t":
        # Testcase generator mode
        generated_testcases = {"test_cases": []}

    for test in testcases["test_cases"]:
        testcase_num += 1
        # Returns CompletedProcess instance with attributes args, returncode, stdout and stderr, all of type string.
        process_stdin = test["input"]

        if compilation_error_occurred:
            # Write 'Compilation Error' into student_row for each testcase
            student_row.append("Compilation Error")
            continue

        try:
            if flag == None:
                # Student mode
                print("-----TEST CASE NUMBER " + str(test["id"]) + "-----")
                print("---Given Input---")
                print(test["input"])
                print("---Expected Output---")
                print(test["output"])
                print("---Your Output---")

            # Terminate process after 5 seconds
            completed_process = subprocess.run(
                ".\\a.exe",
                capture_output=True,
                input=process_stdin,
                text=True,
                timeout=test["time_out"],
                shell=True,
                check=False,
            )
            # print(completed_process)

            process_stdout = completed_process.stdout

        except subprocess.TimeoutExpired:
            if flag == None or flag == "-t":
                # Student mode or Test Case Generator mode
                print("Timeout on test case " + str(test["id"]))
                print("---Result: Failed---")

            elif flag == "-i":
                # Instructor mode
                # Writing TimeoutExpired error into student_row
                student_row.append("Timeout")

        except subprocess.CalledProcessError as error:
            # Runtime exceptions other than timeout
            if flag == None or flag == "-t":
                # Student mode and Test Case Generator mode
                print("Exception: ", error.stderr)
                print("---Result: Failed---")

            elif flag == "-i":
                # Instructor mode
                # Writing error into student_row
                student_row.append(error.stderr)

        except Exception as error:
            # All other exceptions
            # Unlikely that any exceptions other than timeout or runtime errors occur, but this handles it
            if flag == None or flag == "-t":
                # Student mode and Test Case Generator mode
                print("Exception:", error)
                print("---Result: Failed---")

            elif flag == "-i":
                # Instructor mode
                # Writing other errors into student_row
                student_row.append(error)

        else:
            # Only runs if no exception
            if flag == "-i":
                # Instructor mode
                # Writing status into student_row if all runs well
                testcase_passed = process_stdout == test["output"]
                student_row.append(testcase_passed)

            elif flag == None:
                # Student mode

                testcase_passed = process_stdout == test["output"]
                print(process_stdout)
                result = "Passed" if process_stdout == test["output"] else "Failed"
                print("---Result: " + result + "---")

            elif flag == "-t":
                # Testcase generator mode
                # add output into generated_testcases
                test["output"] = process_stdout
                generated_testcases["test_cases"].append(test)
                testcase_passed = process_stdout == test["output"]

            # Increases score if stdout and expected output match
            score += int(testcase_passed)

    if flag == "-i":
        # Instructor mode
        # Storing final score into CSV
        student_row.append(score)
        output_file_writer.writerow(student_row)

        # Closing the output csv file
        output_file.close()

    if flag == "-t":
        # Testcase generator mode
        # Dump generated testcases into <c_code_file_name>_testcases.json
        with open(
            os.path.splitext(os.path.basename(code_path))[0] + "_testcases.json", "w"
        ) as outfile:
            json.dump(generated_testcases, outfile)
        print("Test cases generated")

    if flag is None:
        print("\nFinal Score:", score, "/", testcase_num)

    # Deletes a.out after evaluation
    if os.path.exists("a.exe"):
        os.remove("a.exe")

    return score


if __name__ == "__main__":
    try:
        print("Final Score:", autoeval(sys.argv[1], sys.argv[2], sys.argv[3]))
    except IndexError:
        if sys.argv[2] == "-b":
            autoeval(None, sys.argv[1], sys.argv[2])
        else:
            autoeval(sys.argv[1], sys.argv[2])
