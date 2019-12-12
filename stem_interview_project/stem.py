'''
Stem Telemetry Reader
By Thawee Techathamnukool
Date: 11/27/2019

Interview project

Provide object-oriented system design, implementation, and test plan for the
following requirements:

  * Read telemetry in from the attached data file in the format

  ```
  T, kW, V, I
  ```

  * For each of the kW, V, and I fields, process the input data and output a log in the following format:

  ```
T, kW, V, I, kW-avg, V-avg, I-avg
  ```

  where the first four fields are the input values for each timestamp and the avg fields are the 5-second sliding window average of the corresponding input field (i.e. only output averages when there are no gaps in the data for the last five seconds).

  * Detect anomalies in the input data and output a line describing the anomaly

  ```
2018-01-08 14:54:42.630000, 441.781, 477.47, 925.254, , ,
2018-01-08 14:54:43.784000, 320.249, 475.942, 672.873, , ,
2018-01-08 14:54:44.900000, 435.929, 482.613, 903.268, , ,
2018-01-08 14:54:46.010000, 357.977, 475.937, 752.151, , ,
2018-01-08 14:54:47.189000, 461.782, 483.066, 955.939, , ,
2018-01-08 14:54:48.251000, 601.524, 476.499, 1262.384, 100.254, 79.416, 210.397
2018-01-08 14:54:49.261000, 354.427, 478.227, 741.127, 59.071, 79.704, 123.521
2018-01-08 14:54:50.389000, 354.04, 476.999, 742.224, 59.007, 79.5, 123.704

...
<time>, <kW>, <V>, <I>, <kW-avg>, <V-avg>, <I-avg>
* Anomaly - time gap detected
<time>, <kW>, <V>, <I>, , ,
  ```

  Anomalies to detect:
    * Time gaps greated than 1.5 seconds between inputs
    * kW values < 0.0
    * V values outside range of 480 V +/- 5.0 V
    * I values < 0.0
'''

import dateutil.parser
import datetime
import math


class Telemetry:
    def __init__(self, inputFileName):
        self.inputFile = inputFileName
        self.logRecords = []

    # Read data file and keep each log record as a list
    def readTelemetry(self):
        with open(self.inputFile) as f:
            for line in f:
                fields = line.split(',')
                self.logRecords.append([ datetime.datetime.strptime(fields[0], '%Y-%m-%d %H:%M:%S.%f'), float(fields[1]), float(fields[2]), float(fields[3])])
        f.close()
    
    # Utility function to check if data are valid
    def isLogRecordValid(self, kw, v, i):
        return (kw>=0) and (v>=480-5) and (v<=480+5) and (i>=0)

    # Utility function to check if timestamp is not advanced more than 1.5 seconds
    def checkTimestampJump(self, i):
        if i == 0:
            return True
        else:
            tsCurr = self.logRecords[i][0]
            tsPrev = self.logRecords[i-1][0]
            tsElapsed = (tsCurr - tsPrev).total_seconds()

            return tsElapsed < 1.5

    # Utility function to compute average
    def computeAvg(self, colIndex, rowIndexBegin, rowIndexEnd):
        total = 0

        # +1 is needed to compute data at rowIndexEnd as well
        for i in range (rowIndexBegin, rowIndexEnd+1):
            total = self.logRecords[i][colIndex]
        return total/(rowIndexEnd + 1 - rowIndexBegin)


    def run(self):
        beginIndex = 0

        tsBegin = self.logRecords[beginIndex][0]
        isDataValid = False

        for currentIndex in range (0, len(self.logRecords)):
            tsEnd = self.logRecords[currentIndex][0]
            print(*self.logRecords[currentIndex], sep=', ', end='')

            kwVal = self.logRecords[currentIndex][1]
            vVal = self.logRecords[currentIndex][2]
            iVal = self.logRecords[currentIndex][3]

            if self.isLogRecordValid(kwVal, vVal, iVal) and self.checkTimestampJump(currentIndex):
                # Data and timestamp are valid
                if isDataValid == False:
                    # if prev record was invalid, reset sliding window begin index and its timestamp
                    beginIndex = currentIndex # 
                    tsBegin = self.logRecords[beginIndex][0]
                isDataValid = True
            else:
                # Data and/or timestamp are invalid, set invalid flag
                isDataValid = False

            tsElapsed = (tsEnd - tsBegin).total_seconds()

            if tsElapsed >= 5 and isDataValid:
                # Good record, compute average 
                kWAvg = self.computeAvg(1, beginIndex, currentIndex)
                vAvg = self.computeAvg(2, beginIndex, currentIndex)
                iAvg = self.computeAvg(3, beginIndex, currentIndex)

                print(', ',round(kWAvg,3),', ',round(vAvg,3),', ',round(iAvg,3),sep='')

                # advance sliding window index
                beginIndex += 1
                tsBegin = self.logRecords[beginIndex][0]
            else:
                # Invalid record, no average values as ouput
                print(', , ,')

if __name__ == '__main__':
    t = Telemetry('telemetry.dat')
    t.readTelemetry()
    t.run()
