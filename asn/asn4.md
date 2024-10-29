# UTS ALPRO

Projek Opsional TA 2024/2025 - Mata Kuliah Algoritma dan Pemograman

Buatlah sebuah program yang berfungsi sebagai simulasi mesin ATM untuk melakukan setoran dan penarikan data. Di program tersebut terdapat beberapa menu yaitu:
1. Daftar Nasabah
2. Setor Uang
3. Tarik Uang
4. Lihat Data Nasabah dan Saldo
5. Lihat Riwayat Setor dan Tarik

Ketentuan yang perlu diperthatikan dalam membuat setiap menu:

**1. Daftar Nasabah**
- Hanya bisa memasukkan data 1 nasabah saja

**2. Alur Setor Uang**
- Nasabah memasukkan pin*
- Nasabah memasukkan jumlah uang yang disetor
- Jumlah uang yang disetor akan bertambah ke saldo nasabah
- Jumlah yang yang disetor disimpan (maksimum 100 kali setor)

**3. Alur Tarik Uang**
- Nasabah memasukkan pin*
- Nasabah memasukkan jumlah uang yang akan ditarik**
- Jumlah uang yang ditarik akan mengurangi saldo nasabah
- Jumlah uang yang ditarik disimpan (maksimum 100 kali tarik)

**4. Lihat Data Nasabah dan Saldo**
- Menampilkan informasi data nasabah disertai dengan saldo nasabah saat ini

**5. Lihat Riwayat Setor dan Tarik**
- Menampilkan list setoran dan penarikan yang sudah dilakukan nasabah

Ketentuan umum yang perlu diperhatikan:

***) PIN**
- Nasabah mempunyai kesempatan 3 kali kesalahan memasukkan pin.
- Jika 3 kali salah, maka data nasabah akan diblokir.
- Jika data nasabah diblokir, nasabah tidak bisa mengakses menu setor dan menu tarik
- Jika data nasabah diblokir, nasabah tetap bisa mengakses menu lihat saldo dan lihat riwayat
- Untuk bisa melakukan setor dan tarik, nasabah perlu mendaftarkan ulang dan riwayat setor tarik sebelumnya akan terhapus

****) Jumlah Uang yang Akan Ditarik**
- Jumlah uang yang bisa ditarik tidak bisa melebihi saldo

Happy Coding!
