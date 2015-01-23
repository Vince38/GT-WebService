<h1> WEB SERVICES - Client </h1> 
<br>
<form method="GET" action="traitement.inc.php">
   <input type="submit" value="Empty req GET" />   
</form>
<form method="POST" action="traitement.inc.php">
   <input type="submit" value="Empty req POST" />   
</form>
<form method="PUT" action="traitement.inc.php">
   <input type="submit" value="Empty req PUT" />   
</form>
<hr>
<h2> GET - Lecture </h2>
<form method="GET" action="traitement.inc.php">
   	<p>
   		Functions : 
   		<select name="function">
   			<option value="Get_Documentation()">Get_Documentation()</option>
			<option value="Get_List_Users()">Get_List_Users()</option>
			<option value="Get_User()">Get_User()</option>
			<option value="Get_Role()">Get_Role()</option>
		</select> <br>
   		Result type : 
   		<select name="type">
		  <option value="json">json</option>
		  <option value="xml">xml</option>
		</select> <br>
   		Pseudo : <input type="text" name="login" /> <br>
   		Password : <input type="text" name="pwd" /> <br>
   	</p>

	<input type="submit" value="Envoyer" />	
</form>
<hr>
<h2> POST - Ecriture </h2>
<form method="post" action="traitement.inc.php">
   	<p>
   		Functions : 
   		<select name="function">
   			<option value="Set_User()">Set_User()</option>
		</select> <br>
   		Result type : 
   		<select name="type">
		  <option value="json">json</option>
		  <option value="xml">xml</option>
		</select> <br>
   		Pseudo : <input type="text" name="login" /> <br>
   		Password : <input type="text" name="pwd" /> <br>
   		Role : <input type="text" name="role" /> <br>
   	</p>

	<input type="submit" value="Envoyer" />	
</form>
<!-- <hr>
<h2> PUT - Modification </h2>
<form method="PUT" action="traitement.inc.php">
      <p>
         Functions : 
         <select name="function">
            <option value="Update_Role()">Update_Role()</option>
      </select> <br>
         Result type : 
         <select name="type">
        <option value="json">json</option>
        <option value="xml">xml</option>
      </select> <br>
         Pseudo : <input type="text" name="login" /> <br>
         Password : <input type="text" name="pwd" /> <br>
         New Role : <input type="text" name="role" /> <br>
      </p>

   <input type="submit" value="Envoyer" />   
</form> -->
<!-- <hr>
<h2> DELETE - Suppression </h2>
   <form method="DELETE" action="traitement.inc.php">
      <p>
         Functions : 
         <select name="function">
            <option value="Set_User()">Set_User()</option>
      </select> <br>
         Result type : 
         <select name="type">
        <option value="json">json</option>
        <option value="xml">xml</option>
      </select> <br>
         Pseudo : <input type="text" name="login" /> <br>
         Password : <input type="text" name="pwd" /> <br>
         Role : <input type="text" name="role" /> <br>
      </p>

   <input type="submit" value="Envoyer" />   
</form>
 -->
