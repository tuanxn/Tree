// Student ID: 20274909

#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;

//int main()
//{
//   Tree temp = Tree();
////   temp.make_special_config_1({ "AABA", "ABAB", "ABBA", "BABA", "COBO", "COCO", "CODO", "COFO", "COGO", "COHO", "COJO",
////"COKO", "DIBI", "DIDI", "DIFI", "DIGI", "DIHI", "DIJI", "DIKI", "DILI" });
//
//   temp._root->insert_child(new Tree::Node("child"));
//   temp._root->insert_sibling(new Tree::Node("sib"));
//   temp._root->_sibling->insert_sibling(new Tree::Node("sib2"));
//
//   Tree temp2 = temp;
//
//   //Tree::Node new_node = temp_node;
//
//   //Tree::Node diff_node = temp.create_node("diff");
//
//   //cout << new_node.is_equal(&new_node, &diff_node);
//
//   //cout << new_node.is_equal(&new_node, &temp_node);
//
//
//}

Tree::Node* Tree::Node::insert_sibling(Node* p) {
   if (_sibling == nullptr) {
      _sibling = p;
      return p;
   }

   this->_sibling->insert_sibling(p);

   cout << "insert sibling";

   return p;
}

Tree::Node* Tree::Node::insert_child(Node* p) {
   if (_child == nullptr) {
      _child = p;
      return p;
   }

   this->_child->insert_sibling(p);

   cout << "insert child";

   return p;
}

const Tree::Node& Tree::Node::operator=(const Tree::Node& that) {
   
   if (this != &that) {
      Node* temp = new Node(that.get_data());
      if (that._child == nullptr) {
         temp->_child = nullptr;
      }
      else {
         temp->_child = new Node(*that._child);
      }
      if (that._sibling == nullptr) {
         temp->_sibling = nullptr;
      }else {
         temp->_sibling = new Node(*that._sibling);
      }
      this->set_data(temp->get_data());
      this->_child = temp->_child;
      this->_sibling = temp->_sibling;
   }
   cout << "assign node";
   return *this;
}

Tree::Node::Node(const Node& that) {
   *this = that;
}

bool Tree::Node::is_equal(const Node* p1, const Node* p2) {
   if (p1 == nullptr && p2 == nullptr) {
      return true;
   }
   else if (*p1 == *p2) {
      return true;
   }
   return false;
}

bool Tree::Node::operator==(const Node& that) const {
   bool result = true;

   if (this->_child == nullptr && that._child == nullptr && this->_sibling == nullptr && that._sibling == nullptr) {
      return true;
   }
   else if (this->_child == nullptr && that._child != nullptr) {
      return false;
   }
   else if (this->_child != nullptr && that._child == nullptr) {
      return false;
   }
   else if (this->_sibling == nullptr && that._sibling != nullptr) {
      return false;
   }
   else if (this->_sibling != nullptr && that._sibling == nullptr) {
      return false;
   }
   else {
      result = is_equal(this->_child, that._child);
      if (result) {
         result = is_equal(this->_sibling, that._sibling);
      }
   }
   return result;
}

bool Tree::Node::operator!=(const Node& that) const {
   return (!(this == &that));
}

string Tree::Node::to_string() const {
   string output = this->get_data() + " :";
   if (this->_child != nullptr) {
      Node* temp = this->_child;
      output += " " + temp->get_data();
      while (temp->_sibling != nullptr) {
         output += " " + temp->_sibling->get_data();
         temp = temp->_sibling;
      }
   }

   output += "\n";

   if (this->_child != nullptr) {
      output += "# Child of " + this->get_data() + "\n";
      output += this->_child->to_string();
   }

   if (this->_sibling != nullptr) {
      output += "# Next sib of " + this->get_data() + "\n";
      output += this->_sibling->to_string();
   }
   return output;
}

Tree::Tree(const Tree& that) {
   *this = that;
}
Tree& Tree::operator=(const Tree& that) {
   if (this != &that) {
      Tree* temp = new Tree();
      temp->_root = new Node(*that._root);
      this->_root = temp->_root;
   }
   cout << "assign node";
   return *this;
}

string Tree::to_string() const {
   string output = "";
   output += "# Tree rooted at " + this->_root->get_data() + "\n";
   output += "# The following lines are of the form:\n";
   output += "#   node: child1 child2...\n";
   output += this->_root->to_string();
   output += "# End of Tree\n";
   return output;
}

void Tree::make_special_config_1(const vector<string>& names) {
   Node* root_sib;
   Node* root_sib_child;

   this->_root->insert_sibling(new Node(names[0]));
   root_sib = this->_root->_sibling; // AABA
   root_sib->insert_child(new Node(names[4]));
   root_sib_child = root_sib->_child; // COBO
   root_sib_child->insert_child(new Node(names[12]));
   root_sib_child->insert_sibling(new Node(names[5]));
   root_sib_child = root_sib_child->_sibling; // COCO
   root_sib_child->insert_child(new Node(names[13]));

   root_sib->insert_sibling(new Node(names[1]));
   root_sib = root_sib->_sibling; // ABAB
   root_sib->insert_child(new Node(names[6]));
   root_sib_child = root_sib->_child; // CODO
   root_sib_child->insert_child(new Node(names[14]));
   root_sib_child->insert_sibling(new Node(names[7]));
   root_sib_child = root_sib_child->_sibling; // COFO
   root_sib_child->insert_child(new Node(names[15]));

   root_sib->insert_sibling(new Node(names[2]));
   root_sib = root_sib->_sibling; // ABBA
   root_sib->insert_child(new Node(names[8]));
   root_sib_child = root_sib->_child; // COGO
   root_sib_child->insert_child(new Node(names[16]));
   root_sib_child->insert_sibling(new Node(names[9]));
   root_sib_child = root_sib_child->_sibling; // COHO
   root_sib_child->insert_child(new Node(names[17]));

   root_sib->insert_sibling(new Node(names[3]));
   root_sib = root_sib->_sibling; // BABA
   root_sib->insert_child(new Node(names[10]));
   root_sib_child = root_sib->_child; // COJO
   root_sib_child->insert_child(new Node(names[18]));
   root_sib_child->insert_sibling(new Node(names[11]));
   root_sib_child = root_sib_child->_sibling; // COKO
   root_sib_child->insert_child(new Node(names[19]));

}