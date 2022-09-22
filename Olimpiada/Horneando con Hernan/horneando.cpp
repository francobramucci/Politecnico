void alarma();

int x;

void inicializar(int temperaturaMaxima) {
    x = temperaturaMaxima;
}

void cambiarTemperatura(int nuevaTemperatura) {
    if(nuevaTemperatura > x) alarma();
}
