m = int(input("Enter students mark : "))

if(m<=100 and m>=90):
    grade = "Ex"

elif(m<90 and m>=80):
    grade = " A "

elif(m<80 and m>=70):
    grade = " B "


elif(m<70 and m>=60):
    grade =" C "
    
elif(m<60 and m>=50):
    grade = " D "
    
elif(m<50):
    grade = " F "

print("Your grade id :  ", grade)
