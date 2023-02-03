public class TestAnimals {
   

    public static void main(String[] args) {
        Fish d = new Fish();
        Cat c = new Cat("Spampa");
        Animal a = new Fish();
        Animal e = new Spider();
        Pet p = new Cat();
        
        System.out.println("Fish:");
        d.eat();
        d.walk();
        System.out.println("Cat:");
        c.eat();
        c.walk();
        System.out.println("Animal:");
        a.eat();
        a.walk();
        System.out.println("Spider:");
        e.eat();
        e.walk();
        System.out.println("Pet:");
        p.play();
        p.setName("Spampa");
        System.out.println(p.getName());
    }
}
