If you are using XAMPP then open
C:\xampp\apache\conf\httpd.conf
in your favorite php editor.

OR

If you are using WAMP then open
C:\wamp\bin\apache\Apache2.2.11\conf\httpd.conf
in your favorite php editor.
We need to shift "C:\xampp\htdocs" to "D:\projects" so that when we open "http://localhost", then instead of listing projects in "htdocs" folder it will list our projects from "D:\projects" .

Please modify following snippet of code in httpd.conf

Hash(#) shows that line is commented

    On line 186

    #
    # DocumentRoot: The directory out of which you will serve your
    # documents. By default, all requests are taken from this directory, but
    # symbolic links and aliases may be used to point to other locations.
    #
    #DocumentRoot "C:/xampp/htdocs"
    DocumentRoot "D:/projects"

    On line 221
    #
    # This should be changed to whatever you set DocumentRoot to.
    #
    # < Directory "C:/xampp/htdocs">
    < Directory "D:/projects">

    Don't forget to re-start your apache server to make changes working.
