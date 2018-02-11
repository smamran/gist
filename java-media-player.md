## Media Player Online Java

```sh
 javac -cp .:jl1.0.1.jar Main.java [Linux]
 java -cp .:jl1.0.1.jar Main https://www.google.com/media/mp3/audio.mp3 [Linux]
 ------------------------------------------------------------------------------
 javac -cp .;jl1.0.1.jar Main.java [Windows]
 java -cp .;jl1.0.1.jar Main https://www.google.com/media/mp3/audio.mp3 [Windows]
 ```
### Source Code
 
 ```java
import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;

public class Main {

    private static String link;

    public Main(String arg) {
        this.link = arg;
    }

    public static void play() {
        String song = link;
        Player mp3player = null;
        BufferedInputStream in = null;
        try {
            in = new BufferedInputStream(new URL(song).openStream());
            mp3player = new Player(in);
            mp3player.play();
        } catch (MalformedURLException ex) {
        } catch (IOException e) {
        } catch (JavaLayerException e) {
        } catch (NullPointerException ex) {
        }

    }

    public static void main(String args[]) {
        Main mn = new Main(args[0]);
        mn.play();
    }

}
```
