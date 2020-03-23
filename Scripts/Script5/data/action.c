Action()
{

	/* Login */

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("1_transaction_Login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128391.357958688zzAtVDAptHfDQzctpHicif", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=79", ENDITEM, 
		"Name=login.y", "Value=4", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_Login",LR_AUTO);

	lr_start_transaction("2_transaction_Flights");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(22);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_revert_auto_header("Sec-Fetch-Site");

	web_add_header("X-Goog-Update-AppId", 
		"ihnlcenocehgdaegdmhbidjhnhdchfmm,oimompecagnajdejgnnjijobebaeigek,mimojjlkmoijpicakmndhoigimigcmbb,gcmjkmgdlgnkkcocmoeiminaijmmjnii,hnimpnehoodheedghdeeijklkeaacbdc,llkgjffcdpffmhiakmfcdcblohccpfmo,hfnkpimlhhgieaddgfemjhofmfblmnib,khaoiebndkojlmppeemjhbpbandiljpe,giekcmmlnklenlaomppkphknjmnnpneh,aemomkdncapdnfajjbbcbdebjljbpmpj,gkmgaooipdjhmangpemjhigmamcehddo,ehgidpndbllacpjalkiimkbadgjfnnmc,bklopemakmnopmghhmccadeonafabnal,jflookgnkcckhobaglndicnbbgbonegd");

	web_add_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_header("X-Goog-Update-Updater", 
		"chrome-80.0.3987.149");

	web_custom_request("json", 
		"URL=http://update.googleapis.com/service/update2/json?cup2key=9:1098886763&cup2hreq=32edf58a864a57756f85286fe2a45da610b31d7897a487733e681a741255b65c", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chrome\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ihnlcenocehgdaegdmhbidjhnhdchfmm\",\"brand\":\"GGLS\",\"cohortname\":\"Auto\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{59280127-c08b-476d-bc7b-f21b0ecbbb17}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"oimompecagnajdejgnnjijobebaeigek\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{c43cf858-2fb7-4c15-aff6-e4a249a2c127}\",\"rd\""
		":4830},\"updatecheck\":{},\"version\":\"4.10.1610.0\"},{\"appid\":\"mimojjlkmoijpicakmndhoigimigcmbb\",\"brand\":\"GGLS\",\"cohort\":\"1:d0j:\",\"cohorthint\":\"Chrome [M50+]\",\"cohortname\":\"Chrome [M50+]\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.836a5a90b448bede995cdbbb251804b24208eacc171d33b84334a8735c33a176\"}]},\"ping\":{\"ping_freshness\":\"{9bcdac2a-44f2-410b-a97e-5c3cc4b24f9c}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"32.0.0.344\"},{\"appid\":\""
		"gcmjkmgdlgnkkcocmoeiminaijmmjnii\",\"brand\":\"GGLS\",\"cohort\":\"1:bm1:\",\"cohorthint\":\"M54ToM99\",\"cohortname\":\"M54ToM99\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.715c48ce73b7ee71924470b10e920a4e23cd6f9c860f367d00feaff0d03eb52f\"}]},\"ping\":{\"ping_freshness\":\"{02cab537-4a8a-43d4-a061-5a413d639360}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"9.11.0\"},{\"appid\":\"hnimpnehoodheedghdeeijklkeaacbdc\",\"brand\":\"GGLS\",\"enabled\":true,\"packages\":{\"package\":[{\""
		"fp\":\"1.1cd7dc2056afaa0f6a705c9a17d22bba6578b33f5dae9e2d6518a0bfcced2396\"}]},\"ping\":{\"ping_freshness\":\"{9a0d6314-b38b-483a-86b6-e1794dd20510}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.57.44.2492\"},{\"appid\":\"llkgjffcdpffmhiakmfcdcblohccpfmo\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{9210bb31-4b20-42f5-bfe8-073517447219}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"hfnkpimlhhgieaddgfemjhofmfblmnib\",\"brand\":\"GGLS\",\"cohort"
		"\":\"1:jcl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.46fe0954de4a08e46ea219b8f9ca6dd980333ae6d326d91e109c57954822ddf9\"}]},\"ping\":{\"ping_freshness\":\"{a9a62c0e-7887-4245-9c75-5c641bf200a7}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"5767\"},{\"appid\":\"khaoiebndkojlmppeemjhbpbandiljpe\",\"brand\":\"GGLS\",\"cohort\":\"1:cux:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\""
		":\"1.5cb8df53fe2b86bf838ea2c9ffc3d5ef8460f679a779ac8aa924b5afffd052cb\"}]},\"ping\":{\"ping_freshness\":\"{6d195bb0-4195-4613-99f9-7b469420cf8a}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"42\"},{\"appid\":\"giekcmmlnklenlaomppkphknjmnnpneh\",\"brand\":\"GGLS\",\"cohort\":\"1:j5l:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.3eb16d6c28b502ac4cfee8f4a148df05f4d93229fa36a71db8b08d06329ff18a\"}]},\"ping\":{\"ping_freshness\":\""
		"{33fda43b-73c7-44ef-a57b-7c788e8f1b31}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"7\"},{\"appid\":\"aemomkdncapdnfajjbbcbdebjljbpmpj\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{2dba3b9c-54b5-4b56-aa3f-8bc2d2355dba}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.0.5.0\"},{\"appid\":\"gkmgaooipdjhmangpemjhigmamcehddo\",\"brand\":\"GGLS\",\"cohort\":\"1:pw3:\",\"cohorthint\":\"Stable\",\"cohortname\":\"Stable\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\""
		"1.4d9ddf151092a9830f94069b96d5f165e9acd31e5372d342d3c1a3bcb8a28262\"}]},\"ping\":{\"ping_freshness\":\"{ef961884-6e8a-47fd-b196-8b2df273b7fb}\",\"rd\":4830},\"tag\":\"eset_exp_b\",\"updatecheck\":{},\"version\":\"80.230.200\"},{\"appid\":\"ehgidpndbllacpjalkiimkbadgjfnnmc\",\"brand\":\"GGLS\",\"cohort\":\"1:ofl:\",\"cohorthint\":\"stable64\",\"cohortname\":\"stable64\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.a8a79d350c2a5e3bc36226633a8e0bed0dfab184e77f38fc8f0820ebacf8eafc\"}]},\""
		"ping\":{\"ping_freshness\":\"{bc51ffb2-930f-4990-be3a-beb58d9fca1b}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"2018.8.8.0\"},{\"appid\":\"bklopemakmnopmghhmccadeonafabnal\",\"brand\":\"GGLS\",\"cohort\":\"1:swl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.6dce22b9a11fa1e62b22559c4a157ce745e7fc63c6c6941a82cf11e8ecf65b0e\"}]},\"ping\":{\"ping_freshness\":\"{d3f630fc-e5d4-4275-98ba-93718337bf4f}\",\"rd\":4830},\"updatecheck\":{},\""
		"version\":\"3\"},{\"appid\":\"jflookgnkcckhobaglndicnbbgbonegd\",\"brand\":\"GGLS\",\"cohort\":\"1:s7x:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.215c1abf84d5582a2db2fbefaa2770f51f5fed2ffa002cec4942a3f975d8af93\"}]},\"ping\":{\"ping_freshness\":\"{601d46dd-1c71-476b-bc6c-4ab4968b189f}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"488\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\""
		"ru\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{d914099d-20b5-4a12-983e-3bafba3098e9}\",\"sessionid\":\"{d97787d9-6762-4185-82be-fd980b49953d}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	lr_end_transaction("2_transaction_Flights",LR_AUTO);

	lr_start_transaction("3_transaction_Logoff");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(22);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction_Logoff",LR_AUTO);

	return 0;
}