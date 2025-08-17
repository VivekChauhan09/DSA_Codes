import mysql.connector
from datetime import datetime
con=mysql.connector.connect(host="localhost",
                            user="root",
                            password="vivek",
                            database="attendance_management_system_for_3rd_sem")
if con.is_connected():
    print("CONNECTION SUCCESSFUL")
else:
    print("CONNECTION FAILED")
curobj = con.cursor()
try:
    query1 = "INSERT INTO LOGIC_DESIGN_ATTENDANCE(rollno,stud_name) VALUES(8,'Harsh  ')"
    curobj.execute(query1)
    # Insert into Table2
    query2 = "INSERT INTO DATA_STRUCTURE_ATTENDANCE(rollno,stud_name) VALUES(8,'Harsh  ')"
    curobj.execute(query2)
    query3 = "INSERT INTO OOPS_ATTENDANCE(rollno,stud_name) VALUES(8,'Harsh  ')"
    curobj.execute(query3)
    # Commit the changes to the database
    con.commit()
except Exception as e:
        print(f"Error: {e}")