<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%@page import="java.util.Calendar.*"%>
<%@page import="java.util.Date"%>
<%@page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta http-equiv="refresh" content="3; url=#">
    <title>Button Data</title>
    <style>
        h1 {font-size:16pt; background:skyblue; padding:5px; }
    </style>
</head>
<body>
    <h1>Button DATA</h1>
    <p>now time : <%=java.util.Calendar.getInstance().getTime() %></p>
    
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
                out.println("DB연결 성공");
            } catch (Exception e) {
                e.printStackTrace();
            }
        %>
    <table>
        <tr><th>Date</th><th>ButtonState</th></tr>
        <%
            String SQL = "SELECT * FROM Button ORDER BY Date DESC limit 5";
            try {
                pstmt = conn.prepareStatement(SQL);
                rs = pstmt.executeQuery();
                
                while(rs.next()) {
                    
                    out.println("<tr>");
                    out.println("<td>" + rs.getString("DATE") + "</td>");
                    out.println("<td>" + rs.getString("BUTTON") + "</td>");
                    out.println("</tr>");
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        %>

    </table>
</body>
</html>