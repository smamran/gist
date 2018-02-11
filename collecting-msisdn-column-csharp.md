## Collecting All MSISDN From a MySQL Server Databases
```cs
// MySQLFetch.cs
// csc MySQLFetch.cs /reference:MySql.Data.dll

using System;
using System.Linq;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using System.Collections;
using System.Collections.Generic;
using System.Data;

class MySQLFetch{

	public static void Main(string[]args) {
		MySqlConnection conn;
		string myConnectionString;

		myConnectionString = "server=127.0.0.1;uid=root;" +
			"pwd=nopass;";

		MySqlDataReader rdr = null;
		Stack db_table_stack = new Stack();
		List < string > msisdn_list = new List < string > ();

		try {
			conn = new MySqlConnection();
			conn.ConnectionString = myConnectionString;

			Console.WriteLine("Connecting....");

			conn.Open();
			
			string stm = "SELECT \n" +
				"     table_schema AS db_name, \n" +
				"     table_name AS tbl_name, \n" +
				"     ROUND(((data_length + index_length) / 1024 / 1024), 2) tbl_size_mb \n" +
				"FROM information_schema.TABLES \n" +
				"ORDER BY tbl_size_mb DESC;";
			MySqlCommand cmd = new MySqlCommand(stm, conn);

			rdr = cmd.ExecuteReader();
			while (rdr.Read()) {
				if (!rdr.IsDBNull(2)) {
					if (Convert.ToDouble(rdr.GetString("tbl_size_mb")) >= Convert.ToDouble("0.01")) {
						string s = rdr.GetString("db_name") + "." + rdr.GetString("tbl_name");
						db_table_stack.Push(s);

					}
				}
			}

			rdr.Close();

			Console.WriteLine(db_table_stack.Count);
			string db_table;
			while (db_table_stack.Count != 0) {
				db_table = Convert.ToString(db_table_stack.Pop());
				stm = "select * from " + db_table;

				try {

					MySqlCommand myCommand = new MySqlCommand(stm, conn);

					rdr = myCommand.ExecuteReader();

					int totalField = rdr.FieldCount;

					// Field can be accessed through 0 to n-1
					
					for (int i = 0; i <= totalField - 1; i++) {
						if (rdr.GetName(i) == "MSISDN") {
							while (rdr.Read()) {
								msisdn_list.Add(rdr.GetString("MSISDN"));
							}
							break;
						} else if (rdr.GetName(i) == "msisdn") {
							while (rdr.Read()) {
								msisdn_list.Add(rdr.GetString("msisdn"));
							}
							break;
						} else if (rdr.GetName(i) == "ano") {
							while (rdr.Read()) {
								msisdn_list.Add(rdr.GetString("ano"));
							}
							break;
						}
					}

				} catch (MySqlException ex) {
					MessageBox.Show(ex.Message);
				}
				rdr.Close();
			}

		} catch (MySqlException ex) {
			MessageBox.Show(ex.Message);
		}

		Console.WriteLine(msisdn_list.Count);

		List < string > unique = msisdn_list.Distinct().ToList();

		Console.WriteLine(unique.Count);

		Console.WriteLine("Goodbye!");
	}
}
```
