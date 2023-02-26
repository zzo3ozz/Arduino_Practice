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
    <title>GPS Data 확인 Page</title>
    <style>
        h1 {font-size:16pt; background:skyblue; padding:5px; }
        table { border-style: 1px, solid, black;}
    </style>
</head>
<body>
    <h1>GPS DATA</h1>
    <p>now time : <%=java.util.Calendar.getInstance().getTime() %></p>
    
        <%
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
        
            try {
                String dbURL = "jdbc:mariadb://Address:13306/id_ts?useUnicode=true&characterEncoding=utf8";
                String dbID = "id";
                String dbPW = "pw";
                Class.forName("org.mariadb.jdbc.Driver");
                conn = DriverManager.getConnection(dbURL, dbID, dbPW);
                out.println("DB연결 성공");
            } catch (Exception e) {
                e.printStackTrace();
            }
        %>
    <table>
        <tr><th>Date</th><th>Latitude</th><th>N/S</th><th>Longitude</th><th>W/E</th><th>Speed</th><th>Course</th></tr>
        <%
            String SQL = "SELECT * FROM GPSData ORDER BY Date DESC limit 5";
            try {
                pstmt = conn.prepareStatement(SQL);
                rs = pstmt.executeQuery();
                
                while(rs.next()) {
                    
                    out.println("<tr>");
                    out.println("<td>" + rs.getTimestamp("Date") + "</td>");
                    out.println("<td>" + rs.getString("Latitude") + "</td>");
                    out.println("<td>" + rs.getString("NS") + "</td>");
                    out.println("<td>" + rs.getString("Longitude") + "</td>");
                    out.println("<td>" + rs.getString("WE") + "</td>");
                    out.println("<td>" + rs.getString("Km") + "</td>");
                    out.println("<td>" + rs.getString("Direction") + "</td>");
                    out.println("</tr>");
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        %>

    </table>
</body>
</html>