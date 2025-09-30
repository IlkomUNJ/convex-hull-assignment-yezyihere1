[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/1PRAkQnI)
# Identity
Name : Raja Nazwa Anugerah Pratama

# AI usage
What kind of AI are you using : Saya menggunakan Google Gemini (Large Language Model).

Explain how you use the AI to solve the assignment:
Saya menggunakan AI sebagai asisten scaffolding dan validasi struktur User Interface dalam lingkungan pengembangan Qt. Penggunaan AI secara spesifik hanya meliputi aspek UI/Framework yang berfungsi sebagai kerangka aplikasi:
1.Struktur dan Layout: Memperoleh panduan kode untuk membangun hierarki UI (QMainWindow/QVBoxLayout) yang memisahkan kanvas dan tombol dengan benar sesuai dengan diagram tugas.
2.Event Handling: Mendapatkan template kode untuk penanganan input mouse pada kanvas dan koneksi signal-slot tombol.
3.Validasi Fungsi Framework: Memeriksa function signature yang diperlukan untuk menjembatani class UI dengan class algoritma.
4.Debugging Visual: Menyelesaikan masalah warna latar belakang kanvas yang muncul hitam karena tema gelap sistem.

Used Queries (Fokus pada UI dan Scaffolding):
1.Bagaimana cara merancang struktur UI Qt yang paling optimal (dengan QMainWindow, QWidget, dan Layouts) untuk membagi area gambar dan area tombol sesuai
2.Tolong jelaskan base class yang paling tepat untuk MainWindow, DrawingWidget, dan class khusus algoritma (ConvexHull)."
3.Mengapa rendering latar belakang kanvas saya menjadi hitam? Bagaimana cara menerapkan fixed white background secara paksa menggunakan QPalette di konstruktor DrawingWidget?
4.Saya perlu membuat kerangka kode untuk DrawingWidget yang bisa mengimplementasikan event klik mouse untuk menangkap input koordinat dan menggambar titik-titik tersebut.

# Collaboration usage
Self Taught (Saya mengerjakan tugas ini secara mandiri).

Explain how you are using others to complete the assignment in this section:
Saya tidak berkolaborasi dengan individu lain. Semua bantuan eksternal yang saya terima berasal dari alat kecerdasan buatan (AI) Gemini, yang saya gunakan sebagai referensi scaffolding Qt.

Saya menggunakan template kode yang dihasilkan AI hanya sebagai kerangka dasar (boilerplate) untuk setup UI (learn the ideas). Namun, implementasi logika inti dan semua optimasi algoritma untuk Slow Convex Hull dan Fast Convex Hull, termasuk penentuan di mana variabel iterations harus dihitung, sepenuhnya saya kembangkan secara mandiri berdasarkan pemahaman saya

# Commit Rules
Use .gitignore to stripe any binaries from the resulting build before commit.  If you cloned directly from the template, you are safe. 

# Due Time
September 30th, 2025. 23: 59 WIB
