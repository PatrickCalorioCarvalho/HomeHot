import pyodbc
import pandas as pd 
import matplotlib.pyplot as plt

conn = pyodbc.connect('Driver={SQL Server};'
                      'Server=SERVIDOR;'
                      'Database=BANCODEDADOS;'
                      'Trusted_Connection=yes;')

query ="SELECT Umidade,Temperatura,Data FROM Sensor where Nome = 'Sala' and Umidade != 0 and Temperatura != 0"
DFSensor = pd.read_sql(query, conn)
DFSensor.plot(title='Sala')
query ="SELECT Umidade,Temperatura,Data FROM Sensor where Nome = 'QuartoPatrick' and Umidade != 0 and Temperatura != 0"
DFSensor = pd.read_sql(query, conn)
DFSensor.plot(title='QuartoPatrick')