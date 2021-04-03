import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;


public class Snake {
	private Node head = null;
	private Node tail = null;
	private int size = 0;
	Yard y = null;
	
	Node n = new Node(20, 30, Dir.L);
	
	public Snake(Yard y) {
		head = n;
		tail = n;
		size = 1;
		this.y = y;
	}
	
	public void addToTail() {
		Node n = null;
		switch(tail.dir) {
		case L:
			n = new Node(tail.row, tail.col+1, tail.dir);
			break;
		case R:
			n = new Node(tail.row, tail.col-1, tail.dir);
			break;
		case U:
			n = new Node(tail.row+1, tail.col, tail.dir);
		case D:
			n = new Node(tail.row-1, tail.col, tail.dir);
			break;
		}
		tail.next = n;
		n.prev = tail;
		tail = n;
		size++;
	}
	
	public void addToHead() {
		Node n = null;
		switch(head.dir) {
		case L:
			n = new Node(head.row, head.col-1, head.dir);
			break;
		case R:
			n = new Node(head.row, head.col+1, head.dir);
			break;
		case U:
			n = new Node(head.row-1, head.col, head.dir);
			break;
		case D:
			n = new Node(head.row+1, head.col, head.dir);
			break;
		}
		n.next = head;
		head.prev = n;
		head = n;
		size++;
	}
	
	public void draw(Graphics g) {
		if(size <= 0)
			return ;
		
		move();
		for(Node n=head; n!=null; n=n.next) {
			n.draw(g);
		}
	}
	
	private void move() {
		 addToHead();
		 deleteFromTail();
		 checkDead();
	}

	private void checkDead() {
		if(head.row < 2 || head.row >Yard.ROWS || head.col < 0 || head.col > Yard.COLS) {
			y.stop();
		}
		for(Node n=head.next; n!=null; n=n.next) {
			if(head.row == n.row && head.col == n.col)
				y.stop();
		}
	}

	private void deleteFromTail() {
		if(size == 0)
			return ;
		tail = tail.prev;
		tail.next = null;
	}
	
	public Rectangle getRect() {
		return new Rectangle(head.col * Yard.BLOCK_SIZE, head.row * Yard.BLOCK_SIZE, Yard.BLOCK_SIZE, Yard.BLOCK_SIZE);
	}

	public void eat(Egg e) {
		if(this.getRect().intersects(e.getRect())) {
			addToHead();
			e.reAppear();  
			y.setSore(y.getScore() + 5);
		}
	}
	
	private class Node {
		int w = Yard.BLOCK_SIZE , h = Yard.BLOCK_SIZE;
		int row, col;
		Dir dir = Dir.L;
		Node next = null;
		Node prev = null;
		public Node(int row, int col, Dir dir) {
			this.row = row;
			this.col = col;
			this.dir = dir;
		}
		
		public void draw(Graphics g) {
			Color c = g.getColor();
			g.setColor(Color.BLACK);
			g.fillRect(col*Yard.BLOCK_SIZE, row*Yard.BLOCK_SIZE, w, h);
			g.setColor(c);
		}

	}

	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		switch(key) {
		case KeyEvent.VK_LEFT:
			if(head.dir != Dir.R)
				head.dir = Dir.L;
			break;
		case KeyEvent.VK_UP:
			if(head.dir != Dir.D)
				head.dir = Dir.U;
			break;
		case KeyEvent.VK_RIGHT:
			if(head.dir != Dir.L)
				head.dir = Dir.R;
			break;
		case KeyEvent.VK_DOWN:
			if(head.dir != Dir.U)
				head.dir = Dir.D;
			break;
		}
		
	}
}
