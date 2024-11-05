#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() 
{
		//socket fonksiyonunun dönüş değerini tutacak bir integer değişken tanımlıyoruz
	int s_socket;
        		/*
			socket fonksiyonun domain argümanını AF_INET ile yani IPV4 ile başlatıyoruz
			
			hangi dosya transfer protokolünü seçeceğimiz ikinci argümanda TCP protokolünü temsil
			eden SOCK_STREAM değerini giriyoruz. Hız değilde güvenlik bizim için daha önemli
			olduğu için TCP seçtik.
		*/
	s_socket = socket(AF_INET, SOCK_STREAM, 0); // AF_INET IPV4 - SOCK_STREAM TCP - Protokol
    if (s_socket == -1) 
	{
        perror("Socket failed!");
        return 1;
    }

    sockaddr_in server_address;
    //burada hangi ağ türünü kullanacağımı belirliyoruz IPV4 seçtik.
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5555);
    server_address.sin_addr.s_addr = inet_addr("192.168.1.1");
    //hangi IP adresleri üzerinden gelecek istemcileri kabul edeceğimizi belirliyoruz. 
	//INADDR_ANY diyerek herhangi bir IP üzerinden gelecek tüm istemcileri kabul edeceğimizi belirttik.
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    close(s_socket);
    return 0;
}