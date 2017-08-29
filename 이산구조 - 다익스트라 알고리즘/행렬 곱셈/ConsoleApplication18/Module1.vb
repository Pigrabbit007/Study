Module Module1

    Sub Main()
        Dim a(0 To 2, 0 To 2) As Integer
        Dim b(0 To 2, 0 To 2) As Integer
        Dim c(0 To 2, 0 To 2) As Integer
        Dim h, n As Integer

        For i = 0 To 2
            For j = 0 To 2
                h += 1 : n += 1
                a(i, j) = h : b(i, j) = n
        Next j, i

        For i = 0 To 2
            For j = 0 To 2
                For k = 0 To 2
                    c(i, j) += a(i, k) * b(k, j)
        Next k, j, i

        For i = 0 To 2
            For j = 0 To 2
                If (a(i, j) < 10) Then
                    Console.Write("  {0}", a(i, j))
                Else
                    Console.Write(" {0}", a(i, j))
                End If
            Next j
            Console.Write("  :   ")
            For j = 0 To 2
                If (b(i, j) < 10) Then
                    Console.Write("  {0}", b(i, j))
                Else
                    Console.Write(" {0}", b(i, j))
                End If
            Next j
            Console.Write("  :   ")
            For j = 0 To 2
                If (c(i, j) < 10) Then
                    Console.Write("  {0}", c(i, j))
                Else
                    Console.Write(" {0}", c(i, j))
                End If
            Next j
            Console.WriteLine()
        Next i
    End Sub

End Module
