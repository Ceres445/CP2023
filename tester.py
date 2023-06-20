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
    # Loads testcases from the json file as a python dict

    with open(testcases_path, "r") as f:
        testcases = json.load(f)

    # Prints code file name
    print(
        "Testing code for student with BITS ID: "
        + os.path.splitext(os.path.basename(code_path))[0]
    )

    # Compiles C code
    # Compilation errors need to be handled here
    compilation_process = subprocess.run(
        "gcc " + code_path + ' -lm',
        text=True,
        timeout=5,
        shell=True,
        capture_output=True,
    )

    if not os.path.exists(
        os.path.join(os.getcwd(), "a.out")
    ):  # If compilation error occurs
        compilation_error_occurred = True
        print("Compilation Error:\n")
        print(compilation_process.stderr)
        return -1  # Exit if compilation error in student mode

    for test in testcases["test_cases"]:
        testcase_num += 1
        # Returns CompletedProcess instance with attributes args, returncode, stdout and stderr, all of type string.
        process_stdin = test["input"]

        try:
            # Student mode
            print("-----TEST CASE NUMBER " + str(test["id"]) + "-----")
            print("---Given Input---")
            print(test["input"])
            print("---Expected Output---")
            print(test["output"])
            print("---Your Output---")

            # Terminate process after 5 seconds
            completed_process = subprocess.run(
                "./a.out",
                capture_output=True,
                input=process_stdin,
                text=True,
                timeout=test["time_out"],
                shell=True,
                check=False,
            )

            process_stdout = completed_process.stdout

        except subprocess.TimeoutExpired:
            # Student mode or Test Case Generator mode
            print("Timeout on test case " + str(test["id"]))
            print("---Result: Failed---")

        except subprocess.CalledProcessError as error:
            # Runtime exceptions other than timeout
            # Student mode and Test Case Generator mode
            print("Exception: ", error.stderr)
            print("---Result: Failed---")

        except Exception as error:
            # All other exceptions
            # Unlikely that any exceptions other than timeout or runtime errors occur, but this handles it
            # Student mode and Test Case Generator mode
            print("Exception:", error)
            print("---Result: Failed---")

        else:
            # Only runs if no exception
            # Student mode

            testcase_passed = process_stdout == test["output"]
            print(process_stdout)
            result = "Passed" if process_stdout == test["output"] else "Failed"
            if result == "Failed":
                test["output"] += "L" * 50
                total = [
                    (process_stdout[i], test["output"][i])
                    for i in range(len(process_stdout))
                    if process_stdout[i] != test["output"][i]
                ]
                print(total)
                a = "".join([i[0] for i in total])
                b = "".join([i[1] for i in total])
                print("Your output: ", a)
                print("expected: ", b)
            print("---Result: " + result + "---")

            # Increases score if stdout and expected output match
            score += int(testcase_passed)

    print("\nFinal Score:", score, "/", testcase_num)

    # Deletes a.out after evaluation
    if os.path.exists("a.out"):
        os.remove("a.out")

    if score == testcase_num:
        return 0
    else:
        return -1


if __name__ == "__main__":
    import os

    cur = os.getcwd().split("/")[-1]
    import glob

    print(cur)
    if glob.glob(cur + ".c"):
        code_path = glob.glob(cur + ".c")[0]
    else:
        raise Exception("No C file found in current directory")
    if glob.glob(cur + "*.json"):
        testcases_path = glob.glob(cur + "*.json")[-1]
    else:
        raise Exception("No JSON file found in current directory")
    if autoeval(code_path, testcases_path) == 0:
        print("All test cases passed")
    else:
        raise Exception("Some test cases failed")
