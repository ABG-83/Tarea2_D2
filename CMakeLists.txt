cmake_minimum_required(VERSION 3.10)


project(Tarea2_D2)


set(CMAKE_CXX_STANDARD 11)

# inclusion de las carpetas
include_directories(includeAlg Graficas)

# Busca las librerías y paquetes de GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(CAIRO REQUIRED cairo)

# Incluye los directorios de GTK y Cairo
include_directories(${GTK3_INCLUDE_DIRS} ${CAIRO_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS} ${CAIRO_LIBRARY_DIRS})

# Ignora los warnings de GTK si es necesario
add_definitions(${GTK3_CFLAGS_OTHER})

# Agrega el ejecutable, asegurándote de incluir solo una vez cada archivo relevante
add_executable(TareaExtraclase2
        main.cpp
        Algoritmos/bubbleSort.cpp
        Algoritmos/BST.cpp
        Graficas/graficas.h
        Algoritmos/mergeSort.cpp
        Algoritmos/SelectionSort.cpp
        Algoritmos/AllSortedLinkedList.cpp
)

# Vincula las librerías de GTK y Cairo al proyecto
target_link_libraries(TareaExtraclase2 ${GTK3_LIBRARIES} ${CAIRO_LIBRARIES})
