// Student ID: 20274909

#pragma once
#include <string>
#include <vector>

using namespace std;

class Tree {
private:

   //comment out
//public:

   //comment end
   struct Node { // Inner class
      std::string _data;
      Node* _sibling, * _child;
      static bool is_equal(const Node* p1, const Node* p2);
      Node(std::string s = "") { _data = s; _sibling = nullptr; _child = nullptr; }
      Node(const Node& that);
      const Node& operator=(const Node& that); // Deep clone
      ~Node() {
         while (this->_sibling != nullptr) {
            delete this->_sibling;
            this->_sibling = nullptr;
         }
         while (this->_child != nullptr) {
            delete this->_child;
            this->_child = nullptr;
         }
      }
      std::string get_data() const { return _data; }
      void set_data(std::string s) { _data = s; }
      Node* insert_sibling(Node* p);
      Node* insert_child(Node* p);
      std::string to_string() const;
      bool operator==(const Node& that) const;
      bool operator!=(const Node& that) const;
   };
   Node* _root;
public:
   Tree() { _root = new Node("ROOT"); }
   ~Tree() { delete _root; _root = nullptr; }
   Tree(const Tree& that);
   Tree& operator=(const Tree& that); // Deep clone
   std::string to_string() const;
   void make_special_config_1(const std::vector<std::string>& names);
   bool operator==(const Tree& that) const {
      return this->_root->is_equal(_root, that._root);
   }
   bool operator!=(const Tree& that) const {
      return (!(*this == that));
   }
   friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
      return os; // TODO
   };
   friend class Tests; // Don't remove this line

   // comment out below

   //Node create_node(string str) {
   //   return Node(str);
   //}

};