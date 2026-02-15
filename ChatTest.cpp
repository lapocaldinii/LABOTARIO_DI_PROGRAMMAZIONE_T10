// Test di ChatTest.cpp

// Test del costruttore della classe Chat
void testCostruttore() {
    Chat c;
    // Verifica che il numero di messaggi inizialmente sia 0
    assert(c.getMessaggi().size() == 0);
}

// Test dell'aggiunta di un messaggio
void testAggiungiMessaggio() {
    Chat c;
    c.aggiungiMessaggio("Ciao!");
    // Verifica che il numero di messaggi ora sia 1
    assert(c.getMessaggi().size() == 1);
    // Verifica che il messaggio aggiunto è corretto
    assert(c.getMessaggi()[0] == "Ciao!");
}

// Test della rimozione di un messaggio
void testRimuoviMessaggio() {
    Chat c;
    c.aggiungiMessaggio("Ciao!");
    c.rimuoviMessaggio(0);
    // Verifica che il numero di messaggi sia 0 dopo la rimozione
    assert(c.getMessaggi().size() == 0);
}

// Test della ritorna di tutti i messaggi
void testGetMessaggi() {
    Chat c;
    c.aggiungiMessaggio("Ciao!");
    c.aggiungiMessaggio("Come va?");
    // Verifica che il numero totale di messaggi sia 2
    assert(c.getMessaggi().size() == 2);
    // Verifica che i messaggi siano corretti
    assert(c.getMessaggi()[0] == "Ciao!");
    assert(c.getMessaggi()[1] == "Come va?");
}