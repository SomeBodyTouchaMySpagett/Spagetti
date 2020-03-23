Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_custom_request("token", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE", 
		LAST);

	web_add_cookie("ANID=AHWqTUkCr231W1LCtB8OrxtZ5hxZJj_TK_Feys7ePG7Z0I88OOMpgRrWTwCeFYoz; DOMAIN=accounts.google.com");

	web_add_cookie("LSOLH=Ywg1fNeYWqQe4Ij4dGh72GffYe_R4hY:26211932:6055; DOMAIN=accounts.google.com");

	web_add_cookie("CONSENT=YES+RU.ru+201911; DOMAIN=accounts.google.com");

	web_add_cookie("HSID=Aw9jMyJqY1_fJdP4n; DOMAIN=accounts.google.com");

	web_add_cookie("SSID=A17LAQosEpzBE-NBP; DOMAIN=accounts.google.com");

	web_add_cookie("APISID=vcGjFFB9PP-aTEaA/Ar4Mz4WNryKRF2F8P; DOMAIN=accounts.google.com");

	web_add_cookie("SAPISID=UcyaO9ZOKzrZvLh5/Ag0uSFkdxwk_ma_Qh; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-HSID=Aw9jMyJqY1_fJdP4n; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-SSID=A17LAQosEpzBE-NBP; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-APISID=vcGjFFB9PP-aTEaA/Ar4Mz4WNryKRF2F8P; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-3PAPISID=UcyaO9ZOKzrZvLh5/Ag0uSFkdxwk_ma_Qh; DOMAIN=accounts.google.com");

	web_add_cookie("ACCOUNT_CHOOSER=AFx_qI67PnmZA1QQiG3FA0JVn9dKCyyN_r3oC7iBhgk4oK5MUe6x697rRyaBHYdU2Nt2Yl7cZhAymV9FkyNSZBB-wzgd5Lc_74W6B5wWsWsoy50oR1w7vVxnXsNx9kvOxg4HnP-89_Stw7LwficZZ6PVt8WqI0v01QITKFBcFaS0LnhVR7doQG0iRqpwRxmHV1JH6YQfNe7Fe5y9vkTdjItqtbXKkhu6kRvQ9G5ANBXrL6hVg0_GXPwH17lEHfqnWunzd2fw7RD3khTxqb51Mj2CYoshCM2CWOD72FJn16M-OUC6lHeYX0gbLnSfUsPR-kY0a9rqV0pi; DOMAIN=accounts.google.com");

	web_add_cookie("LSID=lso|o.mail.google.com|s.RU|s.blogger|s.youtube:uAcbCjo2Xrr3ul9gwS64RHA442vhoMCONB3a2I1ToClMoY3OediYwSx1ITtA67bOHoL-qA.; DOMAIN=accounts.google.com");

	web_add_cookie("__Host-3PLSID=lso|o.mail.google.com|s.RU|s.blogger|s.youtube:uAcbCjo2Xrr3ul9gwS64RHA442vhoMCONB3a2I1ToClMoY3OAFk2bEevUzvZZWBDj-PbeQ.; DOMAIN=accounts.google.com");

	web_add_cookie("GAPS=1:xttJ9fycOvQUG0G3w1wakshA-fbzOfPR0cKie5XrsGCCzJ4pPjfsjt29KHEiEUntRvypEflUs2qrSt-AB0eGX0A2gxLUcg:BLvHWwthoz6mbf_6; DOMAIN=accounts.google.com");

	web_add_cookie("SEARCH_SAMESITE=CgQImI8B; DOMAIN=accounts.google.com");

	web_add_cookie("SID=uwcbClo0s42nLydR9zJMnT-yo2RjEa6lQhCdwOz3BOHtNrlV8B0PAS6-2a6_qBVmi7NsIw.; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-3PSID=uwcbClo0s42nLydR9zJMnT-yo2RjEa6lQhCdwOz3BOHtNrlV4K11IzNvGcaO6c9-q94WXA.; DOMAIN=accounts.google.com");

	web_add_cookie("NID=200=Er0axQZYyEp23zKEFis9tMVh0OYJkTwm1RsDLs-I2xktDEBWsfQMkoAKelu7P9RHTafMGOzivh8OPqz2rjL0N3JEKdznWhdb4B-WNpkL46XknW2WUXLn4JEl-K3ALr_HEBYMin4h_J_SKb7DFTThRU1qDtcf6QuZ4aVkgOp_NSRq-Xzn7o_2Kj00FLRfU3NIldsZJxW87RUdiBQyy86beGMyKN2uT1QdEt_UX4njgnRsvQqM1Y8CkyHcsfk6fP6RkIxrd1_Abzx2Wgk; DOMAIN=accounts.google.com");

	web_add_cookie("1P_JAR=2020-3-23-0; DOMAIN=accounts.google.com");

	web_add_cookie("SIDCC=AJi4QfGhFKdW_WlCKuYw0C2NMHB3YNvnfdeMTmXxzwKDVxTNuT0MDJMZgLH9htlNrY1L0-UItSmr; DOMAIN=accounts.google.com");

	web_add_header("Origin", 
		"https://www.google.com");

	web_custom_request("ListAccounts", 
		"URL=https://accounts.google.com/ListAccounts?gpsia=1&source=ChromiumBrowser&json=standard", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"Body= ", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("token_2", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/chromesync", 
		LAST);

	web_add_header("A-IM", 
		"x-bm,gzip");

	web_url("seed", 
		"URL=https://clientservices.googleapis.com/chrome-variations/seed?osname=win&channel=stable&milestone=80", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bins.json", 
		"URL=https://www.gstatic.com/autofill/hourly/bins.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("merchants.json", 
		"URL=https://www.gstatic.com/autofill/weekly/merchants.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("issuetoken", 
		"URL=https://oauthaccountmanager.googleapis.com/v1/issuetoken", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"Body=force=false&response_type=token&scope=https://www.googleapis.com/auth/calendar.readonly+https://www.googleapis.com/auth/cast-edu-messaging+https://www.googleapis.com/auth/clouddevices+https://www.googleapis.com/auth/hangouts+https://www.googleapis.com/auth/hangouts.readonly+https://www.googleapis.com/auth/meetings+https://www.googleapis.com/auth/plus.peopleapi.readwrite+https://www.googleapis.com/auth/userinfo.email&client_id="
		"919648714761-55j965o0km033psv3i9qls5mo3qtdrb0.apps.googleusercontent.com&origin=pkedcjkdefgpdelpbcmbmeomcjbeemfm&device_id=57e7fe73-4fef-478a-b9ec-87bcf202f2dc&device_type=chrome&lib_ver=extension", 
		LAST);

	/* Login */

	web_concurrent_start(NULL);

	web_url("client_model_v5_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t9.inf", 
		LAST);

	web_url("client_model_v5_ext_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_ext_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t10.inf", 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_url("query", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZTfkiOcFFuDAjLeeNQA4kIy3OQUx6JBQ=", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t11.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_custom_request("token_3", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/firebase.messaging", 
		LAST);

	web_add_header("X-Goog-Update-AppId", 
		"mgndgikekgjfcpckkfioiadnlibdjbkf");

	web_add_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_header("X-Goog-Update-Updater", 
		"chromecrx-80.0.3987.149");

	web_url("crx", 
		"URL=https://clients2.google.com/service/update2/crx?os=win&arch=x64&os_arch=x86_64&nacl_arch=x86-64&prod=chromecrx&prodchannel=&prodversion=80.0.3987.149&lang=ru&acceptformat=crx3&x=id%3Dmgndgikekgjfcpckkfioiadnlibdjbkf%26v%3D0.0.0.0%26installedby%3Dinternal%26uc%26ping%3Dr%253D68%2526e%253D1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("ANID=AHWqTUmmX5MPIB9sl3td6ewVP9yhBhIUvbDX1um6SSLXUL8iMrkC1xA5BoRvGcB7; DOMAIN=www.google.ru");

	web_add_cookie("CONSENT=YES+RU.ru+201911; DOMAIN=www.google.ru");

	web_add_cookie("SID=swcbCiNzyAisixh5Li9ZfpYLc1GtvzNfAg7_88d9ZIzd6QtlJuXJWQ8Iqujnt-MIEk8XDg.; DOMAIN=www.google.ru");

	web_add_cookie("__Secure-3PSID=swcbCiNzyAisixh5Li9ZfpYLc1GtvzNfAg7_88d9ZIzd6QtlbTC1_8WznwZYtVXPQVdVxQ.; DOMAIN=www.google.ru");

	web_add_cookie("HSID=AZXtGLgYm0nNdWThY; DOMAIN=www.google.ru");

	web_add_cookie("SSID=AlZOUgYi-HBipAXAB; DOMAIN=www.google.ru");

	web_add_cookie("APISID=vcGjFFB9PP-aTEaA/Ar4Mz4WNryKRF2F8P; DOMAIN=www.google.ru");

	web_add_cookie("SAPISID=UcyaO9ZOKzrZvLh5/Ag0uSFkdxwk_ma_Qh; DOMAIN=www.google.ru");

	web_add_cookie("__Secure-HSID=AZXtGLgYm0nNdWThY; DOMAIN=www.google.ru");

	web_add_cookie("__Secure-SSID=AlZOUgYi-HBipAXAB; DOMAIN=www.google.ru");

	web_add_cookie("__Secure-APISID=vcGjFFB9PP-aTEaA/Ar4Mz4WNryKRF2F8P; DOMAIN=www.google.ru");

	web_add_cookie("__Secure-3PAPISID=UcyaO9ZOKzrZvLh5/Ag0uSFkdxwk_ma_Qh; DOMAIN=www.google.ru");

	web_add_cookie("NID=196=RUHHLiRj8nRSNM8hVPmt9p9Fqm8kCaNEDy1HKQF8W0KWUm5fyNs4_oZMJ5cBr6ZNBvp2u_97LBk79lRdqE-R_VZkIpV4Pv7L2HVCe71xmeG8urn4UEQ9IDkBAOl9H11v4dUa_u2Xqq9X8m8OWhSSgxuwgilLyvEPPQDl0FvHBdtS2_dSUZHESZcXbSw0tZFEh01X4-QSn6sMIRVYL7TFMDOe; DOMAIN=www.google.ru");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("collect", 
		"URL=https://www.google-analytics.com/r/collect?v=1&_v=j81&a=1651158355&t=pageview&_s=1&dl=chrome-extension%3A%2F%2Fhflefjhkfeiaignkclmphmokmmbhbhik%2F_generated_background_page.html&dp=%2Fbackground%2F1.5.21%2FOn&ul=ru-ru&de=UTF-8&sd=24-bit&sr=1280x720&vp=&je=0&_u=QACAAEAB~&jid=329437527&gjid=759265209&cid=557659239.1548187056&tid=UA-93290101-2&_gid=513539985.1584803240&_r=1&cd1=1.5.21&cd2=On&z=519351278", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t14.inf", 
		LAST);

	web_custom_request("CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmca", 
		"URL=https://clients4.google.com/invalidation/android/request/CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmcaACoCCAAyH2NvbS5nb29nbGUuY2hyb21lLmludmFsaWRhdGlvbnM", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/x-protobuffer", 
		"BodyBinary=\nY\n\\x06\n\\x04\\x08\\x03\\x10\\x02\\x12%\n\\x06\n\\x04\\x08\\x03\\x10\\x01\\x12\\x12\t\\xFA\\xE6E\\xE2\\xED\\xD2\\x9D\\xBD\\x11\\x8EO\"z3M=Z\\x1A\\x07\\x08\\x972\\x10\\x03\\x18\\x01\\x1A\\x18\\x08\\x00\\x12\\x14\\xDA9\\xA3\\xEE^kK\r2U\\xBF\\xEF\\x95`\\x18\\x90\\xAF\\xD8\\x07\t \\xBC\\xA2\\xA9\\xAC\\x83\\x81\\x03(\\x002\\x0118\\x9F\\x082\\x94\\x01\n\\x8F\\x01\n\\x07\\x08\\x03\\x10\\xAC\\xA1\\xCD\t\\x12rMozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
		"Chrome/80.0.3987.149 Safari/537.36\\x1A\\x03C++\"\\x0Bchrome-sync \\x01", 
		LAST);

	lr_start_transaction("1_transaction_Login");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_revert_auto_header("Sec-Fetch-Site");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(7);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128385.900526529zzADitQpHfiDDDDDDQzcDpAQiff", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=2", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_Login",LR_AUTO);

	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_add_header("X-Goog-Update-AppId", 
		"ihnlcenocehgdaegdmhbidjhnhdchfmm,mimojjlkmoijpicakmndhoigimigcmbb,oimompecagnajdejgnnjijobebaeigek,gcmjkmgdlgnkkcocmoeiminaijmmjnii,hnimpnehoodheedghdeeijklkeaacbdc,llkgjffcdpffmhiakmfcdcblohccpfmo,hfnkpimlhhgieaddgfemjhofmfblmnib,khaoiebndkojlmppeemjhbpbandiljpe,giekcmmlnklenlaomppkphknjmnnpneh,aemomkdncapdnfajjbbcbdebjljbpmpj,gkmgaooipdjhmangpemjhigmamcehddo,ehgidpndbllacpjalkiimkbadgjfnnmc,bklopemakmnopmghhmccadeonafabnal,jflookgnkcckhobaglndicnbbgbonegd");

	web_add_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_header("X-Goog-Update-Updater", 
		"chrome-80.0.3987.149");

	lr_think_time(15);

	web_custom_request("json", 
		"URL=http://update.googleapis.com/service/update2/json?cup2key=9:4225032246&cup2hreq=5d90cce17115cd1c1b576e26570d69c2d67877b12840db12cc8877e7efc8c380", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chrome\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ihnlcenocehgdaegdmhbidjhnhdchfmm\",\"brand\":\"GGLS\",\"cohortname\":\"Auto\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{903ad9d1-8520-49b6-a37a-14acb40f7f32}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"mimojjlkmoijpicakmndhoigimigcmbb\",\"brand\":\"GGLS\",\"cohort\":\"1:d0j:\",\"cohorthint\":\"Chrome [M50+]\",\"cohortname\":\"Chrome [M50+]\",\"enabled\""
		":true,\"packages\":{\"package\":[{\"fp\":\"1.836a5a90b448bede995cdbbb251804b24208eacc171d33b84334a8735c33a176\"}]},\"ping\":{\"ping_freshness\":\"{6f63c739-9551-4dc0-bafb-960a38c0959d}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"32.0.0.344\"},{\"appid\":\"oimompecagnajdejgnnjijobebaeigek\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{824cb69f-dc88-439c-82ca-0fc0ee5bc40b}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"4.10.1610.0\"},{\"appid\":\""
		"gcmjkmgdlgnkkcocmoeiminaijmmjnii\",\"brand\":\"GGLS\",\"cohort\":\"1:bm1:\",\"cohorthint\":\"M54ToM99\",\"cohortname\":\"M54ToM99\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.715c48ce73b7ee71924470b10e920a4e23cd6f9c860f367d00feaff0d03eb52f\"}]},\"ping\":{\"ping_freshness\":\"{2199db45-acad-428d-af3c-3489b55c00c9}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"9.11.0\"},{\"appid\":\"hnimpnehoodheedghdeeijklkeaacbdc\",\"brand\":\"GGLS\",\"enabled\":true,\"packages\":{\"package\":[{\""
		"fp\":\"1.1cd7dc2056afaa0f6a705c9a17d22bba6578b33f5dae9e2d6518a0bfcced2396\"}]},\"ping\":{\"ping_freshness\":\"{6eec5933-1ff2-4896-990a-24c527441e36}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"0.57.44.2492\"},{\"appid\":\"llkgjffcdpffmhiakmfcdcblohccpfmo\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{36772eb0-adcc-4d06-a8c6-0a7ba177a5dd}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"hfnkpimlhhgieaddgfemjhofmfblmnib\",\"brand\":\"GGLS\",\"cohort"
		"\":\"1:jcl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.4ee61ed387cd33fea76c21381378142df29210b74ccfe79e81e091c5af83fdab\"}]},\"ping\":{\"ping_freshness\":\"{fde10f59-aff0-4956-9f6b-242ce4b2b250}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"5766\"},{\"appid\":\"khaoiebndkojlmppeemjhbpbandiljpe\",\"brand\":\"GGLS\",\"cohort\":\"1:cux:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\""
		":\"1.5cb8df53fe2b86bf838ea2c9ffc3d5ef8460f679a779ac8aa924b5afffd052cb\"}]},\"ping\":{\"ping_freshness\":\"{055b6638-a3da-4ded-953c-b72542f4c77a}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"42\"},{\"appid\":\"giekcmmlnklenlaomppkphknjmnnpneh\",\"brand\":\"GGLS\",\"cohort\":\"1:j5l:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.3eb16d6c28b502ac4cfee8f4a148df05f4d93229fa36a71db8b08d06329ff18a\"}]},\"ping\":{\"ping_freshness\":\""
		"{51264405-692f-43fd-933b-6d6b10b78b75}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"7\"},{\"appid\":\"aemomkdncapdnfajjbbcbdebjljbpmpj\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{c0e3edd7-0d3c-45d7-95bb-e4fd0946c37c}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"1.0.5.0\"},{\"appid\":\"gkmgaooipdjhmangpemjhigmamcehddo\",\"brand\":\"GGLS\",\"cohort\":\"1:pw3:\",\"cohorthint\":\"Stable\",\"cohortname\":\"Stable\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\""
		"1.4d9ddf151092a9830f94069b96d5f165e9acd31e5372d342d3c1a3bcb8a28262\"}]},\"ping\":{\"ping_freshness\":\"{44fb32ba-d216-4a16-87ee-7161fa270d57}\",\"rd\":4829},\"tag\":\"eset_exp_b\",\"updatecheck\":{},\"version\":\"80.230.200\"},{\"appid\":\"ehgidpndbllacpjalkiimkbadgjfnnmc\",\"brand\":\"GGLS\",\"cohort\":\"1:ofl:\",\"cohorthint\":\"stable64\",\"cohortname\":\"stable64\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.a8a79d350c2a5e3bc36226633a8e0bed0dfab184e77f38fc8f0820ebacf8eafc\"}]},\""
		"ping\":{\"ping_freshness\":\"{82a32828-3c84-42ce-9056-17fafc0af5b9}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"2018.8.8.0\"},{\"appid\":\"bklopemakmnopmghhmccadeonafabnal\",\"brand\":\"GGLS\",\"cohort\":\"1:swl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.6dce22b9a11fa1e62b22559c4a157ce745e7fc63c6c6941a82cf11e8ecf65b0e\"}]},\"ping\":{\"ping_freshness\":\"{d32428f2-30c4-409d-a3bd-cd7e4452b062}\",\"rd\":4829},\"updatecheck\":{},\""
		"version\":\"3\"},{\"appid\":\"jflookgnkcckhobaglndicnbbgbonegd\",\"brand\":\"GGLS\",\"cohort\":\"1:s7x:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.7ce940e8f0d98ef6c59f4d04b198b3dee628c892ef24d59894d6613eecf02284\"}]},\"ping\":{\"ping_freshness\":\"{a6da6e07-b220-4ee8-bd53-fb9ede78782a}\",\"rd\":4829},\"updatecheck\":{},\"version\":\"479\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\""
		"ru\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{13243e7b-0d92-4d2d-950a-4d6d08a6e9f0}\",\"sessionid\":\"{878e2c33-8858-4688-bdcf-dfd4584fe0ee}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	lr_start_transaction("2_transaction_Flight");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("query_2", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZQUJTom3LFQojLVRiKa0kIy17ncSlJCMtHzs5hSQjLdqFmWEkIy2pjkq9JBQ=", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t19.inf", 
		LAST);

	lr_end_transaction("2_transaction_Flight",LR_AUTO);

	lr_start_transaction("3_transaction_Flight_Info");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	lr_think_time(46);

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
		"Name=depart", "Value=Sydney", ENDITEM, 
		"Name=departDate", "Value=03/24/2020", ENDITEM, 
		"Name=arrive", "Value=Zurich", ENDITEM, 
		"Name=returnDate", "Value=03/26/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=findFlights.x", "Value=53", ENDITEM, 
		"Name=findFlights.y", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("3_transaction_Flight_Info",LR_AUTO);

	lr_start_transaction("4_transaction_Select_Time");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"chrome-extension://bihmplhobchoageeokmgbdihknkjbknd");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	lr_think_time(27);

	web_custom_request("chrome_ext", 
		"URL=https://event.shelljacket.us/api/report/chrome_ext", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"Body={\"event\":\"pageview\",\"payload\":{\"category\":1584923720477,\"connection-country\":\"gb\",\"connection-status\":\"disconnected\",\"country\":\"ru\",\"hash\":\"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\",\"ts\":1584923720477,\"version\":3.13}}\n{\"event\":\"pageview\",\"payload\":{\"category\":1584923720479,\"connection-country\":\"gb\",\"connection-status\":\"disconnected\",\"country\":\"ru\",\"hash\":\"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\","
		"\"ts\":1584923720479,\"version\":3.13}}\n{\"event\":\"pageview\",\"payload\":{\"category\":1584923720706,\"connection-country\":\"gb\",\"connection-status\":\"disconnected\",\"country\":\"ru\",\"hash\":\"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\",\"ts\":1584923720706,\"version\":3.13}}\n{\"event\":\"pageview\",\"payload\":{\"category\":1584923720715,\"connection-country\":\"gb\",\"connection-status\":\"disconnected\",\"country\":\"ru\",\"hash\":\""
		"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\",\"ts\":1584923720716,\"version\":3.13}}\n{\"event\":\"pageview\",\"payload\":{\"category\":1584923720767,\"connection-country\":\"gb\",\"connection-status\":\"disconnected\",\"country\":\"ru\",\"hash\":\"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\",\"ts\":1584923720767,\"version\":3.13}}\n{\"event\":\"pageview\",\"payload\":{\"category\":1584923727881,\"connection-country\":\"gb\",\"connection-status\":\""
		"disconnected\",\"country\":\"ru\",\"hash\":\"tca2662e40fb5e9bd557ecd8991d2843d9\",\"id\":\"touch-vpn-chrome\",\"ts\":1584923727881,\"version\":3.13}}\n", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

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
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=reserveFlights.x", "Value=38", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_concurrent_start(NULL);

	web_url("query_3", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZOcpZyM7guAAjLWtomm4kIy1Pnif4JCMtY5MnhyQjLaJZuEkkIy34tP6gJCMtV2gsmSQjLW36ZskkFA==", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t23.inf", 
		LAST);

	web_add_header("X-Client-Data", 
		"CI+2yQEIpLbJAQjEtskBCKmdygEIpaDKAQjPr8oBCLywygEIhrXKAQiXtcoBCO21ygEIjrrKAQjmxsoB");

	web_add_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("netcheck.gif", 
		"URL=https://ssl.gstatic.com/docs/common/netcheck.gif?zx=jlcxppz016fy", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://docs.google.com/offline/extension/frame?ouid=", 
		"Snapshot=t24.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("4_transaction_Select_Time",LR_AUTO);

	lr_start_transaction("5_transaction_Payment");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(53);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=Huntress", ENDITEM, 
		"Name=address2", "Value=New-York", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=11/21", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=outboundFlight", "Value=892;1903;03/24/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=982;1903;03/26/2020", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=77", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("5_transaction_Payment",LR_AUTO);

	lr_start_transaction("6_transaction_Itinerary");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(33);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-HTTP-Method-Override", 
		"POST");

	web_url("threatListUpdates:fetch", 
		"URL=https://safebrowsing.googleapis.com/v4/threatListUpdates:fetch?$req="
		"Ch0KDGdvb2dsZWNocm9tZRINODAuMC4zOTg3LjE0ORopCAUQARobCg0IBRAGGAEiAzAwMTABEL2hCBoCGArcJHCvIgQgASACKAEaKQgBEAEaGwoNCAEQBhgBIgMwMDEwARCblQcaAhgKzG-t9iIEIAEgAigBGikIAxABGhsKDQgDEAYYASIDMDAxMAEQq5gHGgIYCqta7DEiBCABIAIoARopCAcQARobCg0IBxAGGAEiAzAwMTABEKSMBxoCGAry6-bHIgQgASACKAEaJwgBEAEaGQoNCAEQBhgBIgMwMDEwAxAUGgIYCv-xTLIiBCABIAIoAxooCAEQCBoaCg0IARAIGAEiAzAwMTAEEM4ZGgIYCtQW8j4iBCABIAIoBBonCAkQARoZCg0ICRAGGAEiAzAwMTAGEAMaAhgKlWHZyiIEIAEgAigGGigIDxABGhoKDQgPEAYYASIDMDAxMAEQhSYaAhgK7gTjdiIEIAEgAigBGicIChAIGh"
		"kKDQgKEAgYASIDMDAxMAEQBRoCGAqQdhXdIgQgASACKAEaJwgJEAEaGQoNCAkQBhgBIgMwMDEwARAZGgIYCpqx1XoiBCABIAIoARooCAgQARoaCg0ICBAGGAEiAzAwMTABEKYIGgIYCtWn3Q4iBCABIAIoARooCA0QARoaCg0IDRAGGAEiAzAwMTABEPpwGgIYCi1D6wsiBCABIAIoARopCA4QARobCg0IDhAGGAEiAzAwMTABENOnAxoCGAoA4BTHIgQgASACKAEaKAgQEAEaGgoNCBAQBhgBIgMwMDEwARD4ARoCGAqaQKh0IgQgASACKAEiAggB&$ct=application/x-protobuf&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-protobuf", 
		"Referer=", 
		"Snapshot=t27.inf", 
		LAST);

	lr_end_transaction("6_transaction_Itinerary",LR_AUTO);

	lr_start_transaction("7_transaction_Logoff");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(22);

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

	return 0;
}