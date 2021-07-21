#include<iostream>
#include<string>
#include <iomanip>

using namespace std;
struct hoa
{
	int MaLoai;
	string TenHoa;
	int SoNgayHoaTuoi;
	string MuaThuHoach;
	float DonGia;
};
typedef struct hoa HOA;
void Nhap(HOA&);
void Xuat(HOA);
void Nhap(HOA[], int &);
void Xuat(HOA[], int);
void HoaNhanhHeoNhat(HOA[], int);
float TongDonGia(HOA[], int);
void SapGiam(HOA[], int);
void HoanVi(HOA&, HOA&);

int main()
{
	HOA a[100];
	int n;
	Nhap(a, n);
	cout << "\nMang hoa vua nhap la: ";
	Xuat(a, n);
	cout << endl;
	cout << "\nHoa nhanh heo nhat la: ";
	HoaNhanhHeoNhat(a, n);
	cout << endl;
	cout << "\nTong so don gia trong mang : " << TongDonGia(a, n);
	cout << endl;
	cout << "\nMang sau khi sap xep cac hoa giam theo don gia la: ";
	SapGiam(a, n);
	Xuat(a, n);

	return 0;
}

void Nhap(HOA& x)
{
	cout << "\nNhap ma hoa: ";
	cin >> x.MaLoai;
	cout << "Nhap ten hoa: ";
	cin.ignore();
	getline(cin, x.TenHoa);
	cout << "Nhap so ngay hoa tuoi: ";
	cin >> x.SoNgayHoaTuoi;
	cout << "Nhap mua thu hoach cua hoa: ";
	cin.ignore();
	getline(cin, x.MuaThuHoach);
	cout << "Nhap don gia cua hoa: ";
	cin >> x.DonGia;
}

void Xuat(HOA x)
{
	cout << "\nMa loai hoa: " << x.MaLoai;
	cout << "\nTen hoa: " << x.TenHoa;
	cout << "\nSo ngay hoa tuoi: " << x.SoNgayHoaTuoi;
	cout << "\nMua thu hoach cua hoa: " << x.MuaThuHoach;
	cout << "\nNhap don gia cua hoa: " << x.DonGia << " dong.";
}

void Nhap(HOA a[], int& n)
{
	cout << "\nNhap so luong hoa cua cua hang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap hoa thu " << i << ": ";
		Nhap(a[i]);
	}
}

void Xuat(HOA a[], int n )
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nHoa " << i << ": ";
		Xuat(a[i]);
		cout << endl;
	}
}

void HoaNhanhHeoNhat(HOA a[], int n)
{
	HOA lc = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i].SoNgayHoaTuoi < lc.SoNgayHoaTuoi)
			lc = a[i];
	}
	Xuat(lc);
}

float TongDonGia(HOA a[], int n)
{
	float S = 0;
	for (int i = 0; i < n; i++)
	{
		S = S + a[i].DonGia;
	}
	return S;
}

void HoanVi(HOA& b, HOA& k)
{
	HOA temp = b;
	b = k;
	k = temp;
}

void SapGiam(HOA a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].DonGia < a[j].DonGia)
				HoanVi(a[i], a[j]);
}