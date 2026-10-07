import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        TextField input = new TextField("Enter...");
        input.setPrefColumnCount(7);

        TilePane r = new TilePane();
        Label label = new Label("Empty");

        Evaluator calculate = new Evaluator();

        EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                label.setText(calculate.handToCalculation(input.getText(), MODE.BASIC));
            }
        };

        input.setOnAction(event);
        r.getChildren().addAll(input, label);

        Scene sc = new Scene(r, 200, 200);
        primaryStage.setScene(sc);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
