<%@ page language="java" contentType="text/html; charset=UTF-8"
  pageEncoding="UTF-8"%>
<%@page import="java.io.*"%>
<%@page import="java.util.Date"%>
<%@page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <title>Final Data 보내기</title>
  <style> h1 {font-size:16pt; background:#AAFFAA; padding:5px; } </style>
</head>
<body>
  <h1>Send JSP Page</h1>
  <p>이 페이지는 JSP 샘플입니다.(마리아DB로 보내기)</p>
  <p><%=java.util.Calendar.getInstance().getTime() %></p>
  <p>----------------------------------</p>
<%
  request.setCharacterEncoding("utf-8");
  String button = request.getParameter("Button");
  String temp = request.getParameter("temp");
  String hum = request.getParameter("mosture");

%>
  <p>----------------------------------</p>
<%
    Connection conn = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;
    
    try {
	    String dbURL = "jdbc:mariadb://sc1.swu.ac.kr:13306/tjdud0814_ts?useUnicode=true&characterEncoding=utf8";
	    String dbID = "tjdud0814";
	    String dbPW = "tjdud0814551";
	    Class.forName("org.mariadb.jdbc.Driver");
	    conn = DriverManager.getConnection(dbURL, dbID, dbPW);
	    out.println("연결 성공");
    } catch (Exception e) {
		e.printStackTrace();
	}

    String SQL = "INSERT INTO Mix (Date, Button, Temperature, Humidity) VALUES (DEFAULT, '"
                   + button + "', '" + temp + "', '" + hum + "')";
    out.println(SQL);
    int ret = -1;
    try {
        pstmt = conn.prepareStatement(SQL);
        ret = pstmt.executeUpdate();
    } catch (Exception e) {
        e.printStackTrace();
    }

    pstmt = null;

    String buttonState = null;
    String SQL2 = "SELECT State FROM LED WHERE number = (SELECT MAX(number)FROM LED)";
    out.println(SQL2);
    try {
        pstmt = conn.prepareStatement(SQL2);
        rs = pstmt.executeQuery();
        while(rs.next())
          out.println("led=" + rs.getString("State"));
    } catch (Exception e) {
        e.printStackTrace();
    }
%>
</body>
</html>


