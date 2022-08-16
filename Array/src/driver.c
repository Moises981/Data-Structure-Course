#include <array.h>

int main() {
  struct Array array;
  Init(&array);
  int option, index, item, size;
  do {
    printf("\nMenu\n");
    printf("0. Append\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choise [0-6]:");

    scanf("%d", &option);

    switch (option) {
    case 0:
      printf("Enter a item\n");
      scanf("%d", &item);
      Append(&array, item);
      break;
    case 1:
      printf("Enter an index and a item\n");
      scanf("%d %d", &index, &item);
      Insert(&array, index, item);
      break;
    case 2:
      printf("Enter an index\n");
      scanf("%d", &index);
      Delete(&array, index);
      break;
    case 3:
      printf("Enter a item to search\n");
      scanf("%d", &item);
      index = LinearSearch(&array, item);
      printf("Element found at index: %d", index);
      break;
    case 4:
      printf("Sum of items is: %d", Sum(&array));
      break;
    case 5:
      Display(&array);
      break;
    }
  } while (0 <= option < 6);
}