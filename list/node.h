#ifndef NODE_H
#define NODE_H

template <typename T> class DLL;

template <typename T> class Node
{
  friend class DLL <T>;

  public:

    Node(const T &v): prev(NULL), value(v), next(NULL) { }
   ~Node() { }

  private:
    Node <T> *prev;
    Node <T> *next;
    T value;
};

#endif
