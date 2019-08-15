

class Widget
{
    Widget(int i, bool b);
    Widget(int i, double d);
    Widget(std::initializer_list<int,double> il);
};
Widget w1(10,true); // calls 1st constructor
Widget w1{10,true}; // calls now it is called initializer_list and true is converted to double
Widget w1(10,5.0); // calls 2nd constructor
Widget w1{10,5.0}; // calls now it is called initializer_list and 5.0 is converted to double
