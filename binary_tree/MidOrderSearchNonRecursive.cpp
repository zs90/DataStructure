struct BiTreeNode {
	int data;
	struct BiTreeNode * lchild;
	struct BiTreeNode * rchild;
};

void MidOrderTraverseNonRecursive(struct BiTreeNode * T){
	stack <struct BiTreeNode *> s;
	struct BiTreeNode *p = T;
	struct BiTreeNode *tmp;
	
	while (!s.empty() || p){
		if(p){
			s.push(p);
			p = p->lchild;
		}
		else{
			tmp = s.top();
			s.pop();
			visit(tmp->data);
			p = tmp->rchild;
		}
	}
}