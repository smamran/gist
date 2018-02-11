## Collecting All MSISDN From a MySQL Server Databases
```java
// javac -cp .;mysql-jdbc.jar MySQLServerFetch.java
// java -cp .;mysql-jdbc.jar MySQLServerFetch

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.Stack;

public class MySQLServerFetch {
    //    JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    //    To Store Data
    static final String DB_LOCALHOST = "jdbc:mysql://localhost/";

    //     From Fetch Data
    static final String DB_FETCH_SERVER = "jdbc:mysql://localhost/";
    static final String fileToWrite = "localhost.txt";

    //    Database credentials From
    static final String USER_FETCH = "root";
    static final String PASS_FETCH = "nopass";

    //     Database Credential To
    static final String USER_LOCAL = "root";
    static final String PASS_LOCAL = "nopass";


    static Stack<String> db_table_stack = new Stack<>();
    static Stack<String> msisdn = new Stack<>();

    public static void main(String[] args) throws SQLException, IOException {
        Connection conn_local = null;
        Connection conn_fetch = null;
        Statement stmt = null;
        try {
//            STEP 2: Register JDBC driver
            Class.forName("com.mysql.jdbc.Driver");

//            STEP 3: Open a connection
            System.out.println("Connecting to database...");
            conn_local = DriverManager.getConnection(DB_LOCALHOST, USER_LOCAL, PASS_LOCAL);
            conn_fetch = DriverManager.getConnection(DB_FETCH_SERVER, USER_FETCH, PASS_FETCH);

//            STEP 4: Execute a query
            System.out.println("Creating statement...");
            stmt = conn_fetch.createStatement();
            String sql;
            sql = "SELECT \n" +
                    "     table_schema AS db_name, \n" +
                    "     table_name AS tbl_name, \n" +
                    "     ROUND(((data_length + index_length) / 1024 / 1024), 2) tbl_size_mb \n" +
                    "FROM information_schema.TABLES \n" +
                    "ORDER BY tbl_size_mb DESC;";
            ResultSet rs = stmt.executeQuery(sql);

//            STEP 5: Extract data from result set
            while (rs.next()) {
//                Retrieve by column name
                String db_name = rs.getString("db_name");
                String tbl_name = rs.getString("tbl_name");
                String tbl_size_mb = rs.getString("tbl_size_mb");

//                Push DB.TABLE Name to Stack
                if (tbl_size_mb != null) {
                    if (Double.parseDouble(tbl_size_mb) >= 0.01)
                        db_table_stack.push(db_name + "." + tbl_name);
                }
            }
//            STEP 6: Clean-up environment
//            rs.close();
//            stmt.close();
//            conn.close();
        } catch (SQLException se) {
//            Handle errors for JDBC
            se.printStackTrace();
        } catch (Exception e) {
//            Handle errors for Class.forName
            e.printStackTrace();
        } finally {
//            finally block used to close resources
//            try{
//                if(stmt!=null)
//                    stmt.close();
//            }catch(SQLException se2){
//            }// nothing we can do
//            try{
//                if(conn!=null)
//                    conn.close();
//            }catch(SQLException se){
//                se.printStackTrace();
//            }//end finally try
        }//end try

//         Total count of DB.TABLE
        System.out.println(db_table_stack.size());

        String db_table;
        while (!db_table_stack.empty()) {
            db_table = db_table_stack.pop();
            String query = "select msisdn from " + db_table;
            try {
                ResultSet rs = stmt.executeQuery(query);
                ResultSetMetaData metaData = rs.getMetaData();

                // Checking whether a query is executed successfully
                // and found metadata
                if (metaData.getColumnCount() > 0) {
                    // Push All MSISDN to Stack
                    while (rs.next()) {
                        msisdn.push(rs.getString("msisdn"));
                    }
                }
            } catch (SQLException e) {
                //e.printStackTrace();
            }
        }

        // All MSISDN Including Duplicates
        System.out.println(msisdn.size());

        // Unique MSISDN
        Set<String> hashSet = new HashSet<>(msisdn);
        System.out.println(hashSet.size());

        BufferedWriter out = new BufferedWriter(new FileWriter(fileToWrite));
        Iterator it = hashSet.iterator();
        while (it.hasNext()) {
            out.write(it.next() + "\n");
        }
        out.close();

        System.out.println("Goodbye!");
    }//end main
}//end MySQLServerFetch
```
