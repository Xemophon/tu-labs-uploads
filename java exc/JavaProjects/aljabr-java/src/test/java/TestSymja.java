import org.matheclipse.core.eval.ExprEvaluator;

void main() {
    ExprEvaluator evalue = new ExprEvaluator(false, (short) 100);
    Scanner util = new Scanner(System.in);
    System.out.println("Write expr: ");
    String input = util.nextLine();
    while(!input.equalsIgnoreCase("exit")){
        System.out.println(evalue.eval(input).toString());
        input = util.nextLine();
    }
}
