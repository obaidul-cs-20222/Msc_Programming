import java.lang.*;
import java.util.*;

abstract class Pizza {
    void prepare() {
        System.out.print("Preparing pizza...");
    }

    void bake() {
        System.out.print("Baking pizza...");
    }

    void cut() {
        System.out.print("Cutting pizza...");
    }

    void box() {
        System.out.println("Boxing pizza...");
    }

    abstract String getType();

    abstract String getStyle(String style);
}

class ChickenPizza extends Pizza {
    String getType() {
        return "Chicken Pizza";
    }

    String getStyle(String style) {

        if (style.equals("SouthIndian")) {
            return style;
        } else if (style.equals("NorthIndian")) {
            return style;
        } else if (style.equals("American")) {
            return style;
        } else {
            return "Choose a valid style";
        }
    }
}

class PaneerPizza extends Pizza {
    String getType() {
        return "Paneer Pizza";
    }

    String getStyle(String style) {

        if (style.equals("SouthIndian")) {
            return style;
        } else if (style.equals("NorthIndian")) {
            return style;
        } else if (style.equals("American")) {
            return style;
        } else {
            return "Choose a valid style";
        }
    }
}

class CornPizza extends Pizza {
    String getType() {
        return "Corn Pizza";
    }

    String getStyle(String style) {

        if (style.equals("SouthIndian")) {
            return style;
        } else if (style.equals("NorthIndian")) {
            return style;
        } else if (style.equals("American")) {
            return style;
        } else {
            return "Choose a valid style";
        }
    }
}

class PizzaStore {
    Pizza orderPizza(String type, String style) {
        Pizza pizza;
        if (type.equals("chicken")) {
            pizza = new ChickenPizza();
        } else if (type.equals("paneer")) {
            pizza = new PaneerPizza();
        } else if (type.equals("corn")) {
            pizza = new CornPizza();
        } else {
            return null;
        }

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
}

public class client {
    public static void main(String[] args) {

        PizzaStore store = new PizzaStore();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the type of pizza you want to order:");
        String type = scanner.nextLine();
        System.out.println("Enter the style of pizza you want to order:");
        String style = scanner.nextLine();
        Pizza pizza = store.orderPizza(type, style);
        System.out.println("Ordered a " + pizza.getStyle(style) + " style " + pizza.getType());
        scanner.close();
    }
}
