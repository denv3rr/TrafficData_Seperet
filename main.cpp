/*
 * main.cpp - main entry
 *
 */

int main()
{
    int choice;

    do
    {
        displayMenu();
        std::cin >> choice;
        handleMenuSelection(choice);
    } while (choice != 5); // change this depending on exit function location

    return 0;
}