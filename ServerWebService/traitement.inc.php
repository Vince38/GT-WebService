
<?php
// traitement.inc.php = Traitement frontal des données recues
// library.inc = Traitement des données avevc la BD Mysql
// Reccuperation des methodes :
include "library.inc";

// # traitement.inc.php : 
// 1. Traitement frontal des données GET
// 2. Traitement frontal des données POST
// 3. Traitement frontal des données PUT
// 4. Traitement URL vides - GET/POST/PUT

//===========================================================================================================================
//==> Analyse des données recues
//==> Traitement frontal des données GET
//===========================================================================================================================
if (!empty($_GET["function"])){
	$function=$_GET["function"];

	if($function=="Get_Documentation()"){
		Get_Documentation();
	}
	if($function=="Get_List_Users()"){
		Get_List_Users();
	}
	if($function=="Get_Role()"){
		if (!empty($_GET["login"])){
			$login=$_GET["login"];
			GetRole($login);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"EmptyParameter",'Description'=>"Saisir un login en parametre");
			SendJson($group,$messages);
		}
	}
	if($function=="Get_User()"){
		if (!empty($_GET["login"])&&!empty($_GET["pwd"])){
			$login=$_GET["login"];
			$password=$_GET["pwd"];
			Get_User($login,$password);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"EmptyParameter(s)",'Description'=>"Saisir un login et un password en parametre");
			SendJson($group,$messages);
		}
	}
}
//===========================================================================================================================
//==> Analyse des données recues
//==> Traitement frontal des données POST
//===========================================================================================================================
if (!empty($_POST["function"])){
	$function=$_POST["function"];
	if($function=="Set_User()"){
		if (!empty($_POST["login"])&&!empty($_POST["pwd"])&&!empty($_POST["role"])){
			$login=$_POST["login"];
			$password=$_POST["pwd"];
			$role=$_POST["role"];
			Set_User($login,$password,$role);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"EmptyParameter(s)",'Description'=>"Saisir un login, un password et un role en parametre");
			SendJson($group,$messages);
		}
	}
}

//===========================================================================================================================
//==> Analyse des données recues
//==> Traitement frontal des données PUT
//===========================================================================================================================
if (!empty($_PUT["function"])){
	$function=$_PUT["function"];
	if($function=="Update_Role()"){
		if (!empty($_PUT["login"])&&!empty($_PUT["pwd"])&&!empty($_PUT["role"])){
			$login=$_PUT["login"];
			$password=$_PUT["pwd"];
			$role=$_PUT["role"];
			Update_Role($login,$password,$role);
		}else{
			$group = "Errors";
			$messages[] = array('Error'=>"EmptyParameter(s)",'Description'=>"Saisir un login, un password et un nouveau role en parametre");
			SendJson($group,$messages);
		}
	}
}


//===========================================================================================================================
//==> Traitement frontal des données GET/POST/PUT pour renvoi vers la documention ou autres traitements
//===========================================================================================================================
if (((empty($_GET["type"]))&&(empty($_GET["login"]))&&(empty($_GET["pwd"]))&&(empty($_GET["function"]))&&(empty($_POST["function"]))&&(empty($_PUT["function"])))){
	//pas d'attributs, on affiche la documentation
	Get_Documentation();
}else{
	//attributs envoyés par le client
	if(!empty($_GET["function"])){
		$type = $_GET["function"];
		if(!empty($_GET["type"])){
			$type = $_GET["type"];
		}
		if(!empty($_GET["login"])){
			$log = $_GET["login"];
		}
		if(!empty($_GET["pwd"])){
			$pwd = $_GET["pwd"];
		}
	}
	if(!empty($_POST["function"])){
		$type = $_POST["function"];
		if(!empty($_POST["type"])){
			$type = $_POST["type"];
		}
		if(!empty($_POST["login"])){
			$log = $_POST["login"];
		}
		if(!empty($_POST["pwd"])){
			$pwd = $_POST["pwd"];
		}
	}
	//===========================================================================================================================
}

?>
