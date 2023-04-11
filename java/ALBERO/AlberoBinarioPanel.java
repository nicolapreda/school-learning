import java.awt.*;
import javax.swing.*;

public class AlberoBinarioPanel extends JPanel {
    
    private AlberoBinario albero;
    private int raggioNodo = 20;
    private int distanzaOrizzontale = 80;
    private int distanzaVerticale = 50;
    
    public AlberoBinarioPanel(AlberoBinario albero,int W, int H) {
        this.albero = albero;
        this.distanzaOrizzontale=W/4;
        this.distanzaVerticale=H/4;

    }
    




    @Override
    protected void paintComponent(Graphics g) {

        super.paintComponent(g);

        disegnaNodo(g, albero.getRadice(), getWidth() / 2, 20, distanzaOrizzontale);
    }
    
    private void disegnaNodo(Graphics g, NodoAlbero nodo, int x, int y, int d) {
        g.setColor(new Color(0,0,255));
        g.drawOval(x - raggioNodo, y - raggioNodo, 2 * raggioNodo, 2 * raggioNodo);
        g.setColor(new Color(0,0,0));
        g.drawString(Integer.toString(nodo.getValore()), x - 6, y + 5);
        
        if (nodo.getSinistro() != null) {
            int xSinistro = x - d ;
            int ySinistro = y + distanzaVerticale ;
            g.setColor(new Color(255,0,0));
            g.drawLine(x-raggioNodo, y, xSinistro+ raggioNodo*2/3, ySinistro- raggioNodo*2/3);
            disegnaNodo(g, nodo.getSinistro(), xSinistro, ySinistro, d/2);
        }
        
        if (nodo.getDestro() != null) {
            int xDestro = x + d ;
            int yDestro = y + distanzaVerticale ;
            g.setColor(new Color(0,0,0));
            g.drawLine(x+raggioNodo, y, xDestro- raggioNodo*2/3, yDestro- raggioNodo*2/3);
            disegnaNodo(g, nodo.getDestro(), xDestro, yDestro, d / 2);
        }
    }
}