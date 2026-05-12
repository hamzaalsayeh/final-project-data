#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct Product {
    string serial, date;
    Product* next = nullptr;
};

struct Category {
    string name;
    vector<Category*> children;
    Product* products = nullptr;
};

Category* root = new Category{"Warehouse"};
stack<string> recent;

Category* find(Category* node, string name) {
    if (node->name == name) return node;
    for (auto c : node->children)
        if (auto r = find(c, name)) return r;
    return nullptr;
}

void display(Category* node, int d = 0) {
    cout << string(d*3,' ') << "- " << node->name << "\n";
    for (auto c : node->children) display(c, d+1);
    for (auto p = node->products; p; p = p->next)
        cout << string((d+1)*3,' ') << "* " << p->serial << " (" << p->date << ")\n";
}

int main() {
    auto* elec = new Category{"Electronics"};
    elec->children.push_back(new Category{"iPhones"});
    root->children.push_back(elec);

    int ch;
    while (true) {
        cout << "\n1.Add Category  2.Add Product  3.Search  4.Display  5.Recent  6.Exit\n> ";
        cin >> ch; cin.ignore();

        if (ch == 1) {
            string p, n;
            cout << "Parent: "; getline(cin, p);
            cout << "Name: ";   getline(cin, n);
            auto* par = find(root, p);
            if (par) { par->children.push_back(new Category{n}); cout << "Done!\n"; }
            else cout << "Not found.\n";

        } else if (ch == 2) {
            string c, s, d;
            cout << "Category: "; getline(cin, c);
            cout << "Serial: ";   getline(cin, s);
            cout << "Date: ";     getline(cin, d);
            auto* cat = find(root, c);
            if (!cat) { cout << "Not found.\n"; continue; }
            cat->products = new Product{s, d, cat->products};
            if ((int)recent.size() == 5) {
                stack<string> t;
                while (!recent.empty()) { t.push(recent.top()); recent.pop(); }
                t.pop();
                while (!t.empty()) { recent.push(t.top()); t.pop(); }
            }
            recent.push(s + " -> " + c);
            cout << "Added!\n";

        } else if (ch == 3) {
            string n; cout << "Search: "; getline(cin, n);
            auto* c = find(root, n);
            if (c) display(c); else cout << "Not found.\n";

        } else if (ch == 4) {
            display(root);

        } else if (ch == 5) {
            auto tmp = recent;
            while (!tmp.empty()) { cout << tmp.top() << "\n"; tmp.pop(); }

        } else if (ch == 6) {
            cout << "Bye!\n"; break;
        }
    }
    return 0;
}
