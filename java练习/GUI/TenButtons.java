import java.awt.*;

import javax.swing.border.Border;

public class TenButtons {
	/*public static void main(String[] args) {
		Frame f = new Frame("Java Frame");
		Panel pn = new Panel();
		Panel ps = new Panel();
		f.add(pn, BorderLayout.NORTH);
		f.add(ps, BorderLayout.SOUTH);
		Button b1 = new Button("BUTTON");
		Panel pn1 = new Panel();
		Button b2 = new Button("BUTTON");
		Button b3 = new Button("BUTTON");
		pn1.setLayout(new GridLayout(2, 1));
		pn1.add(b2);
		pn1.add(b3);
		Button b4 = new Button("BUTTON");
		pn.setLayout(new GridLayout(1, 3));
		pn.add(b1);
		pn.add(pn1);
		pn.add(b4);
		Button b5 = new Button("BUTTON");
		Panel ps1 = new Panel();
		ps1.setLayout(new GridLayout(2, 2));
		for(int i=0; i<4; i++)
			ps1.add(new Button("BUTTON"));
		Button b10 = new Button("BUTTON");
		ps.setLayout(new GridLayout(1, 3));
		ps.add(b5);
		ps.add(ps1);
		ps.add(b10);
		f.pack();
		f.setVisible(true);
	}*/
	
	public static void main(String[] args) {
		Frame f = new Frame("Java Frame");
		f.setLayout(new GridLayout(2, 1));
		f.setLocation(300, 400);
		f.setSize(300, 200);
		f.setBackground(new Color(204, 204, 255));
		Panel p1 = new Panel(new BorderLayout());
		Panel p2 = new Panel(new BorderLayout());
		Panel p11 = new Panel(new GridLayout(2, 1));
		Panel p21 = new Panel(new GridLayout(2, 2));
		p11.add(new Button("BUTTON"));
		p11.add(new Button("BUTTON"));
		p1.add(new Button("BUTTON"), BorderLayout.WEST);
		p1.add(p11, BorderLayout.CENTER);
		p1.add(new Button("BUTTON"), BorderLayout.EAST);
		
		for(int i=0; i<4; i++)
			p21.add(new Button("BUTTON"));
		p2.add(new Button("BUTTON"), BorderLayout.WEST);
		p2.add(p21, BorderLayout.CENTER);
		p2.add(new Button("BUTTON"), BorderLayout.EAST);
		
		f.add(p1);
		f.add(p2);
		f.setVisible(true);
	}
}