import java.lang.*;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.shape.*;
public class RaceTrack extends Application {
    public static void main(String[] args) {
        RaceTrack track = new RaceTrack();
        Thread car1 = new Thread();
        Thread car2 = new Thread();
        Thread car3 = new Thread();

        track.start();
    }
    @Override
    public void start(Stage aStage) {
        Group root = new Group();
        Scene s = new Scene(root, 500, 200);
        aStage.setTitle("Richmond Raceway");
    }
}