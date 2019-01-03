#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int maxheightutil(std::vector<int>&nodes,std::vector<int>&memoizedheight,int index){
	if (nodes[index]==-1){
		return 1;
	}
	if (memoizedheight[index]!=0){
		return memoizedheight[index];
	}
	memoizedheight[index]=1+maxheightutil(nodes,memoizedheight,nodes[index]);
	return memoizedheight[index];
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  /*
  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  /*
  int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }
  */
  
  // No need to create a node structure. Just a vector is sufficient.
  
  std::vector<int> nodes(n);
  std::vector<int>memoizedheight(n);
  for (int i=0;i<n;i++){
  	std::cin>>nodes[i];
  	memoizedheight[i]=0;
  }
  
  
  int maxHeight=0;
  for (int leaf_index=0;leaf_index<n;leaf_index++){
  	maxheightutil(nodes,memoizedheight,leaf_index);
  }
 // for (int i=0;i<memoizedheight.size();i++)std::cout<<memoizedheight[i]<<" ";
 // std::cout<<"\n";
  maxHeight=*max_element(memoizedheight.begin(),memoizedheight.end());

    
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
