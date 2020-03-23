Action()
{

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_set_sockets_option("SSL_VERSION", "2&3");

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
		"Snapshot=t27.inf", 
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

	web_add_cookie("NID=200=iRAhfcV85SQYQ96vU_Qz3_eecWG-38Wpwnya2eG207YsKeRdx7IBOetQlaA0cuwBEQXORroGWwtyOuVN_tJ8WL1EzahVugdpv8vTAyokFMQDsYAid301akIoXWuWGaI7NAwdL0PveD5ZMgqkRuES038BDOXjtlQ9nqf8d8VuI4NhqsjEowTX6h06xeu6n6u7peCiti7NR3jt289YytuHt8i1sBeHlDuR6mJgCUK8WNtpElUka8-ggsrdeUGJBiTgIx9Wtez2H4nzGiQ; DOMAIN=accounts.google.com");

	web_add_cookie("1P_JAR=2020-3-23-16; DOMAIN=accounts.google.com");

	web_add_cookie("SIDCC=AJi4QfGk4LwNgKtlbQDhFeN3eHmx2S6vqPPIzLbYcgp45OocEeGTSFyje1W73UJTeVoACP7LM8eo; DOMAIN=accounts.google.com");

	web_add_header("Origin", 
		"https://www.google.com");

	web_custom_request("ListAccounts", 
		"URL=https://accounts.google.com/ListAccounts?gpsia=1&source=ChromiumBrowser&json=standard", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t28.inf", 
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
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/chromesync", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
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
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Sec-Fetch-Dest");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("issuetoken", 
		"URL=https://oauthaccountmanager.googleapis.com/v1/issuetoken", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"Body=force=false&response_type=token&scope=https://www.googleapis.com/auth/calendar.readonly+https://www.googleapis.com/auth/cast-edu-messaging+https://www.googleapis.com/auth/clouddevices+https://www.googleapis.com/auth/hangouts+https://www.googleapis.com/auth/hangouts.readonly+https://www.googleapis.com/auth/meetings+https://www.googleapis.com/auth/plus.peopleapi.readwrite+https://www.googleapis.com/auth/userinfo.email&client_id="
		"919648714761-55j965o0km033psv3i9qls5mo3qtdrb0.apps.googleusercontent.com&origin=pkedcjkdefgpdelpbcmbmeomcjbeemfm&device_id=57e7fe73-4fef-478a-b9ec-87bcf202f2dc&device_type=chrome&lib_ver=extension", 
		LAST);

	web_concurrent_start(NULL);

	web_url("client_model_v5_ext_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_ext_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t32.inf", 
		LAST);

	web_url("client_model_v5_variation_0.pb", 
		"URL=https://ssl.gstatic.com/safebrowsing/csd/client_model_v5_variation_0.pb", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t33.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_url("merchants.json", 
		"URL=https://www.gstatic.com/autofill/weekly/merchants.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bins.json", 
		"URL=https://www.gstatic.com/autofill/hourly/bins.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("A-IM", 
		"x-bm,gzip");

	web_url("seed", 
		"URL=https://clientservices.googleapis.com/chrome-variations/seed?osname=win&channel=stable&milestone=80", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_url("query", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZTfkiOcFFuDAjLeeNQA4kIy3OQUx6JBQ=", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t37.inf", 
		LAST);

	/* Login */

	lr_think_time(4);

	web_custom_request("token_3", 
		"URL=https://www.googleapis.com/oauth2/v4/token", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		"Body=client_id=77185425430.apps.googleusercontent.com&client_secret=OTJgUOQcT7lO7GsGZq2G4IlT&grant_type=refresh_token&refresh_token=1//0cRVWJEwkYsOpCgYIARAAGAwSNwF-L9IrGupuDl21sZ-csuTljhH7J6P8xYvf-YYhI_Z1glscVPc6k8SPQpfr5hFombNdvS3eLrE&scope=https://www.googleapis.com/auth/firebase.messaging", 
		LAST);

	web_add_header("X-Goog-Update-AppId", 
		"mgndgikekgjfcpckkfioiadnlibdjbkf");

	web_add_auto_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_auto_header("X-Goog-Update-Updater", 
		"chromecrx-80.0.3987.149");

	web_url("crx", 
		"URL=https://clients2.google.com/service/update2/crx?os=win&arch=x64&os_arch=x86_64&nacl_arch=x86-64&prod=chromecrx&prodchannel=&prodversion=80.0.3987.149&lang=ru&acceptformat=crx3&x=id%3Dmgndgikekgjfcpckkfioiadnlibdjbkf%26v%3D0.0.0.0%26installedby%3Dinternal%26uc%26ping%3Dr%253D69%2526e%253D1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Goog-Update-AppId", 
		"aapocclcgogkmnckokdopfmhonfmgoek,aohghmighlieiainnegkcijnfilokake,apdfllckaahabafndbhieahigkjlhalf,bihmplhobchoageeokmgbdihknkjbknd,blpcfgokakmgnkcojhhkbfbldkacnbeo,dmpojjilddefgnhiicjcmhbkjgbbclob,felcaaldnbdncclmgdcncolpebgiejap,gbchcmhmhahfdphkhkmpfmihenigjmpp,ghbmnnjooekpmoecnnnilnnbdlolhkhi,gighmmpiobklfepjocnamgkkbiglidom,hflefjhkfeiaignkclmphmokmmbhbhik,hmdcmlfkchdmnmnmheododdhjedfccka,inomeogfingihgjfjlpeplalcfajhgai,nmmhkkegccagdldgiimedpiccmgmieda,pjkljhegncpnkpknbcohdijeoejaedia,"
		"pkedcjkdefgpdelpbcmbmeomcjbeemfm");

	web_custom_request("json", 
		"URL=https://update.googleapis.com/service/update2/json?cup2key=9:309990114&cup2hreq=e4451cd918b23b0921b3954af93712fa9937a0c7ffda3871aa2473b03f6f040f", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chromecrx\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"aapocclcgogkmnckokdopfmhonfmgoek\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.0.10\"}]},\"ping\":{\"ping_freshness\":\"{78c686e5-0ccc-4b42-a86f-3d5b303a3228}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.10\"},{\"appid\":\"aohghmighlieiainnegkcijnfilokake\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\""
		",\"packages\":{\"package\":[{\"fp\":\"2.0.10\"}]},\"ping\":{\"ping_freshness\":\"{e7945534-2045-44c9-9f5e-516030930cb3}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.10\"},{\"appid\":\"apdfllckaahabafndbhieahigkjlhalf\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.14.2\"}]},\"ping\":{\"ping_freshness\":\"{2be3552a-525c-49b6-8270-df29e2c4b41b}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"14.2\"},{\"appid\":\""
		"bihmplhobchoageeokmgbdihknkjbknd\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"1.0a8bf15b5506a05975f1c5f2ad63ae478066838e46ced9edb0dfa54fa66f082d\"}]},\"ping\":{\"ping_freshness\":\"{be3e43d7-a418-4175-bf5d-5147e376700a}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"3.1.3\"},{\"appid\":\"blpcfgokakmgnkcojhhkbfbldkacnbeo\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.4.2.8\"}]},\""
		"ping\":{\"ping_freshness\":\"{20744cb2-414b-4ac6-866a-ad215089ef2f}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"4.2.8\"},{\"appid\":\"dmpojjilddefgnhiicjcmhbkjgbbclob\",\"brand\":\"GGLS\",\"disabled\":[{\"reason\":8192}],\"enabled\":false,\"installedby\":\"external\",\"packages\":{\"package\":[{\"fp\":\"2.1.8.7\"}]},\"ping\":{\"ping_freshness\":\"{4a7ed152-92a1-4b77-b5ce-9e8fd28e2e93}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.8.7\"},{\"appid\":\"felcaaldnbdncclmgdcncolpebgiejap\",\""
		"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.1.2\"}]},\"ping\":{\"ping_freshness\":\"{bb7b90ee-2191-4b2d-970e-c30ce54f0d5b}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.2\"},{\"appid\":\"gbchcmhmhahfdphkhkmpfmihenigjmpp\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.77.0.3836.0\"}]},\"ping\":{\"ping_freshness\":\"{8de3a17a-074e-445a-9aac-b98f342fd689}\",\"rd\":4830},\""
		"updatecheck\":{},\"version\":\"77.0.3836.0\"},{\"appid\":\"ghbmnnjooekpmoecnnnilnnbdlolhkhi\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"external\",\"packages\":{\"package\":[{\"fp\":\"1.2da6adba85d5c61f712a493272cf7c6dd3806347997698ebc5c4dfd84beb75c9\"}]},\"ping\":{\"ping_freshness\":\"{389f0e71-39cc-48cb-820b-0659d06ad1f2}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.9.1\"},{\"appid\":\"gighmmpiobklfepjocnamgkkbiglidom\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\""
		"internal\",\"packages\":{\"package\":[{\"fp\":\"1.f675c62c6af32e166f4d35b0e6b2d16561f8a0c292a028c8d40c3b056319079c\"}]},\"ping\":{\"ping_freshness\":\"{ae1f30aa-d6b5-41a1-bc16-d910a626e1e3}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"4.8.0\"},{\"appid\":\"hflefjhkfeiaignkclmphmokmmbhbhik\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.1.5.21\"}]},\"ping\":{\"ping_freshness\":\"{a0d0ac49-a1a5-49f7-b8fa-25ff13429e33}\",\"rd\":4830},\""
		"updatecheck\":{},\"version\":\"1.5.21\"},{\"appid\":\"hmdcmlfkchdmnmnmheododdhjedfccka\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.0.5.3\"}]},\"ping\":{\"ping_freshness\":\"{6f841b65-1c0e-4060-bfa8-78d9244c22b5}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.5.3\"},{\"appid\":\"inomeogfingihgjfjlpeplalcfajhgai\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.1.5\"}]},\"ping\":"
		"{\"ping_freshness\":\"{34b449d9-fcf2-4cc7-ac1e-5c3b15f73dbe}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.5\"},{\"appid\":\"nmmhkkegccagdldgiimedpiccmgmieda\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"other\",\"packages\":{\"package\":[{\"fp\":\"2.1.0.0.5\"}]},\"ping\":{\"ping_freshness\":\"{56e8451d-67a0-429e-9930-577e9ce2246c}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.0.0.5\"},{\"appid\":\"pjkljhegncpnkpknbcohdijeoejaedia\",\"brand\":\"GGLS\",\"enabled\":true,\""
		"installedby\":\"internal\",\"packages\":{\"package\":[{\"fp\":\"2.8.2\"}]},\"ping\":{\"ping_freshness\":\"{052aca04-4cc4-47d0-a74a-764c5da49c46}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"8.2\"},{\"appid\":\"pkedcjkdefgpdelpbcmbmeomcjbeemfm\",\"brand\":\"GGLS\",\"enabled\":true,\"installedby\":\"other\",\"packages\":{\"package\":[{\"fp\":\"1.586542a833e7c975201d6787bb06943fe8b1373acd37d1002338784bd4376b23\"}]},\"ping\":{\"ping_freshness\":\"{1043ff8f-a8ce-4599-8b51-55f2efb8f0e2}\",\"rd\":4830"
		"},\"updatecheck\":{},\"version\":\"8220.313.1.1\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\"ru\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{5292dc76-334e-4931-8d11-f35eeb21f799}\",\"sessionid\":\"{e7a21e6e-0587-4241-a6ae-960010171d57}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\""
		"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	web_revert_auto_header("X-Goog-Update-Interactivity");

	web_revert_auto_header("X-Goog-Update-Updater");

	web_custom_request("CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmca", 
		"URL=https://clients4.google.com/invalidation/android/request/CHES4QEStwFBUEE5MWJITmEyb1dCN0VDek5US3NEXzd4UlZBblNwSWRqdGhtYzF4ZmljTC1HbEFCTEpYWFk1bFZlTnkwRlJfeHB5TnRvdXkyMEZDMTRac2x5N1RySmZSZ1ZGYkczM2xpdktub2tIRkhWallNQ2N4MDVSUlkxOS1mSllQQWFyZmlIZGk2WmZGRnZtSFRiTjAzanhZNDB4ZlJONE1VWVBSRHRheWtDY0RGa1pmQTcxTlp2X01kTmcaACoCCAAyH2NvbS5nb29nbGUuY2hyb21lLmludmFsaWRhdGlvbnM", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EncType=application/x-protobuffer", 
		"BodyBinary=\nY\n\\x06\n\\x04\\x08\\x03\\x10\\x02\\x12%\n\\x06\n\\x04\\x08\\x03\\x10\\x01\\x12\\x12\t\\xFA\\xE6E\\xE2\\xED\\xD2\\x9D\\xBD\\x11\\x8EO\"z3M=Z\\x1A\\x07\\x08\\x972\\x10\\x03\\x18\\x01\\x1A\\x18\\x08\\x00\\x12\\x14\\xDA9\\xA3\\xEE^kK\r2U\\xBF\\xEF\\x95`\\x18\\x90\\xAF\\xD8\\x07\t \\xA7\\x8C\\xD3\\xC7\\x83\\x81\\x03(\\x002\\x0118\\x9F\\x082\\x94\\x01\n\\x8F\\x01\n\\x07\\x08\\x03\\x10\\xAC\\xA1\\xCD\t\\x12rMozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
		"Chrome/80.0.3987.149 Safari/537.36\\x1A\\x03C++\"\\x0Bchrome-sync \\x01", 
		LAST);

	lr_start_transaction("1_transaction_Login");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(12);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128390.542810855zzAtAiipftfiDDDDDQzctpfDVcHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=71", ENDITEM, 
		"Name=login.y", "Value=2", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction_Login",LR_AUTO);

	web_revert_auto_header("Sec-Fetch-Dest");

	web_add_header("X-Goog-Update-AppId", 
		"ihnlcenocehgdaegdmhbidjhnhdchfmm,mimojjlkmoijpicakmndhoigimigcmbb,oimompecagnajdejgnnjijobebaeigek,gcmjkmgdlgnkkcocmoeiminaijmmjnii,llkgjffcdpffmhiakmfcdcblohccpfmo,hnimpnehoodheedghdeeijklkeaacbdc,hfnkpimlhhgieaddgfemjhofmfblmnib,khaoiebndkojlmppeemjhbpbandiljpe,giekcmmlnklenlaomppkphknjmnnpneh,aemomkdncapdnfajjbbcbdebjljbpmpj,gkmgaooipdjhmangpemjhigmamcehddo,jflookgnkcckhobaglndicnbbgbonegd,bklopemakmnopmghhmccadeonafabnal,ehgidpndbllacpjalkiimkbadgjfnnmc");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("X-Goog-Update-Interactivity", 
		"bg");

	web_add_auto_header("X-Goog-Update-Updater", 
		"chrome-80.0.3987.149");

	lr_think_time(17);

	web_custom_request("json_2", 
		"URL=https://update.googleapis.com/service/update2/json?cup2key=9:60789455&cup2hreq=68be1511e3030ed8455d38561aa772a29db4e68c6c6a199400e93fdde32ae485", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chrome\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ihnlcenocehgdaegdmhbidjhnhdchfmm\",\"brand\":\"GGLS\",\"cohortname\":\"Auto\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{e7e5a5fb-32f7-40a7-88f7-4d087273ce79}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"mimojjlkmoijpicakmndhoigimigcmbb\",\"brand\":\"GGLS\",\"cohort\":\"1:d0j:\",\"cohorthint\":\"Chrome [M50+]\",\"cohortname\":\"Chrome [M50+]\",\"enabled\""
		":true,\"packages\":{\"package\":[{\"fp\":\"1.836a5a90b448bede995cdbbb251804b24208eacc171d33b84334a8735c33a176\"}]},\"ping\":{\"ping_freshness\":\"{2064b4c6-c398-4716-9d05-0fb38235b4fd}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"32.0.0.344\"},{\"appid\":\"oimompecagnajdejgnnjijobebaeigek\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{7866fd22-7544-499f-b3d6-efc89b483ce4}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"4.10.1610.0\"},{\"appid\":\""
		"gcmjkmgdlgnkkcocmoeiminaijmmjnii\",\"brand\":\"GGLS\",\"cohort\":\"1:bm1:\",\"cohorthint\":\"M54ToM99\",\"cohortname\":\"M54ToM99\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.715c48ce73b7ee71924470b10e920a4e23cd6f9c860f367d00feaff0d03eb52f\"}]},\"ping\":{\"ping_freshness\":\"{a6781d95-c5b3-434b-84d5-30e3d2805fc7}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"9.11.0\"},{\"appid\":\"llkgjffcdpffmhiakmfcdcblohccpfmo\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\""
		"{1a379cb6-db6a-431b-b272-c2e8cccc89e3}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"hnimpnehoodheedghdeeijklkeaacbdc\",\"brand\":\"GGLS\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.1cd7dc2056afaa0f6a705c9a17d22bba6578b33f5dae9e2d6518a0bfcced2396\"}]},\"ping\":{\"ping_freshness\":\"{351c7e12-6541-4f3f-89b6-d51d06ded3d8}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"0.57.44.2492\"},{\"appid\":\"hfnkpimlhhgieaddgfemjhofmfblmnib\",\"brand\":\"GGLS\",\"cohort\""
		":\"1:jcl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.46fe0954de4a08e46ea219b8f9ca6dd980333ae6d326d91e109c57954822ddf9\"}]},\"ping\":{\"ping_freshness\":\"{231d5862-de05-4aea-b666-cc9eeefc802c}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"5767\"},{\"appid\":\"khaoiebndkojlmppeemjhbpbandiljpe\",\"brand\":\"GGLS\",\"cohort\":\"1:cux:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":"
		"\"1.5cb8df53fe2b86bf838ea2c9ffc3d5ef8460f679a779ac8aa924b5afffd052cb\"}]},\"ping\":{\"ping_freshness\":\"{c8b338a4-e2e9-45fa-846c-a5b7733a7cfd}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"42\"},{\"appid\":\"giekcmmlnklenlaomppkphknjmnnpneh\",\"brand\":\"GGLS\",\"cohort\":\"1:j5l:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.3eb16d6c28b502ac4cfee8f4a148df05f4d93229fa36a71db8b08d06329ff18a\"}]},\"ping\":{\"ping_freshness\":\""
		"{ce7e3fbe-e684-4972-a039-203800d5ba42}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"7\"},{\"appid\":\"aemomkdncapdnfajjbbcbdebjljbpmpj\",\"brand\":\"GGLS\",\"enabled\":true,\"ping\":{\"ping_freshness\":\"{5349a30a-97ed-4c27-8f9d-f6534b1dcc95}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"1.0.5.0\"},{\"appid\":\"gkmgaooipdjhmangpemjhigmamcehddo\",\"brand\":\"GGLS\",\"cohort\":\"1:pw3:\",\"cohorthint\":\"Stable\",\"cohortname\":\"Stable\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\""
		"1.4d9ddf151092a9830f94069b96d5f165e9acd31e5372d342d3c1a3bcb8a28262\"}]},\"ping\":{\"ping_freshness\":\"{33efc389-45ec-4164-8f60-06ce6a502c79}\",\"rd\":4830},\"tag\":\"eset_exp_b\",\"updatecheck\":{},\"version\":\"80.230.200\"},{\"appid\":\"jflookgnkcckhobaglndicnbbgbonegd\",\"brand\":\"GGLS\",\"cohort\":\"1:s7x:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.ce40d6cf456098cbd3eec69e78887666eadc0364d18421c915da528a6cf1272b\"}]},\"ping\":{\""
		"ping_freshness\":\"{b55c8e71-b53c-4161-a131-6d531a57a224}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"487\"},{\"appid\":\"bklopemakmnopmghhmccadeonafabnal\",\"brand\":\"GGLS\",\"cohort\":\"1:swl:\",\"cohorthint\":\"Auto\",\"cohortname\":\"Auto\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.6dce22b9a11fa1e62b22559c4a157ce745e7fc63c6c6941a82cf11e8ecf65b0e\"}]},\"ping\":{\"ping_freshness\":\"{e163dfa4-2a19-493e-94f9-99c4584db922}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"3\"},{\""
		"appid\":\"ehgidpndbllacpjalkiimkbadgjfnnmc\",\"brand\":\"GGLS\",\"cohort\":\"1:ofl:\",\"cohorthint\":\"stable64\",\"cohortname\":\"stable64\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.a8a79d350c2a5e3bc36226633a8e0bed0dfab184e77f38fc8f0820ebacf8eafc\"}]},\"ping\":{\"ping_freshness\":\"{e908e99e-f10b-42cd-8ee0-f669a12030ba}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"2018.8.8.0\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\"ru\",\""
		"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{d3dbe7fc-dd22-46f3-978d-bc30c4c78868}\",\"sessionid\":\"{0249a746-6ead-4cef-85d7-375c3f937432}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	web_add_header("X-Goog-Update-AppId", 
		"ggkkehgbnfjpeggfpleeakpidbkibbmn");

	web_custom_request("json_3", 
		"URL=https://update.googleapis.com/service/update2/json?cup2key=9:2864570984&cup2hreq=214f09f9a779bd1ef45b7bc8bd05b8378ec161f766cda1c61290464898c90c15", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"chrome\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ggkkehgbnfjpeggfpleeakpidbkibbmn\",\"brand\":\"GGLS\",\"cohort\":\"1:ut9:\",\"cohorthint\":\"M80ToM89\",\"cohortname\":\"M80ToM89\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.6c8e831187722e3b53d26536eea4f630045d299f0fe6031861128cfb959e7628\"}]},\"ping\":{\"ping_freshness\":\"{b83e2b7e-8f40-461c-b65a-b4571d095f47}\",\"rd\":4830},\"updatecheck\":{},\"version\":\"2020.3.9.1143"
		"\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\":\"ru\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"6.3.9600.0\"},\"prodversion\":\"80.0.3987.149\",\"protocol\":\"3.1\",\"requestid\":\"{d0f8ce1a-d21f-4c5d-ba70-1d52990bffa0}\",\"sessionid\":\"{27a2fa45-947f-465a-ab6b-1ff29dad99cd}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\""
		"updatepolicy\":-1,\"version\":\"1.3.35.452\"},\"updaterversion\":\"80.0.3987.149\"}}", 
		LAST);

	lr_start_transaction("2_transaction_Flights");

	web_revert_auto_header("X-Goog-Update-Interactivity");

	web_revert_auto_header("X-Goog-Update-Updater");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(9);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_url("query_2", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZQUJTom3LFQojLVRiKa0kIy17ncSlJCMtHzs5hSQjLdqFmWEkIy2pjkq9JBQ=", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t46.inf", 
		LAST);

	lr_end_transaction("2_transaction_Flights",LR_AUTO);

	lr_start_transaction("3_transaction_Flight_Info");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(45);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=London", ENDITEM, 
		"Name=departDate", "Value=03/24/2020", ENDITEM, 
		"Name=arrive", "Value=Seattle", ENDITEM, 
		"Name=returnDate", "Value=03/25/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=findFlights.x", "Value=77", ENDITEM, 
		"Name=findFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("3_transaction_Flight_Info",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("4_transaction_Select_Time");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=271;730;03/24/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=51", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);

	web_add_header("X-Goog-Api-Key", 
		"AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw");

	web_url("query_3", 
		"URL=https://clients1.google.com/tbproxy/af/query?q=Chc2LjEuMTcxNS4xNDQyL2VuIChHR0xMKRMZOcpZyM7guAAjLWtomm4kIy1Pnif4JCMtY5MnhyQjLaJZuEkkIy34tP6gJCMtV2gsmSQjLW36ZskkFA==", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/proto", 
		"Referer=", 
		"Snapshot=t49.inf", 
		LAST);

	lr_end_transaction("4_transaction_Select_Time",LR_AUTO);

	lr_start_transaction("5_transaction_Payment");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(80);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=Killer", ENDITEM, 
		"Name=address2", "Value=Town", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=11/21", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value=271;730;03/24/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=71", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("5_transaction_Payment",LR_AUTO);

	return 0;
}