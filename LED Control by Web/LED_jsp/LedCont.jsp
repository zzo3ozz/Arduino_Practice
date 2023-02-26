<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.io.*" %>
<%@page import="java.sql.*"%>
<%
    request.setCharacterEncoding("utf-8");
    String sLedCtrl = request.getParameter("led");

    Connection conn = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;
    
    try {
	    String dbURL = "jdbc:mariadb://sc1.swu.ac.kr:13306/tjdud0814_ts?useUnicode=true&characterEncoding=utf8";
	    String dbID = "tjdud0814";
	    String dbPW = "tjdud0814551";
	    Class.forName("org.mariadb.jdbc.Driver");
	    conn = DriverManager.getConnection(dbURL, dbID, dbPW);
    } catch (Exception e) {
		e.printStackTrace();
	}

    String SQL = "INSERT INTO LED (State) VALUES ('" +  sLedCtrl + "')";
    int ret = -1;
    try {
        pstmt = conn.prepareStatement(SQL);
        ret = pstmt.executeUpdate();
    } catch (Exception e) {
        e.printStackTrace();
    }
%>
<%
    BufferedReader reader = null;
    String strLed = "";
    String LedState = "";
%>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>LED 제어 생성</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    </head>

    <body>
        <div class = "row">
            <div class = "col-12"><h3>LED 제어</h3></div>
            <div class = "col-12">LED 상태: <%=strLed%> </div>
        </div>

        <form method="get">
            <div class = "form-check">
                <input class = "form-check-input" type = "radio" name = "led" value = "on"
                <% if(LedState.equals("on")) out.print(" checked"); %> >LED On
            </div>
            <div class = "form-check">
                <input class = "form-check-input" type = "radio" name = "led" value = "off"
                <% if(LedState.equals("off")) out.print(" checked"); %> >LED Off
            </div>

            <div class = "row">
                <div class = "col-12"><button type="submit" class="btn btn-online-success">LED 상태제어</buttton></div>
            </div>
        </form>
    </body>
</html>