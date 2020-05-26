#include <iostream>

#include <glad/glad.h> // Glad GLFW 'in üstünde dahil edildi.

#include <GLFW/glfw3.h> // GLFW Kutuphane dosyamızı dahil ettik.

#include <glm/mat4x4.hpp> // Kullanmak istediğimiz kütüphaneyi seçebiliriz.

#include "kutuphane.hpp"

int main(int argc, char** argv){

    if(!glfwInit())  // glfw yüklenmesi sağlanıyor. Yüklenmezse programın çalışmasına
        return -1;   // gerek kalmayacak.

    // Pencere oluşturuluyor.
    GLFWwindow* window = glfwCreateWindow(800,600,"İlk GLFW Penceresi",NULL,NULL);

    if(window == NULL){
        std::cout << "Pencere oluşturulamadı!" << std::endl;

        glfwTerminate(); // Kaynakları serbest bırak.

        return -1; // main 'i durdur.
    }

    glfwMakeContextCurrent(window); // OpenGL 'i kullanacağımız pencereyi bağlıyoruz.

    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window); // OpenGL çizimlerini pencereye aktarmayı sağlıyor.

        glfwPollEvents(); // Klavye veya fare tıklanması gibi olayları aktarıyor.
    }
    
}