package com.gm.dp.iterator;

import com.gm.dp.iterator.Collection;

public class LinkedList implements Collection{

	private Node head = null;
	private Node tail = null;
	private int size = 0;
	
	public void add(Object o) {
		Node n = new Node(o, null);
		
		if(head == null) {
			head = n;
			tail = n;
		}
		tail.setNext(n);
		tail = n;
		size++;
	}
	
	public int size() {
		return size;
	}

	@Override
	public Iterator iterator() {
		return new LinkedListIterator();
	}
	
	private class LinkedListIterator implements Iterator {

		private int currentIndex = 0;
		
		@Override
		public Object next() {
			if(currentIndex < size) {
				Node n = head;
				int i = 0;
				while(i < currentIndex) {
					n = (Node) n.getNext();
					i++;
				}
				return n;
			}
			return null;
		}

		@Override
		public boolean hasNext() {
			if(currentIndex >=size)  return false;
			else return true;
		}
		
		
	}
}
