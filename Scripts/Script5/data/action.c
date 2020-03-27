Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

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
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("analytics.js", 
		"URL=https://www.google-analytics.com/analytics.js", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t42.inf", 
		LAST);

	web_add_header("A-IM", 
		"x-bm,gzip");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("seed", 
		"URL=https://clientservices.googleapis.com/chrome-variations/seed?osname=win&channel=stable&milestone=80", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	web_url("merchants.json", 
		"URL=https://www.gstatic.com/autofill/weekly/merchants.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bins.json", 
		"URL=https://www.gstatic.com/autofill/hourly/bins.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_custom_request("token", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t46.inf", 
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

	web_add_cookie("SID=vQcbClwjt_R2r4-gzX_is6cA6vIsMZKjqmAqc-RPrTkIhI817X45o1oOubYK0IVdY6LtIg.; DOMAIN=accounts.google.com");

	web_add_cookie("__Secure-3PSID=vQcbClwjt_R2r4-gzX_is6cA6vIsMZKjqmAqc-RPrTkIhI81hG70OlwJkrK552nFRrTyiw.; DOMAIN=accounts.google.com");

	web_add_cookie("NID=201=qu0rPeTgBsBx9_qzLR87gsHO4dEqQuRF5-MsKX-poW3s7vicw1lzLRuX9-5m2Y-o9FPXFXHa8C726knzOmwd9NkYoAwEg2AWl99GlwYiV3L0R8zx1zg27-CbsgCZ_J0UHhmhIDHXWl_YgewAFig1-ewng3p_LYIhk-hYU3NSsLAwFh5bAM-t5lPQegxFNmvXdrOt4wVLOAwaCCi2QMlwesq-eklVITL1xwTqY-aLqksisHxGbBUqWFFWLlesL1pd_hF3vIUNVwedyck; DOMAIN=accounts.google.com");

	web_add_cookie("1P_JAR=2020-03-27-18; DOMAIN=accounts.google.com");

	web_add_cookie("SIDCC=AJi4QfERunXWkEH6_7TamNFdfA42RPbtt83bQoVTSR8Txh4bO9Cxeeqs28IM2pCD5sndIw46VTBA; DOMAIN=accounts.google.com");

	web_add_header("Origin", 
		"https://www.google.com");

	web_custom_request("ListAccounts", 
		"URL=https://accounts.google.com/ListAccounts?gpsia=1&source=ChromiumBrowser&json=standard", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"Body= ", 
		LAST);

	web_custom_request("token_2", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/chromesync", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_concurrent_start(NULL);

	web_url("webtours.png", 
		"URL=http://localhost:1080/WebTours/images/webtours.png", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://localhost:1080/WebTours/header.html", 
		"Snapshot=t50.inf", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("hp_logo.png", 
		"URL=http://localhost:1080/WebTours/images/hp_logo.png", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://localhost:1080/WebTours/header.html", 
		"Snapshot=t51.inf", 
		LAST);

	web_url("client_model_v5_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t52.inf", 
		LAST);

	web_url("client_model_v5_ext_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_ext_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t53.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_custom_request("issuetoken", 
		"URL=https://oauthaccountmanager.googleapis.com/v1/issuetoken", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"Body=force=false&response_type=token&scope=https://www.googleapis.com/auth/calendar.readonly+https://www.googleapis.com/auth/cast-edu-messaging+https://www.googleapis.com/auth/clouddevices+https://www.googleapis.com/auth/hangouts+https://www.googleapis.com/auth/hangouts.readonly+https://www.googleapis.com/auth/meetings+https://www.googleapis.com/auth/plus.peopleapi.readwrite+https://www.googleapis.com/auth/userinfo.email&client_id="
		"919648714761-55j965o0km033psv3i9qls5mo3qtdrb0.apps.googleusercontent.com&origin=pkedcjkdefgpdelpbcmbmeomcjbeemfm&device_id=57e7fe73-4fef-478a-b9ec-87bcf202f2dc&device_type=chrome&lib_ver=extension", 
		LAST);

	web_add_header("X-Goog-Encode-Response-If-Executable", 
		"base64");

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_url("Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRIlCU35IjnBRbgwEgsN541ADhIAGgAiABILDc5BTHoSABoAIgAaAA==", 
		"URL=https://content-autofill.googleapis.com/v1/pages/Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRIlCU35IjnBRbgwEgsN541ADhIAGgAiABILDc5BTHoSABoAIgAaAA==?alt=proto", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t55.inf", 
		LAST);

	web_custom_request("token_3", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/firebase.messaging", 
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
		"URL=https://www.google-analytics.com/r/collect?v=1&_v=j81&a=175079766&t=pageview&_s=1&dl=chrome-extension%3A%2F%2Fhflefjhkfeiaignkclmphmokmmbhbhik%2F_generated_background_page.html&dp=%2Fbackground%2F1.5.21%2FOn&ul=ru-ru&de=UTF-8&sd=24-bit&sr=1280x720&vp=&je=0&_u=QACAAEAB~&jid=1243174395&gjid=1060386558&cid=557659239.1548187056&tid=UA-93290101-2&_gid=513539985.1584803240&_r=1&cd1=1.5.21&cd2=On&z=1204945862", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t57.inf", 
		LAST);

	web_add_header("X-Goog-Update-AppId", 
		"mgndgikekgjfcpckkfioiadnlibdjbkf");

	web_add_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_header("X-Goog-Update-Updater", 
		"chromecrx-80.0.3987.149");

	web_url("crx", 
		"URL=https://clients2.google.com/service/update2/crx?os=win&arch=x64&os_arch=x86_64&nacl_arch=x86-64&prod=chromecrx&prodchannel=&prodversion=80.0.3987.149&lang=ru&acceptformat=crx3&x=id%3Dmgndgikekgjfcpckkfioiadnlibdjbkf%26v%3D0.0.0.0%26installedby%3Dinternal%26uc%26ping%3Dr%253D73%2526e%253D1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmca", 
		"URL=https://clients4.google.com/invalidation/android/request/CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmcaACoCCAAyH2NvbS5nb29nbGUuY2hyb21lLmludmFsaWRhdGlvbnM", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		"EncType=application/x-protobuffer", 
		"BodyBinary=\nY\n\\x06\n\\x04\\x08\\x03\\x10\\x02\\x12%\n\\x06\n\\x04\\x08\\x03\\x10\\x01\\x12\\x12\t\\xFA\\xE6E\\xE2\\xED\\xD2\\x9D\\xBD\\x11\\x8EO\"z3M=Z\\x1A\\x07\\x08\\x972\\x10\\x03\\x18\\x01\\x1A\\x18\\x08\\x00\\x12\\x14\\xDA9\\xA3\\xEE^kK\r2U\\xBF\\xEF\\x95`\\x18\\x90\\xAF\\xD8\\x07\t \\xE7\\xB6\\xA8\\xF1\\x84\\x81\\x03(\\x002\\x0118\\x9F\\x082\\x94\\x01\n\\x8F\\x01\n\\x07\\x08\\x03\\x10\\xAC\\xA1\\xCD\t\\x12rMozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
		"Chrome/80.0.3987.149 Safari/537.36\\x1A\\x03C++\"\\x0Bchrome-sync \\x01", 
		LAST);

	lr_start_transaction("1_transaction_Login_Buy_Itinerary_Home");

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

	lr_think_time(29);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128419.365249089zzAffHVpVDQzDDptczz", ENDITEM, 
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
		"ihnlcenocehgdaegdmhbidjhnhdchfmm,mimojjlkmoijpicakmndhoigimigcmbb,oimompecagnajdejgnnjijobebaeigek,hnimpnehoodheedghdeeijklkeaacbdc,gcmjkmgdlgnkkcocmoeiminaijmmjnii,llkgjffcdpffmhiakmfcdcblohccpfmo,hfnkpimlhhgieaddgfemjhofmfblmnib,khaoiebndkojlmppeemjhbpbandiljpe,aemomkdncapdnfajjbbcbdebjljbpmpj,giekcmmlnklenlaomppkphknjmnnpneh,gkmgaooipdjhmangpemjhigmamcehddo,ehgidpndbllacpjalkiimkbadgjfnnmc,bklopemakmnopmghhmccadeonafabnal,jflookgnkcckhobaglndicnbbgbonegd");

	web_add_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_header("X-Goog-Update-Updater", 
		"chrome-80.0.3987.149");

	lr_think_time(9);

	web_custom_request("json", 
		"URL=http://update.googleapis.com/service/update2/json?cup2key=9:2285440355&cup2hreq=d928ac989fd4c951dc9b29772e635be9fcea95425c3ed75d0fd96223568bc565", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chrome\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ihnlcenocehgdaegdmhbidjhnhdchfmm\",\"brand\":\"GGLS\",\"cohortname\":\"Auto\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{befab04d-4389-4614-8ca9-2da6edfd35d9}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"mimojjlkmoijpicakmndhoigimigcmbb\",\"brand\":\"GGLS\",\"cohort\":\"1:d0j:\",\"cohorthint\":\"Chrome [M50+]\",\"cohortname\":\"Chrome [M50+]\",\"enabled\""
		":true,\"packages\":{\"package\":[{\"fp\":\"1.836a5a90b448bede995cdbbb251804b24208eacc171d33b84334a8735c33a176\"}]},\"ping\":{\"ping_freshness\":\"{7a0d5049-bbb3-483e-9089-4933133b3c9f}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"32.0.0.344\"},{\"appid\":\"oimompecagnajdejgnnjijobebaeigek\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{1e234f4e-e6e7-4c3b-9d25-f59f12179b15}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"4.10.1610.0\"},{\"appid\":\""
		"hnimpnehoodheedghdeeijklkeaacbdc\",\"brand\":\"GGLS\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.1cd7dc2056afaa0f6a705c9a17d22bba6578b33f5dae9e2d6518a0bfcced2396\"}]},\"ping\":{\"ping_freshness\":\"{7c86cb34-0cdd-41e1-b4ac-d4929206ada9}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"0.57.44.2492\"},{\"appid\":\"gcmjkmgdlgnkkcocmoeiminaijmmjnii\",\"brand\":\"GGLS\",\"cohort\":\"1:bm1:\",\"cohorthint\":\"M54ToM99\",\"cohortname\":\"M54ToM99\",\"enabled\":true,\"packages\":{\"package\":"
		"[{\"fp\":\"1.715c48ce73b7ee71924470b10e920a4e23cd6f9c860f367d00feaff0d03eb52f\"}]},\"ping\":{\"ping_freshness\":\"{6d3fb54f-6d09-45f3-b7e7-14d60dba9714}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"9.11.0\"},{\"appid\":\"llkgjffcdpffmhiakmfcdcblohccpfmo\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{eedb88a9-4728-470d-9fe8-a972e1df2d55}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"hfnkpimlhhgieaddgfemjhofmfblmnib\",\"brand\":\"GGLS\",\"cohort\""
		":\"1:jcl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.c0ad0573265ca1304f14665ec39629a8111863afe20af39f33890e27e8739af4\"}]},\"ping\":{\"ping_freshness\":\"{9e7f3c58-7384-406d-a73b-0f09f0e776d0}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"5775\"},{\"appid\":\"khaoiebndkojlmppeemjhbpbandiljpe\",\"brand\":\"GGLS\",\"cohort\":\"1:cux:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":"
		"\"1.5cb8df53fe2b86bf838ea2c9ffc3d5ef8460f679a779ac8aa924b5afffd052cb\"}]},\"ping\":{\"ping_freshness\":\"{c648d24f-1140-46e5-99b1-f5fd4e40f503}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"42\"},{\"appid\":\"aemomkdncapdnfajjbbcbdebjljbpmpj\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{b2ec559e-eb62-4d22-9187-8cadc21c3f9c}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"1.0.5.0\"},{\"appid\":\"giekcmmlnklenlaomppkphknjmnnpneh\",\"brand\":\"GGLS\",\"cohort\":\"1:j5l:\",\""
		"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.3eb16d6c28b502ac4cfee8f4a148df05f4d93229fa36a71db8b08d06329ff18a\"}]},\"ping\":{\"ping_freshness\":\"{01945c86-ac3d-4f2f-9f92-7fc19bfea326}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"7\"},{\"appid\":\"gkmgaooipdjhmangpemjhigmamcehddo\",\"brand\":\"GGLS\",\"cohort\":\"1:pw3:\",\"cohorthint\":\"Stable\",\"cohortname\":\"Stable\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\""
		"1.4d9ddf151092a9830f94069b96d5f165e9acd31e5372d342d3c1a3bcb8a28262\"}]},\"ping\":{\"ping_freshness\":\"{4c1934a0-0833-45a0-905d-8893a1778622}\",\"rd\":4834},\"tag\":\"eset_exp_b\",\"updatecheck\":{},\"version\":\"80.230.200\"},{\"appid\":\"ehgidpndbllacpjalkiimkbadgjfnnmc\",\"brand\":\"GGLS\",\"cohort\":\"1:ofl:\",\"cohorthint\":\"stable64\",\"cohortname\":\"stable64\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.a8a79d350c2a5e3bc36226633a8e0bed0dfab184e77f38fc8f0820ebacf8eafc\"}]},\""
		"ping\":{\"ping_freshness\":\"{b8e7fc1a-61ff-4178-a6d8-8062a24b9bce}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"2018.8.8.0\"},{\"appid\":\"bklopemakmnopmghhmccadeonafabnal\",\"brand\":\"GGLS\",\"cohort\":\"1:swl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.6dce22b9a11fa1e62b22559c4a157ce745e7fc63c6c6941a82cf11e8ecf65b0e\"}]},\"ping\":{\"ping_freshness\":\"{df8ba4c8-2f31-4349-a09d-bd90a4a854e8}\",\"rd\":4834},\"updatecheck\":{},\""
		"version\":\"3\"},{\"appid\":\"jflookgnkcckhobaglndicnbbgbonegd\",\"brand\":\"GGLS\",\"cohort\":\"1:s7x:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.f97033d828c56b79d9edc3c43bef4921f4e566e3c2f832cc4255acdf14fa44e3\"}]},\"ping\":{\"ping_freshness\":\"{a1338f75-3213-47a8-959f-308e0bfb2c57}\",\"rd\":4834},\"updatecheck\":{},\"version\":\"535\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\""
		"ru\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{578cb20a-8442-4c9e-b1ca-207827b83db1}\",\"sessionid\":\"{121716aa-6844-4042-907c-bf53c7c0508d}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	lr_start_transaction("2_transaction_Flights");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(10);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Goog-Encode-Response-If-Executable", 
		"base64");

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_concurrent_start(NULL);

	web_url("Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRJMCUFCU6JtyxUKEgsNVGIprRIAGgAiABILDXudxKUSABoAIgASCw0fOzmFEgAaACIAEgsN2oWZYRIAGgAiABILDamOSr0SABoAIgAaAA==", 
		"URL=https://content-autofill.googleapis.com/v1/pages/Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRJMCUFCU6JtyxUKEgsNVGIprRIAGgAiABILDXudxKUSABoAIgASCw0fOzmFEgAaACIAEgsN2oWZYRIAGgAiABILDamOSr0SABoAIgAaAA==?alt=proto", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t63.inf", 
		LAST);

	web_add_header("X-HTTP-Method-Override", 
		"POST");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_url("threatListUpdates:fetch", 
		"URL=https://safebrowsing.googleapis.com/v4/threatListUpdates:fetch?$req="
		"Ch0KDGdvb2dsZWNocm9tZRINODAuMC4zOTg3LjE0ORopCAUQARobCg0IBRAGGAEiAzAwMTABEIqlCBoCGApZ4YQ2IgQgASACKAEaKQgBEAEaGwoNCAEQBhgBIgMwMDEwARDWlwcaAhgKnTJJnSIEIAEgAigBGikIAxABGhsKDQgDEAYYASIDMDAxMAEQ4ZoHGgIYChTZxFIiBCABIAIoARopCAcQARobCg0IBxAGGAEiAzAwMTABEPCPBxoCGApRAnXWIgQgASACKAEaJwgBEAEaGQoNCAEQBhgBIgMwMDEwAxAUGgIYCv-xTLIiBCABIAIoAxooCAEQCBoaCg0IARAIGAEiAzAwMTAEENsZGgIYChbr8SUiBCABIAIoBBonCAkQARoZCg0ICRAGGAEiAzAwMTAGEAMaAhgKlWHZyiIEIAEgAigGGigIDxABGhoKDQgPEAYYASIDMDAxMAEQyyYaAhgKpcZCqyIEIAEgAigBGicIChAIGh"
		"kKDQgKEAgYASIDMDAxMAEQBRoCGAqQdhXdIgQgASACKAEaJwgJEAEaGQoNCAkQBhgBIgMwMDEwARAZGgIYCpqx1XoiBCABIAIoARooCAgQARoaCg0ICBAGGAEiAzAwMTABEKsIGgIYCnvksUkiBCABIAIoARooCA0QARoaCg0IDRAGGAEiAzAwMTABEK5xGgIYCjynEPAiBCABIAIoARopCA4QARobCg0IDhAGGAEiAzAwMTABEIyrAxoCGArENAFSIgQgASACKAEaKAgQEAEaGgoNCBAQBhgBIgMwMDEwARCFAhoCGApv4oh0IgQgASACKAEiAggB&$ct=application/x-protobuf&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-protobuf", 
		"Referer=", 
		"Snapshot=t64.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("2_transaction_Flights",LR_AUTO);

	lr_start_transaction("3_transaction_Flight_Info");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(44);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Los Angeles", ENDITEM, 
		"Name=departDate", "Value=03/28/2020", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=03/29/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=findFlights.x", "Value=66", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("3_transaction_Flight_Info",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("4_transaction_Select_Time");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=342;601;03/28/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=36", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	web_add_header("X-Goog-Encode-Response-If-Executable", 
		"base64");

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_concurrent_start(NULL);

	web_url("Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRJmCTnKWcjO4LgAEgsNa2iabhIAGgAiABILDU-eJ_gSABoAIgASCw1jkyeHEgAaACIAEgsNolm4SRIAGgAiABILDfi0_qASABoAIgASCw1XaCyZEgAaACIAEgsNbfpmyRIAGgAiABoA", 
		"URL=https://content-autofill.googleapis.com/v1/pages/Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRJmCTnKWcjO4LgAEgsNa2iabhIAGgAiABILDU-eJ_gSABoAIgASCw1jkyeHEgAaACIAEgsNolm4SRIAGgAiABILDfi0_qASABoAIgASCw1XaCyZEgAaACIAEgsNbfpmyRIAGgAiABoA?alt=proto", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t67.inf", 
		LAST);

	web_add_header("X-Client-Data", 
		"CI+2yQEIpLbJAQjEtskBCKmdygEIz6/KAQi8sMoBCIa1ygEIl7XKAQjttcoBCI66ygEI5sbKAQ==");

	web_url("netcheck.gif", 
		"URL=https://ssl.gstatic.com/docs/common/netcheck.gif?zx=xi3ikxxszrc7", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://docs.google.com/offline/extension/frame?ouid=", 
		"Snapshot=t68.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("4_transaction_Select_Time",LR_AUTO);

	lr_start_transaction("5_transaction_Payment");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(43);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=sadawdwadwad", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value=342;601;03/28/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=42", ENDITEM, 
		"Name=buyFlights.y", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("5_transaction_Payment",LR_AUTO);

	lr_start_transaction("6_transaction_Itinerary");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(33);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("6_transaction_Itinerary",LR_AUTO);

	lr_start_transaction("7_transaction_Home");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(21);

	web_url("Home Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_transaction_Home",LR_AUTO);

	lr_end_transaction("1_transaction_Login_Buy_Itinerary_Home",LR_AUTO);

	return 0;
}