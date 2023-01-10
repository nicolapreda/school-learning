import java.util.Date;

public class Main 
{
    public static void main(String[] args) 
    {
        Persona p = new Persona("Rossi", "Mario", new Date(2005, 05, 07));
        System.out.println(p.eta());
    }
}