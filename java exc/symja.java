import org.matheclipse.core.eval.ExprEvaluator;
import org.matheclipse.core.interfaces.IExpr;
import org.matheclipse.core.interfaces.IAST;

public class symja {
    public static void main(String[] args) {
        // 1. Инициализиране на енджина на Symja
        ExprEvaluator util = new ExprEvaluator();

        // 2. Стартиране на Trace върху интеграла
        String input = "Trace( Integrate(2 * x, x) )";
        IExpr traceResult = util.eval(input);

        System.out.println("=== СТЪПКИ НА ИНТЕГРИРАНЕ ===");
        // 3. Обхождане и филтриране на AST дървото
        printIntegrationSteps(traceResult);
    }

    private static void printIntegrationSteps(IExpr expr) {
        // Ако елементът е списък/възел (IAST), го обхождаме рекурсивно
        if (expr instanceof IAST) {
            IAST ast = (IAST) expr;
            
            // Проверяваме дали текущият възел е функция Integrate
            if (ast.isAST() && ast.head().toString().equals("Integrate")) {
                // Извеждаме красиво форматирания математически израз
                System.out.println("👉 Прилагане на правило за: " + ast.toString());
            }
            
            // Продължаваме дълбочинното обхождане (DFS) на дървото
            for (int i = 1; i < ast.size(); i++) {
                printIntegrationSteps(ast.get(i));
            }
        }
    }
}
