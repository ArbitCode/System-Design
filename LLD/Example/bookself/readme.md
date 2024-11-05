# Requirements

## Iterator : 1 (Single Responsibility Principle) Cohesive Class

1. A user must be able to add a fictional book and their attributes to the catalogue
2. The attributes for each book shall be books title and author's first and last name.
3. A user must be able to search for books that matches the user's target attribute values.
4. Searches for the books will depend on any number of target attributes.
5. String matches of the book titles and authors' first and last names must be case insensitive.
6. A user must be able to specifiy any number of wild-card target attributes.

## Iterator : 2 (Encapsulation, delegation, and loose coupling)

1. Add two more book atributes : the publication year and genre (ADVENTURE, DETECTIVE, FANTASY, HISTORIC, HORROR, ROMANCE, SCIFI)

Principle: Encapsulation - The Encapsulate what varies supports the principle of least knowledge

**Principle: Delegates - Move functionality out of one class(requester) into another class(delegates) to make two class more cohesive. The requester class commonly has member variable that points to delegates class.**

**Loose Coupling : Least Knowledge about other classes.**

## Iterator : 3 (More kinds of books and their attributes) lot's of subclass so bad design

1. It must be able to add cookbooks and their attributes to the catalog.
2. The attributes for cookbook must include its region (CHINA, FRANCE, INDIA, ITALY, MEXICO, US, NONE)

Principle: Open-Closed Principle: supports loose coupling and encapsulation

Principle: Don't Repeat Yourself

## Iterator : 4 Use Map [Solution]

## Summary

* It Usually takes several development iterations to achieve a well desinged program. Be willing to backtrack from bad desigin decisions.
* SRP : states that a class should be cohesive and have only one primary responsibility.
* The Encapsulate what varies principle: states that code that can vary should be isolated to keep its changes from causing other code to change.
* The Delegation Principle: states that one class can perform work on the behalf of another class, where the work belongs to a more suitable cohesive class.
* The Pricinple of least knowledge: states that classes should not know about each other's implementation, and so classes are loosely coupled with few dependency on each other.
* The open-closed principle: states that a class should be closed for modification but open for extension to provide both stability and fexibilty.
* The code to the interface principle: for runtime flexibility we should not write code that can work only with specific subclasses but use polymorphism that can work with multiple sub classes.
* The Don't Repleat yourself Principle: states the well designed code does not contain duplicate copies of code.
