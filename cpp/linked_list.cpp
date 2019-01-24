#include <iostream>
#include <vector>

using namespace std;

struct node_t {
  int v;
  node_t* next;
};

node_t* get_last_node(node_t* current_node) {
  while (current_node->next) {
      current_node = current_node->next;
  }
    return current_node;
}

void insert(node_t*& head, int v) {
    if (!head) {
        head = new node_t {v, NULL};
        return;
    }
  node_t* last_node = get_last_node(head);
  last_node->next = new node_t {v, NULL};
}

void insert(node_t*& head, node_t* new_node) {
    new_node->next = NULL;
    if (!head) {
        head = new_node;
        return;
    }
  node_t* last_node = get_last_node(head);
  last_node->next = new_node;
}

bool havent_seen_odd_number_yet(node_t* current_node, node_t* previous_node) {
    if (current_node == previous_node)
        return true;
    else
        return false;
}

node_t* even_node(node_t** head) {
    node_t* current_node = *head;
    node_t* previous_node = *head;
    node_t* even_nodes = NULL;
    while (current_node) {
        if ( (current_node->v)%2 == 0 ) {
            node_t* to_delete = current_node;
            if (havent_seen_odd_number_yet(current_node, previous_node)) {
                previous_node = current_node->next;
                *head = previous_node;
            }
            else {
                previous_node->next = current_node->next;
            }
            current_node= current_node->next;
            insert(even_nodes, to_delete);
            continue;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return even_nodes;
}

void test_list(node_t* list, const vector<int> expected_values) {
  node_t* p =list;
  size_t i = 0;
  while (p && i < expected_values.size()) {
    if (p->v != expected_values[i]) {
      std::cout << p->v << " != " << expected_values[i] << std::endl;
      break;
    }
    p = p->next;
    i++;
  }
  if (p == NULL && i == expected_values.size()) {
    std::cout << "Test passed!" << std::endl;
  } else {
    std::cout << "Test failed!" << std::endl;
  }
}

void print_list(node_t* list) {
  node_t* p =list;
  cout << "Printing list: " << endl;
    while (p) {
      cout << p->v <<endl;
      p = p->next;
    }
}

int main() {
  node_t* my_list =NULL;
  node_t* even_list= even_node(&my_list);
  test_list(my_list, {});
  test_list(even_list, {});
  
  insert(my_list, 0);
  even_list= even_node(&my_list);
  test_list(my_list, {});
  test_list(even_list, {0});

  insert(my_list, 0);
  insert(my_list, 2);
  even_list= even_node(&my_list);
  test_list(my_list, {});
  test_list(even_list, {0, 2});

  insert(my_list, 0);
  insert(my_list, 1);
  insert(my_list, 2);
  insert(my_list, 3);
  insert(my_list, 2);
  even_list= even_node(&my_list);
  test_list(my_list, {1, 3});
  test_list(even_list, {0, 2, 2});
}
