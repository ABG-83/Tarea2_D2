//
// Created by aldo-bagliano on 16/09/24.
//
#include <cairo.h>
#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

// Función para dibujar el gráfico
void draw_graph(cairo_t *cr, const std::vector<double>& tiempos_mejor, const std::vector<double>& tiempos_promedio, const std::vector<double>& tiempos_peor, const std::vector<size_t>& tamaños, const std::string& algoritmo) {
    // Dibujar el título del gráfico
    cairo_set_source_rgb(cr, 0, 0, 0);  // Color negro para el título
    cairo_move_to(cr, 50, 30);  // Posición del título
    cairo_show_text(cr, algoritmo.c_str());  // Dibujar el nombre del algoritmo

    if (tamaños.size() < 2) {
        std::cout << "No hay suficientes datos para graficar , ponga mas valores de n ." << std::endl;
        return; // No se puede graficar
    }

    // Ajustar el área de la gráfica
    double max_tiempo = std::max({
        *std::max_element(tiempos_mejor.begin(), tiempos_mejor.end()),
        *std::max_element(tiempos_promedio.begin(), tiempos_promedio.end()),
        *std::max_element(tiempos_peor.begin(), tiempos_peor.end())
    });

    if (max_tiempo == 0) {
        std::cout << "Max tiempo es cero, no se puede graficar." << std::endl;
        return; // Evitar división por cero
    }

    double escala_y = 200.0 / max_tiempo;  // Escala vertical
    double escala_x = 400.0 / (tamaños.size() - 1);  // Escala horizontal

    // Dibujar tiempos para el mejor caso (verde)
    cairo_set_source_rgb(cr, 0, 1, 0);  // Verde
    cairo_move_to(cr, 50, 250 - tiempos_mejor[0] * escala_y);
    for (size_t i = 1; i < tamaños.size(); ++i) {
        cairo_line_to(cr, 50 + i * escala_x, 250 - tiempos_mejor[i] * escala_y);
    }
    cairo_stroke(cr);  // Dibujar la línea

    // Dibujar tiempos para el caso promedio (azul)
    cairo_set_source_rgb(cr, 0, 0, 1);  // Azul
    cairo_move_to(cr, 50, 250 - tiempos_promedio[0] * escala_y);
    for (size_t i = 1; i < tamaños.size(); ++i) {
        cairo_line_to(cr, 50 + i * escala_x, 250 - tiempos_promedio[i] * escala_y);
    }
    cairo_stroke(cr);  // Dibujar la línea

    // Dibujar tiempos para el peor caso (rojo)
    cairo_set_source_rgb(cr, 1, 0, 0);  // Rojo
    cairo_move_to(cr, 50, 250 - tiempos_peor[0] * escala_y);
    for (size_t i = 1; i < tamaños.size(); ++i) {
        cairo_line_to(cr, 50 + i * escala_x, 250 - tiempos_peor[i] * escala_y);
    }
    cairo_stroke(cr);  // Dibujar la línea
}

// Estructura para almacenar los parámetros que se pasan al callback
struct GraphData {
    const std::vector<double>* tiempos_mejor;
    const std::vector<double>* tiempos_promedio;
    const std::vector<double>* tiempos_peor;
    const std::vector<size_t>* tamaños;
    std::string algoritmo;
};

// Función de callback para dibujar el gráfico
gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    GraphData* data = static_cast<GraphData*>(user_data);
    draw_graph(cr, *data->tiempos_mejor, *data->tiempos_promedio, *data->tiempos_peor, *data->tamaños, data->algoritmo);
    return FALSE;
}

// Función para generar un gráfico para un algoritmo
void generarGraficoPorAlgoritmo(const std::vector<double>& tiempos_mejor, const std::vector<double>& tiempos_promedio, const std::vector<double>& tiempos_peor, const std::vector<size_t>& tamaños, const std::string& algoritmo) {
    GtkWidget *window;
    GtkWidget *drawing_area;

    // Inicializar GTK
    gtk_init(nullptr, nullptr);

    // Crear la ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), ("Gráfica de " + algoritmo).c_str());
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);

    // Crear el área de dibujo
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 500, 300);
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Crear la estructura para pasar los datos al callback
    GraphData* graph_data = new GraphData{&tiempos_mejor, &tiempos_promedio, &tiempos_peor, &tamaños, algoritmo};

    // Conectar la señal para dibujar el gráfico
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), graph_data);

    // Conectar la señal para cerrar la ventana
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);

    // Mostrar todos los widgets
    gtk_widget_show_all(window);

    // Iniciar el bucle de eventos de GTK
    gtk_main();

    // Liberar la memoria asignada a graph_data
    delete graph_data;
}