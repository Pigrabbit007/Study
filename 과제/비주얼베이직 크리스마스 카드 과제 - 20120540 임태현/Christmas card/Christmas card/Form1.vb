Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        TextBox1.Visible = True

        Dim myPen As Pen
        Dim myBrush As Brush

        Dim A1 As New Point(100, 100)
        Dim A2 As New Point(50, 150)
        Dim A3 As New Point(150, 150)
        Dim B1 As New Point(100, 130)
        Dim B2 As New Point(35, 180)
        Dim B3 As New Point(165, 180)

        Dim C1 As New Point(85, 180)
        Dim C2 As New Point(85, 230)
        Dim C3 As New Point(115, 180)
        Dim C4 As New Point(115, 230)

        Dim Rect1 As Point() = {A1, A2, A3}
        Dim Rect2 As Point() = {B1, B2, B3}
        Dim Wood As Point() = {C1, C3, C4, C2}

        Dim myGraphics As Graphics = Me.CreateGraphics

        myBrush = New SolidBrush(Color.Brown)
        myPen = New Pen(Drawing.Color.WhiteSmoke, 5)
        myGraphics.DrawPolygon(myPen, Wood)
        myGraphics.FillPolygon(myBrush, Wood)

        myBrush = New SolidBrush(Color.Green)

        myGraphics.DrawPolygon(myPen, Rect2)
        myGraphics.FillPolygon(myBrush, Rect2)
        myGraphics.DrawPolygon(myPen, Rect1)
        myGraphics.FillPolygon(myBrush, Rect1)
    End Sub
End Class
