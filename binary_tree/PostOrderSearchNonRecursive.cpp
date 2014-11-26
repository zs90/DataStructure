struct BiTreeNode {
	int data;
	struct BiTreeNode * lchild;
	struct BiTreeNode * rchild;
};

void PostOrderTraverseNonRecursive(struct BiTreeNode * T){
	stack <struct BiTreeNode *> s;
	struct BiTreeNode *p = T;
	struct BiTreeNode *visited_node = NULL;
	
	while (!s.empty() || p){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else{
			p = s.top();
			if(p->rchild && p->rchild != visited_node){
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else{
				s.pop();
				visit(p->data);
				visited_node = p;
				p = NULL;
			}
		}
	}
}
