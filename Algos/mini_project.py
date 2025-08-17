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




def disp_stud_det():
    try:
        query = "SELECT rollno, stud_name, overall_attendance FROM student_details_section_a ;"
        curobj.execute(query)
        data = curobj.fetchall()
        for record in data:
            print(f"STUDENT's ROLLNO : {record[0]}, STUDENT's NAME : {record[1]}, OVERALL ATTENDANCE : {record[2]}")
    except Exception as e:
        print(f"Error: {e}")




def mark_math(roll_no):
    try:
        current_date = datetime.now().strftime("%Y-%m-%d")
        user_input_name = input("Enter the date : ")
        sanitized_column_name = user_input_name.replace(" ", "_")
        query = f"ALTER TABLE maths_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P';"
        curobj.execute(query)
        con.commit()

        roll_num = tuple(roll_no)

        query = f"UPDATE maths_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num}"
        curobj.execute(query)

        con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")


def disp_maths():
    query = "SELECT * FROM maths_attendance"
    curobj.execute(query)

    # Fetch all the rows returned by the query
    rows = curobj.fetchall()

    # Display the contents of the table
    for row in rows:
        print(row)

    # Close the cursor and connection
    curobj.close()
    con.close()




def mark_logic(roll_no):
    try:
        current_date = datetime.now().strftime("%Y-%m-%d")
        user_input_name = input("Enter the date : ")
        sanitized_column_name = user_input_name.replace(" ", "_")
        query = f"ALTER TABLE logic_design_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P';"
        curobj.execute(query)
        con.commit()

        roll_num = tuple(roll_no)

        query = f"UPDATE logic_design_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num}"
        curobj.execute(query)

        con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")





def mark_ds(roll_no):
    try:
        current_date = datetime.now().strftime("%Y-%m-%d")
        user_input_name = input("Enter the date : ")
        sanitized_column_name = user_input_name.replace(" ", "_")
        query = f"ALTER TABLE data_structure_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P';"
        curobj.execute(query)
        con.commit()

        roll_num = tuple(roll_no)

        query = f"UPDATE data_structure_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num}"
        curobj.execute(query)

        con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")





def mark_oops(roll_no):
    try:
        current_date = datetime.now().strftime("%Y-%m-%d")
        user_input_name = input("Enter the date : ")
        sanitized_column_name = user_input_name.replace(" ", "_")
        query = f"ALTER TABLE oops_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P';"
        curobj.execute(query)
        con.commit()

        roll_num = tuple(roll_no)

        query = f"UPDATE oops_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num}"
        curobj.execute(query)

        con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")



while True:
    print("1. SHOW STUDENT DETAILS ")
    print("2. MARK MATHS ATTENDANCE ")
    print("3. SHOW MATHS ATTENDANCE ")
    print("4. MARK LOGIC_DESIGN ATTENDANCE ")
    print("5. SHOW LOGIC_DESIGN ATTENDANCE ")
    print("6. MARK DATA_STRUCTURE ATTENDANCE ")
    print("7. SHOW DATA_STRUCTURE ATTENDANCE ")
    print("8. MARK OOPS ATTENDANCE ")
    print("9. SHOW OOPS ATTENDANCE ")
    print("10.SHOW OVERALL ATTENDANCE ")
    print("11.EXIT")
    print()
    ch=int(input("ENTER YOUR CHOICE : "))
    if ch==1:
        disp_stud_det()
        print()

    elif ch==2:
        rollno = []
        num=int(input("Enter the number of absentees : "))
        for i in range(num):
            val=int(input("Enter the roll number"))
            rollno.append(val)
        mark_math(rollno)


    elif ch==3:
        disp_maths()
        print()

    elif ch==4:
        rollno = []
        num=int(input("Enter the number of absentees : "))
        for i in range(num):
            val=int(input("Enter the roll number"))
            rollno.append(val)
        mark_logic(rollno)

    # elif ch==5:

    elif ch==6:
        rollno = []
        num=int(input("Enter the number of absentees : "))
        for i in range(num):
            val=int(input("Enter the roll number"))
            rollno.append(val)
        mark_ds(rollno)

    # elif ch==7:

    elif ch==8:
        rollno = []
        num=int(input("Enter the number of absentees : "))
        for i in range(num):
            val=int(input("Enter the roll number"))
            rollno.append(val)
        mark_oops(rollno)

    # elif ch==9:

    # elif ch==10:

    elif ch==11:
        print("PROGRAM TERMINATED SUCCESSFULLY ")
        print()
        break

    else:
        print("INVALID CHOICE ")
        print()