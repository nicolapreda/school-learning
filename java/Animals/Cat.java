//implements implementa l'interfaccia che serve per dare delle regole alle classi che lo implementano

class Cat extends Animal implements Pet {
    private String name;

    public Cat(String name) {
        //per chiamare il costruttore della superclasse
        super(4);
        super.legs = 4;
        this.name = name;
    }

    public Cat() {
        this("");
    }

    public void eat() {
        System.out.println("Il gatto sta mangiando.");
    }
    public String play() {
        return "Il gatto sta giocando.";
    }
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
}
