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
		wprintf(L"Sở thích: %ls\n\n", x.sothich);//owr day
		BatDau = b + 2;
	}
	else {
		BatDau = b;
	}
	
}

/*void XuatFile(sinhvien a)
{
wchar_t b[50];
wchar_t

}*/

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