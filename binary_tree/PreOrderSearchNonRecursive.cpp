struct BiTreeNode {
	int data;
	struct BiTreeNode * lchild;
	struct BiTreeNode * rchild;
};

void PreOrderTraverseNonRecursive(struct BiTreeNode * T){
	stack <struct node *> s;
	struct BiTreeNode *p = T;
	struct BiTreeNode *tmp;
	
	while (!s.empty() || p){
		if(p){
			visit(p->data);
			s.push(p);
			p = p->lchild;
		}
		else{
			tmp = s.top();
			s.pop();
			p = tmp->rchild;
		}
	}
}