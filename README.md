Key Improvements for your code
While the logic works, here are a few technical tips to improve your repository:-

Fixed Salary Logic: Currently, salary=(minutes/60)*100 uses integer division. 
If an employee works 110 minutes, it calculates as $1 \times 100$ instead of $1.83 \times 100$. 
Consider using salary = (minutes / 60.0) * 100;.

Fix the File Bug: In main(), you have ofstream fout("employee.dat", ios::binary);. This line overwrites your database every time you start the program. You should remove that line or use ios::app.

Security: Your login() function is a bool but doesn't actually return true or false. Adding return true; after a successful login would allow you to restrict access to the other functions.
