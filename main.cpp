#include <iostream>
#include <unistd.h>
#include <cstring>
#include <ifaddrs.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/utsname.h>
#include <cstdlib>

using namespace std;

void obtener_direccion_ip() {
    struct ifaddrs *ifaddr, *ifa;
    int family;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == nullptr) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, nullptr, 0, NI_NUMERICHOST);
            cout << "Interfaz: " << ifa->ifa_name << " Dirección IP: " << host << endl;
        }
    }

    freeifaddrs(ifaddr);
}

void obtener_nombre_host() {
    char hostname[NI_MAXHOST];
    if (gethostname(hostname, NI_MAXHOST) == 0) {
        cout << "Nombre de host: " << hostname << endl;
    } else {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
}

void verificar_conectividad_google() {
    cout << "Verificando conectividad con google.es..." << endl;
    int result = system("ping -c 4 google.es");
    if (result == 0) {
        cout << "Conectividad con google.es exitosa" << endl;
    } else {
        cout << "Conectividad con google.es fallida" << endl;
    }
}

void abrir_wireshark() {
    cout << "Abriendo Wireshark..." << endl;
    system("wireshark &");
}

void usar_tcpdump_icmp_arp() {
    cout << "Usando TCPDUMP para ICMP y ARP..." << endl;
    system("sudo tcpdump -i any 'icmp or arp' -c 10");
}

void verificar_version_kernel() {
    cout << "Verificando versión del kernel..." << endl;
    system("uname -r");
}

int main() {
    obtener_direccion_ip();
           system("sleep(1)");

    obtener_nombre_host();
           system("sleep(1)");

    verificar_conectividad_google();
           system("sleep(1)");

    abrir_wireshark();
         system("sleep(1)");
  
    usar_tcpdump_icmp_arp();
         system("sleep(1)");
  
    verificar_version_kernel();
       system("sleep(1)");

    return 0;
}


