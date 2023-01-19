abstract class Solido {
    double pesoSpecifico;

    abstract double volume();
    abstract double superficie();

    double peso() {
        return pesoSpecifico * volume();
    }
}