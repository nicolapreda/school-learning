class Cubo extends Solido {
    double lato;

    Cubo(double lato, double pesoSpecifico) {
        this.lato = lato;
        this.pesoSpecifico = pesoSpecifico;
    }

    @Override
    double volume() {
        return lato * lato * lato;
    }

    @Override
    double superficie() {
        return 6 * lato * lato;
    }
}