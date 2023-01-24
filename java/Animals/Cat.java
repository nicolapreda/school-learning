class Cat extends Animal implements Pet {
    private String name;

    public Cat(String name) {
        super(4);
        this.name = name;
    }

    public Cat() {
        this("");
    }

    @Override
    public void play() {
        System.out.println(name + " plays with a toy.");
    }

    @Override
    public void beFriendly() {
        System.out.println(name + " cuddles with its owner.");
    }

    @Override
    public void eat() {
        System.out.println(name + " eats cat food.");
    }
}
