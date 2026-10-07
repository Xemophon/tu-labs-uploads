import org.matheclipse.core.eval.ExprEvaluator;
import org.matheclipse.core.interfaces.IExpr;

import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Evaluator {

    private final ExecutorService executor = Executors.newSingleThreadExecutor();

    public Evaluator() {

    }

    private String evaluate(String input) {
        try {
            ExprEvaluator util = new ExprEvaluator(false, (short) 0);
            IExpr rawResult = util.eval(input);
            return rawResult.toString();
        } catch (final Exception | StackOverflowError | OutOfMemoryError ex) {
            return "Error: " + ex.getMessage();
        }
    }

    public String solveIntegration(String input, String[] limits) {
        final String targetInput = (limits != null)
                ? "Integrate(" + input + ", {x, " + limits[0] + ", " + limits[1] + "})"
                : "Integrate(" + input + ", x)";

        try {
            Future<String> futureResult = executor.submit(() -> evaluate(targetInput));

            return futureResult.get();

        } catch (Exception e) {
            return "Error during execution: " + e.getMessage();
        }
    }

    public String handToCalculation(String input, MODE mode){
        String regex = "\\$";
        switch(mode){
            case INTEGRATE : {
                String[] inputs = input.split(regex);
                return solveIntegration(inputs[0], Arrays.copyOfRange(inputs, 1,2));
                break;
            }
            case BASIC : {
            }
            case DIFFERENTIATE : {
            }
            case SUMMATION : {
            }
            case LAPLACE : {
            }
            case INVERSE_LAPLACE : {
            }
        }
    }

    public void shutdown() {
        executor.shutdown();
    }
}