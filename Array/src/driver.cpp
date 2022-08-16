#include <array.hpp>

int main() {
  Array<int> array;
  int option, index, item;
  do {

    std::cout << "\nMenu\n"
              << "0. Append\n"
              << "1. Insert\n"
              << "2. Delete\n"
              << "3. Search\n"
              << "4. Sum\n"
              << "5. Display\n"
              << "6. Exit\n"
              << "Enter your choise [0-6]:";

    std::cin >> option;

    switch (option) {
    case 0:
      std::cout << "Enter a item\n";
      std::cin >> item;
      array.Append(item);
      break;
    case 1:
      std::cout << "Enter an index and a item\n";
      std::cin >> index >> item;
      array.Insert(index, item);
      break;
    case 2:
      std::cout << "Enter an index\n";
      std::cin >> index;
      array.Delete(index);
      break;
    case 3:
      std::cout << "Enter a item to search\n";
      std::cin >> item;
      index = array.LinearSearch(item);
      std::cout << "Element found at index: " << index;
      break;
    case 4:
      std::cout << "Sum of items is: " << array.Sum();
      break;
    case 5:
      array.Display();
      break;
    }
  } while (0 <= option && option < 6);
}