package http;

import java.awt.List;
import java.awt.image.ReplicateScaleFilter;
import java.io.BufferedReader;
import java.io.Console;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.sql.Struct;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.simple.*;
import org.json.simple.parser.JSONParser;


 
public class HTTPExemple {
 
	private final String USER_AGENT = "Mozilla/5.0";
 
	public static void main(String[] args) throws Exception {
 
		HTTPExemple http = new HTTPExemple();
		
		String function = "";
		String login = "";
		String pwd = "";
		String type ="";
 
		//System.out.println("Testing 1 - Send Http GET request");
		//http.sendGet(function, login, pwd, type, "C:\\Users\\vince_000\\Documents\\TESTFILE.txt");
		
		System.out.println("\nTesting 2 - Connexion User");
		http.testConnexionUser();
 
	}
 
	// HTTP GET request
	private void sendGet(String nameFunction, String loginUser, String passwordUser, String typeOf, String NameFile) throws Exception {
 
		String function = "?function=" + nameFunction;
		String login = "&login=" + loginUser;
		String password = "&pwd=" + passwordUser;
		String type = "&type=" + typeOf;
		
		
		String url = "http://10.24.4.4/traitement.inc.php" + function + login + password + type;
 
		URL obj = new URL(url);
		HttpURLConnection con = (HttpURLConnection) obj.openConnection();
 
		// optional default is GET
		con.setRequestMethod("GET");
 
		//add request header
		con.setRequestProperty("User-Agent", USER_AGENT);
 
		int responseCode = con.getResponseCode();
		//System.out.println("\nSending 'GET' request to URL : " + url);
		//System.out.println("Response Code : " + responseCode);
 
		BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
		String inputLine;
		StringBuffer response = new StringBuffer();
		
		while ((inputLine = in.readLine()) != null) {
			response.append(inputLine);
		}
		in.close();
		
		//print result
		System.out.println(response.toString());
		createFile(response, NameFile);
	}
	
	private void testConnexionUser() throws IOException, JSONException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your login : ");
		String loginUser = sc.nextLine();
		System.out.println("Enter you password : ");
		String pwd = sc.nextLine();
		
		// Gestion des paramètres
		String function = "?function=Get_User()";
		String login = "&login=" + loginUser;
		String password = "&pwd=" + pwd;
		String type = "&type=";
		
		// URL de connexion
		String url = "http://10.24.4.4/traitement.inc.php" + function + login + password + type;
		
		URL obj = new URL(url);
		HttpURLConnection con = (HttpURLConnection) obj.openConnection();
		// optional default is GET
		con.setRequestMethod("GET");
		//add request header
		con.setRequestProperty("User-Agent", USER_AGENT);
		
		BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
		String inputLine;
		StringBuffer response = new StringBuffer();
		
		while ((inputLine = in.readLine()) != null) {
			response.append(inputLine);
		}
		in.close();
		
		JSONObject jsonObject = new JSONObject(response.toString());
		//JSONArray erreurs = jsonObject.getJSONArray("Errors");
		
		if(jsonObject.get("Au").toString().equals("true")) {
			JSONArray roles = jsonObject.getJSONArray("Role");
			for (int j = 0; j < roles.length(); j++) {
				JSONObject role = roles.getJSONObject(j);
				// On créé les attributs de chaque method :
				String typeRole = role.getString("type");
				System.out.println("Success connection, Role : " + typeRole);
			}
		}
		else {
			Object erreur = jsonObject.getString("Description");
			// On créé les attributs de chaque method :
			System.out.println("Connection error : " + erreur);
		}
	}
	
	@SuppressWarnings("rawtypes")
	private void createFile(StringBuffer json, String nameFile) throws JSONException, IOException {
		
		// Création ou ouverture du fichier
		File file = new File(nameFile);	
		// Le true a la fin permet d'écrire à la fin du fichier si il existe
		FileWriter fw = new FileWriter(file, true);
				
		// On créé l'objet JSON
		JSONObject jsonObject = new JSONObject(json.toString());
		System.out.println(jsonObject);
		// On récupère toutes les Méthodes
		JSONArray methods = jsonObject.getJSONArray("Methods");
		
		fw.write("Methodes :");
		fw.write("\r\n");
		
		for (int j = 1; j < methods.length(); j++) {
			JSONObject method = methods.getJSONObject(j);
			// On créé les attributs de chaque method :
			String name = method.getString("Name");
			fw.write("Name : " + name);
			fw.write("\r\n");
			String argument = method.getString("Arguments");
			fw.write("Arguments : " + argument);
			fw.write("\r\n");
			String description = method.getString("Description");
			fw.write("Description : " + description);
			fw.write("\r\n");
			//System.out.println(method);
			fw.write("\r\n");
			fw.write("\r\n");
		}
		
		
		/*JSONObject jsonObject = new JSONObject(json.toString());
		for (Iterator iterator = jsonObject.keys(); iterator.hasNext();) {
			Object cle = iterator.next();
			fw.write(cle.toString());
			fw.write("\r\n");
			JSONArray value = (JSONArray) jsonObject.get(String.valueOf(cle));

			
			
		}*/
		
		

		fw.close();
	}
 
	// HTTP POST request
	/*private void sendPost() throws Exception {
 
		String url = "http://localhost/traitement.inc.php";
		URL obj = new URL(url);
		HttpURLConnection con = (HttpURLConnection) obj.openConnection();
 
		//add reuqest header
		con.setRequestMethod("POST");
		con.setRequestProperty("User-Agent", USER_AGENT);
		con.setRequestProperty("Accept-Language", "en-US,en;q=0.5");
		
		String urlParameters = "function=Get_Role()";
		
		// Send post request
		con.setDoOutput(true);
		DataOutputStream wr = new DataOutputStream(con.getOutputStream());
		wr.writeBytes(urlParameters);
		wr.writeBytes("login=Fraisse");
		wr.flush();
		wr.close();
 
		int responseCode = con.getResponseCode();
		String responseMessage = con.getResponseMessage();
		System.out.println("\nSending 'POST' request to URL : " + url);
		System.out.println("Post parameters : " + urlParameters);
		System.out.println("Response Code : " + responseCode);
		System.out.println("Response Message : " + responseMessage);
 
		BufferedReader in = new BufferedReader(
		        new InputStreamReader(con.getInputStream()));
		String inputLine;
		StringBuffer response = new StringBuffer();
 
		while ((inputLine = in.readLine()) != null) {
			response.append(inputLine);
		}
		in.close();
 
		//print result
		System.out.println(response.toString());
 
	}*/
}