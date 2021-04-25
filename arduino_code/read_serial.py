import serial

arduino_port = "COM3" # serial port that Arduino is connected to
baud = 9600 # arduino runs at 9600 baud
fileName = "sensor_data.csv" # name of CSV file to be generated

#setting up serial connection and creating the CSV file
ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port: " + arduino_port)

# use input parameter w to write a new file, use "a" to append to file
file = open(fileName, "w")
print("Created file")

samples = 10 # how many samples to collect
print_labels = False
line = 0 #start at 0 because header is 0

while line < samples:
    #incoming = ser.read(9999)
    #if len(incoming) > 0:
    if print_labels:
        if line==0:
            print("Printing Column Headers")
        else:
            print("Line " + str(line) + ": writing...")

    #display the data to the terminal
    getData = str(ser.readline().decode())
    data = getData[0:][:-2]
    print(data)

    #add the data to the file
    file = open(fileName, "a") #append data to fileN
    file.write(data + "\n") #write data with a newline
    line = line+1

#close out file
print("Data collection complete!")
file.close()
