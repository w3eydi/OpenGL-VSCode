# VS Code Cmake Yapılandırma & Otomatik Çalıştırma

Bu bölümde ilk bölümün devamı olarak VS Code da Cmake yapılandırma ayarlarını göreceğiz. Bu şekilde VS Code ortamımızı artık **konsol(terminal)** ekranında tek tek kod yazıp, derlemek yerine bir kaç tıklamayla da tüm işi yapabilir hale getireceğiz.
>**Not :** VS Code kurulu değilse; [Pardus forumda mevcut olan bu bağlantıya tıklayarak](https://forum.pardus.org.tr), ulaşabilirsiniz.

## Eğitim İçeriği

Eğitimimizde VS Code ile bağlantı kurmamızı ve yapılandırmamızı sağlayan **`.json`** dosyalarını ele alacağız.

---

## Configure Tasks (Görev Oluşturma ve Yapılandırma)

**Cmake** otomatik çalıştırılması için VS Code Tasks sistemini kullanacağız. Bunun için; **VS Code** üst menüsünde **`Terminal --> Configure Tasks...`** seçeneğini seçtikten sonra, **`Create tasks.json file from template`** ile devam ediyoruz. Karşımıza çıkan ekranda **`Other ...`** ile başlayan seçeneği seçiyoruz.

![](images/others.png)

Muhtemelen karşınıza aşağıdaki kodlar gelecektir. Detaylı bir şekilde bilgi almak için belirtilen Microsoft 'un kaynağına gidebilirsiniz.

```json

{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "echo",
            "type": "shell",
            "command": "echo Hello"
        }
    ]
}

```

Şimdi dosyamızı aşağıdaki gibi değiştirelim.

```json

{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Cmake",
            "type": "shell",
            "command": "cmake",
            "options": {
                "cwd": "${workspaceFolder}/../BuildKlasor"
            },
            "args": [ 
                "${workspaceFolder}"
            ],
            "group":{
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}

```

Böylelikle ilk görevimizi eklemiş olduk. **`Terminal --> Run Task...`** seçeneğini seçtiğimizde task menüsünde **`CMake`** isimli oluşturduğumuz taskı görebiliyoruz. **Build** türünde bir task olduğu için <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd> ile de **`Terminal --> Run Build Task...`** görevini kısayoldan çalıştırmış oluruz.
>**Not :** `"cwd": değişkenine çıktıyı çalıştığımız klasörün üstündeki klasörde "BuildKlasor" şeklinde yol belirttik. Şu anki haliyle bu klasörü siz oluşturmazsanız hata alırsınız. Bunu da şimdi geliştirerek, bu hatayı gidermekden bahsedeceğiz.

![](images/run-task.png)

![](images/run-task-sonuc.png)

Öncelikle **Cmake** taskımıza ön tanımlı olacak şekilde task tanımlıyoruz. Bu önce bu taskı çalıştır, bittikten sonra Cmake 'i çalıştır anlamına geliyor. Bunun için Cmake dizisi içerisindeki son tanımdan sonra **,(virgül)** koyup, **"dependsOn":** değişkenini ekliyoruz. Ön tanımlı oluşturulacak taskın ismini belirtiyoruz.

```json

"dependsOn":[
                "BuildKlasorOlustur"
]

```

Harika! Sıra taskımızı eklemeye geldi. "tasks": dizi içerisinde **Cmake** taskından sonrada ,(virgül) ile ayırıp, süslü parantezler açıp, içerisine yeni taskımızı tanımlamaya başlıyoruz.

```json

"label": "BuildKlasorOlustur"
...
...

```

type, command gibi değerleri tanımladıktan sonra yeni taskımızla birlikte **tasks.json** dosyamızın son hali şu şekilde olmalıdır.

```json

{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Cmake",
            "type": "shell",
            "command": "cmake",
            "options": {
                "cwd": "${workspaceFolder}/../BuildKlasor"
            },
            "args": [ 
                "${workspaceFolder}"
            ],
            "group":{
                "kind": "build",
                "isDefault": true
            },
            "dependsOn":[
                "BuildKlasorOlustur"
            ]
        },
        {
            "label": "BuildKlasorOlustur",
            "type": "shell",
            "command": "mkdir",
            "options": {
                "cwd": "${workspaceFolder}/.."
            },
            "args": [
                "-p", 
                "BuildKlasor"
            ]
        }
    ]
}

```

Dikkat edilmesi gereken husus, `"args":` değişkenine `"-p"` değerini vermeseydik, ilk çalışmada sorun olmasa da ikinci ve diğer çalışmalarımızda **mkdir** komutu hata döndürecekti. Çünkü; "BuildKlasor" isimli dizini bir kere oluşturduktan sonra üstüne yazmaz. O nedenle hata alırız ve Cmake taskımızda ön tanımlı task çalışmadığından dolayı herhangi bir işlem gerçekleşmez. İşte bunu engellemek için `"-p"` parametresini kullanıyoruz.




`main.cpp` dosyası içeriği : (**Not :** Son hali değildir. Aşama aşama anlatılmak istenmiştir.)

```c
#include <iostream>

#include "kutuphane.hpp"

int main(int argc, char** argv){

    std::cout << topla(10,20) << std::endl;


    std::cin.get();
}
```

**VS Code** bir metin editörüdür. IDE gibi davranması için çeşitli eklentileri kurmamız gerekiyor. En başta [Pardus Forumda oluşturduğum konudan](forum.pardus.org.tr) Türkçe VS Code **`C/C++`** eklentisini kurmuş olmalıydınız. Soldaki eklentiler menüsünden `Extensions` veya <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>X</kbd> kısayoluyla açabilirsiniz.

![](images/extensions.png)

Tabi; **`Cmake`** diye aratıp, Cmake eklentilerini de kurmalıyız. Ayrıca; yine Microsoft 'un geliştirmeyi devraldığı **`Cmake Tools`** eklentisini de kurmalısınız. Kurulum bittiğinde otomatik olarak yapılandırma seçeneği çıkmaktadır. Dilerseniz bu kısayol yöntemiyle yapılandırabilirsiniz. Biz şimdilik uzun yolu tercih edip, mantığını anlamaya çalışacağız.

![](images/cmake.png)

**Cmake,** projemizi istediğimiz platformda derlenebilecek hale getirmeye yarayan bir araçtır. Bunu yapabilmesi için projemizde kullandığımız dosyaları ona tanıtmamız gerekiyor. Yani; bazı bilgilere sahip olması gerekiyor. Hangi dosyaların dahil olduğu, hangi kütüphaneleri projemize dahil edeceğimizi önceden Cmake 'e bildiriyoruz. Bunun için **`CMakeLists.txt`** isimli bir dosyayı ana dizinde oluşturuyoruz.

İlk olarak Cmake versiyonunu belirtiyoruz.

```cmake
cmake_minimum_required(VERSION 2.8)
```

Daha sonra projenin çıktı olarak oluşturulacağı ismi giriyoruz.

```cmake
project(OpenGLCMakeBuild)
```

Şimdi Cmake 'e proje dizin yollarını ve dahil olan dosyaları ekliyoruz. `${CMAKE_SOURCE_DIR}` ile proje yolunu belirtsede, `set()` fonksiyonuyla kendi değişkenimizi oluşturup, `PROJECT_DIR` ismine atıyoruz. Böylece daha temiz ve karmaşıklığa yol açmadan bu değişken ismi üzerinden diğer değişkenlerimizi de oluşturuyoruz.

```cmake
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/kutuphane.cpp)

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/kutuphane.hpp)
```

Son olarak projemizdeki kütüphaneleri ve yürütülebilen dosyaları sisteme ekliyoruz. Buradaki `${PROJECT_NAME}` aslında yukarıda `cmake project(OpenGLCMakeBuild)` koduyla oluşturduğumuz proje ismidir.

```cmake
include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
```

---

## Cmake İle Projeyi Çalıştırma

**VS Code** içerisinden Kurulum dosyasındaki boş alanda fare ile sağ tıklayarak **Open in Terminal** ile yapabileceğimiz gibi ilgili klasörde de **Uçbirimde aç** seçeneğiyle de konsol ekranına ulaşabiliriz. Konsol ekranına ulaştıktan sonra bir sonraki bölümde dış bir klasöre aktaracak olsakda bu ders kapsamında deneme yapmamız için **`build`** isimli bir klasör oluşturuyoruz.

```bash
mkdir build
cd build
```

Şimdi sıra inşa işlemine geldi. Bir üstteki klasördeki `CMakeLists.txt` dosyasını kullanabilmek için konsolda **`cmake ..`** komutunu çalıştırıyoruz. Bu sayede cmake bizim bulunduğumuz klasöre **`make`** komutuyla sistemimize uygun çalışan dosyaları elde edebileceğimiz inşa işlemine başlayacaktır.

![](images/cmake-build.png)

Bulunduğumuz `build` klasörünü **`ls`** komutuyla kontrol ettiğimizde derleme yapabileceğimiz **`Makefile`** 'ın oluştuğunu görüyoruz. `make` komutuyla çalıştırılabilir dosyamızı oluşturuyoruz. Dosyamızı çalıştırarak fonksiyon sonucunun döndüğünü konsol ekranından görebiliriz. Sırada bu işlemleri VS Code ile konsola bulaşmadan otomatik hale getirmeyi ve devamında çalışmaya OpenGL entegrasyonu göreceğiz.

![](images/make-run.png)

---

**MIT Lisansı**

[Telif Hakkı](https://github.com/w3eydi/OpenGL-VSCode/blob/master/LICENSE) (Copyright) (c) 2020 Eydi Gözeneli - github.com/w3eydi
