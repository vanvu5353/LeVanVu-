#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<wchar.h>
#include<stdlib.h>
#include <fcntl.h> 
#include <io.h> 

#define _CRT_SECURE_NO_WARNINGS

struct sinhvien
{
	wchar_t* mssv;
	wchar_t* hoten;
	wchar_t* khoa1;
	wchar_t* khoa2;
	wchar_t* ngaysinh;
	wchar_t* hinhanh;
	wchar_t* Gmail;
	wchar_t* motabanthan;
	wchar_t* sothich;
};

int DDai(wchar_t s[])
{
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int VuVan(FILE* f, wchar_t h)
{
	wchar_t ch;
	int v = 0;
	while (!feof(f)) {
		ch = fgetwc(f);
		if (ch != h)
		{
			v++;
		}
		else
			return v + 1;
	}
	return v;
}
int TimKiem(FILE* f, wchar_t s[])
{
	int j, zhu = 0;
	while (!feof(f)) {
		j = 0;
		fseek(f, zhu, SEEK_SET);
		for (int i = 0; i < DDai(s); i++) {
			if (fgetwc(f) == s[i]) {
				j++;
			}
			else {
				break;
			}
		}
		if (j == DDai(s) - 1) {
			return ftell(f);
		}
		else {
			fseek(f, zhu + 1, SEEK_SET);
		}
		zhu++;
	}
	return -1;
}
int TK(FILE* f, int pos, wchar_t x)
{
	int v = 0;
	while (fgetwc(f) != x)
	{
		v++;
	}
	return v - 1;
}

void replace(FILE* f, wchar_t s[], int pos, wchar_t x)
{
	if (TK(f, pos, x) > DDai(s))
	{
		fseek(f, pos + 1, SEEK_SET);
		while (fgetwc(f) != L'-')
			fputwc(L' ', f);
		fseek(f, pos + 1, SEEK_SET);
		fputws(s, f);
	}
	else
	{
		wchar_t tmp[1000];
		fseek(f, TK(f, pos, x) + pos, SEEK_SET);
		fgetws(tmp, 1000, f);
		wprintf(L"%ls", tmp);
		fseek(f, pos, SEEK_SET);
		fputws(s, f);
		fputws(tmp, f);
	}
}

void DocFile(FILE* fIn, sinhvien &x, int &BatDau)
{
	fseek(fIn, BatDau, SEEK_SET);
	int a = VuVan(fIn, L',');
	x.mssv = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, BatDau, SEEK_SET);
	fgetws(x.mssv, a, fIn);
	int b = ftell(fIn);
	wprintf(L"MSSV: %ls\n", x.mssv);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.hoten = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hoten, a, fIn);
	b = ftell(fIn);
	wprintf(L"Họ và Tên: %ls\n", x.hoten);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.khoa1 = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoa1, a, fIn);
	b = ftell(fIn);
	wprintf(L"Khoa: %ls\n", x.khoa1);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.khoa2 = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.khoa2, a, fIn);
	b = ftell(fIn);
	wprintf(L"Khóa: %ls\n", x.khoa2);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.ngaysinh = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.ngaysinh, a, fIn);
	b = ftell(fIn);
	wprintf(L"Ngày sinh: %ls\n", x.ngaysinh);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.Gmail = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.Gmail, a, fIn);
	b = ftell(fIn);
	wprintf(L"Gmail: %ls\n", x.Gmail);

	fseek(fIn, b + 1, SEEK_SET);
	a = VuVan(fIn, L',');
	x.hinhanh = (wchar_t*)malloc(sizeof(wchar_t)*a);
	fseek(fIn, b + 1, SEEK_SET);
	fgetws(x.hinhanh, a, fIn);
	b = ftell(fIn);
	wprintf(L"Link hình ảnh: %ls\n", x.hinhanh);

	fseek(fIn, b + 1, SEEK_SET);
	if (fgetwc(fIn) != L'\"') {
		fseek(fIn, b + 1, SEEK_SET);
		a = VuVan(fIn, L',');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 1, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn);
	}
	else {
		fseek(fIn, b + 2, SEEK_SET);
		a = VuVan(fIn, L'\"');
		x.motabanthan = (wchar_t*)malloc(sizeof(wchar_t)*a);
		fseek(fIn, b + 2, SEEK_SET);
		fgetws(x.motabanthan, a, fIn);
		b = ftell(fIn) + 1;
	}
	wprintf(L"Mô tả bản thân: %ls\n", x.motabanthan); 

	fseek(fIn, b, SEEK_SET);
	if (fgetwc(fIn) == L',') {
		if (fgetwc(fIn) != L'\"') {
			fseek(fIn, b + 1, SEEK_SET);
			a = VuVan(fIn, '\n');
			x.sothich = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 1, SEEK_SET);
			fgetws(x.sothich, a, fIn);
			b = ftell(fIn);
			BatDau = b;
		}
		else {
			fseek(fIn, b + 2, SEEK_SET);
			a = VuVan(fIn, '\"');
			x.sothich = (wchar_t*)malloc(sizeof(wchar_t)*a);
			fseek(fIn, b + 2, SEEK_SET);
			fgetws(x.sothich, a, fIn);

			b = ftell(fIn) + 1;
			fgetwc(fIn);
			fgetwc(fIn);

		}
		wprintf(L"Sở thích: %ls\n\n", x.sothich);
		BatDau = b + 2;
	}
	else {
		BatDau = b;
	}
	
}

void XuatFile(sinhvien v)
{
	wchar_t b[50];
	wchar_t c[] = L".htm";
	wcscpy(b, v.mssv);
	wcscat(b, c);
	FILE* f = _wfopen(b, L"w,css=UTF-8");
	if (f != 0)
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"    <head>\n");
		fwprintf(f, L"        <meta http-equiv=\"Content - Type\" content=\"text / html; charset = utf - 8\" />\n");
		fwprintf(f, L"        <link rel=\"stylesheet\" type=\"text / css\" href=\"personal.css\" />\n");
		fwprintf(f, L"        <title>HCMUS - %ls</title>\n", v.hoten);
		fwprintf(f, L"    </head>\n");
		fwprintf(f, L"    <body>\n");
		fwprintf(f, L"        <div class=\"Layout_container\">\n");
		fwprintf(f, L"            <!-- Begin Layout Banner Region -->\n");
		fwprintf(f, L"            <div class=\"Layout_Banner\" >\n");
		fwprintf(f, L"                <div><img id=\"logo\" src=\"Images / logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(f, L"                <div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(f, L"            </div>\n");
		fwprintf(f, L"            <!-- End Layout Banner Region -->\n");
		fwprintf(f, L"            <!-- Begin Layout MainContents Region -->\n");
		fwprintf(f, L"            <div class=\"Layout_MainContents\">\n");
		fwprintf(f, L"                <!-- Begin Below Banner Region -->\n");
		fwprintf(f, L"                <div class=\"Personal_Main_Information\">\n");
		fwprintf(f, L"                    <!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(f, L"<div class=\"Personal_Location\">\n");
		fwprintf(f, L"                        <img src=\"Images / LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(f, L"<div class=\"Personal_FullName\">%ls - %ls</div>\n", v.hoten, v.mssv);
		fwprintf(f, L"<div class=\"Personal_Department\">KHOA %ls</div>\n", v.khoa1);
		fwprintf(f, L"                        <br />\n");
		fwprintf(f, L"                        <div class=\"Personal_Phone\">\n");
		fwprintf(f, L"Email: %ls\n", v.Gmail);
		fwprintf(f, L"                        </div>\n");
		fwprintf(f, L"                        <br />\n");
		fwprintf(f, L"                        <br />\n");
		fwprintf(f, L"                    </div>\n");
		fwprintf(f, L"<!-- End Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(f, L"                    <div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"                        <img src=\"Images / 1212123.jpg\" class=\"Personal_Hinhcanhan\" />\n");
		fwprintf(f, L"                    </div>\n");
		fwprintf(f, L"                </div>\n");
		fwprintf(f, L"                <!-- End Below Banner Region -->\n");
		fwprintf(f, L"                <!-- Begin MainContents Region -->\n");
		fwprintf(f, L"                <div class=\"MainContain\">\n\n");
		fwprintf(f, L"                    <!-- Begin Top Region -->\n");
		fwprintf(f, L"                    <div class=\"MainContain_Top\">\n\n");
		fwprintf(f, L"                        <div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"                        <div>\n");
		fwprintf(f, L"                            <ul class=\"TextInList\">\n");
		fwprintf(f, L"                                <li>Họ và tên: %ls</li>\n", v.hoten);
		fwprintf(f, L"                                <li>MSSV: %ls</li>\n", v.mssv);
		fwprintf(f, L"                                <li>Sinh viên khoa %ls</li>\n", v.khoa1);
		fwprintf(f, L"                                <li>Ngày sinh: %ls</li>\n", v.ngaysinh);
		fwprintf(f, L"                                <li>Email: %ls</li>\n", v.Gmail);
		fwprintf(f, L"                            </ul>\n");
		fwprintf(f, L"                        </div>\n");
		fwprintf(f, L"                        <div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"                        <div>\n");
		fwprintf(f, L"                            <ul class=\"TextInList\">\n");
		fwprintf(f, L"                                <li>%ls</li>\n", v.sothich);
		fwprintf(f, L"                            </ul>\n");
		fwprintf(f, L"                        </div>\n");
		fwprintf(f, L"                        <div class=\"InfoGroup\">Mô tả</div>\n");
		fwprintf(f, L"                        <div class=\"Description\">\n");
		fwprintf(f, L"                            %ls.\n", v.motabanthan);
		fwprintf(f, L"                        </div>\n");
		fwprintf(f, L"                    </div>\n");
		fwprintf(f, L"                </div>\n");
		fwprintf(f, L"            </div>\n\n");
		fwprintf(f, L"            <!-- Begin Layout Footer -->\n");
		fwprintf(f, L"            <div class=\"Layout_Footer\">\n");
		fwprintf(f, L"                <div class=\"divCopyright\">\n");
		fwprintf(f, L"                    <br />\n");
		fwprintf(f, L"                    <img src=\"Images / LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />>\n");
		fwprintf(f, L"                    <br />\n");
		fwprintf(f, L"                    @2013</br>\n");
		fwprintf(f, L"                    Đồ án giữ kỳ</br>\n");
		fwprintf(f, L"                Kỹ thuật lập trình</br>\n");
		fwprintf(f, L"                TH2012/03</br>\n");
		fwprintf(f, L"                1712919 - Lê Văn Vũ</br>\n");
		fwprintf(f, L"                </div>\n");
		fwprintf(f, L"            </div>\n");
		fwprintf(f, L"            <!-- End Layout Footer -->\n");
		fwprintf(f, L"        </div>\n");
		fwprintf(f, L"    </body>\n");
		fwprintf(f, L"</html>\n");
	}
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	FILE* file=_wfopen(L"abcd.csv", L"r, ccs=UTF-8");

	if (file == NULL)
	{
		wprintf(L"\nSr!!! KHONG MO DUOC FILE ^-^ \n");
	}
	else
	{
		int v = 0, BatDau = 3;
		sinhvien* x;
		x = (sinhvien*)malloc(sizeof(sinhvien) * 12);
		while (!feof(file)) {
			v++;

			DocFile(file, x[v - 1], BatDau);
		}
		free(x);
		fclose(file);
	}

	_getch();
	return 0;
}