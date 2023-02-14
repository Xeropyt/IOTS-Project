## index.html

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/try1.png?raw=true)

The function aboved is called when the login button is clicked
> login.addEventListener('click')
...
By default login button is shown, after login button is clicked, it is hidden from the user
> document.getElementById("login").hidden = false; //by default show button
...
The user's email will be updated for the requesting of otp later
...
When successfully logged in, set fail counter back to 0
> await set(ref(database, 'Fail/') { fail: 0, });
...
The last line catches the error when login is unsuccessful

The conuation of the snippet is shown below:

![Image not found!](https://github.com/Xeropyt/IOTS-Project/blob/main/Images/try2.png?raw=true)

The error code and message will be displayed on the webpage when login is unsuccessful

The fail counter will then increment by 1 until 5 is reached
> attempt ++;
...
Once the user fails to log in 5 times the form will then disable the button and firebase will
lock the user out until his/her account has been reset
