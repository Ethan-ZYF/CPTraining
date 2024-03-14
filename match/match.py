import subprocess
from random import randint

MY_CODE_PATH = "./Zme.cpp"
AC_CODE_PATH = "./Zac.cpp"
MY_OUTPUT_PATH = "./me.out"
AC_OUTPUT_PATH = "./ac.out"
NUM_TESTS = 100


def make_input(outfile):
    T = 1
    outfile.write(f"{T}\n")
    for t in range(T):
        N = randint(1, 100)
        outfile.write(f"{N}\n")
        for _ in range(N):
            outfile.write(f"{randint(1, N)} {randint(1, N)}\n")


def compile_code():
    subprocess.run(["g++-13", MY_CODE_PATH, "-o", "me"])
    subprocess.run(["g++-13", AC_CODE_PATH, "-o", "ac"])


def run_code():
    subprocess.run(["./me"], stdin=open("input.txt", "r"), stdout=open(MY_OUTPUT_PATH, "w"))
    subprocess.run(["./ac"], stdin=open("input.txt", "r"), stdout=open(AC_OUTPUT_PATH, "w"))


def compare_output() -> bool:
    my_output = open(MY_OUTPUT_PATH, "r").read()
    ac_output = open(AC_OUTPUT_PATH, "r").read()
    if my_output == ac_output:
        print("AC")
        return True
    else:
        print("WA")
        return False


def cleanup():
    subprocess.run(["rm", "me"])
    subprocess.run(["rm", "ac"])
    subprocess.run(["rm", MY_OUTPUT_PATH])
    subprocess.run(["rm", AC_OUTPUT_PATH])


if __name__ == "__main__":

    compile_code()

    for i in range(NUM_TESTS):
        with open("input.txt", "w") as infile:
            make_input(infile)
        print(f"Running test {i + 1}", end=": ")
        run_code()
        if not compare_output():
            print("Test case:")
            print(open("input.txt", "r").read())
            break
    cleanup()
