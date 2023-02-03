public class TestArray {
    /*Create a TestArray program to insert into an array instances of the classes. You have to
declare the following array:
Animal[] farm = new Animal[n];
where n is a number inputted by the user.
Every time you insert a new item into the array farm, show all items to test polymorphism. */

    public static void main(String[] args) {
        int n = 5;
        Animal[] farm = new Animal[n];
        farm[0] = new Fish();
        farm[1] = new Cat("Spampa");
        farm[2] = new Fish();
        farm[3] = new Spider();
        farm[4] = new Cat();
        for (int i = 0; i < n; i++) {
            farm[i].eat();
            farm[i].walk();
        }
    }
}
