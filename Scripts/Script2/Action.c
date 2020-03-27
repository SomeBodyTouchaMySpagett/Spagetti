Action()
{
	lr_start_transaction("transaction_Login-Buy-Itinerary-Exit");
	
	web_reg_find("Text=Welcome to the Web Tours site.","Search=Body",LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

/*Correlation comment - Do not change!  Original value='128385.900526529zzADitQpHfiDDDDDDQzcDpAQiff' Name ='userSession' Type ='RecordReplay'*/
	web_reg_save_param("userSession",
	"LB/IC=name=\"userSession\" value=\"",
	"RB=\"/>",
	LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	/* Login */

	lr_start_transaction("1_transaction_Login");

	web_reg_find("Text=Welcome",LAST);
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t16.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=75", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("1_transaction_Login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("2_transaction_Flights");
	
	web_reg_find("Text=Find Flight","Search=Body",LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("2_transaction_Flights",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("3_transaction_Flight_Info");

	web_reg_find("Text=Find Flight","Search=Body",LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={City_1}", ENDITEM, 
		"Name=departDate", "Value={depart_date}", ENDITEM, 
		"Name=arrive", "Value={City_2}", ENDITEM, 
		"Name=returnDate", "Value={arrive_date}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={Sit}", ENDITEM, 
		"Name=seatType", "Value={Class}", ENDITEM, 
		"Name=findFlights.x", "Value=53", ENDITEM, 
		"Name=findFlights.y", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("3_transaction_Flight_Info",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("4_transaction_Select_Time");
	
	web_reg_find("Text=Payment Details","Search=Body",LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=892;1903;03/24/2020", ENDITEM, 
		"Name=returnFlight", "Value=982;1903;03/26/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={Class}", ENDITEM, 
		"Name=seatPref", "Value={Sit}", ENDITEM, 
		"Name=reserveFlights.x", "Value=38", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("4_transaction_Select_Time",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("5_transaction_Payment");
	
	web_reg_find("Text=Invoice","Search=Body",LAST);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={Login}", ENDITEM, 
		"Name=lastName", "Value={Password}", ENDITEM, 
		"Name=address1", "Value={Street}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=pass1", "Value={Name} + {LastName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value=11/21", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={Class}", ENDITEM, 
		"Name=seatPref", "Value={Sit}", ENDITEM, 
		"Name=outboundFlight", "Value=892;1903;03/24/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=982;1903;03/26/2020", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=77", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("5_transaction_Payment",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("6_transaction_Itinerary");
	
	web_reg_find("Text=Itinerary","Search=Body",LAST);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("6_transaction_Itinerary",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("7_transaction_Logoff");
	
	web_reg_find("Text=Welcome to the Web Tours site.","Search=Body",LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST); 

	lr_end_transaction("7_transaction_Logoff",LR_AUTO);
	
	lr_end_transaction("transaction_Login-Buy-Itinerary-Exit",LR_AUTO);

	return 0;
}