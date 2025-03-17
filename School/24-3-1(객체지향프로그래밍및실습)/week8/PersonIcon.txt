import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;

public class PersonIcon extends JPanel {

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setColor(new Color(135, 206, 235));
        g2d.setStroke(new BasicStroke(5.0f));
        int centerX = getWidth() / 2;
        int centerY = getHeight() / 2;

        int headRadius = 60;
        Ellipse2D head = new Ellipse2D.Double(centerX - headRadius, centerY - headRadius - 160, headRadius * 2, headRadius * 2);
        g2d.draw(head);

        Line2D body = new Line2D.Double(centerX, centerY-100, centerX, centerY+100);
        g2d.draw(body);

        Line2D leftArm = new Line2D.Double(centerX, centerY-60, centerX - 150, centerY-60);
        Line2D rightArm = new Line2D.Double(centerX, centerY-60, centerX + 150, centerY-60);
        g2d.draw(leftArm);
        g2d.draw(rightArm);

        Line2D leftLeg = new Line2D.Double(centerX , centerY + 100, centerX - 80, centerY + 250);
        Line2D rightLeg = new Line2D.Double(centerX, centerY + 100, centerX + 80, centerY + 250);
        g2d.draw(leftLeg);
        g2d.draw(rightLeg);
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Person Icon");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 800);
        frame.add(new PersonIcon());
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}