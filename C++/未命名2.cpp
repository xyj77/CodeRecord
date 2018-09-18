import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

class Node {
	char key;
	Node left;
	Node right;
	Node parent;
	
	Node(char key) {
		this.key = key; 
	}
}
class Tree {
	Node root;
	void middleTraversal() {
		if(this.root == null) {
			return;
		}
		StringBuffer buffer = new StringBuffer();
		Stack<Node> stack = new Stack<Node>();
		
		Node node = this.root;
		while(node != null || !stack.isEmpty()) {
			while(node != null) {
				stack.push(node);
				node = node.left;
			}
			Node pop = stack.pop();
			buffer.append(pop.key).append(" ");
			node = pop.right;
		}
		System.out.println(buffer.toString());
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while(cin.hasNext()) {
			String string = cin.nextLine().trim();
			process(string);
		}
		cin.close();
	}
	
	static void process(String string){
		Node parent = null;
		Node root = null;
		Node node = null;
		boolean left = true;
		OUTER: for(int i=0; i<string.length(); i++) {
			char ch = string.charAt(i);
			
			if(ch == '#') {
				if(left) {
					left = false;
				} else {
					while(true) {
						parent = parent.parent;
						if(parent == null) {
							break OUTER;
						}
						if(parent.right == null) {
							break;
						}
					}
				}
				continue;
			}
			node = new Node(ch);
			if(root == null) {
				root = node;
			}
			
			if(parent != null) {
				if(left) {
					parent.left = node;
				} else {
					parent.right = node;
					left = true;
				}
				node.parent = parent;
			}
			parent = node;
		}
		
		Tree tree = new Tree();
		tree.root = root;
		tree.middleTraversal();
	}
}
