## Java URL Extract Crawler
```java
package com.sm.javavm;

import java.io.*;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
    public static void main(String[] args) throws IOException {

        String url = "https://developer.android.com/reference/classes.html";

        StringBuilder stringBuilder = fetchHttpUrl(url);

        // Pattern for recognizing a URL, based off RFC 3986
        final Pattern urlPattern = Pattern.compile(
                "(?:^|[\\W])((ht|f)tp(s?):\\/\\/|www\\.)"
                        + "(([\\w\\-]+\\.){1,}?([\\w\\-.~]+\\/?)*"
                        + "[\\p{Alnum}.,%_=?&#\\-+()\\[\\]\\*$~@!:/{};']*)",
                Pattern.CASE_INSENSITIVE | Pattern.MULTILINE | Pattern.DOTALL);

        Matcher matcher = urlPattern.matcher(stringBuilder);

        List<String> list = new ArrayList<>();

        int counter = 1;
        while (matcher.find()) {
            int matchStart = matcher.start(1);
            int matchEnd = matcher.end();
            System.out.println(counter + " : " + matchStart + " => " + matchEnd);
            System.out.println(stringBuilder.substring(matchStart, matchEnd));
            list.add(stringBuilder.substring(matchStart, matchEnd));
            counter++;
        }
        counter--;
        System.out.println("Total Found :" + counter);
        FileWriter fileWriter = null;

        try {
            fileWriter = new FileWriter("links.csv");
            String COMMA_SEPARATOR = ",";
            String NEW_LINE_SEPARATOR = "\n";
            String FILE_HEADER = "No,Link";

            fileWriter.append(FILE_HEADER.toString());
            fileWriter.append(NEW_LINE_SEPARATOR);
            int id = 1;
            for (String s : list) {
                fileWriter.append(String.valueOf(id));
                fileWriter.append(COMMA_SEPARATOR);
                fileWriter.append(s);
                fileWriter.append(NEW_LINE_SEPARATOR);
                id++;
            }

            fileWriter.flush();
            fileWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static StringBuilder fetchHttpUrl(String url) throws IOException {
        URL oracle = new URL(url);
        BufferedReader in = new BufferedReader(
                new InputStreamReader(oracle.openStream()));

        String inputLine;

        StringBuilder stringBuilder = new StringBuilder();

        while ((inputLine = in.readLine()) != null)
            stringBuilder.append(inputLine + "\n");
        in.close();
        return stringBuilder;
    }
}
```
