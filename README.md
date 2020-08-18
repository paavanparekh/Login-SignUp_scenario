# Login-SignUp_scenario-
sign In or sign Up scenario for any software using CPP  and graphics.h


author: Me and [param parekh](https://github.com/paramparekh)  <br />
project : Basic cpp project with graphics.h :)    <br />
Problem statement : Create a Login/SignUp scenario with graphics.h in cpp  <br />

Topics covered in the project is:   <br />
               1)  Cpp basics       <br />
               2)  file handling    <br />
               3)  Graphics in cpp  <br />
               4)  Mouse Handling   <br />
First of all what is login and SignUp for any software/website :click [here](https://ell.stackexchange.com/questions/24384/what-is-the-difference-among-sign-up-sign-in-and-log-in#:~:text=Sign%20up%20means%20%22to%20register,no%20such%20noun%20as%20*signin.)

**working of SIGN UP Page** ::<br/>
Sign Up Page has 3 text feilds namely "Username" , "Password" , "Emailid"
If user want to join any site/software then he/she register himself/herself through signUp page
We have to put some constraints for these 3 feilds in our project,It may differ from any other constraints of login/signup scenario ,<br/>
<br/>
1)Constraints for Username ::<br/>
-length :at most 8      <br/>
-Invalid Character: space  <br/>
-ErrorMessage if not satisfied:"Invalid username.Reenter it"<br/>
-ErrorMessage if user exists in database:"username exists.Reenter it"<br/>
<br/><br/>
2)Constraints for Password ::<br/>
-length : at most 8 <br/>
-Valid if contains at least one Capital letter,number and special characters(" ! , @ , # ") <br/>
-ErrorMessage if not satisfied:"Invalid password.Reenter it"<br/>
<br/><br/>
3)Constraints for EmailId ::<br/>
-valid if contains only one '@' and at least one '.'<br/>
-ErrorMessage if not satisfied:"Invalid EmailId.ReEnter it"<br/>
-ErrorMessage if user exists in database:"Emailid exists.Reenter it"<br/>
<br/><br/>
When user clicks on the ***SignUp*** button,then Userdata(username,password,emailid) are stored in "userdata.txt" and user will enter in welcome page

**working of Login In(Sign In) Page** ::<br/>
Sign In page has 2 text feilds namely "username" and "password"
If user is already registered in site/software then he/she will always be entered in welcome Page through **Login**
constraints for username and Password is same as mention above in the working of SignUp page
If registered user forgot his password then he/she will update password by clicking on "Forgot Password?" feild.we will discuss working of "FORGOT PASSWORD" later in this file.
Login Page is main Page of this Project,all clients see this page first if client already registered then he/she will be welcomed by login page but if user not exist then he/she will be registered by clicking on "New User?Create Account" field.

**working of ForgotPassword page**::<br/>
ForgotPassword Page has 3 text feilds namely "username" , "New password" , "Confirm password"
If registred user does not remember his/her password then he/she can change their password by this page.After filling this text fields user have to click on "Chage" button.
"Change" button changes old password to new in database.
if not registered user entered in this page then it will show error because of User will not be found in record

**Userinterface with keyboard and mouse**
Important  functions that can interact with mouse and Keyboard are ::<br/>
**1)GetCursorPos()**<br/>
**2)GetAsyncKeyState()**<br/>
**3)getch()**<br/>
**4)text_read()** user defined func that can read string from the keyboard as well as print it on graphics page <br/>
**5)text_read_password()** user defined func that can read password from the keyboard as well as print " * " on graphics page <br/>
**IMPORTANT NOTE ::** <br/><br/>
**USER INPUT STARTS FOR ANY TEXT FEILD IF USER CLICKS ON PARTICULAR FEILD AND INPUT ENDS WITH CLICKING ON "ENTER" KEY**
<br/><br/><br/>
Happy coding <br/> 
***;) ;)***













