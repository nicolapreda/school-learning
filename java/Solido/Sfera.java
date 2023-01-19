class Sfera extends Solido {
    double raggio;

    Sfera(double raggio, double pesoSpecifico) {
        this.raggio = raggio;
        this.pesoSpecifico = pesoSpecifico;
    }

    @Override
    double volume() {
        return (4.0 / 3.0) * Math.PI * Math.pow(raggio, 3);
    }

    @Override
    double superficie() {
        return 4 * Math.PI * Math.pow(raggio, 2);
    }
}