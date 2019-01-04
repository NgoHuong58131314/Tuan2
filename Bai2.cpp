#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
#include<fstream>
#include<stdio.h>
FILE *f;
struct NhanVien{
	char nhanvienid[4]; 
	char hoten[20];
	int tuoi;
	float luongnv;
};
vector<NhanVien> ds;	

NhanVien NhapNVTuBanPhim();
void InNV(NhanVien nv);
void InDSNV();
bool ThemNV(NhanVien nv);
bool XoaNV(char *id);
void CapNhatNV(NhanVien nvMoi);
void DocFIle();
void GhiFile();

NhanVien NhapNVTuBanPhim()
{
	NhanVien nv;
	cout << "\nNhap id nhan vien: "; fflush(stdin);
	gets(nv.nhanvienid);
	cout << "\nNhap ho ten nhan vien: ";
	gets(nv.hoten); fflush(stdin);
	cout << "\nNhap tuoi nhan vien: ";
	cin >> nv.tuoi;
	cout << "\nNhap luong nhan vien: ";
	cin >> nv.luongnv;
	return nv;
}
void InNV(NhanVien nv){
	cout << "ID: " << "\tHo ten: " << "\tTuoi: " << "\tLuong: " << endl;
}
void InDSNV()
{
	int n = ds.size();
	for(int i=0; i<n; i++)
		InNV(ds[i]);
}
bool ThemNV(NhanVien nv)
{
	int size = ds.size();
	for(int i=0; i<size; i++)
		if(strcmp(nv.nhanvienid, ds[i].nhanvienid)==0)
	return false;	
	ds.push_back(nv);	//Them nhan vien vao cuoi ds
	GhiFile();	
	return true;
}

bool XoaNV(char *id){
	int xoanv=-1;
	int size = ds.size();
	for(int i=0; i<size; i++){
		if(strcmp(id, ds[i].nhanvienid)==0)
			xoanv=i;
			break;
	}
	if(xoanv!=-1){
		ds.erase(ds.begin()+xoanv);
		GhiFile();
		return true;
	}
	else return false;
}
void CapNhatNV(NhanVien nvMoi)
{
	int vtMoi=-1;
	int size = ds.size();
	for(int i=0; i<size; i++){
		if(strcmp(nvMoi.nhanvienid, ds[i].nhanvienid)==0)
			vtMoi=i;
			break;
	}
	if(vtMoi!=-1){
		strcpy(ds[vtMoi].nhanvienid, nvMoi.nhanvienid);
		strcpy(ds[vtMoi].hoten, nvMoi.hoten);
		ds[vtMoi].tuoi=nvMoi.tuoi;
		ds[vtMoi].luongnv=nvMoi.luongnv;
		GhiFile();	
	}

}
void DocFile(){
	f=fopen("input.txt", "rb");
	if(f==NULL)
		cout<<"\nMo file khong thanh cong. Xin kiem tra lai!";
	else
		while(!feof(f)){
			NhanVien nv;
			fread(&nv, sizeof(NhanVien), 1, f);
			ds.push_back(nv);
		}
	fclose(f);
	ds.pop_back();
}
void GhiFile(){
	int size=ds.size();
	NhanVien nv;
	f=fopen("output.txt", "wb");
	for(int i=0; i<size; i++){
		nv=ds[i];
		fwrite(&nv, sizeof(NhanVien), 1, f);
	}
}
int main()
{
	NhanVien nv;

	while(true){
	cout << "\n---------------------MENU---------------------\n";	
	cout << "1. Nhap nhan vien tu ban phim" << endl;
	cout << "2. Them mot nhan vien" << endl;
	cout << "3. Xoa mot nhan vien theo ma nhan vien" << endl;
	cout << "4. Cap nhat nhan vien theo ma nhan vien" << endl;
	cout << "5. Doc du lieu tu file input" << endl;
	cout << "6. Ghi ket qua vao file output" << endl;
	cout << "7. Ket thuc" << endl;
	system("cls");
	cout << "\n---------------------END-------------------\n";
	
	int select;
	cout << "\nLua chon cua ban la: ";
	cin >> select;
	switch (select)
	{
		case 1:
			cout<<"\nNhap nhan vien tu ban phim\n";
			NhapNVTuBanPhim();
			break;
		case 2:
			cout<<"\nThem nhan vien vao ds nhan vien\n";
			NhanVien nvt=NhapNVTuBanPhim();
			ThemNV(nvt);
			cout<<"\nNhan vien da them vao ds nhan vien\n";
			InDSNV();
			break;
		case 3:
			cout<<"\nXoa mot nhan vien theo ma nhan vien\n";
			XoaNV("002");
			cout<<"\nDanh sach nhan vien sau khi xoa";
			InDSNV();
			break;
		case 4:
			cout<<"\nCap nhat nhan vien theo ma nhan vien\n";
			NhanVien nvMoi=NhapNVTuBanPhim;
			CapNhatNV(nvMoi);
			cout <<"\nDanh sach nhan vien sau khi cap nhat";
			InDSNV();
			break;
		case 5:
			cout<<"\nDoc du lieu tu file input\n";
			DocFile();
			break;
		case 6:
			cout<<"\nGhi du lieu vao file output\n";
			GhiFile();
			break;
		case 7:
			break;
	}
	}
}
