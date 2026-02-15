# Google Test Setup e Configurazione

# Per utilizzare Google Test nel tuo progetto, assicurati di avere il pacchetto Google Test scaricato e disponibile nel tuo sistema.

# Aggiungi il percorso di Google Test alle variabili di inclusione e di libreria. Questo permette di compilare e linkare correttamente le unità di test.

# Includi il modulo di Google Test nel tuo progetto.
include_directories(${GTEST_INCLUDE_DIRS})

# Crea un obiettivo per eseguire i test.
add_executable(runUnitTests ${TEST_SOURCES})

# Associa Google Test all'obiettivo di test creato.
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)