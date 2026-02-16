spisokint = []
spisokfloat = []
spisokstr = []
converted_line = []

def convert_value():
    with open("csv_20260206_08a514.txt") as f:
        f_out = open("csv_20260206_08a514_out.txt" , "w")
        final_result = []
        data = f.readline()
        data_float = data[1].split(",")
        for data_tmp in data:
            data_float = data_tmp.split(",")
            converted_line = []
            for x in data_float:
                if (x[0] == "-" and x.isdigit()) or (x[0] != "-" and x.isdigit()):
                    converted_line.append(int(x))
                elif (x[0] == "-" and "." in x) or (x[0] != "-" and "." in x):
                    converted_line.append(float(x))
                else:
                    converted_line.append(x)
            final_result.append(converted_line)
        final_result = {final_result[0][0]: [final_result[i][1] for i in range(1 , len(final_result[1]))]}
        final_result = {final_result[0][1]: [final_result[i][1] for i in range(1 , len(final_result[1]))]}
        final_result = {final_result[0][2]: [final_result[i][1] for i in range(1 , len(final_result[1]))]}
        final_result = {final_result[0][3]: [final_result[i][1] for i in range(1 , len(final_result[1]))]}
        final_result = {final_result[0][4]: [final_result[i][1] for i in range(1 , len(final_result[1]))]}
        print(final_result.get("Name"))
        print(final_result.get("Age"))
        print(final_result.get("Salary"))
        print(final_result.get("FullTime"))
        print(final_result.get("Department"))
        return final_result
print(convert_value())