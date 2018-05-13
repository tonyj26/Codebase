
import javafx.application.*;
import javafx.event.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.geometry.*;

public class Login extends Application {
  public static void main(String[] args) {
    launch(args);
  }

  @Override 
  public void start(Stage primaryStage) {
    primaryStage.setTitle("JavaFX Welcome");

    GridPane grid = new GridPane();
    grid.setAlignment(Pos.CENTER);
    grid.setHgap(10);
    grid.setVgap(10);
    grid.setPadding(new Insets(25, 25, 25, 25));

    Text SceneTitle = new Text("Welcome");
    sceneTtle.setFont(Font.font("Tahoma", FontWeight.NORMAL, 20));
    grid.add(scenetitle, 0, 0, 2, 1);

    Label userName = new Label("User Name:");
    grid.add(userName, 0,1);
    
    TextField userTextField = new TextField();
    grid.add(userTextField, 1, 1);

    label pw = new Label("Password:");
    grid.add(pw, 0, 2);

    passwordField pwBox = new PasswordField();
    grid.add(pwBox, 1, 2);


    Scene scene = new Scene(grid, 300, 275);
    primaryStage.show();
  }
}

