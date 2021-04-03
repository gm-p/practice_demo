import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.Random;


public class Egg {
	int row, col;
	int w = Yard.BLOCK_SIZE;
	int h = Yard.BLOCK_SIZE;
	private static Random r = new Random();
	private Color color = Color.GREEN;

	public Egg(int row, int col) {
		this.row = row;
		this.col = col;
	}
	
	public Egg() {
		this(r.nextInt(Yard.ROWS-2)+2, r.nextInt(Yard.COLS));
	}

	public int getRow() {
		return row;
	}

	public void setRow(int row) {
		this.row = row;
	}

	public int getCol() {
		return col;
	}

	public void setCol(int col) {
		this.col = col;
	}
	
	public void draw(Graphics g) {
		Color c = g.getColor();
		g.setColor(color);
		g.fillOval(col*Yard.BLOCK_SIZE, row*Yard.BLOCK_SIZE, w, h);
		g.setColor(c);
		if(color == Color.GREEN)
			color = Color.RED;
		else
			color = Color.GREEN;
	}
	
	public Rectangle getRect() {
		return new Rectangle(col*Yard.BLOCK_SIZE, row*Yard.BLOCK_SIZE, w, h);
	}
	
	public void reAppear() {
		row = r.nextInt(Yard.ROWS-2)+2;
		col = r.nextInt(Yard.COLS);
	}
	
}
