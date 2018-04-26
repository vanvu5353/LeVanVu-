wchar_t b[50];
wchar_t c[] = L".htm";
wcscpy(b, a[i].MSSV);
wcscat(b, c);
FILE* x = _wfopen(b, L"w, ccs= UTF-8");
if (x != NULL)
{
	fwprintf(x, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(x, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(x, L"	<head>\n");
	fwprintf(x, L"		<meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf - 8\" />\n");
	fwprintf(x, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(x, L"		<title>HCMUS - %ls</title>\n", a[i].HoTen);
	fwprintf(x, L"	</head>\n");
	fwprintf(x, L"	<body>\n");
	fwprintf(x, L"		<div class=\"Layout_container\">\n");
	fwprintf(x, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(x, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(x, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(x, L"				<div class=\"Header_Title\">TR??NG ??I H?C Khoa H?C T? NHIÊN </div>\n");
	fwprintf(x, L"			</div>\n");
	fwprintf(x, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(x, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(x, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(x, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(x, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(x, L"					<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(x, L"					<div class=\"Personal_Location\">\n");
	fwprintf(x, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(x, L"						<span class=\"Personal_FullName\">%ls - %s</span>\n", a[i].HoTen, a[i].MSSV);
	fwprintf(x, L"						<div class=\"Personal_Department\">Khoa %ls</div>\n", a[i].Khoa);
	fwprintf(x, L"						<br />\n");
	fwprintf(x, L"						<div class=\"Personal_Phone\">\n");
	fwprintf(x, L"							Email: %ls\n", a[i].Email);
	fwprintf(x, L"						</div>\n");
	fwprintf(x, L"						<br />\n");
	fwprintf(x, L"						<br />\n");
	fwprintf(x, L"					</div>\n");
	fwprintf(x, L"					<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(x, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(x, L"						<img src=\"%s\" class=\"Personal_Hinhcanhan\" />\n", a[i].Hinh);
	fwprintf(x, L"					</div>\n");
	fwprintf(x, L"				</div>\n");
	fwprintf(x, L"				<!-- End Below Banner Region -->\n");
	fwprintf(x, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(x, L"				<div class=\"MainContain\">\n");
	fwprintf(x, L"\n");
	fwprintf(x, L"					<!-- Begin Top Region -->\n");
	fwprintf(x, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(x, L"\n");
	fwprintf(x, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(x, L"						<div>\n");
	fwprintf(x, L"							 <ul class=\"TextInList\">\n");
	fwprintf(x, L"								<li>H? và tên: %ls</li>\n", a[i].HoTen);
	fwprintf(x, L"								<li>MSSV: %ls</li>\n", a[i].MSSV);
	fwprintf(x, L"								<li>Sinh viên Khoa %ls</li>\n", a[i].Khoa);
	fwprintf(x, L"								<li>Ngày sinh: %ls</li>\n", a[i].NgaySinh);
	fwprintf(x, L"								<li>Email: %ls</li>\n", a[i].Email);
	fwprintf(x, L"							</ul>\n");
	fwprintf(x, L"						</div>\n");
	fwprintf(x, L"						<div class=\"InfoGroup\">S? thích</div>\n");
	fwprintf(x, L"						<div>\n");
	fwprintf(x, L"							<ul class=\"TextInList\">\n");
	if (sothich[i] == 0)
	{
		fwprintf(x, L"								<li>Không có.\n</li>\n");
	}
	if (sothich[i] == 1)
	{
		fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
	}
	else if (sothich[i] == 2)
	{

		fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
		fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich2);
	}
	fwprintf(x, L"							</ul>\n");
	fwprintf(x, L"						</div>\n");
	fwprintf(x, L"						<div class=\"InfoGroup\">Mô t?</div>\n");
	fwprintf(x, L"						<div class=\"Description\">\n");
	fwprintf(x, L"							%ls.\n", a[i].MoTa);
	fwprintf(x, L"						</div>\n");
	fwprintf(x, L"\n");
	fwprintf(x, L"					</div>\n");
	fwprintf(x, L"				</div>\n");
	fwprintf(x, L"			</div>\n");
	fwprintf(x, L"\n");
	fwprintf(x, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(x, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(x, L"				<div class=\"divCopyright\">\n");
	fwprintf(x, L"					<br />\n");
	fwprintf(x, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(x, L"					<br />\n");
	fwprintf(x, L"					@2018</br>\n");
	fwprintf(x, L"					?? án gi?a k?</br>\n");
	fwprintf(x, L"				K? thu?t l?p trình</br>\n");
	fwprintf(x, L"				TH2018/04</br>\n");
	fwprintf(x, L"				1712903 - Nguy?n Ng?c Viên</br>\n");
	fwprintf(x, L"				</div>\n");
	fwprintf(x, L"			</div>\n");
	fwprintf(x, L"			<!-- End Layout Footer -->\n");
	fwprintf(x, L"		</div>\n");
	fwprintf(x, L"	</body>\n");
	fwprintf(x, L"</html>\n");
	fwprintf(x, L"\n");
	wprintf(L" ->T?o file %ls (sinh viên th? %d) thành công.\n", b, i + 1);
}
fclose(x);