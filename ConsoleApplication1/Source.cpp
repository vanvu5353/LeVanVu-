
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>

struct sothich
{
	string sothich;
};
typedef struct sothich SoThich;

struct sinhvien
{
	string MSSV;
	string HoTen;
	string Khoa1;
	int Khoa2;
	string ngaysinh;
	string hinhanh;
	string motabanthan;
	vector<SoThich> CacSoThich;
};
typedef struct sinhvien SinhVien;

void DocThongTinSinhVien(ifstream &filein, SinhVien &sv)
{

	getline(filein,sv.MSSV,',');
	getline(filein, sv.HoTen, ',');
	getline(filein, sv.Khoa1, ',');
	getline(filein, sv.Khoa2, ',');
	getline(filein, sv.ngaysinh, ',');
	getline(filein, sv.hinhanh, ',');
	getline(filein, sv.motabanthan, ',');
}

void DocFile(ifstream &filein, vector<SinhVien> &ds_sv)
{
	while (filein.eof() == false)
	{
		SinhVien sv;
		DocThongTinSinhVien(filein, sv)
			ds_sv.push_back(sv);
	}
}

void main()
{
	ifstream filein;
	filein.open("1712919.csv", ios_base::in);
	vector<SinhVien>ds_sv;
	DocFile(filein, ds_sv);
	file.close();
	systen("pause");
 }