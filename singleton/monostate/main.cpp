#include"iostream"


class Printer{
	static int id;
public:
	void setID(int val){id = val;};
	int getID(){return id;};	
};

// Can you see what’s happening here? The class appears as an ordinary
// class with getters and setters, but they actually work on static data!
// This might seem like a really neat trick: you let people instantiate
// Printer but they all refer to the same data. However, how are users
// supposed to know this? A user will happily instantiate two printers, assign
// them different ids, and be very surprised when both of them are identical!
// The Monostate approach works to some degree and has a couple
// of advantages. For example, it is easy to inherit, it can leverage
// polymorphism, and its lifetime is reasonbly well defined (but then again,
// you might not always wish it so). Its greatest advantage is that you can take
// an existing object that’s already used throughout the system, patch it up
// to behave in a Monostate way, and provided your system works fine with
// the nonplurality of object intances, you’ve got yourself a Singleton-like
// implementation with no extra code needing to be rewritten.
// 
// The disadvantages are obvious, too: it is an intrusive approach
// (converting an ordinary object to a Monostate is not easy), and its use of
// static members means it always takes up space, even when it’s not needed.
// Ultimately, Monostate’s greatest downfall is that it makes a very optimistic
// assumption that the class fields are always exposed through getters and
// setters. If they are being accessed directly, your refactoring is almost
// doomed to fail.

int main(){



	return 0;
}
