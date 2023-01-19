class Cono extends Solido {
    double raggio;
    double altezza;

    Cono(double raggio, double altezza, double pesoSpecifico) {
        this.raggio = raggio;
        this.altezza = altezza;
        this.pesoSpecifico = pesoSpecifico;
    }

    @Override
    double volume() {
        return Math.PI * Math.pow(raggio, 2) * (altezza / 3);
    }

    @Override
    double superficie() {
        double generatrice = Math.sqrt(Math.pow(raggio, 2) + Math.pow(altezza, 2));
        return Math.PI * raggio * (raggio + generatrice);
    }
}
