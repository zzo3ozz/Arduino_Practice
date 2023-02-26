<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.io.*" %>
<%@page import="java.util.Date"%>
<%@page import="java.sql.*"%>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>LED 제어</title>
    </head>
    <body>
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
            String buttonState = null;
            String SQL = "SELECT State FROM LED WHERE number = (SELECT MAX(number)FROM LED)";
            out.println(SQL);
            try {
                pstmt = conn.prepareStatement(SQL);
                rs = pstmt.executeQuery();
                while(rs.next())
                    out.println("led=" + rs.getString("State"));
            } catch (Exception e) {
                e.printStackTrace();
            }
        %>
    </body>
</html>