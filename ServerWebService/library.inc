<?php
//=====================================================================================================================
// Méthodes GET Lecture 
//=====================================================================================================================
function Get_Documentation(){
	$methods = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{
		// Run the query  WHERE First_name = '$specFirstName'
		$result= mysqli_query($mysqli,"SELECT * FROM Methods");
		// Output rows 
		while($row = mysqli_fetch_array($result)) {
		 	$methods[] = array('Name'=>$row["Name"],'Arguments'=>$row["Arguments"],'Description'=>$row["Description"]);
		}
		//=============================================================================================
		/* output in necessary format */
		if($format == 'json') {
			header('Content-type: application/json');
			echo json_encode(array('Methods'=>$methods));
		}
		else {
			$xml = new SimpleXMLElement('<xml/>');
			echo "<?xml version='1.0' encoding='ISO-8859-1' ?>";
			foreach($methods as $index => $Method) {
				if(is_array($Method)) {
					$track = $xml->addChild('method');
					foreach($Method as $key => $value) {
		    			$track->addChild('Method', $value);
		    		}
		    	}
		    }

			Header('Content-type: text/xml');
			print($xml->asXML());
		}
	}

/*	echo "<br>";
	echo "<hr>";
	echo "Documentation :";
	echo "<br>";
	echo "<hr>";
	echo "<br><b># Attributs : </b><br>";
	echo "<b>> Login :</b> varchar 250<br>";
	echo "<b>> Password :</b> varchar 250<br>";
	echo "<b>> Type :</b> varchar 250<br>";
	echo "<br><b># Methodes : </b><br>";
	echo "> <b>get_List_Users()</b> ; Methode : [GET] ; <i>Liste tous les logins des utilisateurs</i>";
	echo "<hr>";*/
}

//=====================================================================================================================
function Get_List_Users(){
	$logins = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{
		// Run the query  WHERE First_name = '$specFirstName'
		$result= mysqli_query($mysqli,"SELECT * FROM user");
		// Output rows 
		while($row = mysqli_fetch_array($result)) {
		 	$logins[] = array('login'=>$row["Login"]);
		}
		//==========================²===================================================================
		/* output in necessary format */
		if($format == 'json') {
			header('Content-type: application/json');
			echo json_encode(array('logins'=>$logins));
		}
		else {
			$xml = new SimpleXMLElement('<xml/>');
			echo "<?xml version='1.0' encoding='ISO-8859-1' ?>";
			foreach($logins as $index => $login) {
				if(is_array($login)) {
					$track = $xml->addChild('User');
					foreach($login as $key => $value) {
		    			$track->addChild('Login', $value);
		    		}
		    	}
		    }
			Header('Content-type: text/xml');
			print($xml->asXML());
		}
	}
}
//=====================================================================================================================
function Get_User($login_user,$password_user){
	$logins = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{
		// Run the query  WHERE First_name = '$specFirstName'
		$result= mysqli_query($mysqli,"SELECT * FROM user WHERE Login='".$login_user."' AND Password='".$password_user."'");
		// Output rows 
		$i=0;
		while($row = mysqli_fetch_array($result)) {
			$i=1;
		 	$login[] = array('login'=>$row["Login"]);
		 	$passwd[] = array('password'=>$row["Password"]);
		 	$roles[] = array('type'=>$row["Type"]);
		}
		if($i==0){

			header('Content-type: application/json');
			echo json_encode(array('Au'=>"false",'Error'=>"Bad Credential(s)",'Description'=>"User is undefined"));
		}else{
			header('Content-type: application/json');
			echo json_encode(array('Au'=>"true",'Role'=>$roles,'Login'=>$login,'Password'=>$passwd));
		}
	}
}

//=====================================================================================================================
function GetRole($Login){
	$roles = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{
		// Run the query  WHERE First_name = '$specFirstName'
		$result= mysqli_query($mysqli,"SELECT * FROM user WHERE Login='".$Login."'");
		// Output rows 
		while($row = mysqli_fetch_array($result)) {
		 	$roles[] = array('role'=>$row["Type"]);
		}
		//==========================²===================================================================
		/* output in necessary format */
		if($format == 'json') {
			header('Content-type: application/json');
			echo json_encode(array('Roles'=>$roles));
		}
		else {
			$xml = new SimpleXMLElement('<xml/>');
			echo "<?xml version='1.0' encoding='ISO-8859-1' ?>";
			foreach($roles as $index => $login) {
				if(is_array($login)) {
					$track = $xml->addChild('UserRole');
					foreach($login as $key => $value) {
		    			$track->addChild('Role', $value);
		    		}
		    	}
		    }
			Header('Content-type: text/xml');
			print($xml->asXML());
		}
	}
}

//=====================================================================================================================
// Méthodes POST Ecriture 
//=====================================================================================================================

function SetRole($Login){

}
//=====================================================================================================================
function Set_User($login_user,$password_user,$role_user){
	$roles = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{

		$result= mysqli_query($mysqli,"INSERT INTO `user`(`Login`, `Password`, `Type`) VALUES ('".$login_user."','".$password_user."','".$role_user."')");

		if($format == 'json') {
			Get_User($login_user,$password_user);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"OutFormat",'Description'=>"You can only return json format for the moment.");
			SendJson($group,$messages);
		}
	}
}

//=====================================================================================================================
// Méthodes PUT Update 
//=====================================================================================================================
function Update_Role($login_user,$password_user,$role_user){
	$roles = array();
	//$format = strtolower($_GET['format']) == 'json' ? 'json' : 'xml'; //xml is the default
	$format = 'json';
	$mysqli = new mysqli("localhost", "Ladmin", "admin", "db-webservice");
	if ($mysqli->connect_errno) {
	    echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}else{

		$result= mysqli_query($mysqli,"UPDATE `user` SET Type='".$role_user."' WHERE Login='".$login_user."'");

		if($format == 'json') {
			Get_User($login_user,$password_user);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"OutFormat",'Description'=>"You can only return json format for the moment.");
			SendJson($group,$messages);
		}
	}
}
//=====================================================================================================================
// Autres méthodes pour traitement 
//=====================================================================================================================
function SendJson($group,$message){
	header('Content-type: application/json');
	echo json_encode(array(''.$group.''=>$message));
}

//=====================================================================================================================

?>

