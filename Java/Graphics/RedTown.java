import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class RedTown extends JFrame {
    public static void main(String[] args) {
        new RedTown();
    }

    public RedTown()
    {
        super("RedTown");
        createUI();
        setVisible(true);
    }

    protected void createUI()
    {
        setSize(400, 400);
        setLocation(100, 100);
        getContentPane().setLayout(new GridBagLayout());

        JButton colorButton = new JButton("Choose a color...");
        getContentPane().add(colorButton);
        
        colorButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent ae)
            {
                Color c = JColorChooser.showDialog(RedTown.this, 
                    "Choose a color...", getBackground());
                if (c != null) getContentPane().setBackground(c);
            }
        });

        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent we)
            {
                System.exit(0);
            }
        });
    }
}
