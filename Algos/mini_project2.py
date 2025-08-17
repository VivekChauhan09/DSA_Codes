import mysql.connector
from datetime import datetime
con=mysql.connector.connect(host="localhost",
                            user="root",
                            password="vivek",
                            database="attendance_management_system_for_3rd_sem")

curobj = con.cursor()

def disp_stud_det():
    try:
        query = "SELECT * FROM student_details_sec_a"
        curobj.execute(query)
        columns = [column[0] for column in curobj.description]
        rows = curobj.fetchall()
        print(" | ".join(f"{str(column).ljust(18)}" for column in columns))
        for row in rows:
            print(" | ".join(f"{str(value).ljust(18)}" for value in row))
    except Exception as e:
        print(f"Error: {e}")
    print()

        
def mark_maths(roll_no):
    try:
        user_input_name = input("Enter the date: ")
        sanitized_column_name = user_input_name.replace(" ", "_")

        query1 = f"ALTER TABLE maths_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P'"
        curobj.execute(query1)
        con.commit()

        if len(roll_no) ==1:
            query2 = f"UPDATE maths_attendance SET {sanitized_column_name} = 'A' WHERE rollno = {roll_no[0]}"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_maths_lec = total_maths_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_maths_lec = attended_maths_lec+1  where rollno != {roll_no[0]}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no) > 1:
            roll_num = tuple(roll_no)
            query2 = f"UPDATE maths_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num};"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_maths_lec = total_maths_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_maths_lec = attended_maths_lec+1  where rollno NOT IN {tuple(roll_num)}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no)==0:
            query2 = f"UPDATE maths_attendance SET {sanitized_column_name} = 'P'"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_maths_lec = total_maths_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_maths_lec = attended_maths_lec+1"
            curobj.execute(query4)
            con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")
    print()

def disp_maths():
    query = "SELECT * FROM maths_attendance"
    curobj.execute(query)
    columns = [column[0] for column in curobj.description]
    rows = curobj.fetchall()
    print(" | ".join(f"{str(column).ljust(9)}" for column in columns))
    for row in rows:
        print(" | ".join(f"{str(value).ljust(9)}" for value in row))
    print()


def mark_logic(roll_no):
    try:
        user_input_name = input("Enter the date: ")
        sanitized_column_name = user_input_name.replace(" ", "_")

        query1 = f"ALTER TABLE logic_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P'"
        curobj.execute(query1)
        con.commit()

        if len(roll_no) ==1:
            query2 = f"UPDATE logic_attendance SET {sanitized_column_name} = 'A' WHERE rollno = {roll_no[0]}"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_logic_lec = total_logic_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_logic_lec = attended_logic_lec+1  where rollno != {roll_no[0]}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no) > 1:
            roll_num = tuple(roll_no)
            query2 = f"UPDATE logic_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num};"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_logic_lec = total_logic_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_logic_lec = attended_logic_lec+1  where rollno NOT IN {tuple(roll_num)}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no)==0:
            query2 = f"UPDATE logic_attendance SET {sanitized_column_name} = 'P'"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_logic_lec = total_logic_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_logic_lec = attended_logic_lec+1"
            curobj.execute(query4)
            con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")
    print()

def disp_logic():
    query = "SELECT * FROM logic_attendance"
    curobj.execute(query)
    columns = [column[0] for column in curobj.description]
    rows = curobj.fetchall()
    print(" | ".join(f"{str(column).ljust(9)}" for column in columns))
    for row in rows:
        print(" | ".join(f"{str(value).ljust(9)}" for value in row))
    print()


def mark_ds(roll_no):
    try:
        user_input_name = input("Enter the date: ")
        sanitized_column_name = user_input_name.replace(" ", "_")

        query1 = f"ALTER TABLE ds_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P'"
        curobj.execute(query1)
        con.commit()

        if len(roll_no) ==1:
            query2 = f"UPDATE ds_attendance SET {sanitized_column_name} = 'A' WHERE rollno = {roll_no[0]}"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_ds_lec = total_ds_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_ds_lec = attended_ds_lec+1  where rollno != {roll_no[0]}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no) > 1:
            roll_num = tuple(roll_no)
            query2 = f"UPDATE ds_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num};"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_ds_lec = total_ds_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_ds_lec = attended_ds_lec+1  where rollno NOT IN {tuple(roll_num)}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no)==0:
            query2 = f"UPDATE ds_attendance SET {sanitized_column_name} = 'P'"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_ds_lec = total_ds_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_ds_lec = attended_ds_lec+1"
            curobj.execute(query4)
            con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")
    print()

def disp_ds():
    query = "SELECT * FROM ds_attendance"
    curobj.execute(query)
    columns = [column[0] for column in curobj.description]
    rows = curobj.fetchall()
    print(" | ".join(f"{str(column).ljust(9)}" for column in columns))
    for row in rows:
        print(" | ".join(f"{str(value).ljust(9)}" for value in row))
    print()


def mark_oops(roll_no):
    try:
        user_input_name = input("Enter the date: ")
        sanitized_column_name = user_input_name.replace(" ", "_")

        query1 = f"ALTER TABLE oops_attendance ADD COLUMN {sanitized_column_name} char(1) DEFAULT 'P'"
        curobj.execute(query1)
        con.commit()

        if len(roll_no) ==1:
            query2 = f"UPDATE oops_attendance SET {sanitized_column_name} = 'A' WHERE rollno = {roll_no[0]}"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_oops_lec = total_oops_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_oops_lec = attended_oops_lec+1  where rollno != {roll_no[0]}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no) > 1:
            roll_num = tuple(roll_no)
            query2 = f"UPDATE oops_attendance SET {sanitized_column_name} = 'A' WHERE rollno IN {roll_num};"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_oops_lec = total_oops_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_oops_lec = attended_oops_lec+1  where rollno NOT IN {tuple(roll_num)}"
            curobj.execute(query4)
            con.commit()

        elif len(roll_no)==0:
            query2 = f"UPDATE oops_attendance SET {sanitized_column_name} = 'P'"
            curobj.execute(query2)
            con.commit()
            query3= "UPDATE student_details_sec_a SET total_oops_lec = total_oops_lec+1"
            curobj.execute(query3)
            con.commit()
            query4= f"UPDATE student_details_sec_a SET attended_oops_lec = attended_oops_lec+1"
            curobj.execute(query4)
            con.commit()

        print("Attendance updated successfully")
    except Exception as e:
        print(f"Error: {e}")
    print()

def disp_oops():
    query = "SELECT * FROM oops_attendance"
    curobj.execute(query)
    columns = [column[0] for column in curobj.description]
    rows = curobj.fetchall()
    print(" | ".join(f"{str(column).ljust(9)}" for column in columns))
    for row in rows:
        print(" | ".join(f"{str(value).ljust(9)}" for value in row))
    print()


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
    print("10.EXIT")
    print()
    ch=int(input("ENTER YOUR CHOICE : "))
    print()
    if ch==1:
        disp_stud_det()
        print()
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==2:
        code=input("Enter the code to verify : ")
        if code=='TMA300':
            rollno = []
            num=int(input("Enter the number of absentees : "))
            for i in range(num):
                val=int(input("Enter the roll number : "))
                rollno.append(val)
            mark_maths(rollno)
        else:
            print("Invalid code")
            print("Access denied")  
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break


    elif ch==3:
        disp_maths()
        print()
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==4:
        code=input("Enter the code to verify : ")
        if code=='TLD300':
            rollno = []
            num=int(input("Enter the number of absentees : "))
            for i in range(num):
                val=int(input("Enter the roll number : "))
                rollno.append(val)
            mark_logic(rollno)
        else:
            print("Invalid code")
            print("Access denied")  
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==5:
        disp_logic()
        print()
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==6:
        code=input("Enter the code to verify : ")
        if code=='TDS300':
            rollno = []
            num=int(input("Enter the number of absentees : "))
            for i in range(num):
                val=int(input("Enter the roll number : "))
                rollno.append(val)
            mark_ds(rollno)
        else:
            print("Invalid code")
            print("Access denied")  
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==7:
        disp_ds()
        print()
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==8:
        code=input("Enter the code to verify : ")
        if code=='TOP300':
            rollno = []
            num=int(input("Enter the number of absentees : "))
            for i in range(num):
                val=int(input("Enter the roll number : "))
                rollno.append(val)
            mark_oops(rollno)
        else:
            print("Invalid code")
            print("Access denied")  
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==9:
        disp_oops()
        print()
        choice=input("Want to continue (Y/N) : ")
        print()
        if(choice == 'Y'):
            continue
        else:
            print("PROGRAM TERMINATED SUCCESSFULLY")
            print()
            break

    elif ch==10:
        print("PROGRAM TERMINATED SUCCESSFULLY ")
        print()
        break

    else:
        print("INVALID CHOICE ")
        print()