list::~list()
{
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

list::item list::a_empty()
{
    a_a_empty(first);
}

list::item list::a_a_empty(Node* g)
{
    Node* temp;
    if (g == NULL)
        return 0;
    else {
        temp = g;
        //g=g->next;
        a_a_empty(g->next);
        delete temp;
    }
}

bool list::isPresent(const item& target)
{
    return i_isPresent(first, target);
}

bool list::i_isPresent(Node* g, const item& target)
{
    if (g->data == target)
        return (g != NULL);
    else
        return g_isPresent(g->next, target);
}

list::Node* list::get_node(const item& entry, Node* g)
{
    Node* temp;
    temp = new Node;
    temp->data = entry;
    temp->next = g;
    return temp;
}

void list::insert(const item& entry)
{
    i_insert(first, entry);
}

void list::i_insert(Node*& g, const item& entry)
{
    if (g == NULL || entry < g->data) {
        g = get_node(entry, g);
    }
    else {
        i_insert(g->next, entry);
    }
}

void list::remove(const item& target)
{
    r_remove(first, target);
}

void list::r_remove(Node*& g, const item& target)
{
    Node* temp;
    if (g->data == target) {
        temp = g;
        g = g->next;
        delete temp;
    }
    else {
        r_remove(g->next, target);
    }
}

int list::length()
{
    return l_length(first);
}

int list::l_length(Node*& g)
{
    if (g == NULL)
        return 0;
    else
        return 1 + l_length(g->next);
}

list::item list::nth(item n)
{
    return n_nth(first, n);
}

list::item list::n_nth(Node* g, item target)
{
    int i = 1;
    if (i == target)
        return g->data;
    else
        return n_nth(g->next, target - 1);
}

ostream& operator<<(ostream& out_s, list& list1)
{
    list::Node* g;
    g = list1.first;
    while (g != NULL) {
        out_s << g->data << " ";
        g = g->next;
    }
    return out_s;
}
