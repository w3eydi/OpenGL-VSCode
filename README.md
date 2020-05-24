# OpenGL-VSCode

Tübitak Ulakbim tarafından geliştirilen Pardus üzerinden OpenGL kulanımını VS Code ile  başlangıç projesi oluşturularak, Türkçe içeriklere ve Pardus 'un yaygınlaştırılmasına katkı sunmak amacıyla hazırlanmıştır.

İçerikler sadece VS Code ortamında kurulum ve başlangıç projesi olarak planlanmıştır. İçeriğin amacı; kurulum kısmı oldukça meşakkatli ve fazla ayar gerektirdiği için video ortamından bağımsız kalıcı bir Türkçe içerik bulunması nedeniyle oluşturulmuştur. OpenGL konusunda ilerlemek için ilham alınan [Kayhan Ayar - Youtube](https://www.youtube.com/playlist?list=PLIM5iw4GHbNW2nleNK5XIvyhZzGiaiBfp) sayfasından **Modern OpenGL Eğitim Serisi** tavsiye edilmektedir. Eğitmen oldukça detaylı ve anlaşılabilecek basitlikte konuyu anlatmaktadır.

---

## Eğitim Başlıkları

Genel eğitim VS Code, Cmake, OpenGL gibi konulara değinmiştir. Detaylı bir başlangıç kurulum eğitimidir.

## 1. VS Code Cmake Kurulumu & Manuel Çalıştırma : [000-Kurulum](https://github.com/w3eydi/OpenGL-VSCode/tree/master/000-Kurulum)
>**Not :** VS Code kurulu değilse; [Pardus forumda mevcut olan bu bağlantıya tıklayarak](https://forum.pardus.org.tr), ulaşabilirsiniz.



## 2. VS Code Cmake Yapılandırma & Otomatik Çalıştırma : [001-OtoÇalıştır](https://github.com/w3eydi/OpenGL-VSCode/tree/master/001-Oto%C3%87al%C4%B1%C5%9Ft%C4%B1r)
Kısayollarıyla birlikte kurulumu **Konsol** ekranında uğraşmadan kalıcı hale getiriliyor. Böylelikle elde edeceğiniz VS Code projesini başka bir bölüme kopyalayarak, temiz bir başlangıç projesi elde edeceksiniz. Üstelik elde edilen bu proje de **Terminal(Konsol)** ekranı üzerinden işlem yapmanıza gerek kalmadan kısayollarla veya bir kaç tıklamayla projenizi derleyebileceksiniz.

>**Not :** VS Code kurulu değilse; [Pardus forumda mevcut olan bu bağlantıya tıklayarak](https://forum.pardus.org.tr), ulaşabilirsiniz.



## 3. VS Code GLFW Kütüphanesi Entegrasyonu : [002-SiyahEkran](https://github.com/w3eydi/OpenGL-VSCode/tree/master/002-SiyahEkran)
**GLFW** işletim sisteminden bağımsız olarak OpenGL 'i kullanacağımız pencereyi oluşturmaya ve girdileri kontrol etmemize yarayan bir kütüphanedir. Programcıya, üzerinde çalışılan işletim sisteminden bağımsız olarak OpenGL ve Vulkan için 'context' ve pencere oluşturma, klavye, fare, oyun çubuğu girdi ve çıktılarını yönetme kolaylığı sağlar. Bütün bunları OpenGL kullanarak da yapabiliriz, fakat her işletim sistemi için ayrı ayrı API 'lerine göre işlem yapmamız gerekecektir. GLFW bizi bundan kurtarır ve programcıların üzerinde çalıştıkları işletim sisteminin özel API 'leriyle cebelleşmesini önler. 



## 4. Glad ve Glm Kütüphaneleri Entegrasyonu : [003-GladveGlm](https://github.com/w3eydi/OpenGL-VSCode/tree/master/003-GladveGlm)

**Glad,** [OpenGL Loading Library](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library#glad_.28Multi-Language_GL.2FGLES.2FEGL.2FGLX.2FWGL_Loader-Generator.29) olarak geçen çeşitli OpenGL fonksiyonlarını çalışma zamanında işaretçilerle sistemimize entegre eden bir kütüphanedir. Bizim kullandığımız işletim sistemindeki OpenGL kütüphanelerine elle ulaşmak yerine Glad kullanarak otomatik bir erişim sağlıyoruz.

**Glm,** çeşitli görselleştirme hesaplamaları yapmamızı sağlayan vektör ve matris kütüphanesidir.

(çalışma devam ediyor.)



## 5. VS Code Üzerinden OpenGL ile Örnek Proje : 002-Başlangıç-Proje
İlk projemizle örnek bir proje oluşturup, faaliyete geçiriyoruz.
(çalışma devam ediyor.)

---

**MIT Lisansı**

Telif Hakkı (Copyright) (c) 2020 Eydi Gözeneli - github.com/w3eydi

>Hiçbir ücret talep edilmeden burada işbu yazılımın bir kopyasını ve belgelendirme dosyalarını (“Yazılım”) elde eden herkese verilen izin; kullanma, kopyalama, değiştirme, birleştirme, yayımlama, dağıtma, alt lisanslama, ve/veya yazılımın kopyalarını satma eylemleri de dahil olmak üzere ve bununla kısıtlama olmaksızın, yazılımın sınırlama olmadan ticaretini yapmak için verilmiş olup, bunları yapmaları için yazılımın sağlandığı kişilere aşağıdakileri yapmak koşuluyla sunulur:

>Yukarıdaki telif hakkı bildirimi ve işbu izin bildirimi yazılımın tüm kopyalarına veya önemli parçalarına eklenmelidir. 

>YAZILIM “HİÇBİR DEĞİŞİKLİK YAPILMADAN” ESASINA BAĞLI OLARAK, TİCARETE ELVERİŞLİLİK, ÖZEL BİR AMACA UYGUNLUK VE İHLAL OLMAMASI DA DAHİL VE BUNUNLA KISITLI OLMAKSIZIN AÇIKÇA VEYA ÜSTÜ KAPALI OLARAK HİÇBİR TEMİNAT OLMAKSIZIN SUNULMUŞTUR. HİÇBİR KOŞULDA YAZARLAR VEYA TELİF HAKKI SAHİPLERİ HERHANGİ BİR İDDİAYA, HASARA VEYA DİĞER YÜKÜMLÜLÜKLERE KARŞI, YAZILIMLA VEYA KULLANIMLA VEYA YAZILIMIN BAŞKA BAĞLANTILARIYLA İLGİLİ, BUNLARDAN KAYNAKLANAN VE BUNLARIN SONUCU BİR SÖZLEŞME DAVASI, HAKSIZ FİİL VEYA DİĞER EYLEMLERDEN SORUMLU DEĞİLDİR.
