<!DOCTYPE html>
<html>
<head>
  <title>Student Information Management System</title>
</head>
<body>
  <h1>Student Information Management System</h1>

  <h2>1. Add Student Details</h2>
  <form>
    <label for="firstName">First Name:</label>
    <input type="text" id="firstName" name="firstName"><br><br>

    <label for="lastName">Last Name:</label>
    <input type="text" id="lastName" name="lastName"><br><br>

    <label for="rollNumber">Roll Number:</label>
    <input type="text" id="rollNumber" name="rollNumber"><br><br>

    <label for="courses">Courses:</label>
    <input type="text" id="courses" name="courses"><br><br>

    <label for="age">Age:</label>
    <input type="text" id="age" name="age"><br><br>

    <label for="gender">Gender:</label>
    <input type="text" id="gender" name="gender"><br><br>

    <input type="submit" value="Add Student">
  </form>

  <h2>2. Display Students</h2>
  <!-- Code to display the list of students -->

  <h2>3. Find Student by Roll Number</h2>
  <form>
    <label for="searchRollNumber">Enter Roll Number:</label>
    <input type="text" id="searchRollNumber" name="searchRollNumber"><br><br>

    <input type="submit" value="Find Student">
  </form>

  <h2>4. Find Students by First Name</h2>
  <form>
    <label for="searchFirstName">Enter First Name:</label>
    <input type="text" id="searchFirstName" name="searchFirstName"><br><br>

    <input type="submit" value="Find Students">
  </form>

  <h2>5. Find Students Registered in a Course</h2>
  <form>
    <label for="searchCourse">Enter Course Name:</label>
    <input type="text" id="searchCourse" name="searchCourse"><br><br>

    <input type="submit" value="Find Students">
  </form>

  <h2>6. Count of Students</h2>
  <!-- Code to display the total number of students -->

  <h2>7. Delete a Student</h2>
  <form>
    <label for="deleteRollNumber">Enter Roll Number:</label>
    <input type="text" id="deleteRollNumber" name="deleteRollNumber"><br><br>

    <input type="submit" value="Delete Student">
  </form>

  <h2>8. Update Student</h2>
  <form>
    <label for="updateRollNumber">Enter Roll Number:</label>
    <input type="text" id="updateRollNumber" name="updateRollNumber"><br><br>

    <!-- Code to choose the fields to update -->

    <input type="submit" value="Update Student">
  </form>

</body>
</html>
