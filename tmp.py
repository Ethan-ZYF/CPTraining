import csv


def read_csv(file_path):
    data = []
    with open(file_path, "r") as file:
        reader = csv.reader(file)
        # merge 2nd and 3rd columns
        data = [(row[0], row[1] + "\n" + row[2]) for row in reader]
    return data


def write_csv(file_path, data):
    with open(file_path, "w") as file:
        writer = csv.writer(file)
        for row in data:
            writer.writerow(row)


data = read_csv("gre.csv")
write_csv("gre2.csv", data)
