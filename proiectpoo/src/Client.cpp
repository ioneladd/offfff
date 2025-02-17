#include "Client.h"
Client::Client() {
    // Constructor implicit
}

bool Client::autentificare(const string& username, const string& password) {
    for (const auto& client : dateClienti) {
        if (client.username == username && client.password == password) {
            return true;
        }
    }
    return false;
}

bool Client::incarcaDateleDinFisier(const string& numeFisier) {
    ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fisierului: " << numeFisier << endl;
        return false;
    }

    string username, password;
    while (fisier >> username >> password) {
        dateClienti.push_back({username, password});
    }

    fisier.close();
    return true;
}
bool Client::adaugaClient(const string& username, const string& password) {
    dateClienti.push_back({username, password});
    ofstream fisier("Clienti.txt");
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fisierului pentru scriere: " << "Clienti.txt" << endl;
        return false;
    }

    for (const auto& client : dateClienti) {
        fisier << client.username << " " << client.password << endl;
    }

    fisier.close();
    return true;
}



