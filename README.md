Park.Me!
=================

This repository is used for Online Progress Reporting of IoT Academy in Compfest 8 and managed by The-ex.org

### List of Member
1. Hedy Pamungkas as `Backend Developer`
2. Mukmin as `Hardware Developer`
3. Rizky Novriansyah as `Android Developer`

### Progress Report `08/08/2016`
1. Telah mendapatkan library yg akan digunakan dalam project ini yang telah disesuaikan dari board yang akan digunakan yaitu RF24 (bisa di download disini `https://github.com/maniacbug/RF24`) yang digunakan untuk komunikasi secara wireless antara node client dengan hub menggunakan nRF24l01 dan protokol mqtt + ethernet (bisa di download disini `https://github.com/knolleary/pubsubclient`) yang digunakan untuk mengirimkan data sensor ke server / mqtt broker yang selanjutnya data tersebut akan di proses sehingga mendapakatan keputusan yang tepat
2. Telah menguji library menggunakan contoh file yang diberikan dan berjalan sesuai dengan yang ditentukan baik library RF24 maupun mqtt + ethernet
3. Telah membuat rangkaian skematik untuk semua device pendukung Park.Me! baik dari sisi node client maupun hub, dimana node client ini kita menggunakan board Arduino Nano dikarenakan membutuhkan board yang tidak terlalu besar yang fungsinya akan melakukan collecting sekaligus mengirimkan data sensor kepada hub untuk selanjutnya dikirimkan ke server / mqtt broker. Pada hub, kita menggunakan board Intel Galileo Gen 1 dikarenakan membutuhkan board yang reliable untuk menghandle jumlah node client yang cukup banyak dan juga memiliki fitur untuk konektivitasnya yakni menggunakan ethernet
4. Telah mengimplementasikan beberapa mockup UI/UX dari aplikasi android menggunakan Android Studio IDE

### Progress Report `19/08/2016`
soon

### Progress Report `26/08/2016`
soon

### Progress Report `02/09/2016`
soon

### Progress Report `09/09/2016`
soon

### Progress Report `16/09/2016`
soon

### License

This software is licensed under the MIT License.

Copyright Hedy Pamungkas, 2016.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
